#include "State.h"

State::State(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: states_(states), window_(window)
{
	if (menuSetting == nullptr)
	{
		this->menu_Setting_ = new MenuSetting(this->window_);
	}
	else
	{
		this->menu_Setting_ = menuSetting;
	}

	if(menuPause == nullptr)
	{
		this->menu_Pause_ = new MenuPause(this->window_);
	}
	else
	{
		this->menu_Pause_ = menuPause;
	}
}

State::~State()
{
	delete this->menu_Pause_;
}

void State::UpdateMousePosition()
{
	this->mouse_Position_Window_ = sf::Mouse::getPosition(*this->window_);

	//std::cout << "X: " << this->mouse_Position_Window_.x << " Y: " << this->mouse_Position_Window_.y << std::endl;
}
