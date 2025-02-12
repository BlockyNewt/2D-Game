#include "EnemyTest.h"

void EnemyTest::initializeStats()
{
	/*
		SET ALL STATS FOR THE ENEMY
	*/
	this->name_ = "Test Enemy";

	this->velocity_.x = 0.f;
	this->velocity_.y = 0.f;
	this->movement_Speed_ = 100.f;
	this->gravity_ = 6.f;

	this->health_Max_ = 15;
	this->health_ = this->health_Max_;
	this->mana_Max_ = 3;
	this->mana_ = this->mana_Max_;
	this->strength_ = 0;
	this->dexerity_ = 0;
	this->constitution_ = 0;
	this->intelligence_ = 0;
	this->perception_ = 0;
	this->wisdom_ = 0;

	this->cold_ = 0;
	this->fire_ = 0;
	this->lightning_ = 0;
	this->poison_ = 0;

	this->level_ = 1;
	this->exp_ = std::floor(2.4 * (std::pow(this->level_, 1.4)) * 1.2);
	this->exp_Tick_ = 0;
}

void EnemyTest::initializeModel(const sf::Vector2f& position, const int& range, ResourceEnemy* resourceEnemy)
{
	/*
		SET SIZE AND POSITION OF MODEL, NEXT POSITION, AND ATTACK RANGE 
	*/
	this->enemy_Model_.setSize(sf::Vector2f(43.f, 37.f));
	this->enemy_Model_.setPosition(position);
	this->enemy_Model_.setFillColor(sf::Color::White);
	this->enemy_Model_.setOutlineThickness(1.f);
	this->enemy_Model_.setOutlineColor(sf::Color::Transparent);
	this->enemy_Model_.setTexture(resourceEnemy->getEnemyTexture(ENEMY_TEXTURE_TYPE_::SKELETON_WALK_TEXTURE));
	this->enemy_Model_.setTextureRect(sf::IntRect(0, 0, 43, 37));

	this->next_Position_.setSize(sf::Vector2f(this->enemy_Model_.getSize().x, this->enemy_Model_.getSize().y));
	this->next_Position_.setPosition(sf::Vector2f(this->enemy_Model_.getPosition().x, this->enemy_Model_.getPosition().y));
	this->next_Position_.setFillColor(sf::Color::Transparent);
	this->next_Position_.setOutlineThickness(1.f);
	this->next_Position_.setOutlineColor(sf::Color::White);


	this->range_ = range;

	this->attack_Range_.setSize(sf::Vector2f(this->enemy_Model_.getSize().x * this->range_, this->enemy_Model_.getSize().y));
	this->attack_Range_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->attack_Range_.getSize().x / 2.f - this->enemy_Model_.getSize().x, this->enemy_Model_.getGlobalBounds().top));
	this->attack_Range_.setFillColor(sf::Color::Transparent);
	this->attack_Range_.setOutlineThickness(1.f);
	this->attack_Range_.setOutlineColor(sf::Color::Yellow);
}

void EnemyTest::initializeHealthBar()
{
	/*
		SET SIZE AND POSITION OF ENEMY HEALTH BAR
	*/
	this->health_Bar_Back_.setSize(sf::Vector2f(100.f, 10.f));
	this->health_Bar_Back_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->health_Bar_Back_.getSize().x / 2.f + 10.f, this->enemy_Model_.getGlobalBounds().top - this->health_Bar_Back_.getGlobalBounds().height - 5.f));
	this->health_Bar_Back_.setFillColor(sf::Color::White);
	this->health_Bar_Back_.setOutlineThickness(1.f);
	this->health_Bar_Back_.setOutlineColor(sf::Color::White);

	this->health_Bar_Front_.setPosition(sf::Vector2f(this->health_Bar_Back_.getPosition().x + 2.f, this->health_Bar_Back_.getPosition().y + 2.f));
	this->health_Bar_Front_.setSize(sf::Vector2f(this->health_Bar_Back_.getSize().x, this->health_Bar_Back_.getSize().y - 4.f));
	this->health_Bar_Front_.setFillColor(sf::Color::Green);
	this->health_Bar_Front_.setOutlineThickness(1.f);
	this->health_Bar_Front_.setOutlineColor(sf::Color::Green);
}

