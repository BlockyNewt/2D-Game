#include "State.h"

State::State(std::stack<State*>* states, sf::RenderWindow* window)
	: states_(states), window_(window)
{
}

State::~State()
{
}

void State::UpdateMousePosition()
{
	this->mouse_Position_Window_ = sf::Mouse::getPosition(*this->window_);

	//std::cout << "X: " << this->mouse_Position_Window_.x << " Y: " << this->mouse_Position_Window_.y << std::endl;
}
