#include "StateTestZone.h"

StateTestZone::StateTestZone(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, resourceFont, resourceHud, resourceRace, menuSetting, menuPause)
{

	this->player_Test_ = new PlayerTest(*this->resource_Font_, *this->resource_Hud_, *this->resource_Race_);

	this->menu_Character_Creation_ = new MenuCharacterCreation(this->window_->getSize().x, this->window_->getSize().y, *this->resource_Font_, *this->resource_Hud_, *this->resource_Race_);

	this->camera_ = new Camera(this->window_->getSize().x, this->window_->getSize().y);

	this->tilemap_ = new Tilemap(20, 20, 50 , 2);

	this->npc_Test_ = new NpcTest(*this->resource_Font_);
	this->npc_Test_->setSettings(this->window_->getSize(), *this->resource_Font_);



	this->resource_Enemy_ = new ResourceEnemy();
	this->resource_Enemy_->loadAllEnemyTextures();

	this->max_Enemies_ = 1;
	this->enemy_Test_ = new EnemyTest(sf::Vector2f(800.f, 120.f), 3, *this->resource_Font_, *this->resource_Enemy_);
	this->enemy_Test_One_ = new EnemyTest(sf::Vector2f(400.f, 180.f), 5, *this->resource_Font_, *this->resource_Enemy_);

	this->enemies_.push_back(this->enemy_Test_);
	//this->enemies_.push_back(this->enemy_Test_One_);



	this->merchant_Test_ = new MerchantTest(*this->resource_Font_);



	this->gather_Test_ = new GatherTest(GATHERTYPE::MINING, *this->resource_Font_, *this->resource_Hud_);



	this->load_X_A_.setSettings(800.f, 400.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color(85, 158, 131), 1.f, sf::Color::Red, true);

	this->load_B_A_.setSettings(150.f, 50.f, this->load_X_A_.getLeftPosition(true, 250), this->load_X_A_.getBottomPosition(false, 55), sf::Color(27, 133, 184), 1, sf::Color::Red, true);
	this->load_B_B_.setSettings(150.f, 50.f, this->load_B_A_.getRightPosition(true, 20), this->load_B_A_.getTopPosition(), sf::Color(27, 133, 184), 1, sf::Color::Red, true);

	this->load_T_A_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 35, "Load a tilemap", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 250.f), this->load_X_A_.getTopPosition(true, 10.f)), true);
	this->load_T_B_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 25, "Filename: ", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 10.f), this->load_X_A_.getTopPosition(true, 200.f)), true);
	this->load_T_C_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 25, "Load", sf::Vector2f(this->load_B_A_.getLeftPosition(true, 10.f), this->load_B_A_.getTopPosition(true, 10.f)), true);
	this->load_T_D_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 25, "Close", sf::Vector2f(this->load_B_B_.getLeftPosition(true, 10.f), this->load_B_B_.getTopPosition(true, 10.f)), true);

	this->load_I_A_.setSettings(500.f, 40.f, this->load_T_B_.getRightPosition(true, 10.f), this->load_T_B_.getTopPosition(), sf::Color::Black, 1.f, sf::Color::Red, true, false, 30, *this->resource_Font_);

		  
}

StateTestZone::~StateTestZone()
{
	delete this->player_Test_;

	delete this->npc_Test_;

	delete this->menu_Character_Creation_;
	
	delete this->camera_;
	
	delete this->tilemap_;

	delete this->resource_Enemy_;
}

void StateTestZone::updateLoadPollEvent(sf::Event& ev)
{
	/*
		IF THE LOAD BOX IS NOT VISIBLE THEN WE CAN REOPEN IT BY PRESSING F1
	*/
	if (!this->load_X_A_.getIsVisible())
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::F1)
			{
				if (!this->load_X_A_.getIsVisible())
				{
					this->load_X_A_.setIsVisible(true);
					this->load_B_A_.setIsVisible(true);
					this->load_B_B_.setIsVisible(true);
					this->load_T_A_.setIsVisible(true);
					this->load_T_B_.setIsVisible(true);
					this->load_T_C_.setIsVisible(true);
					this->load_T_D_.setIsVisible(true);
					this->load_I_A_.setIsVisible(true);
				}
			}
		}
	}
	else
	{
		/*
			IF IT IS VISIBLE THEN UPDATE THE POLL EVENTS
		*/
		this->load_I_A_.updatePollEvent(ev);

		/*
			LOAD BUTTON
		*/
		if (this->load_B_A_.updatePollEvent(ev))
		{
			this->tilemap_->load(this->load_I_A_.getString());

			this->player_Test_->setPosition(200.f, 200.f);

			this->load_X_A_.setIsVisible(false);
			this->load_B_A_.setIsVisible(false);
			this->load_B_B_.setIsVisible(false);
			this->load_T_A_.setIsVisible(false);
			this->load_T_B_.setIsVisible(false);
			this->load_T_C_.setIsVisible(false);
			this->load_T_D_.setIsVisible(false);
			this->load_I_A_.setIsVisible(false);

			this->load_I_A_.clearString();
		}

		/*
			CLOSE BUTTON
		*/
		if (this->load_B_B_.updatePollEvent(ev))
		{
			this->load_X_A_.setIsVisible(false);
			this->load_B_A_.setIsVisible(false);
			this->load_B_B_.setIsVisible(false);
			this->load_T_A_.setIsVisible(false);
			this->load_T_B_.setIsVisible(false);
			this->load_T_C_.setIsVisible(false);
			this->load_T_D_.setIsVisible(false);
			this->load_I_A_.setIsVisible(false);
		}
	}
}

