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
	/*
		UPDATE DIFFERENT MOUSE POSITOINS BASE ON THE VIEW WE ARE SENDING IN
	*/

	this->window_->setView(*view);

	this->mouse_Position_Window_ = sf::Mouse::getPosition(*this->window_);

	this->mouse_Position_View_ = this->window_->mapPixelToCoords(this->mouse_Position_Window_);

	this->mouse_Position_Grid_ = sf::Vector2u(
		static_cast<unsigned>(this->mouse_Position_View_.x) / static_cast<unsigned>(tileSizeXY),
		static_cast<unsigned>(this->mouse_Position_View_.y) / static_cast<unsigned>(tileSizeXY));

	//std::cout << "X: " << this->mouse_Position_Window_.x << " Y: " << this->mouse_Position_Window_.y << std::endl;
	//std::cout << "X: " << this->mouse_Position_View_.x << " Y: " << this->mouse_Position_View_.y << std::endl;
}

void State::updateDeltaClock()
{
	/*
		UPDATE DELTA TIME
	*/

	this->dt_ = this->dt_Clock_.restart().asSeconds();

	//std::cout << "DEBUG::STATE::UPDATEDELTACLOCK() -> SECONDS: " << this->dt_ << std::endl;
}

const float State::percentToPixelX(const float sizeX)
{
	/*

	TO GET SIZEX...
	EXAMPLE: 200 / 1280 * 100 = 15.6
			 1280 * 15.6 / 100 = 200
	*/

	return std::floor(static_cast<float>(this->window_->getSize().x)) * (sizeX / 100.f);
}

const float State::percentToPixelY(const float sizeY)
{
	return std::floor(static_cast<float>(this->window_->getSize().y)) * (sizeY / 100.f);
}