EnemyTest::EnemyTest()
{
	for (int x = 0; x < this->items_.size(); ++x)
	{
		delete this->items_[x];
		this->items_.erase(this->items_.begin() + x);
	}

	std::cout << "DEBUG::ENEMYTEST::~ENEMYTEST() -> Deconstructed" << std::endl;
}

EnemyTest::EnemyTest(const sf::Vector2f& position, const int& range, const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceEnemy* resourceEnemy, ResourceItem* resourceItem)
{
	this->initializeStats();
	this->initializeModel(position, range, resourceEnemy);
	this->initializeHealthBar();

	this->t_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, this->name_, sf::Vector2f(this->enemy_Model_.getPosition().x, this->enemy_Model_.getPosition().y), true);

	this->direction_ = DIRECTION::RIGHT;

	this->is_Bottom_Colliding_ = false;

	this->is_attack_Cooldown_ = false;
	this->is_Dead_ = false;
	
	this->loot_Timer_Max_ = 5.f;
	this->has_Loot_Timer_Started_ = false;

	this->camera_ = NULL;

	this->item_One_ = new ItemTest(0.f, 0.f, ITEMTYPE::HELM, "Helm", "Helm", resourceFont, resourceItem);
	this->item_Two_ = new ItemTest(0.f, 0.f, ITEMTYPE::WEAPON, "Sword", "Sword", resourceFont, resourceItem);
	this->items_.push_back(this->item_One_);
	this->items_.push_back(this->item_Two_);

	this->loot_Window_ = new LootWindow(window, resourceFont, resourceItem);
	this->loot_Window_->addEnemyItems(this->items_);

	this->loot_X_A_.setSettings(50.f, 50.f, 0.f, 0.f, sf::Color::Red, 1.f, sf::Color::White, true);
	this->loot_T_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "E", sf::Vector2f(0.f, 0.f), true);

	this->walk_Texture_ = new sf::Texture();
	*this->walk_Texture_ = *resourceEnemy->getEnemyTexture(ENEMY_TEXTURE_TYPE_::SKELETON_WALK_TEXTURE);

	this->attack_Texture_ = new sf::Texture();
	*this->attack_Texture_ = *resourceEnemy->getEnemyTexture(ENEMY_TEXTURE_TYPE_::SKELETON_ATTACK_TEXTURE);

	this->death_Texture_ = new sf::Texture();
	*this->death_Texture_ = *resourceEnemy->getEnemyTexture(ENEMY_TEXTURE_TYPE_::SKELETON_DEATH_TEXTURE);

	this->walk_Rect_ = sf::IntRect(0, 0, 43, 37);
	this->attack_Rect_ = sf::IntRect(0, 0, 43, 37);
	this->death_Rect_ = sf::IntRect(0, 0, 43, 37);

	this->walk_Sheet_Width_ = 559;
	this->attack_Sheet_Width_ = 774;
	this->death_Sheet_Width_ = 645;

	this->is_Walk_Texture_Set_ = true;
	this->is_Attack_Texture_Set_ = false;
	this->is_Death_Texture_Set_ = false;

	this->resource_Enemy_ = resourceEnemy;
}

EnemyTest::~EnemyTest()
{
	delete this->loot_Window_;

	delete this->walk_Texture_;
	delete this->attack_Texture_;
	delete this->death_Texture_;

	std::cout << "DEBUG::ENEMYTEST::~ENEMYTEST() -> Deconstructed" << std::endl;
}

