#include "PlayerTest.h"

PlayerTest::PlayerTest(const ResourceFont& resourceFont, const ResourceHud& resourceHud)
{
	this->player_Bag_ = new PlayerBag(resourceFont, resourceHud);
	this->player_Hud_ = new PlayerHud(1280, 720, resourceFont, resourceHud);
	this->player_Inventory_ = new PlayerInventory(resourceFont);
	this->player_Quest_ = new PlayerQuest(resourceFont, resourceHud);
	this->player_Skill_Tree_ = new PlayerSkillTree(resourceFont);
	this->player_Gather_ = new PlayerGather(resourceFont);

	this->race_ = new RaceOrc();
	this->race_->initializeRace(0.f, 0.f);
	//this->race_->setPlayerClasses(this->race_->getClassesOne());

	this->name_ = "";

	this->player_Model_.setSize(sf::Vector2f(25.f, 50.f));
	this->player_Model_.setPosition(sf::Vector2f(60.f, 60.f));
	this->player_Model_.setFillColor(sf::Color::Cyan);

	this->next_Position_.setSize(sf::Vector2f(this->player_Model_.getSize().x, this->player_Model_.getSize().y));
	this->next_Position_.setPosition(sf::Vector2f(this->player_Model_.getPosition().x, this->player_Model_.getPosition().y));
	this->next_Position_.setFillColor(sf::Color::Transparent);
	this->next_Position_.setOutlineThickness(1.f);
	this->next_Position_.setOutlineColor(sf::Color::Red);

	this->auto_Attack_Range_.setSize(sf::Vector2f(125.f, 50.f));
	this->auto_Attack_Range_.setPosition(sf::Vector2f(this->player_Model_.getPosition().x, this->player_Model_.getPosition().y));
	this->auto_Attack_Range_.setFillColor(sf::Color::Transparent);
	this->auto_Attack_Range_.setOutlineThickness(1.f);
	this->auto_Attack_Range_.setOutlineColor(sf::Color::Magenta);
	
	this->velocity_.x = 0.f;
	this->velocity_.y = 0.f;
	this->movement_Speed_ = 200.f;
	this->gravity_ = 6.f;
	this->position_Before_Jump_ = 0.f;
	this->jump_Speed_ = 200.f;
	this->max_Jump_Height_ = 60.f;

	this->is_Jumping_ = false;

	this->level_ = 1;
	this->max_Exp_ = std::floor(3 * ((std::pow(this->level_, 2.3))) * 1.5);
	std::cout << "MAX EXP: " << this->max_Exp_ << std::endl;
	this->exp_ = 0;

	this->skill_Points_ = 99;

	this->is_Combat_ = false;

	//TESTING ONLY FIX LATER
	this->player_Bag_->initializeBag();
	this->camera_ = new Camera(0.f, 0.f);
	//this->selected_Enemy_ = new EnemyTest();
	this->selected_Enemy_ = NULL;
	this->class_One_ = NULL;
	this->class_Two_ = NULL;
}

PlayerTest::~PlayerTest()
{
	//delete this->race_;
	delete this->camera_;

	delete this->player_Bag_;
	delete this->player_Hud_;
	delete this->player_Inventory_;
	delete this->player_Quest_;
	delete this->player_Skill_Tree_;
	delete this->player_Gather_;
}

