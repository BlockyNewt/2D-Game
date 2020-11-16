#include "StateTestZone.h"

StateTestZone::StateTestZone(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	this->menu_Character_Creation_ = new MenuCharacterCreation(this->window_->getSize().x, this->window_->getSize().y);

	this->camera_ = new Camera(this->window_->getSize().x, this->window_->getSize().y);

	this->tilemap_ = new Tilemap(20, 20, 30 , 2);

	this->npc_Test_.setSettings(this->window_->getSize());


	this->load_X_A_.setSettings(800.f, 400.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	this->load_B_A_.setSettings(150.f, 50.f, this->load_X_A_.getLeftPosition(true, 250), this->load_X_A_.getBottomPosition(false, 55), sf::Color::Blue, 1, sf::Color::Red, true);
	this->load_B_B_.setSettings(150.f, 50.f, this->load_B_A_.getRightPosition(true, 20), this->load_B_A_.getTopPosition(), sf::Color::Blue, 1, sf::Color::Red, true);

	this->load_T_A_.setSettings("Font/arial.ttf", 35, "Load a tilemap", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 250.f), this->load_X_A_.getTopPosition(true, 10.f)), true);
	this->load_T_B_.setSettings("Font/arial.ttf", 25, "Filename: ", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 10.f), this->load_X_A_.getTopPosition(true, 200.f)), true);
	this->load_T_C_.setSettings("Font/arial.ttf", 25, "Load", sf::Vector2f(this->load_B_A_.getLeftPosition(true, 10.f), this->load_B_A_.getTopPosition(true, 10.f)), true);
	this->load_T_D_.setSettings("Font/arial.ttf", 25, "Close", sf::Vector2f(this->load_B_B_.getLeftPosition(true, 10.f), this->load_B_B_.getTopPosition(true, 10.f)), true);

	this->load_I_A_.setSettings(500.f, 40.f, this->load_T_B_.getRightPosition(true, 10.f), this->load_T_B_.getTopPosition(), sf::Color::Black, 1.f, sf::Color::Red, true, false, 30);


	this->character_Creation_X_A_.setSettings(800.f, 400.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	this->character_Creation_B_B_.setSettings(150.f, 50.f, this->character_Creation_X_A_.getLeftPosition(true, 250), this->character_Creation_X_A_.getBottomPosition(false, 55), sf::Color::Blue, 1, sf::Color::Red, true);
	this->character_Creation_B_C_.setSettings(150.f, 50.f, this->character_Creation_B_B_.getRightPosition(true, 20), this->character_Creation_B_B_.getTopPosition(), sf::Color::Blue, 1, sf::Color::Red, true);
		  
	this->character_Creation_T_A_.setSettings("Font/arial.ttf", 35, "Would you like to create a character? \n\nThis is just another test feature. Not needed to do \nfurther testing.", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 10.f), this->character_Creation_X_A_.getTopPosition(true, 10.f)), true);
	this->character_Creation_T_B_.setSettings("Font/arial.ttf", 25, "Yes", sf::Vector2f(this->character_Creation_B_B_.getLeftPosition(true, 10.f), this->character_Creation_B_B_.getTopPosition(true, 10.f)), true);
	this->character_Creation_T_C_.setSettings("Font/arial.ttf", 25, "No", sf::Vector2f(this->character_Creation_B_C_.getLeftPosition(true, 10.f), this->character_Creation_B_C_.getTopPosition(true, 10.f)), true);
}

