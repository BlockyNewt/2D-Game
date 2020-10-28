#include "StateMainMenu.h"

StateMainMenu::StateMainMenu(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEMAINMENU::STATEMAINMENU() -> HAS STARTED." << std::endl;


	this->t_A_.setSettings("Font/arial.ttf", 50, "Title", sf::Vector2f(this->window_->getSize().x /2.f, 10.f), true);

	this->b_B_.setSettings(100.f, 50.f, 10.f, 50.f, sf::Color::Red, 1, sf::Color::Red, true);
	this->t_B_.setSettings("Font/arial.ttf", 18, "Play", this->b_B_.setPositionOfText(this->t_B_.setText()), true);

	this->b_C_.setSettings(100.f, 50.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_C_.setSettings("Font/arial.ttf", 18, "Load", this->b_C_.setPositionOfText(this->t_C_.setText()), true);
	
	this->b_D_.setSettings(100.f, 50.f, this->b_C_.getLeftPosition(), this->b_C_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_D_.setSettings("Font/arial.ttf", 18, "Settings", this->b_D_.setPositionOfText(this->t_D_.setText()), true);
	
	this->b_E_.setSettings(100.f, 50.f, this->b_D_.getLeftPosition(), this->b_D_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_E_.setSettings("Font/arial.ttf", 18, "Exit", this->b_E_.setPositionOfText(this->t_E_.setText()), true);

	this->b_F_.setSettings(100.f, 50.f, this->b_E_.getLeftPosition(), this->b_E_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_F_.setSettings("Font/arial.ttf", 18, "Editor", this->b_F_.setPositionOfText(this->t_F_.setText()), true);

	this->buttons_.push_back(this->b_B_);
	this->buttons_.push_back(this->b_C_);
	this->buttons_.push_back(this->b_D_);
	this->buttons_.push_back(this->b_E_);
	this->buttons_.push_back(this->b_F_);

	this->texts_.push_back(this->t_A_);
	this->texts_.push_back(this->t_B_);
	this->texts_.push_back(this->t_C_);
	this->texts_.push_back(this->t_D_);
	this->texts_.push_back(this->t_E_);
	this->texts_.push_back(this->t_F_);
}

StateMainMenu::~StateMainMenu()
{
}

void StateMainMenu::updatePollEvent(sf::Event& ev)
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
		//NOTHING FOR NOW
	}
	else if (this->buttons_[3].updatePollEvent(ev))
	{
		this->states_->pop();
	}
	else if (this->buttons_[4].updatePollEvent(ev))
	{
		this->states_->push(new StateEditor(this->states_, this->window_));
	}
}

void StateMainMenu::update()
{
	this->updateMousePosition(&this->window_->getDefaultView());

	for (auto& b : this->buttons_)
	{
		b.updateBoundaries(this->mouse_Position_Window_);
	}
}

void StateMainMenu::render(sf::RenderTarget& target)
{
	for (auto& b : this->buttons_)
	{
		b.render(target);
	}

	for (auto& t : this->texts_)
	{
		t.render(target);
	}
}