void PlayerTest::initializeCharacter(Race* race, const std::string& name)
{
	/*
		THIS IS SET AFTER CHARACTER CREATINO IS COMPLETE
	*/
	this->race_ = race;
	this->player_Model_.setFillColor(this->race_->getModel().getFillColor());
	this->player_Model_.setOutlineColor(this->race_->getModel().getOutlineColor());

	if (this->stats_.empty())
	{
		this->stats_.insert(std::make_pair("healthMax", this->race_->getHealthMax()));
		this->stats_.insert(std::make_pair("health", this->race_->getHealth()));
		this->stats_.insert(std::make_pair("manaMax", this->race_->getManaMax()));
		this->stats_.insert(std::make_pair("mana", this->race_->getMana()));
		this->stats_.insert(std::make_pair("strength", this->race_->getStrength()));
		this->stats_.insert(std::make_pair("dexerity", this->race_->getDexerity()));
		this->stats_.insert(std::make_pair("intelligence", this->race_->getIntelligence()));
		this->stats_.insert(std::make_pair("perception", this->race_->getPerception()));
		this->stats_.insert(std::make_pair("wisdom", this->race_->getWisdom()));

		this->resistances_.insert(std::make_pair("cold", this->race_->getCold()));
		this->resistances_.insert(std::make_pair("fire", this->race_->getFire()));
		this->resistances_.insert(std::make_pair("lightning", this->race_->getLightning()));
		this->resistances_.insert(std::make_pair("poison", this->race_->getPoison()));

		std::cout << std::to_string(this->stats_.at("strength")) << std::endl;
		std::cout << std::to_string(this->stats_.at("health")) << std::endl;
	}
	else
	{
		this->stats_.at("healthMax") = this->race_->getHealthMax();
		this->stats_.at("health") = this->race_->getHealth();
		this->stats_.at("manaMax") = this->race_->getManaMax();
		this->stats_.at("mana") = this->race_->getMana();
		this->stats_.at("strength") = this->race_->getStrength();
		this->stats_.at("dexerity") = this->race_->getDexerity();
		this->stats_.at("intelligence") = this->race_->getIntelligence();
		this->stats_.at("perception") = this->race_->getPerception();
		this->stats_.at("wisdom") = this->race_->getWisdom();

		this->resistances_.at("cold") = this->race_->getCold();
		this->resistances_.at("fire") = this->race_->getFire();
		this->resistances_.at("lightning") = this->race_->getLightning();
		this->resistances_.at("poison") = this->race_->getPoison();

		std::cout << std::to_string(this->stats_.at("health")) << std::endl;
	}

	this->name_ = name;
	this->player_Hud_->intializeHud(this->name_, this->getStat("healthMax"), this->getStat("health"), this->getStat("manaMax"), this->getStat("mana"), this->max_Exp_, this->exp_);
}

void PlayerTest::updateSkillsPollEvent(sf::Event& ev, std::vector<Enemy*>& enemies)
{
	this->player_Hud_->updateSkillOnePollEvent(ev, this->player_Skill_Tree_->setClassesOne(), enemies, this->stats_, this->getStatForChange("mana"), this->is_Combat_);
}

