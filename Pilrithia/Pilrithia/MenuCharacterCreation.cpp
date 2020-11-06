#include "MenuCharacterCreation.h"

void MenuCharacterCreation::initializeNameGui()
{
	/*
		SET SETTINGS FOR NAME RELATED OBJECTS
	*/

	this->name_T_A_.setSettings("Font/arial.ttf", 24, "Name:", sf::Vector2f(150.f, 100.f), true);

	this->name_I_A_.setSettings(400.f, 40.f, this->name_T_A_.getRightPosition(true, 10.f), this->name_T_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true, false, 20);

	this->name_B_B_.setSettings(150.f, 40.f, this->name_I_A_.getRightPosition(true, 10.f), this->name_I_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);
	this->name_T_B_.setSettings("Font/arial.ttf", 18, "Complete", sf::Vector2f(this->name_B_B_.getLeftPosition(true, 10.f), this->name_B_B_.getTopPosition(true, 10.f)), true);
}

void MenuCharacterCreation::initializeRaceGui()
{
	/*
		SET SETTINGS FOR RACE RELATED OBJECTS
	*/

	this->race_X_A_.setSettings(800.f, 200.f, this->name_T_A_.getLeftPosition(), this->model_Preview_X_A_.getTopPosition(true, 50.f), sf::Color::Black, 1.f, sf::Color::White, true);

	this->race_B_A_.setSettings(80.f, 80.f, this->race_X_A_.getLeftPosition(false, 115.f), this->race_X_A_.getTopPosition(true, 60.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->race_B_B_.setSettings(80.f, 80.f, this->race_B_A_.getLeftPosition(), this->race_B_A_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->race_B_C_.setSettings(80.f, 80.f, this->race_B_A_.getLeftPosition(), this->race_B_B_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->race_B_D_.setSettings(80.f, 80.f, this->race_B_A_.getLeftPosition(), this->race_B_C_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->race_B_E_.setSettings(80.f, 80.f, this->race_B_D_.getLeftPosition(), this->race_B_D_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);

	this->race_T_A_.setSettings("Font/arial.ttf", 18, this->race_Orc_.getName(), sf::Vector2f(this->race_B_A_.getLeftPosition(true, 10.f), this->race_B_A_.getTopPosition(true, 10.f)), true);
	this->race_T_B_.setSettings("Font/arial.ttf", 18, this->race_Human_.getName(), sf::Vector2f(this->race_B_B_.getLeftPosition(true, 10.f), this->race_B_B_.getTopPosition(true, 10.f)), true);
	this->race_T_C_.setSettings("Font/arial.ttf", 18, this->race_Dwarf_.getName(), sf::Vector2f(this->race_B_C_.getLeftPosition(true, 10.f), this->race_B_C_.getTopPosition(true, 10.f)), true);
	this->race_T_D_.setSettings("Font/arial.ttf", 18, this->race_Elf_.getName(), sf::Vector2f(this->race_B_D_.getLeftPosition(true, 10.f), this->race_B_D_.getTopPosition(true, 10.f)), true);
	this->race_T_E_.setSettings("Font/arial.ttf", 18, "Race 5", sf::Vector2f(this->race_B_E_.getLeftPosition(true, 10.f), this->race_B_E_.getTopPosition(true, 10.f)), true);
	this->race_T_F_.setSettings("Font/arial.ttf", 28, "Race summary", sf::Vector2f(this->race_X_A_.getLeftPosition(true, 300.f), this->race_X_A_.getTopPosition(true, 10.f)), true);
	this->race_T_G_.setSettings("Font/arial.ttf", 18, "Race summary", sf::Vector2f(this->race_X_A_.getLeftPosition(true, 10.f), this->race_X_A_.getTopPosition(true, 60.f)), true);
}

void MenuCharacterCreation::initializeClassGui()
{
	/*
		SET SETTINGS FOR CLASS RELATED OBJECTS
	*/

	this->class_X_A_.setSettings(800.f, 335.f, this->race_X_A_.getLeftPosition(), this->race_X_A_.getBottomPosition(true, 10.f), sf::Color::Black, 1.f, sf::Color::White, true);

	this->class_B_B_.setSettings(80.f, 80.f, this->class_X_A_.getLeftPosition(true, 100.f), this->class_X_A_.getTopPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->class_B_C_.setSettings(80.f, 80.f, this->class_X_A_.getRightPosition(false, 190.f), this->class_B_B_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);
	this->class_B_F_.setSettings(50.f, 50.f, this->class_X_A_.getRightPosition(false, 400.f), this->class_X_A_.getBottomPosition(false, 75), sf::Color::Red, 1.f, sf::Color::White, true);

	this->class_T_A_.setSettings("Font/arial.ttf", 28, "Class", sf::Vector2f(this->class_X_A_.getLeftPosition(true, 350.f), this->class_X_A_.getTopPosition(true, 10.f)), true);
	this->class_T_B_.setSettings("Font/arial.ttf", 18, "Class 1", sf::Vector2f(this->class_B_B_.getLeftPosition(true, 10.f), this->class_B_B_.getTopPosition(true, 10.f)), true);
	this->class_T_C_.setSettings("Font/arial.ttf", 18, "Class 2", sf::Vector2f(this->class_B_C_.getLeftPosition(true, 10.f), this->class_B_C_.getTopPosition(true, 10.f)), true);
	this->class_T_D_.setSettings("Font/arial.ttf", 18, "Class Summary", sf::Vector2f(this->class_X_A_.getLeftPosition(true, 100.f), this->class_X_A_.getTopPosition(true, 100.f)), true);
	this->class_T_E_.setSettings("Font/arial.ttf", 28, "Skillset preview", sf::Vector2f(this->class_X_A_.getLeftPosition(true, 300.f), this->class_X_A_.getTopPosition(true, 200.f)), true);
	this->class_T_F_.setSettings("Font/arial.ttf", 18, "Race class skill 1", sf::Vector2f(this->class_B_F_.getLeftPosition(true, 10.f), this->class_B_F_.getTopPosition(true, 10.f)), true);

	this->class_D_A_.setHoverBoundaries(this->class_B_F_.getGlobalBounds());
}

MenuCharacterCreation::MenuCharacterCreation(const unsigned int windowSizeX, const unsigned int windowSizeY)
{
	this->is_Creating_Character_ = true;

	this->title_T_A_.setSettings("Font/arial.ttf", 50, "Character Creation", sf::Vector2f(windowSizeX / 2.f - 200.f, 10.f), true);

	this->background_X_A_.setSettings(windowSizeX, windowSizeY, 0.f, 0.f, sf::Color::Black, 1.f, sf::Color::Black, true);
	this->model_Preview_X_A_.setSettings(300.f, 600.f, windowSizeX - 310.f, 100.f, sf::Color::Black, 1.f, sf::Color::White, true);

	this->initializeNameGui();
	this->initializeRaceGui();
	this->initializeClassGui();

	/*
		INITIALIZE THE RACES AND SET THE POSITION OF THEIR MODELS
	*/
	this->race_ = NULL;
	this->race_Orc_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));
	this->race_Human_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));
	this->race_Dwarf_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));
	this->race_Elf_.initializeRace(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 250.f));

	/*
		SET SETTINGS FOR RACE PREVIEW MODEL
	*/
	this->race_Model_.setSize(sf::Vector2f(50.f, 50.f));
	this->race_Model_.setPosition(sf::Vector2f(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 200.f)));
	this->race_Model_.setFillColor(sf::Color::Transparent);
	this->race_Model_.setOutlineThickness(1.f);
	this->race_Model_.setOutlineColor(sf::Color::Transparent);

}

