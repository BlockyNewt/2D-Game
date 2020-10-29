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

void State::updateMousePosition(const sf::View* view, float tileSizeXY)
{
	this->window_->setView(*view);

	this->mouse_Position_Window_ = sf::Mouse::getPosition(*this->window_);

	this->mouse_Position_View_ = this->window_->mapPixelToCoords(this->mouse_Position_Window_);

	this->mouse_Position_Grid_ = sf::Vector2u(
		static_cast<unsigned>(this->mouse_Position_View_.x) / static_cast<unsigned>(tileSizeXY),
		static_cast<unsigned>(this->mouse_Position_View_.y) / static_cast<unsigned>(tileSizeXY));

	//std::cout << "X: " << this->mouse_Position_Window_.x << " Y: " << this->mouse_Position_Window_.y << std::endl;
}

void State::updateDeltaClock()
{
	this->dt_ = this->dt_Clock_.restart().asSeconds();
}