void PlayerTest::updatePollEvent(sf::Event& ev, const float& dt)
{
	/*
		PLAYER HUD POLL UPDATES
	*/
	this->player_Hud_->updatePollEvent(ev, this->race_->setHealth(), this->race_->getHealthMax());
	this->player_Inventory_->updatePollEvent(ev, this->stats_, this->resistances_, this->player_Bag_->setItem(), this->player_Bag_->getBagSizeX(), this->player_Bag_->getBagSizeY());
	this->player_Bag_->updatePollEvent(ev, this->player_Inventory_->setEquipment(), this->stats_, this->resistances_);
	this->player_Quest_->updatePollEvent(ev);
	this->player_Skill_Tree_->updatePollEvent(ev, this->stats_, this->skill_Points_);
	this->player_Gather_->updatePollEvent(ev);


	/*
		INVENTORY BUTTON
	*/
	if (this->player_Hud_->updateInventoryPollEvent(ev))
	{
		if (this->player_Inventory_->getIsHidingInventory())
		{
			this->player_Inventory_->setIsHidingInventory(false);
			
			this->player_Inventory_->realignEquipment();

			if (this->player_Skill_Tree_->getClassesOne() != NULL)
			{
				this->player_Inventory_->initializeInventory(this->name_, this->race_->getName(), this->player_Skill_Tree_->getClassesOne()->getName(), this->level_, this->stats_, this->resistances_);
			}
			else
			{
				this->player_Inventory_->initializeInventory(this->name_, this->race_->getName(), "Peasant", this->level_, this->stats_, this->resistances_);
			}
		}
	}


	/*
		BAG BUTTON
	*/
	if (this->player_Hud_->updateBagPollEvent(ev))
	{
		if (this->player_Bag_->getIsHidingBag())
		{
			this->player_Bag_->setIsHidingBag(false);
		
			this->player_Bag_->realignItems();
		}
	}


	/*
		QUEST BUTTON
	*/
	if (this->player_Hud_->updateQuestPollEvent(ev))
	{
		if (this->player_Quest_->getIsHidingQuest())
		{
			this->player_Quest_->setIsHidingQuest(false);
		}
	}

	
	/*
		SKILL TREE BUTTON
	*/
	if (this->player_Hud_->updateSkillTreePollEvent(ev))
	{
		if (this->player_Skill_Tree_->getIsHidingSkillTree())
		{
			this->player_Skill_Tree_->setIsHidingSkillTree(false);
		}
	}


	/*
		GATHER BUTTON
	*/
	if (this->player_Hud_->updateGatherPollEvent(ev))
	{
		if (!this->player_Gather_->getIsVisible())
		{
			this->player_Gather_->setIsVisible(true);
		}
	}


	

	if (this->player_Inventory_->getIsHidingInventory() &&  
		this->player_Bag_->getIsHidingBag() && 
		this->player_Quest_->getIsHidingQuest() && 
		this->player_Skill_Tree_->getIsHidingSkillTree())
	{
		if (!this->is_Jumping_)
		{
			this->velocity_.y = 0.f;
		}

		this->velocity_.x = 0.f;


		/*
			MOVEMENT POLL UPDATES
		*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->is_Jumping_)
		{
			this->velocity_.y += -this->movement_Speed_ * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->velocity_.y += this->movement_Speed_ * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->velocity_.x += -this->movement_Speed_ * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->velocity_.x += this->movement_Speed_ * dt;
		}

		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::F5)
			{
				this->exp_ += 500;

				std::cout << "EXP: " << this->exp_ << std::endl;
			}
		}

		/*
			JUMP POLL UPDATE
		*/
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Space)
			{
				this->is_Jumping_ = true;
				this->velocity_.y += -this->jump_Speed_ * dt;
			}
		}
	}
	
}
//
//void PlayerTest::updateEnemyAutoSelector(Enemy* enemy)
//{
//	if (this->selected_Enemy_ == NULL)
//	{
//		if (this->player_Model_.getGlobalBounds().intersects(enemy->getEnemyGlobalBounds()))
//		{
//			this->selected_Enemy_ = enemy;
//
//			std::cout << "enemy has been selected." << std::endl;
//		}
//	}
//
//	if (this->selected_Enemy_ != NULL)
//	{
//		if (!this->player_Model_.getGlobalBounds().intersects(this->selected_Enemy_->getEnemyGlobalBounds()))
//		{
//			this->selected_Enemy_ = NULL;
//
//			std::cout << "enemy has been set to null due to it leaving range." << std::endl;
//		}
//	}
//
//	if (this->selected_Enemy_ != NULL)
//	{
//		//std::cout << "A" << std::endl;
//		if (this->selected_Enemy_->getIsDead() || this->selected_Enemy_->getHasLootTimerStarted())
//		{
//			//std::cout << "enemy died. Can no reselect a new enemy. " << std::endl;
//			this->selected_Enemy_ = NULL;
//		}
//	}
//}

