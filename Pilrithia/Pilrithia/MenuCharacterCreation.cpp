#include "MenuCharacterCreation.h"

void MenuCharacterCreation::initializeNameGui(ResourceFont* resourceFont, ResourceHud* resourceHud)
{
	/*
		SET SETTINGS FOR NAME RELATED OBJECTS
	*/

	this->name_T_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 24, "Name:", sf::Vector2f(150.f, 100.f), true);

	this->name_I_A_.setSettings(400.f, 40.f, this->name_T_A_.getRightPosition(true, 10.f), this->name_T_A_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true, false, 20, resourceFont);

	this->name_B_B_.setSettings(150.f, 40.f, this->name_I_A_.getRightPosition(true, 10.f), this->name_I_A_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->name_T_B_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Complete", sf::Vector2f(this->name_B_B_.getLeftPosition(true, 10.f), this->name_B_B_.getTopPosition(true, 10.f)), true);
}

void MenuCharacterCreation::initializeRaceGui(ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace)
{
	/*
		SET SETTINGS FOR RACE RELATED OBJECTS
	*/

	this->race_X_A_.setSettings(800.f, 555, this->name_T_A_.getLeftPosition(), this->model_Preview_X_A_.getTopPosition(true, 50.f), sf::Color(90, 82, 85), 1.f, sf::Color::White, true);

	this->race_A_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::RACE_FACE));
	this->race_A_Sprite_.setPosition(sf::Vector2f(this->race_X_A_.getLeftPosition(false, 115.f), this->race_X_A_.getTopPosition(true, 40.f)));

	this->race_B_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::RACE_FACE));
	this->race_B_Sprite_.setPosition(sf::Vector2f(this->race_A_Sprite_.getGlobalBounds().left, this->race_A_Sprite_.getGlobalBounds().top + this->race_A_Sprite_.getGlobalBounds().height + 10.f));

	this->race_C_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::RACE_FACE));
	this->race_C_Sprite_.setPosition(sf::Vector2f(this->race_A_Sprite_.getGlobalBounds().left, this->race_B_Sprite_.getGlobalBounds().top + this->race_B_Sprite_.getGlobalBounds().height + 10.f));

	this->race_D_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::RACE_FACE));
	this->race_D_Sprite_.setPosition(sf::Vector2f(this->race_B_Sprite_.getGlobalBounds().left, this->race_C_Sprite_.getGlobalBounds().top + this->race_C_Sprite_.getGlobalBounds().height + 10.f));

	this->race_E_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::RACE_FACE));
	this->race_E_Sprite_.setPosition(sf::Vector2f(this->race_B_Sprite_.getGlobalBounds().left, this->race_D_Sprite_.getGlobalBounds().top + this->race_D_Sprite_.getGlobalBounds().height + 10.f));


	this->race_B_A_.setSettings(80.f, 80.f, this->race_A_Sprite_.getGlobalBounds().left + 4.f, this->race_A_Sprite_.getGlobalBounds().top + 4.f, sf::Color::White, 1.f, sf::Color::White, true);
	this->race_B_A_.setTexture(resourceRace->getRaceTexture(RACE_TEXTURE_TYPE_::ORC_ICON_));
	this->race_B_B_.setSettings(80.f, 80.f, this->race_B_Sprite_.getGlobalBounds().left + 4.f, this->race_B_Sprite_.getGlobalBounds().top + 4.f, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->race_B_C_.setSettings(80.f, 80.f, this->race_C_Sprite_.getGlobalBounds().left + 4.f, this->race_C_Sprite_.getGlobalBounds().top + 4.f, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->race_B_D_.setSettings(80.f, 80.f, this->race_D_Sprite_.getGlobalBounds().left + 4.f, this->race_D_Sprite_.getGlobalBounds().top + 4.f, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->race_B_E_.setSettings(80.f, 80.f, this->race_E_Sprite_.getGlobalBounds().left + 4.f, this->race_E_Sprite_.getGlobalBounds().top + 4.f, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);

	this->race_T_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, this->race_Orc_.getName(), sf::Vector2f(this->race_B_A_.getLeftPosition(true, 10.f), this->race_B_A_.getTopPosition(true, 10.f)), true);
	/*this->race_T_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, this->race_Human_.getName(), sf::Vector2f(this->race_B_B_.getLeftPosition(true, 10.f), this->race_B_B_.getTopPosition(true, 10.f)), true);
	this->race_T_C_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, this->race_Dwarf_.getName(), sf::Vector2f(this->race_B_C_.getLeftPosition(true, 10.f), this->race_B_C_.getTopPosition(true, 10.f)), true);
	this->race_T_D_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, this->race_Elf_.getName(), sf::Vector2f(this->race_B_D_.getLeftPosition(true, 10.f), this->race_B_D_.getTopPosition(true, 10.f)), true);*/
	this->race_T_E_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Race 5", sf::Vector2f(this->race_B_E_.getLeftPosition(true, 10.f), this->race_B_E_.getTopPosition(true, 10.f)), true);
	this->race_T_F_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 28, "Race summary", sf::Vector2f(this->race_X_A_.getLeftPosition(true, 300.f), this->race_X_A_.getTopPosition(true, 10.f)), true);
	this->race_T_G_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Race summary", sf::Vector2f(this->race_X_A_.getLeftPosition(true, 10.f), this->race_X_A_.getTopPosition(true, 60.f)), true);
}

