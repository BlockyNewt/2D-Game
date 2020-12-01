#include "StateMainMenu.h"

StateMainMenu::StateMainMenu(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, resourceFont, resourceHud, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEMAINMENU::STATEMAINMENU() -> HAS STARTED." << std::endl;

	/*
		SET SETTINGS FOR BUTTONS AND TEXT IN CONSTRUCTOR SINCE THERE ARE NOT MANY
	*/

	this->t_A_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 50, "Dunilidor", sf::Vector2f(this->window_->getSize().x /2.f, 10.f), true);

	/*
		PERCENT TO PIXEL EXAMPLE with b_B_ & t_B_
	*/
	this->b_B_.setSettings(this->percentToPixelX(7.8125f), this->percentToPixelY(6.944444444444444f), 10.f, 50.f, sf::Color(174, 90, 65), 1, sf::Color::Red, true);
	this->t_B_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), this->percentToPixelX(1.40625f), "Play", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);

	this->b_C_.setSettings(100.f, 50.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f), sf::Color(174, 90, 65), 1, sf::Color::Red, true);
	this->t_C_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 18, "Load", sf::Vector2f(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f)), true);
	
	this->b_D_.setSettings(100.f, 50.f, this->b_C_.getLeftPosition(), this->b_C_.getBottomPosition(true, 10.f), sf::Color(174, 90, 65), 1, sf::Color::Red, true);
	this->t_D_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 18, "Settings", sf::Vector2f(this->b_D_.getLeftPosition(true, 10.f), this->b_D_.getTopPosition(true, 10.f)), true);
	
	this->b_E_.setSettings(100.f, 50.f, this->b_D_.getLeftPosition(), this->b_D_.getBottomPosition(true, 10.f), sf::Color(174, 90, 65), 1, sf::Color::Red, true);
	this->t_E_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 18, "Exit", sf::Vector2f(this->b_E_.getLeftPosition(true, 10.f), this->b_E_.getTopPosition(true, 10.f)), true);

	this->b_F_.setSettings(100.f, 50.f, this->b_E_.getLeftPosition(), this->b_E_.getBottomPosition(true, 10.f), sf::Color(174, 90, 65), 1, sf::Color::Red, true);
	this->t_F_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 18, "Editor", sf::Vector2f(this->b_F_.getLeftPosition(true, 10.f), this->b_F_.getTopPosition(true, 10.f)), true);

	this->b_G_.setSettings(100.f, 50.f, this->b_F_.getLeftPosition(), this->b_F_.getBottomPosition(true, 10.f), sf::Color(174, 90, 65), 1, sf::Color::Red, true);
	this->t_G_.setSettings(this->resource_Font_->getFont(FONTTYPE::ARIAL), 18, "Test zone", sf::Vector2f(this->b_G_.getLeftPosition(true, 10.f), this->b_G_.getTopPosition(true, 10.f)), true);

	this->buttons_.push_back(this->b_B_);
	this->buttons_.push_back(this->b_C_);
	this->buttons_.push_back(this->b_D_);
	this->buttons_.push_back(this->b_E_);
	this->buttons_.push_back(this->b_F_);
	this->buttons_.push_back(this->b_G_);

	this->texts_.push_back(this->t_A_);
	this->texts_.push_back(this->t_B_);
	this->texts_.push_back(this->t_C_);
	this->texts_.push_back(this->t_D_);
	this->texts_.push_back(this->t_E_);
	this->texts_.push_back(this->t_F_);
	this->texts_.push_back(this->t_G_);
}

StateMainMenu::~StateMainMenu()
{
}

void StateMainMenu::updatePollEvent(sf::Event& ev)
{
	this->menu_Setting_->updatePollEvent(ev, this->window_);

	if (!this->menu_Setting_->getIsInSettings())
	{
		if (this->buttons_[0].updatePollEvent(ev))
		{
			//NOTHING FOR NOW
		}
		else if (this->buttons_[1].updatePollEvent(ev))
		{
			//NOTHING FOR NOW
		}
		else if (this->buttons_[2].updatePollEvent(ev))
		{
			if (!this->menu_Setting_->getIsInSettings())
			{
				this->menu_Setting_->makeAllVisible(true);
			}
		}

		/*
			EXIT BUTTON
		*/
		else if (this->buttons_[3].updatePollEvent(ev))
		{
			this->states_->pop();
		}

		/*
			EDITOR BUTTON
		*/
		else if (this->buttons_[4].updatePollEvent(ev))
		{
			this->states_->push(new StateEditor(this->states_, this->window_, this->resource_Font_, this->resource_Hud_, this->menu_Setting_, this->menu_Pause_));
		}

		/*
			ZONE TEST BUTTONS
		*/
		else if (this->buttons_[5].updatePollEvent(ev))
		{
			this->states_->push(new StateTestZone(this->states_, this->window_, this->resource_Font_, this->resource_Hud_, this->menu_Setting_, this->menu_Pause_));
		}
	}
}

void StateMainMenu::update()
{
	/*
		UPDATE MOUSE POSITION
	*/
	this->updateMousePosition(&this->window_->getDefaultView());

	if (!this->menu_Setting_->getIsInSettings())
	{

		/*
			UPDATE BUTTONS
		*/
		for (auto& b : this->buttons_)
		{
			b.updateBoundaries(this->mouse_Position_Window_);
		}
	}


	this->menu_Setting_->update(this->mouse_Position_Window_);
}

void StateMainMenu::render(sf::RenderTarget& target)
{
	if (!this->menu_Setting_->getIsInSettings())
	{
		/*
			RENDER BUTTONS AND TEXT
		*/
		for (auto& b : this->buttons_)
		{
			b.render(target);
		}

		for (auto& t : this->texts_)
		{
			t.render(target);
		}
	}


	this->menu_Setting_->render(target);
}