void PlayerTest::update(const sf::Vector2i& mousePositionWindow, const Camera& camera, std::vector<Enemy*>& enemies)
{
	if (this->player_Inventory_->getIsHidingInventory() &&
		this->player_Bag_->getIsHidingBag() &&
		this->player_Quest_->getIsHidingQuest() &&
		this->player_Skill_Tree_->getIsHidingSkillTree() &&
		!this->player_Gather_->getIsVisible())
	{
		this->player_Model_.move(this->velocity_);

		this->next_Position_Bounds_ = this->player_Model_.getGlobalBounds();
		this->next_Position_Bounds_.left += this->velocity_.x;
		this->next_Position_Bounds_.top += this->velocity_.y;

		if (!this->is_Jumping_)
		{
			this->position_Before_Jump_ = this->player_Model_.getGlobalBounds().top;
		}

		if (this->is_Jumping_ && this->player_Model_.getGlobalBounds().top - this->position_Before_Jump_ <= -this->max_Jump_Height_)
		{
			//std::cout << "jumping" << std::endl;

			this->is_Jumping_ = false;
			this->velocity_.y += this->gravity_;
		}

		this->next_Position_.setPosition(this->next_Position_Bounds_.left, this->next_Position_Bounds_.top);
		this->auto_Attack_Range_.setPosition(sf::Vector2f(this->player_Model_.getGlobalBounds().left - this->auto_Attack_Range_.getSize().x / 2.f + this->player_Model_.getGlobalBounds().width / 2.f, this->player_Model_.getPosition().y));

		*this->camera_ = camera;
	}
	

	/*
		UPDATE HUD BUTTONS
	*/
	this->player_Hud_->update(mousePositionWindow, camera, this->player_Model_.getPosition(), this->player_Model_.getGlobalBounds(), enemies, this->is_Combat_, this->auto_Attack_Range_.getGlobalBounds());
	this->player_Inventory_->update(mousePositionWindow);
	this->player_Bag_->update(mousePositionWindow);
	this->player_Quest_->update(mousePositionWindow);
	this->player_Skill_Tree_->update(mousePositionWindow, this->skill_Points_);
	this->player_Gather_->update(mousePositionWindow);

	
	/*
		UPDATE SKILL ONE RANGE POSITION TO REPOSITION TO PLAYER MODEL 
	*/
	if (&this->player_Hud_->setSkillOne() != NULL)
	{
		this->player_Hud_->setSkillOne().update(this->player_Model_.getPosition(), this->player_Model_.getGlobalBounds());
	}


	/*
		SET WIDTH OF HEALTH, MANA, AND EXP BARS OF THE HUD TO CURRENT VALUES
	*/
	this->player_Hud_->setWidthOfBars(this->getStat("healthMax"), this->getStat("health"), this->getStat("manaMax"), this->getStat("mana"), this->max_Exp_, this->exp_);


	/*
		HEALTH AND MANA REGEN
	*/
	if (this->health_Regen_Timer.getElapsedTime().asSeconds() >= 1.f &&
		!this->is_Combat_)
	{
		this->getStatForChange("health")++;

		this->health_Regen_Timer.restart();
	}

	if (this->mana_Regen_Timer.getElapsedTime().asSeconds() >= 1.f &&
		!this->is_Combat_)
	{
		this->getStatForChange("mana")++;

		this->mana_Regen_Timer.restart();
	}


	/*
		IF HEALTH OR MANA IS BELOW OR ABOVE MAX VALUE RESET IT TO 0 OR MAX VALUE
	*/
	if (this->getStat("health") <= 0)
	{
		this->getStatForChange("health") = 0;
	}
	else if (this->getStat("health") >= this->getStat("healthMax"))
	{
		this->getStatForChange("health") = this->getStat("healthMax");
	}

	if (this->getStat("mana") <= 0)
	{
		this->getStatForChange("mana") = 0;
	}
	else if (this->getStat("mana") >= this->getStat("manaMax"))
	{
		this->getStatForChange("mana") = this->getStat("manaMax");
	}


	/*
		CHECK IF A LEVEL UP HAS HAPPENED
	*/
	this->levelUp();
}

void PlayerTest::renderHudItems(sf::RenderTarget& target)
{
	target.setView(target.getDefaultView());

	this->player_Hud_->render(target);

	this->player_Inventory_->render(target);
	this->player_Bag_->render(target);
	this->player_Quest_->render(target);
	this->player_Skill_Tree_->render(target);
	this->player_Gather_->render(target);

	target.setView(this->camera_->getView());
}

void PlayerTest::renderPlayerModel(sf::RenderTarget& target)
{
	target.setView(this->camera_->getView());

	target.draw(this->next_Position_);
	target.draw(this->auto_Attack_Range_);
	target.draw(this->player_Model_);


	if (&this->player_Hud_->setSkillOne() != NULL)
	{
		this->player_Hud_->setSkillOne().render(target);
	}
}

void PlayerTest::addQuest(Quest& quest)
{
	this->player_Quest_->addQuest(quest);
}

void PlayerTest::setStat(const std::string& stat, int value)
{
	auto findPos = this->stats_.find(stat);
	int statValue = 0;
	if (findPos != this->stats_.end())
	{
		statValue = findPos->second + value;
		this->stats_.find(stat)->second = statValue;
	}
}

PlayerBag& PlayerTest::setPlayerBag()
{
	return *this->player_Bag_;
}

PlayerHud& PlayerTest::setPlayerHud()
{
	return *this->player_Hud_;
}

PlayerGather& PlayerTest::setPlayerGather()
{
	return *this->player_Gather_;
}

int& PlayerTest::setExp()
{
	return this->exp_;
}

bool& PlayerTest::setIsCombat()
{
	return this->is_Combat_;
}

