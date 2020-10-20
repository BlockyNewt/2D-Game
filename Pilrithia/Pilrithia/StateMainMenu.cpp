#include "StateMainMenu.h"

StateMainMenu::StateMainMenu(std::stack<State*>* states, sf::RenderWindow* window)
	: State(states, window)
{
	std::cout << "DEBUG::STATEMAINMENU::STATEMAINMENU() -> HAS STARTED." << std::endl;


	this->t_A_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "Title", sf::Vector2f(400.f, 10.f));

	this->b_B_.SetSettings(100, 50, 10.f, 50.f, sf::Color::Red, 1, sf::Color::Red);
	this->t_B_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "Play", this->b_B_.setPositionOfText(this->t_B_.setText()));

	this->b_C_.SetSettings(100, 50, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(10), sf::Color::Red, 1, sf::Color::Red);
	this->t_C_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "Load", this->b_C_.setPositionOfText(this->t_C_.setText()));

	this->buttons_.push_back(this->b_B_);
	this->buttons_.push_back(this->b_C_);

	this->texts_.push_back(this->t_A_);
	this->texts_.push_back(this->t_B_);
	this->texts_.push_back(this->t_C_);
}

StateMainMenu::~StateMainMenu()
{
}

void StateMainMenu::UpdatePollEvent(sf::Event& ev)
{
	this->UpdateMousePosition();

	for (auto& b : this->buttons_)
	{
		b.UpdatePollEvent(ev);
	}
}

void StateMainMenu::Update()
{
	for (auto& b : this->buttons_)
	{
		b.UpdateBoundaries(this->mouse_Position_Window_);
	}
}

void StateMainMenu::Render(sf::RenderTarget& target)
{
	for (auto& b : this->buttons_)
	{
		b.Render(target);
	}

	for (auto& t : this->texts_)
	{
		t.Render(target);
	}
}
