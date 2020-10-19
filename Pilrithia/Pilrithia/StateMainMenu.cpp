#include "StateMainMenu.h"

StateMainMenu::StateMainMenu(std::stack<State*>* states, sf::RenderWindow* window)
	: State(states, window)
{
	std::cout << "DEBUG::STATEMAINMENU::STATEMAINMENU() -> HAS STARTED." << std::endl;

	this->b_1_.SetSettings(200, 100, sf::Color::Red, 1, sf::Color::Red);
	this->t_1_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", "Hello world");
}

StateMainMenu::~StateMainMenu()
{
}

void StateMainMenu::UpdatePollEvent(sf::Event& ev)
{
	this->UpdateMousePosition();

	this->b_1_.UpdatePollEvent(ev);
}

void StateMainMenu::Update()
{
	this->b_1_.UpdateBoundaries(this->mouse_Position_Window_);
}

void StateMainMenu::Render(sf::RenderTarget& target)
{
	this->b_1_.Render(target);
	this->t_1_.Render(target);
}