void EnemyTest::updatePollEvent(sf::Event& ev, std::vector<std::vector<Item*>>& playerBag, const int& maxBagSizeX, const int& maxBagSizeY, const sf::FloatRect playerBoundaries)
{
	if (this->has_Loot_Timer_Started_)
	{
		if (playerBoundaries.intersects(this->enemy_Model_.getGlobalBounds()))
		{
			//LOOT SHIT GOES HERE
			if (ev.type == sf::Event::KeyPressed)
			{
				if (ev.key.code == sf::Keyboard::E)
				{
					this->loot_Window_->setIsVisible(true);
				}
			}

			this->loot_Window_->updatePollEvent(ev, playerBag, maxBagSizeX, maxBagSizeY);
		}
		else
		{
			this->loot_Window_->setIsVisible(false);
		}
	}
}

void EnemyTest::updateAutoMovement(const float& dt)
{
	/*
		AUTO MOVEMENT FOR ENEMY
	*/
	this->velocity_.x = 0.f;

	/*
		IF THE ENEMY IS TOUCHING THE TOP OF A TILE THEN ALLOW IT TO MOVE LEFT AND RIGHT
	*/
	if (this->is_Bottom_Colliding_)
	{
		this->velocity_.y = 0.f;

		if (!this->is_Walk_Texture_Set_)
		{
			this->enemy_Model_.setTexture(this->walk_Texture_);
			this->enemy_Model_.setTextureRect(this->walk_Rect_);

			this->is_Attack_Texture_Set_ = false;
			this->is_Walk_Texture_Set_ = true;
		}


		if (this->direction_ == DIRECTION::RIGHT)
		{
			this->enemy_Model_.setScale(sf::Vector2f(1.f, 1.f));
			this->enemy_Model_.setOrigin(sf::Vector2f(0.f, 0.f));

			this->velocity_.x += this->movement_Speed_ * dt;
		}
		
		else if (this->direction_ == DIRECTION::LEFT)
		{
			this->enemy_Model_.setScale(sf::Vector2f(-1.f, 1.f));
			this->enemy_Model_.setOrigin(sf::Vector2f(this->enemy_Model_.getGlobalBounds().width, 0.f));

			this->velocity_.x -= this->movement_Speed_ * dt;
		}

		this->animation_.update(this->enemy_Model_, this->walk_Rect_, this->walk_Sheet_Width_, 76.92f);
	}

	this->enemy_Model_.move(this->velocity_);

	this->next_Position_Bounds_ = this->enemy_Model_.getGlobalBounds();
	this->next_Position_Bounds_.left += this->velocity_.x;
	this->next_Position_Bounds_.top += this->velocity_.y;

	this->next_Position_.setPosition(sf::Vector2f(this->next_Position_Bounds_.left, this->next_Position_Bounds_.top));
}

void EnemyTest::updateHealth()
{
	/*
		IF HEALTH GOES BELOW 0 THEN SET IT TO 0
	*/
	if (this->health_ <= 0 && !this->has_Loot_Timer_Started_)
	{
		this->health_ = 0;

		this->has_Loot_Timer_Started_ = true;
		this->loot_Timer_.restart();
	}

	/*
		IF ALL THE LOOT HAS BEEN TAKEN MAKE THE ENEMY DEAD AND LET ANOTHER RESPAWN
	*/
	if (this->loot_Window_->getSize() == 0)
	{
		this->is_Dead_ = true;
	}

	if (!this->loot_Window_->getIsVisible())
	{
		if (this->has_Loot_Timer_Started_ &&
			this->loot_Timer_.getElapsedTime().asSeconds() >= this->loot_Timer_Max_)
		{
			//std::cout << "enemy is now dead" << std::endl;
			this->is_Dead_ = true;
		}
	}
	else
	{
		this->loot_Timer_.restart();
	}
	

	
	/*
		MUST USE THIS FOR THE HEALTH BAR VALUES TO WORK
	*/
	float healthMaxToFloat = static_cast<float>(this->health_Max_);
	float healthToFloat = static_cast<float>(this->health_);

	this->health_Bar_Front_.setSize(sf::Vector2f((healthToFloat / healthMaxToFloat) * 95.f, this->health_Bar_Back_.getSize().y - 4.f));

	this->health_Bar_Back_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->health_Bar_Back_.getSize().x / 2.f + 10.f, this->enemy_Model_.getGlobalBounds().top - this->health_Bar_Back_.getGlobalBounds().height - 5.f));
	this->health_Bar_Front_.setPosition(sf::Vector2f(this->health_Bar_Back_.getPosition().x + 2.f, this->health_Bar_Back_.getPosition().y + 2.f));
	
}