StateTestZone::~StateTestZone()
{
	delete this->menu_Character_Creation_;
	
	delete this->camera_;
	
	delete this->tilemap_;
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

			this->player_Test_.setPosition(60.f, 60.f);

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
		if (!this->character_Creation_X_A_.getIsVisible())
		{
			if (this->menu_Character_Creation_->updatePollEvent(ev))
			{
				this->player_Test_.initializeCharacter(&this->menu_Character_Creation_->getRace(), this->menu_Character_Creation_->getName());
			}
		}
		

		
		if (this->character_Creation_X_A_.getIsVisible())
		{
			/*
				IF WE DO NEED TO CREATE A CHARACTER, CLOSE THE TESTING BOX FOR CHARACTER CREATION
			*/
			if (this->character_Creation_B_B_.updatePollEvent(ev))
			{
				this->menu_Character_Creation_->setIsCreatingCharacter(true);

				this->character_Creation_X_A_.setIsVisible(false);
				this->character_Creation_B_B_.setIsVisible(false);
				this->character_Creation_B_C_.setIsVisible(false);
				this->character_Creation_T_A_.setIsVisible(false);
				this->character_Creation_T_B_.setIsVisible(false);
				this->character_Creation_T_C_.setIsVisible(false);
			}

			/*
				IF WE DO NOT NEED TO CREATE A CHARACTER IN TESTING THEN CLOSE THE CHARACTER
				CREATION BOX
			*/
			if (this->character_Creation_B_C_.updatePollEvent(ev))
			{
				this->menu_Character_Creation_->setIsCreatingCharacter(false);
			}
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

			if (this->player_Test_.getPlayerInventory().getIsHidingInventory() &&
				this->player_Test_.getPlayerBag().getIsHidingBag() &&
				this->player_Test_.getPlayerQuest().getIsHidingQuest() &&
				this->player_Test_.getPlayerSkillTree().getIsHidingSkillTree())
			{
				this->camera_->updatePollEvent(ev);
			}

			this->player_Test_.updatePollEvent(ev, this->dt_);

			this->npc_Test_.updatePollEvent(ev, this->player_Test_);

			this->window_->setKeyRepeatEnabled(true);
		}
	}
}

void StateTestZone::update()
{
	this->updateMousePosition(&this->camera_->getView(), this->tilemap_->getTileSizeXY());
	this->updateDeltaClock();

	this->menu_Pause_->update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		if (this->player_Test_.getPlayerInventory().getIsHidingInventory() &&
			this->player_Test_.getPlayerBag().getIsHidingBag() && 
			this->player_Test_.getPlayerQuest().getIsHidingQuest() && 
			this->player_Test_.getPlayerSkillTree().getIsHidingSkillTree())
		{
			this->camera_->setCenter(sf::Vector2f(this->player_Test_.getPlayerModel().getPosition().x, this->player_Test_.getPlayerModel().getPosition().y));
		}

		this->tilemap_->update(*this->camera_);

		this->tilemap_->mapCollision(this->player_Test_, this->enemy_Test_);

		this->enemy_Test_.update(this->dt_);

		this->player_Test_.update(this->mouse_Position_Window_, *this->camera_);

		this->npc_Test_.update(this->mouse_Position_View_, this->mouse_Position_Window_, this->player_Test_.getPlayerGlobalBounds(), *this->camera_, this->player_Test_);


		if (this->menu_Character_Creation_->getIsCreatingCharacter())
		{
			this->menu_Character_Creation_->update(this->mouse_Position_Window_);

			this->character_Creation_B_B_.updateBoundaries(this->mouse_Position_Window_);
			this->character_Creation_B_C_.updateBoundaries(this->mouse_Position_Window_);
		}

		if (this->load_X_A_.getIsVisible() && !this->menu_Character_Creation_->getIsCreatingCharacter())
		{
			this->load_B_A_.updateBoundaries(this->mouse_Position_Window_);
			this->load_B_B_.updateBoundaries(this->mouse_Position_Window_);
			this->load_I_A_.update(this->mouse_Position_Window_);
		}
	}
}

void StateTestZone::render(sf::RenderTarget& target)
{
	target.setView(this->camera_->getView());

	this->tilemap_->render(target);
	
	this->player_Test_.renderPlayerModel(target);

	this->npc_Test_.render(target);

	this->enemy_Test_.render(target);

	this->player_Test_.renderHudItems(target);


	target.setView(target.getDefaultView());



	if (this->menu_Character_Creation_->getIsCreatingCharacter())
	{
		this->menu_Character_Creation_->render(target);

		this->character_Creation_X_A_.render(target);
		this->character_Creation_B_B_.render(target);
		this->character_Creation_B_C_.render(target);
		this->character_Creation_T_A_.render(target);
		this->character_Creation_T_B_.render(target);
		this->character_Creation_T_C_.render(target);
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