void StateTestZone::updateCharacterCreationPollEvent(sf::Event& ev)
{
	/*
		IF THE CHARACTER CREATION HAS BEEN CLOSED PRESS F3 TO REOPEN IT
	*/
	if (!this->menu_Character_Creation_->getIsCreatingCharacter())
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::F3)
			{
				this->menu_Character_Creation_->setIsCreatingCharacter(true);
			}
		}
	}
	else
	{
		/*
			IF IT IS ALREADY OPEN THEN ALLOW US TO INTERACT WITH IT
		*/

		/*
			IF THE POLL EVENT COMES BACK TRUE THEN UPDATE OUR PLAYER
		*/
		if (this->menu_Character_Creation_->updatePollEvent(ev))
		{
			this->player_Test_->initializeCharacter(&this->menu_Character_Creation_->getRace(), this->menu_Character_Creation_->getName());
		}
	}
}

void StateTestZone::updatePollEvent(sf::Event& ev)
{
	/*
		IF WE CLICK EXIT IN THE PAUSE MENU THEN EXIT BACK TO MAIN MENU
	*/
	if (this->menu_Pause_->updatePollEvent(ev))
	{
		this->states_->pop();
	}

	if (!this->menu_Pause_->getIsPaused())
	{
		this->updateLoadPollEvent(ev);
		this->updateCharacterCreationPollEvent(ev);

		/*
			AS LONG AS THE LOAD TILEMAP BOX AND CHARACTER CREATION ARE NOT HAPPENING
			POLL UPDATE OTHER THINGS
		*/
		if (!this->load_X_A_.getIsVisible() && !this->menu_Character_Creation_->getIsCreatingCharacter())
		{
			this->window_->setKeyRepeatEnabled(true);

			if (this->player_Test_->getPlayerInventory().getIsHidingInventory() &&
				this->player_Test_->getPlayerBag().getIsHidingBag() &&
				this->player_Test_->getPlayerQuest().getIsHidingQuest() &&
				this->player_Test_->getPlayerSkillTree().getIsHidingSkillTree() &&
				!this->merchant_Test_->getIsShopBoxVisible())
			{
				this->camera_->updatePollEvent(ev);
			}


			for (auto& e : this->enemies_)
			{
				e->updatePollEvent(ev, this->player_Test_->setPlayerBag().setItem(), this->player_Test_->getPlayerBag().getBagSizeX(), this->player_Test_->getPlayerBag().getBagSizeY(), this->player_Test_->getPlayerModel().getGlobalBounds());
			}

			this->player_Test_->updateSkillsPollEvent(ev, this->enemies_);

			this->player_Test_->updatePollEvent(ev, this->dt_);

			this->npc_Test_->updatePollEvent(ev, *this->player_Test_);

			//TESTING
			this->merchant_Test_->updatePollEvent(ev, this->player_Test_->setPlayerBag().setGold(), this->player_Test_->setPlayerBag().setSilver(), this->player_Test_->setPlayerBag().setCopper(), this->player_Test_->setPlayerBag().setItem(), this->player_Test_->getPlayerBag().getBagSizeX(), this->player_Test_->getPlayerBag().getBagSizeY());


			//TESTING - SHOULD PUT INTO A VECTOR LATER
			if (this->gather_Test_ != NULL)
			{
				this->gather_Test_->updatePollEvent(ev);
			}

			this->window_->setKeyRepeatEnabled(true);
		}
	}
}

