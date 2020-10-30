#include "StateTestZone.h"

StateTestZone::StateTestZone(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	this->camera_ = new Camera(this->window_->getSize().x, this->window_->getSize().y);

	this->tilemap_ = new Tilemap(20, 20, 30);

	this->load_X_A_.setSettings(800.f, 400.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	this->load_B_A_.setSettings(150.f, 50.f, this->load_X_A_.getLeftPosition(true, 250), this->load_X_A_.getBottomPosition(false, 55), sf::Color::Blue, 1, sf::Color::Red, true);
	this->load_B_B_.setSettings(150.f, 50.f, this->load_B_A_.getRightPosition(true, 20), this->load_B_A_.getTopPosition(), sf::Color::Blue, 1, sf::Color::Red, true);

	this->load_T_A_.setSettings("Font/arial.ttf", 35, "Load a tilemap", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 250.f), this->load_X_A_.getTopPosition(true, 10.f)), true);
	this->load_T_B_.setSettings("Font/arial.ttf", 25, "Filename: ", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 10.f), this->load_X_A_.getTopPosition(true, 200.f)), true);
	this->load_T_C_.setSettings("Font/arial.ttf", 25, "Load", sf::Vector2f(this->load_B_A_.getLeftPosition(true, 10.f), this->load_B_A_.getTopPosition(true, 10.f)), true);
	this->load_T_D_.setSettings("Font/arial.ttf", 25, "Close", sf::Vector2f(this->load_B_B_.getLeftPosition(true, 10.f), this->load_B_B_.getTopPosition(true, 10.f)), true);

	this->load_I_A_.setSettings(500.f, 40.f, this->load_T_B_.getRightPosition(true, 10.f), this->load_T_B_.getTopPosition(), sf::Color::Black, 1.f, sf::Color::Red, true, false, 30);
}

StateTestZone::~StateTestZone()
{
}

void StateTestZone::updatePollEvent(sf::Event& ev)
{
	if (this->menu_Pause_->updatePollEvent(ev))
	{
		this->states_->pop();
	}

	if (!this->menu_Pause_->getIsPaused())
	{
		this->window_->setKeyRepeatEnabled(true);

		this->camera_->updatePollEvent(ev);

		this->player_Test_.updatePollEvent(ev, this->dt_);

		this->window_->setKeyRepeatEnabled(true);

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
				else
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


		if (this->load_X_A_.getIsVisible())
		{
			this->load_I_A_.updatePollEvent(ev);

			if (this->load_B_A_.updatePollEvent(ev))
			{
				this->tilemap_->load(this->load_I_A_.getString());
			}

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
}

void StateTestZone::update()
{
	this->updateMousePosition(&this->camera_->getView(), this->tilemap_->getTileSizeXY());
	this->updateDeltaClock();

	this->menu_Pause_->update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		this->tilemap_->update(*this->camera_);

		this->tilemap_->playerCollision(this->player_Test_);

		this->player_Test_.update();

		this->npc_Test_.update(this->player_Test_.getPlayerGlobalBounds());

		this->camera_->setCenter(sf::Vector2f(this->player_Test_.getPlayerModel().getPosition().x, this->player_Test_.getPlayerModel().getPosition().y));

		if (this->load_X_A_.getIsVisible())
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
	
	this->npc_Test_.render(target);

	this->player_Test_.render(target);

	target.setView(target.getDefaultView());


	this->load_X_A_.render(target);
	this->load_B_A_.render(target);
	this->load_B_B_.render(target);
	this->load_T_A_.render(target);
	this->load_T_B_.render(target);
	this->load_T_C_.render(target);
	this->load_T_D_.render(target);
	this->load_I_A_.render(target);


	this->menu_Pause_->render(target);
}