MenuCharacterCreation::~MenuCharacterCreation()
{
	//delete this->race_;
}

void MenuCharacterCreation::updateRacePollEvent(sf::Event& ev)
{
	/*
		UPDATE RACE BUTTON POLL EVENTS 
	*/

	if (this->race_B_A_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Orc_;
	}

	if (this->race_B_B_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Human_;
	}

	if (this->race_B_C_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Dwarf_;
	}

	if (this->race_B_D_.updatePollEvent(ev))
	{
		this->race_ = &this->race_Elf_;
	}

	if (this->race_B_E_.updatePollEvent(ev))
	{
		this->race_T_G_.setString("");
		this->race_Model_.setFillColor(sf::Color::Transparent);
		this->race_Model_.setOutlineColor(sf::Color::Transparent);
	}

	if (this->race_ != NULL)
	{
		/*
			CHANGE NEEDED OBJECTS AFTER YOU CLICK ON A RACE
		*/
		this->race_T_G_.setString(this->race_->getSummary());
		this->race_Model_ = this->race_->getModel();
		this->race_Model_.setPosition(sf::Vector2f(this->model_Preview_X_A_.getLeftPosition(true, 125.f), this->model_Preview_X_A_.getTopPosition(true, 300.f)));

		this->class_T_B_.setString(this->race_->getClassesOne().getName());
		this->class_T_C_.setString(this->race_->getClassesTwo().getName());
	}
}