void MenuCharacterCreation::repositionGui(const sf::RenderWindow* window)
{
	this->title_T_A_.setPosition(window->getSize().x, window->getSize().y);

	this->background_X_A_.setSize(window->getSize().x, window->getSize().y);
	this->model_Preview_X_A_.setPosition(window->getSize().x - 310.f, 100.f);

	this->race_Model_.setPosition(sf::Vector2f(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 200.f)));


	/*
		NAME GUI	
	*/
	this->name_T_A_.setPosition(150.f, 100.f);
	this->name_I_A_.setPosition(sf::Vector2f(this->name_T_A_.getRightPosition(true, 10.f), this->name_T_A_.getTopPosition()));

	this->name_B_B_.setPosition(sf::Vector2f(this->name_I_A_.getRightPosition(true, 10.f), this->name_I_A_.getTopPosition()));
	this->name_T_B_.setPosition(this->name_B_B_.getLeftPosition(true, 10.f), this->name_B_B_.getTopPosition(true, 10.f));

	/*
		RACE GUI
	*/
	this->race_X_A_.setPosition(this->name_T_A_.getLeftPosition(), this->model_Preview_X_A_.getTopPosition(true, 50.f));

	this->race_A_Sprite_.setPosition(sf::Vector2f(this->race_X_A_.getLeftPosition(false, 115.f), this->race_X_A_.getTopPosition(true, 40.f)));
	this->race_B_Sprite_.setPosition(sf::Vector2f(this->race_A_Sprite_.getGlobalBounds().left, this->race_A_Sprite_.getGlobalBounds().top + this->race_A_Sprite_.getGlobalBounds().height + 10.f));
	this->race_C_Sprite_.setPosition(sf::Vector2f(this->race_A_Sprite_.getGlobalBounds().left, this->race_B_Sprite_.getGlobalBounds().top + this->race_B_Sprite_.getGlobalBounds().height + 10.f));
	this->race_D_Sprite_.setPosition(sf::Vector2f(this->race_B_Sprite_.getGlobalBounds().left, this->race_C_Sprite_.getGlobalBounds().top + this->race_C_Sprite_.getGlobalBounds().height + 10.f));
	this->race_E_Sprite_.setPosition(sf::Vector2f(this->race_B_Sprite_.getGlobalBounds().left, this->race_D_Sprite_.getGlobalBounds().top + this->race_D_Sprite_.getGlobalBounds().height + 10.f));


	this->race_B_A_.setPosition(sf::Vector2f(this->race_A_Sprite_.getGlobalBounds().left + 4.f, this->race_A_Sprite_.getGlobalBounds().top + 4.f));
	this->race_B_B_.setPosition(sf::Vector2f(this->race_B_Sprite_.getGlobalBounds().left + 4.f, this->race_B_Sprite_.getGlobalBounds().top + 4.f));
	this->race_B_C_.setPosition(sf::Vector2f(this->race_C_Sprite_.getGlobalBounds().left + 4.f, this->race_C_Sprite_.getGlobalBounds().top + 4.f));
	this->race_B_D_.setPosition(sf::Vector2f(this->race_D_Sprite_.getGlobalBounds().left + 4.f, this->race_D_Sprite_.getGlobalBounds().top + 4.f));
	this->race_B_E_.setPosition(sf::Vector2f(this->race_E_Sprite_.getGlobalBounds().left + 4.f, this->race_E_Sprite_.getGlobalBounds().top + 4.f));

	this->race_T_A_.setPosition(this->race_B_A_.getLeftPosition(true, 10.f), this->race_B_A_.getTopPosition(true, 10.f));

	this->race_T_E_.setPosition(this->race_B_E_.getLeftPosition(true, 10.f), this->race_B_E_.getTopPosition(true, 10.f));
	this->race_T_F_.setPosition(this->race_X_A_.getLeftPosition(true, 300.f), this->race_X_A_.getTopPosition(true, 10.f));
	this->race_T_G_.setPosition(this->race_X_A_.getLeftPosition(true, 10.f), this->race_X_A_.getTopPosition(true, 60.f));
}