void EnemyTest::update(const sf::Vector2i& mousePositionWindow, Camera** camera, const sf::FloatRect playerBounds, const float& dt, int& playerHealth, int& playerExp, bool& playerIsCombat, sf::Clock& playerLeaveCombatTimer)
{
	if (!this->has_Loot_Timer_Started_)
	{
		if (this->is_Falling_)
		{
			this->updateAutoMovement(dt);

		}
		else if (!this->attack_Range_.getGlobalBounds().intersects(playerBounds))
		{
			this->updateAutoMovement(dt);

			if (this->resource_Enemy_->getEnemySound(ENEMY_SOUND_TYPE_::ENEMY_ATTACK)->getStatus() == sf::Sound::Playing)
			{
				this->resource_Enemy_->getEnemySound(ENEMY_SOUND_TYPE_::ENEMY_ATTACK)->stop();
			}
		}
		else if(this->attack_Range_.getGlobalBounds().intersects(playerBounds))
		{
			if (!this->is_Attack_Texture_Set_)
			{
				this->enemy_Model_.setTexture(this->attack_Texture_);
				this->enemy_Model_.setTextureRect(this->attack_Rect_);

				this->is_Walk_Texture_Set_ = false;
				this->is_Attack_Texture_Set_ = true;
			}

			if (this->resource_Enemy_->getEnemySound(ENEMY_SOUND_TYPE_::ENEMY_ATTACK)->getStatus() != sf::Sound::Playing)
			{
				this->resource_Enemy_->getEnemySound(ENEMY_SOUND_TYPE_::ENEMY_ATTACK)->play();
			}

			this->animation_.update(this->enemy_Model_, this->attack_Rect_, this->attack_Sheet_Width_, 55.55f);
			/*
				IF THE LOOT TIMER HAS YET TO BE STARTED THEN SET THE PLAYER IN COMBAT AND RESTART
				THE LEAVE COMBAT TIMER
			*/
			if (!this->has_Loot_Timer_Started_)
			{
				playerIsCombat = true;

				playerLeaveCombatTimer.restart();
			}
			
			/*
				IF ATTACK COOLDOWN IS FALSE THEN INFLICT DAMAGE TO PLAYER
			*/
			if (!this->is_attack_Cooldown_)
			{
				playerHealth -= 1;

				this->is_attack_Cooldown_ = true;
			}
		}
	}
	else
	{
		if (this->resource_Enemy_->getEnemySound(ENEMY_SOUND_TYPE_::ENEMY_ATTACK)->getStatus() == sf::Sound::Playing)
		{
			this->resource_Enemy_->getEnemySound(ENEMY_SOUND_TYPE_::ENEMY_ATTACK)->stop();
		}

		if (!this->is_Death_Texture_Set_)
		{
			this->enemy_Model_.setTexture(this->death_Texture_);
			this->enemy_Model_.setTextureRect(this->death_Rect_);

			this->is_Walk_Texture_Set_ = true;
			this->is_Attack_Texture_Set_ = true;
			this->is_Death_Texture_Set_ = true;
		}
		else
		{
			this->animation_.updateDeath(this->enemy_Model_, this->death_Rect_, this->death_Sheet_Width_, 66.66f);
		}
	}

	
	
	/*
		AFTER 4 SECONDS ATTACK COMES OFF OF COOLDOWN
	*/
	if (this->attack_Cooldown_Clock_.getElapsedTime().asSeconds() >= 4.f)
	{
		this->is_attack_Cooldown_ = false;

		this->attack_Cooldown_Clock_.restart();
	}


	/*
		SET ATTACK RANGE FOR ENEMY
	*/
	this->attack_Range_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->attack_Range_.getSize().x / 2.f + this->enemy_Model_.getSize().x / 2.f, this->enemy_Model_.getGlobalBounds().top));


	this->updateHealth();

	/*
		SET POSITION OF ENEMIES NAME
	*/
	this->t_A_.setPosition(this->health_Bar_Back_.getGlobalBounds().left, this->enemy_Model_.getGlobalBounds().top - 45.f);

	

	/*
		IF LOOT TIMER HAS BEGUN (MEANING ENEMY HAS 0 LIFE)
	*/
	if (this->has_Loot_Timer_Started_)
	{
		this->camera_ = *camera;

		this->loot_Window_->update(mousePositionWindow);

		/*
			IF PLAYER IS WITHIN BOUNDS OF ENEMY THEN SHOW THE LOOT BUTTON 
		*/
		if (playerBounds.intersects(this->enemy_Model_.getGlobalBounds()))
		{
			this->loot_X_A_.setIsVisible(true);
			this->loot_X_A_.setPosition(this->enemy_Model_.getGlobalBounds().left - 10.f, this->enemy_Model_.getGlobalBounds().top - this->loot_X_A_.getSize().x - 50.f);
			this->loot_T_A_.setPosition(this->loot_X_A_.getLeftPosition(true, 10.f), this->loot_X_A_.getTopPosition(true, 10.f));
		}
		else
		{
			this->loot_X_A_.setIsVisible(false);
		}
		
		/*
			INCREASE PLAYER EXP ONE TIME
		*/
		if (this->exp_Tick_ == 0)
		{
			playerExp += this->exp_;
			std::cout << "DEBUG::ENEMYTEST::UPDATE() -> Exp: " << this->exp_ << std::endl;
			this->exp_Tick_++;
		}
	}
}