void MenuCharacterCreation::updateClassPollEvent(sf::Event& ev)
{
	/*
		UPDATE CLASS BUTTONS POLL EVENTS
	*/

	/*
		IF YOU CLICK RACE CLASS ONE BUTTON
	*/
	if (this->class_B_B_.updatePollEvent(ev))
	{
		this->class_T_D_.setString(this->race_->getClassesOne().getSummary());
		this->class_T_F_.setString(this->race_->getClassesOne().getSkillOne().getName());

		this->class_D_A_.setString(this->race_->getClassesOne().getSkillOne().getSummary());

		/*
			SET PLAYERS CLASS TO SELECTED CLASS
		*/
		this->race_->setPlayerClasses(this->race_->getClassesOne());
		std::cout << "Player selected class name: " << this->race_->getPlayerClass().getName() << std::endl;
	}

	/*
		IF YOU CLICK RACE CLASS TWO BUTTON
	*/
	if (this->class_B_C_.updatePollEvent(ev))
	{
		this->class_T_D_.setString(this->race_->getClassesTwo().getSummary());
		this->class_T_F_.setString(this->race_->getClassesTwo().getSkillOne().getName());

		this->class_D_A_.setString(this->race_->getClassesTwo().getSkillOne().getSummary());

		/*
			SET PLAYERS CLASS TO SELECTED CLASS
		*/
		this->race_->setPlayerClasses(this->race_->getClassesTwo());
		std::cout << "Player selected class name: " << this->race_->getPlayerClass().getName() << std::endl;
	}
}

bool MenuCharacterCreation::updatePollEvent(sf::Event& ev)
{
	if (this->is_Creating_Character_)
	{
		this->updateRacePollEvent(ev);
		this->updateClassPollEvent(ev);

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
		this->class_B_B_.updateBoundaries(mousePositionWindow);
		this->class_B_C_.updateBoundaries(mousePositionWindow);

		/*
			UPDATE STRING WHEN TYPING NAME IN
		*/
		this->name_I_A_.update(mousePositionWindow);

		this->class_D_A_.update(mousePositionWindow);
	}
}

void MenuCharacterCreation::render(sf::RenderTarget& target)
{
	if (this->is_Creating_Character_)
	{
		target.setView(target.getDefaultView());

		this->background_X_A_.render(target);
		this->model_Preview_X_A_.render(target);
		this->race_X_A_.render(target);
		this->class_X_A_.render(target);

		this->title_T_A_.render(target);


		this->name_B_B_.render(target);

		this->name_T_A_.render(target);
		this->name_T_B_.render(target);


		this->race_B_A_.render(target);
		this->race_B_B_.render(target);
		this->race_B_C_.render(target);
		this->race_B_D_.render(target);
		this->race_B_E_.render(target);

		this->race_T_A_.render(target);
		this->race_T_B_.render(target);
		this->race_T_C_.render(target);
		this->race_T_D_.render(target);
		this->race_T_E_.render(target);
		this->race_T_F_.render(target);
		this->race_T_G_.render(target);
		

		this->class_B_B_.render(target);
		this->class_B_C_.render(target);
		this->class_B_F_.render(target);

		this->class_T_A_.render(target);
		this->class_T_B_.render(target);
		this->class_T_C_.render(target);
		this->class_T_D_.render(target);
		this->class_T_E_.render(target);
		this->class_T_F_.render(target);

		this->name_I_A_.render(target);

		this->class_D_A_.render(target);

		target.draw(this->race_Model_);
	}
}

void MenuCharacterCreation::setIsCreatingCharacter(bool isCreatingCharacter)
{
	this->is_Creating_Character_ = isCreatingCharacter;
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