void PlayerTest::levelUp()
{
	/*
		IF EXP IS HIGHER THAN MAX EXP THEN THE PLAYER HAS LEVELED UP. 

		SET STAT INCREASE AND STUFF HERE
	*/
	if (this->exp_ >= this->max_Exp_)
	{
		int excessExp = this->exp_ - this->max_Exp_;

		this->level_++;

		this->max_Exp_ = std::floor(3 * ((std::pow(this->level_, 2.3))) * 1.5);
		this->exp_ = 0;
		this->exp_ += excessExp;


		this->setStat("healthMax", std::floor(2.0 * 1.2 + (std::pow(this->level_, 1.2))));
		this->getStatForChange("health") = this->getStat("healthMax");
		this->setStat("manaMax", std::floor(2.0 * 1.2 + (std::pow(this->level_, 1.2))));
		this->getStatForChange("mana") = this->getStat("manaMax");
		this->setStat("strength", std::floor((std::pow(this->level_ / 2.f, 1.2)) / 2.f));
		this->setStat("dexerity", std::floor((std::pow(this->level_ / 2.f, 1.2)) / 2.f));
		this->setStat("intelligence", std::floor((std::pow(this->level_ / 2.f, 1.2)) / 2.f));
		this->setStat("perception", std::floor((std::pow(this->level_ / 2.f, 1.2)) / 2.f));
		this->setStat("wisdom", std::floor((std::pow(this->level_ / 2.f, 1.2)) / 2.f));


		std::cout << std::endl;
		std::cout << "LEVEL: " << this->level_ << std::endl;
		std::cout << "MAX EXP: " << this->max_Exp_ << std::endl;
		std::cout << "EXP: " << this->exp_ << std::endl;
		std::cout << "HEALTH MAX: " << this->stats_.find("healthMax")->second << std::endl;
		std::cout << "HEALTH: " << this->stats_.find("health")->second << std::endl;
		std::cout << "MANA MAX: " << this->stats_.find("manaMax")->second << std::endl;
		std::cout << "MANA: " << this->stats_.find("mana")->second << std::endl;
		std::cout << "STRENGTH: " << this->stats_.find("strength")->second << std::endl;
		std::cout << "DEXERITY: " << this->stats_.at("dexerity") << std::endl;
		std::cout << "INTELLIGENCE: " << this->stats_.at("intelligence") << std::endl;
		std::cout << "PERCEPTION: " << this->stats_.at("perception") << std::endl;
		std::cout << "WISDOM: " << this->stats_.at("wisdom") << std::endl;
	}
}

void PlayerTest::setPosition(float x, float y)
{
	this->player_Model_.setPosition(sf::Vector2f(x, y));
}

void PlayerTest::setVelocityX(float x)
{
	this->velocity_.x = x;
}

void PlayerTest::setVelocityY(float y)
{
	this->velocity_.y = y;
}

void PlayerTest::setIsJumping(bool isJumping)
{
	this->is_Jumping_ = isJumping;
}

PlayerQuest& PlayerTest::setPlayerQuest()
{
	return *this->player_Quest_;
}

sf::RectangleShape& PlayerTest::getPlayerModel()
{
	return this->player_Model_;
}

const sf::Vector2f& PlayerTest::getVelocity() const
{
	return this->velocity_;
}

const float& PlayerTest::getGravity() const
{
	return this->gravity_;
}

const sf::FloatRect PlayerTest::getPlayerGlobalBounds() const
{
	return this->player_Model_.getGlobalBounds();
}

const sf::FloatRect PlayerTest::getNextPositionGlobalBounds() const
{
	return this->next_Position_Bounds_;
}

const bool& PlayerTest::getIsJumping() const
{
	return this->is_Jumping_;
}

const PlayerInventory& PlayerTest::getPlayerInventory() const
{
	return *this->player_Inventory_;
}

const PlayerBag& PlayerTest::getPlayerBag() const
{
	return *this->player_Bag_;
}

const PlayerQuest& PlayerTest::getPlayerQuest() const
{
	return *this->player_Quest_;
}

const PlayerSkillTree& PlayerTest::getPlayerSkillTree() const
{
	return *this->player_Skill_Tree_;
}

const PlayerGather& PlayerTest::getPlayerGather() const
{
	return *this->player_Gather_;
}

const int& PlayerTest::getStat(const std::string& stat) const
{
	auto findPos = this->stats_.find(stat);
	int statValue = 0;
	if (findPos != this->stats_.end())
	{
		statValue = findPos->second;

		return this->stats_.find(stat)->second;
	}
	else
	{
		return statValue;
	}
}

int& PlayerTest::getStatForChange(const std::string& stat)
{
	auto findPos = this->stats_.find(stat);
	int statValue = 0;
	if (findPos != this->stats_.end())
	{
		return this->stats_.find(stat)->second;
	}
	else
	{
		return statValue;
	}
}
