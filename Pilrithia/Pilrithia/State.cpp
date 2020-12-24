#include "State.h"

State::State(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace, ResourceItem* resourceItem, MenuSetting* menuSetting, MenuPause* menuPause)
	: states_(states), window_(window)
{
	if (this->resource_Font_ == nullptr)
	{
		this->resource_Font_ = new ResourceFont();
		this->resource_Font_->loadAllFonts();
	}
	else
	{
		this->resource_Font_ = resourceFont;
	}

	if (this->resource_Hud_ == nullptr)
	{
		this->resource_Hud_ = new ResourceHud();
		this->resource_Hud_->loadAllHudTextures();
		this->resource_Hud_->loadAllHudSounds();
	}
	else
	{
		this->resource_Hud_ = resourceHud;
	}

	if (this->resource_Race_ == nullptr)
	{
		this->resource_Race_ = new ResourceRace();
		this->resource_Race_->loadAllRaceTextures();
		this->resource_Race_->loadAllRaceSounds();
	}
	else
	{
		this->resource_Race_ = resourceRace;
	}

	if (this->resource_Item_ == nullptr)
	{
		this->resource_Item_ = new ResourceItem();
		this->resource_Item_->loadAllItemTextures();
		this->resource_Item_->loadAllItemSounds();

	}
	else
	{
		this->resource_Item_ = resourceItem;
	}

	/*if (resourceEnemy == nullptr)
	{
		this->resource_Enemy_ = new ResourceEnemy();
		this->resource_Enemy_->loadAllEnemyTextures();
		this->resource_Enemy_->loadAllEnemySounds();
	}
	else
	{
		this->resource_Enemy_ = resourceEnemy;
	}

	if (resourceNpc == nullptr)
	{
		this->resource_Npc_ = new ResourceNpc();
		this->resource_Npc_->loadAllNpcTextures();
		this->resource_Npc_->loadAllNpcSounds();
	}
	else
	{
		this->resource_Npc_ = resourceNpc;
	}*/

	if (menuSetting == nullptr)
	{
		this->menu_Setting_ = new MenuSetting(this->window_, *this->resource_Font_);
	}
	else
	{
		this->menu_Setting_ = menuSetting;
	}

	if(menuPause == nullptr)
	{
		this->menu_Pause_ = new MenuPause(this->window_, *this->resource_Font_);
	}
	else
	{
		this->menu_Pause_ = menuPause;
	}

}

State::~State()
{
	if (this->states_->size() == 1)
	{
		//MUST DELETE THESE WHEN CLOSING THE APPLICATION. IF THESE ARE DELETED BEFORE THEN, THEN 
		//YOU WILL GET SOME MEMORY ACCESS VIOLATION ERRORS
		delete this->menu_Pause_;

		delete this->resource_Font_;

		delete this->resource_Hud_;

		delete this->resource_Race_;

		delete this->resource_Item_;

		std::cout << "DEBUG::STATE::~STATE() -> State deconstructed." << std::endl;
	}
}

void State::updateMousePosition(const sf::View* view, float tileSizeXY)
{
	/*
		UPDATE DIFFERENT MOUSE POSITOINS BASE ON THE VIEW WE ARE SENDING IN
	*/

	this->window_->setView(*view);

	this->mouse_Position_Window_ = sf::Mouse::getPosition(*this->window_);
	//std::cout << "x: " << this->window_->getSize().x << " y: " << this->window_->getSize().y << std::endl;

	this->mouse_Position_View_ = this->window_->mapPixelToCoords(this->mouse_Position_Window_);

	this->mouse_Position_Grid_ = sf::Vector2u(
		static_cast<unsigned>(this->mouse_Position_View_.x) / static_cast<unsigned>(tileSizeXY),
		static_cast<unsigned>(this->mouse_Position_View_.y) / static_cast<unsigned>(tileSizeXY));

	//std::cout << "X: " << this->mouse_Position_Window_.x << " Y: " << this->mouse_Position_Window_.y << std::endl;
	//std::cout << "X: " << this->mouse_Position_View_.x << " Y: " << this->mouse_Position_View_.y << std::endl;

}

void State::updateTextureMousePosition(const sf::View* view, const float tileSizeXY)
{
	this->window_->setView(*view);

	this->mouse_Position_Window_ = sf::Mouse::getPosition(*this->window_);

	this->mouse_Position_View_ = this->window_->mapPixelToCoords(this->mouse_Position_Window_);

	this->mouse_Position_Texture_Grid_ = sf::Vector2u(
		static_cast<unsigned>(this->mouse_Position_View_.x) / static_cast<unsigned>(tileSizeXY),
		static_cast<unsigned>(this->mouse_Position_View_.y) / static_cast<unsigned>(tileSizeXY));
}

void State::updateDeltaClock()
{
	/*
		UPDATE DELTA TIME
	*/

	/*float frameRate = 1.f / this->dt_;
	std::cout << frameRate << std::endl;*/

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
	float resizeX = sizeX / this->window_->getSize().x * 100.f;
	std::cout << this->window_->getSize().x << std::endl;
	return std::floor(static_cast<float>(this->window_->getSize().x)) * (resizeX / 100.f);
}

const float State::percentToPixelY(const float sizeY)
{
	float resizeY = sizeY / this->window_->getSize().y * 100.f;

	return std::floor(static_cast<float>(this->window_->getSize().y)) * (resizeY / 100.f);
}