MenuCharacterCreation::MenuCharacterCreation(sf::Vector2u windowSize, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace)
{
	this->is_Creating_Character_ = true;

	this->title_T_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 50, "Character Creation", sf::Vector2f(windowSize.x / 2.f - 200.f, 10.f), true);

	this->background_X_A_.setSettings(windowSize.x, windowSize.y, 0.f, 0.f, sf::Color::Black, 1.f, sf::Color(90, 82, 85), true);
	this->model_Preview_X_A_.setSettings(300.f, 600.f, windowSize.x - 310.f, 100.f, sf::Color(90, 82, 85), 1.f, sf::Color::White, true);

	this->initializeNameGui(resourceFont, resourceHud);
	this->initializeRaceGui(resourceFont, resourceHud, resourceRace);

	/*
		INITIALIZE THE RACES AND SET THE POSITION OF THEIR MODELS
	*/
	this->race_ = NULL;
	this->race_Orc_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));
	/*this->race_Human_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));
	this->race_Dwarf_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));
	this->race_Elf_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));*/

	/*
		SET SETTINGS FOR RACE PREVIEW MODEL
	*/
	this->race_Model_.setSize(sf::Vector2f(96.f, 77.f));
	this->race_Model_.setPosition(sf::Vector2f(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 200.f)));
	this->race_Model_.setFillColor(sf::Color::Transparent);
	this->race_Model_.setOutlineThickness(0.f);
	this->race_Model_.setOutlineColor(sf::Color::Transparent);
	this->race_Model_.setScale(sf::Vector2f(4.f, 4.f));
	

	this->resource_Race_ = resourceRace;
}

MenuCharacterCreation::~MenuCharacterCreation()
{

}

void MenuCharacterCreation::updateRacePollEvent(sf::Event& ev)
{
	/*
		UPDATE RACE BUTTON POLL EVENTS 
	*/

	if (this->race_B_A_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Orc_;

		this->setObjectsBasedOnRace();
	}

	/*if (this->race_B_B_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Human_;

		this->setObjectsBasedOnRace();
	}

	if (this->race_B_C_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Dwarf_;

		this->setObjectsBasedOnRace();
	}

	if (this->race_B_D_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Elf_;

		this->setObjectsBasedOnRace();
	}*/

	if (this->race_B_E_.updatePollEvent(ev))
	{
		this->race_T_G_.setString("");
		this->race_Model_.setFillColor(sf::Color::Transparent);
		this->race_Model_.setOutlineColor(sf::Color::Transparent);
	}

	
}

