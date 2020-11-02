#include "MenuCharacterCreation.h"

MenuCharacterCreation::MenuCharacterCreation(const unsigned int windowSizeX, const unsigned int windowSizeY)
{
	this->race_ = NULL;

	this->is_Creating_Character_ = true;

	this->x_A_.setSettings(windowSizeX, windowSizeY, 0.f, 0.f, sf::Color::Black, 1.f, sf::Color::Black, true);
	this->x_B_.setSettings(300.f, 600.f, 10.f, 100.f, sf::Color::Black, 1.f, sf::Color::White, true);
	this->x_C_.setSettings(800.f, 200.f, this->x_B_.getRightPosition(true, 120.f), this->x_B_.getTopPosition(true, 50.f), sf::Color::Black, 1.f, sf::Color::White, true);
	this->x_D_.setSettings(800.f, 335.f, this->x_C_.getLeftPosition(), this->x_C_.getBottomPosition(true, 10.f), sf::Color::Black, 1.f, sf::Color::White, true);

	this->b_A_.setSettings(150.f, 40.f, this->x_B_.getRightPosition(true, 630.f), this->x_B_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);
	this->b_B_.setSettings(80.f, 80.f, this->x_B_.getRightPosition(true, 20.f), this->x_C_.getTopPosition(true, 60.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->b_C_.setSettings(80.f, 80.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->b_D_.setSettings(80.f, 80.f, this->b_B_.getLeftPosition(), this->b_C_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->b_E_.setSettings(80.f, 80.f, this->b_B_.getLeftPosition(), this->b_D_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);
	this->b_F_.setSettings(80.f, 80.f, this->b_E_.getLeftPosition(), this->b_E_.getBottomPosition(true, 10.f), sf::Color::Red, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 50, "Character Creation", sf::Vector2f(windowSizeX / 2.f - 200.f, 10.f), true);
	this->t_B_.setSettings("Font/arial.ttf", 24, "Name:", sf::Vector2f(this->x_C_.getLeftPosition(), this->x_B_.getTopPosition()), true);
	this->t_C_.setSettings("Font/arial.ttf", 18, "Complete", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);
	this->t_D_.setSettings("Font/arial.ttf", 18, this->race_Orc_.getName(), sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);
	this->t_E_.setSettings("Font/arial.ttf", 18, this->race_Human_.getName(), sf::Vector2f(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f)), true);
	this->t_F_.setSettings("Font/arial.ttf", 18, "Race 3", sf::Vector2f(this->b_D_.getLeftPosition(true, 10.f), this->b_D_.getTopPosition(true, 10.f)), true);
	this->t_G_.setSettings("Font/arial.ttf", 18, "Race 4", sf::Vector2f(this->b_E_.getLeftPosition(true, 10.f), this->b_E_.getTopPosition(true, 10.f)), true);
	this->t_H_.setSettings("Font/arial.ttf", 18, "Race 5", sf::Vector2f(this->b_F_.getLeftPosition(true, 10.f), this->b_F_.getTopPosition(true, 10.f)), true);
	this->t_I_.setSettings("Font/arial.ttf", 28, "Race summary", sf::Vector2f(this->x_C_.getLeftPosition(true, 300.f), this->x_C_.getTopPosition(true, 10.f)), true);
	this->t_J_.setSettings("Font/arial.ttf", 18, this->race_Orc_.getSummary(), sf::Vector2f(this->x_C_.getLeftPosition(true, 10.f), this->t_I_.getBottomPosition(true, 10.f)), true);

	this->i_A_.setSettings(400.f, 40.f, this->t_B_.getRightPosition(true, 10.f), this->x_B_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true, false, 20);



	this->race_Orc_.initializeRace(this->x_B_.getLeftPosition(true, 125.f), this->x_B_.getTopPosition(true, 250.f));
	this->race_Human_.initializeRace(this->x_B_.getLeftPosition(true, 125.f), this->x_B_.getTopPosition(true, 250.f));

	this->race_Model_.setSize(sf::Vector2f(50.f, 50.f));
	this->race_Model_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 125.f), this->x_B_.getTopPosition(true, 250.f)));
	this->race_Model_.setFillColor(sf::Color::Transparent);
	this->race_Model_.setOutlineThickness(1.f);
	this->race_Model_.setOutlineColor(sf::Color::Transparent);
}

MenuCharacterCreation::~MenuCharacterCreation()
{
	delete this->race_;
}

bool MenuCharacterCreation::updatePollEvent(sf::Event& ev)
{
	if (this->is_Creating_Character_)
	{
		this->i_A_.updatePollEvent(ev);

		if (this->b_A_.updatePollEvent(ev))
		{
			this->is_Creating_Character_ = false;

			return true;
		}

		else if (this->b_B_.updatePollEvent(ev))
		{
			this->t_J_.setString(this->race_Orc_.getSummary());
			this->race_Model_ = this->race_Orc_.getModel();
			this->race_ = &this->race_Orc_;

			return false;
		}

		else if (this->b_C_.updatePollEvent(ev))
		{
			this->t_J_.setString(this->race_Human_.getSummary());
			this->race_Model_ = this->race_Human_.getModel();
			this->race_ = &this->race_Human_;

			return false;
		}

		else if (this->b_D_.updatePollEvent(ev))
		{
			this->t_J_.setString("");
			this->race_Model_.setFillColor(sf::Color::Transparent);
			this->race_Model_.setOutlineColor(sf::Color::Transparent);

			return false;
		}

		else if (this->b_E_.updatePollEvent(ev))
		{
			return false;
		}

		else if (this->b_F_.updatePollEvent(ev))
		{
			return false;
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
		this->b_A_.updateBoundaries(mousePositionWindow);
		this->b_B_.updateBoundaries(mousePositionWindow);
		this->b_C_.updateBoundaries(mousePositionWindow);
		this->b_D_.updateBoundaries(mousePositionWindow);
		this->b_E_.updateBoundaries(mousePositionWindow);
		this->b_F_.updateBoundaries(mousePositionWindow);

		this->i_A_.update(mousePositionWindow);
	}
}

void MenuCharacterCreation::render(sf::RenderTarget& target)
{
	if (this->is_Creating_Character_)
	{
		target.setView(target.getDefaultView());

		this->x_A_.render(target);
		this->x_B_.render(target);
		this->x_C_.render(target);
		this->x_D_.render(target);

		this->b_A_.render(target);
		this->b_B_.render(target);
		this->b_C_.render(target);
		this->b_D_.render(target);
		this->b_E_.render(target);
		this->b_F_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);
		this->t_C_.render(target);
		this->t_D_.render(target);
		this->t_E_.render(target);
		this->t_F_.render(target);
		this->t_G_.render(target);
		this->t_H_.render(target);
		this->t_I_.render(target);
		this->t_J_.render(target);

		this->i_A_.render(target);

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