void StateTestZone::updateEnemy()
{
	//ENEMY HANDLING
	for (int i = 0; i < this->enemies_.size(); ++i)
	{
		this->tilemap_->EnemyCollision(*this->enemies_[i]);

		this->enemies_[i]->update(this->mouse_Position_Window_, &this->camera_, this->player_Test_->getPlayerGlobalBounds(), this->dt_, this->player_Test_->getStatForChange("health"), this->player_Test_->setExp(), this->player_Test_->setIsCombat(), this->player_Test_->setPlayerHud().setLeaveCombatTimer());

		//this->player_Test_->updateEnemyAutoSelector(this->enemies_[i]);

		if (this->enemies_[i]->getIsDead())
		{
			delete this->enemies_[i];
			this->enemies_.erase(this->enemies_.begin() + i);
		}
	}

	if (this->enemies_.size() < this->max_Enemies_)
	{
		this->enemies_.push_back(new EnemyTest(sf::Vector2f(600.f, 120.f), 8, *this->resource_Font_, *this->resource_Enemy_));
	}
}

void StateTestZone::updateCharacterCreation()
{
	if (this->menu_Character_Creation_->getIsCreatingCharacter())
	{
		this->menu_Character_Creation_->update(this->mouse_Position_Window_);
	}
}

void StateTestZone::updateLoadTilemap()
{
	if (this->load_X_A_.getIsVisible() && !this->menu_Character_Creation_->getIsCreatingCharacter())
	{
		this->load_B_A_.updateBoundaries(this->mouse_Position_Window_);
		this->load_B_B_.updateBoundaries(this->mouse_Position_Window_);
		this->load_I_A_.update(this->mouse_Position_Window_);
	}
}

void StateTestZone::update()
{
	this->updateMousePosition(&this->camera_->getView(), this->tilemap_->getTileSizeXY());
	this->updateDeltaClock();

	this->menu_Pause_->update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		if (this->player_Test_->getPlayerInventory().getIsHidingInventory() &&
			this->player_Test_->getPlayerBag().getIsHidingBag() && 
			this->player_Test_->getPlayerQuest().getIsHidingQuest() && 
			this->player_Test_->getPlayerSkillTree().getIsHidingSkillTree())
		{
			this->camera_->setCenter(sf::Vector2f(this->player_Test_->getPlayerModel().getPosition().x, this->player_Test_->getPlayerModel().getPosition().y));
		}

		this->tilemap_->update(*this->camera_);

		this->updateEnemy();


		this->tilemap_->PlayerCollision(*this->player_Test_);

		this->player_Test_->update(this->mouse_Position_Window_, *this->camera_, this->enemies_);

		this->npc_Test_->update(this->mouse_Position_View_, this->mouse_Position_Window_, this->player_Test_->getPlayerGlobalBounds(), *this->camera_, *this->player_Test_);

		this->merchant_Test_->update(this->mouse_Position_View_, this->mouse_Position_Window_, this->player_Test_->getPlayerGlobalBounds(), *this->camera_, this->player_Test_->getPlayerInventory().getEquipment(), this->player_Test_->setPlayerBag().setItem());



		//TESTING - SHOULD PUT INTO A VECTOR LATER
		if (this->gather_Test_ != NULL)
		{
			this->gather_Test_->update(this->mouse_Position_Window_, this->player_Test_->getPlayerGlobalBounds(), this->player_Test_->setPlayerGather().setGatheredItems());

			if (this->gather_Test_->getIsGathered())
			{
				delete this->gather_Test_;
				this->gather_Test_ = NULL;
			}
		}

		this->updateCharacterCreation();
	
		this->updateLoadTilemap();
	}
}

void StateTestZone::render(sf::RenderTarget& target)
{
	target.setView(this->camera_->getView());

	this->tilemap_->render(target);
	
	this->player_Test_->renderPlayerModel(target);

	this->npc_Test_->render(target);

	this->merchant_Test_->render(target);

	//TESTING - SHOULD PUT INTO A VECTOR LATER
	if (this->gather_Test_ != NULL)
	{
		this->gather_Test_->render(target);
	}

	target.setView(this->camera_->getView());

	for (auto& e : this->enemies_)
	{
		e->render(target);

	}

	this->player_Test_->renderHudItems(target);


	target.setView(target.getDefaultView());



	if (this->menu_Character_Creation_->getIsCreatingCharacter())
	{
		this->menu_Character_Creation_->render(target);
	}

	if (this->load_X_A_.getIsVisible() && !this->menu_Character_Creation_->getIsCreatingCharacter())
	{
		this->load_X_A_.render(target);
		this->load_B_A_.render(target);
		this->load_B_B_.render(target);
		this->load_T_A_.render(target);
		this->load_T_B_.render(target);
		this->load_T_C_.render(target);
		this->load_T_D_.render(target);
		this->load_I_A_.render(target);
	}


	this->menu_Pause_->render(target);
}