bool MenuCharacterCreation::updatePollEvent(sf::Event& ev)
{
	if (this->is_Creating_Character_)
	{
		this->updateRacePollEvent(ev);

		/*
			UPDATE KEYBOARD INPUT FOR NAME INPUT
		*/
		this->name_I_A_.updatePollEvent(ev);

		if (this->name_B_B_.updatePollEvent(ev))
		{
			this->is_Creating_Character_ = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void MenuCharacterCreation::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Creating_Character_)
	{
		this->name_B_B_.updateBoundaries(mousePositionWindow);
		this->race_B_A_.updateBoundaries(mousePositionWindow);
		this->race_B_B_.updateBoundaries(mousePositionWindow);
		this->race_B_C_.updateBoundaries(mousePositionWindow);
		this->race_B_D_.updateBoundaries(mousePositionWindow);
		this->race_B_E_.updateBoundaries(mousePositionWindow);


		/*
			UPDATE STRING WHEN TYPING NAME IN
		*/
		this->name_I_A_.update(mousePositionWindow);
	}
}

void MenuCharacterCreation::render(sf::RenderTarget& target)
{
	if (this->is_Creating_Character_)
	{
		this->background_X_A_.render(target);
		this->model_Preview_X_A_.render(target);
		this->race_X_A_.render(target);
		//this->class_X_A_.render(target);

		this->title_T_A_.render(target);


		this->name_B_B_.render(target);

		this->name_T_A_.render(target);
		this->name_T_B_.render(target);



		this->race_B_A_.render(target);
		this->race_B_B_.render(target);
		this->race_B_C_.render(target);
		this->race_B_D_.render(target);
		this->race_B_E_.render(target);

		target.draw(this->race_A_Sprite_);
		target.draw(this->race_B_Sprite_);
		target.draw(this->race_C_Sprite_);
		target.draw(this->race_D_Sprite_);
		target.draw(this->race_E_Sprite_);


		this->race_T_A_.render(target);
		this->race_T_B_.render(target);
		this->race_T_C_.render(target);
		this->race_T_D_.render(target);
		this->race_T_E_.render(target);
		this->race_T_F_.render(target);
		this->race_T_G_.render(target);
		

		this->name_I_A_.render(target);

		target.draw(this->race_Model_);
	}
}

void MenuCharacterCreation::setIsCreatingCharacter(bool isCreatingCharacter)
{
	this->is_Creating_Character_ = isCreatingCharacter;
}

void MenuCharacterCreation::setObjectsBasedOnRace()
{
	if (this->race_ != NULL)
	{
		/*
			CHANGE NEEDED OBJECTS AFTER YOU CLICK ON A RACE
		*/
		this->race_->setIconTexture(*this->resource_Race_->getRaceTexture(RACE_TEXTURE_TYPE_::ORC_ICON_));
		this->race_->setRunTexture(*this->resource_Race_->getRaceTexture(RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP));
		this->race_->setIdleTexture(*this->resource_Race_->getRaceTexture(RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_IDLE));
		this->race_->setAttackTexture(*this->resource_Race_->getRaceTexture(RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_ATTACK));
		this->race_->setJumpTexture(*this->resource_Race_->getRaceTexture(RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_JUMP));

		this->race_T_G_.setString(this->race_->getSummary());
		this->race_T_G_.wrapText(this->race_X_A_.getGlobalBounds());

		this->race_Model_ = this->race_->getModel();
		this->race_Model_.setPosition(sf::Vector2f(this->model_Preview_X_A_.getLeftPosition(false, 30.f), this->model_Preview_X_A_.getTopPosition(true, 50.f)));
		this->race_Model_.setTexture(this->resource_Race_->getRaceTexture(RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_IDLE));
		this->race_Model_.setTextureRect(sf::IntRect(0, 0, 96, 77));
		this->race_Model_.setOutlineThickness(1.f);
		this->race_Model_.setOutlineColor(sf::Color::Transparent);
		this->race_Model_.setScale(sf::Vector2f(4.f, 4.f));
	}
}

const bool& MenuCharacterCreation::getIsCreatingCharacter() const
{
	return this->is_Creating_Character_;
}

 Race& MenuCharacterCreation::getRace() const
{
	return *this->race_;
}

 const std::string& MenuCharacterCreation::getName() const
 {
	 return this->name_I_A_.getString();
 }