void EnemyTest::render(sf::RenderTarget& target)
{
	target.draw(this->next_Position_);

	target.draw(this->attack_Range_);

	target.draw(this->health_Bar_Back_);
	target.draw(this->health_Bar_Front_);

	target.draw(this->enemy_Model_);

	this->t_A_.render(target);

	if (this->has_Loot_Timer_Started_)
	{
		if (this->loot_X_A_.getIsVisible())
		{
			this->loot_X_A_.render(target);
			this->loot_T_A_.render(target);
		}

		target.setView(target.getDefaultView());

		this->loot_Window_->render(target);
		
		target.setView(this->camera_->getView());
	}
}

void EnemyTest::setVelocityX(float x)
{
	this->velocity_.x = x;
}

void EnemyTest::setVelocityY(float y)
{
	this->velocity_.y = y;
}

void EnemyTest::setDirection(DIRECTION direction)
{
	this->direction_ = direction;
}

void EnemyTest::setIsBottomColliding(bool isBottomColliding)
{
	this->is_Bottom_Colliding_ = isBottomColliding;
}

void EnemyTest::setHealth(const int& damage)
{
	if (this->health_ > 0)
	{
		this->health_ -= damage;
	}
}

void EnemyTest::setIsFalling(bool isFalling)
{
	this->is_Falling_ = isFalling;
}

sf::RectangleShape& EnemyTest::getEnemyModel()
{
	return this->enemy_Model_;
}

const sf::FloatRect EnemyTest::getEnemyGlobalBounds() const
{
	return this->enemy_Model_.getGlobalBounds();
}

const sf::FloatRect EnemyTest::getNextPositionGlobalBounds()
{
	return this->next_Position_Bounds_;
}

const sf::Vector2f& EnemyTest::getVelocity() const
{
	return this->velocity_;
}

const float& EnemyTest::getGravity() const
{
	return this->gravity_;
}

const DIRECTION& EnemyTest::getDirection()
{
	return this->direction_;
}

const bool& EnemyTest::getIsBottomColliding() const
{
	return this->is_Bottom_Colliding_;
}

const bool& EnemyTest::getHasLootTimerStarted() const
{
	return this->has_Loot_Timer_Started_;
}

const bool& EnemyTest::getIsDead() const
{
	return this->is_Dead_;
}

const int& EnemyTest::getHealth() const
{
	return this->health_;
}

const bool& EnemyTest::getIsFalling() const
{
	return this->is_Falling_;
}
