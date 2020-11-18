#include "SkillButton.h"

SkillButton::SkillButton()
{
	this->max_Amount_ = 0;
	this->amount_ = 0;
}

SkillButton::~SkillButton()
{
}

void SkillButton::setSettings(float radius, float x, float y, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, int maxAllocation)
{
	this->button_.setRadius(radius);
	this->button_.setPosition(sf::Vector2f(x, y));
	this->button_.setFillColor(fillColor);
	this->button_.setOutlineThickness(outlineThickness);
	this->button_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;

	this->max_Amount_ = maxAllocation;

	std::string title = "";
	std::string description = "";

	this->t_A_.setSettings("Font/arial.ttf", 18, std::to_string(this->amount_), sf::Vector2f(this->getRightPosition(true, 10.f), this->getBottomPosition(false, 20.f)), true);
	this->h_A_.setHoverBoundaries(HOVERPOSITION::TOP, this->button_.getGlobalBounds(), this->button_.getGlobalBounds());
	this->h_A_.setString(DESCRIPTIONTYPE::SKILL, title, description);
	
}

void SkillButton::setHoverDescription(const std::string& skillName, const std::string& skillSummary)
{
	this->h_A_.setString(DESCRIPTIONTYPE::SKILL, skillName, skillSummary);
}

void SkillButton::updatePollEvent(sf::Event& ev, int& playerSkillPoints)
{
	/*
		IF YOU ARE HOVERING THEN YOU CANT CLICK THE BUTTON
	*/
	if (this->is_Hovering_)
	{
		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.key.code == sf::Mouse::Left)
			{
				//std::cout << "Left mouse button is being pressed" << std::endl;
				if (this->amount_ < this->max_Amount_)
				{
					this->amount_++;

					playerSkillPoints--;

					this->is_Hovering_ = false;
				}
			}

			else if (ev.key.code == sf::Mouse::Right)
			{
				if (this->amount_ > 0)
				{
					this->is_Hovering_ = false;

					playerSkillPoints++;

					this->amount_--;
				}
			}
		}
	}
}

void SkillButton::update(const sf::Vector2i& mousePositionWindow)
{
	/*
		IF THE MOUSE POSITION OF THE WINDOW IS WITHIN THE BOUNDARIES OF THIS BUTTON THEN CHANGE THE COLOR
	*/
	this->t_A_.setString(std::to_string(this->amount_));

	this->h_A_.update(mousePositionWindow);

	if (this->button_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->button_.setFillColor(sf::Color::Green);

		this->is_Hovering_ = true;
	}
	else
	{
		this->button_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;
	}
}

void SkillButton::render(sf::RenderTarget& target)
{
	target.draw(this->button_);

	this->t_A_.render(target);

	this->h_A_.render(target);
}

const int& SkillButton::getAmount() const
{
	return this->amount_;
}

const float SkillButton::getLeftPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().left + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().left - offset;
	}
}

const float SkillButton::getRightPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().left + this->button_.getGlobalBounds().width + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().left + this->button_.getGlobalBounds().width - offset;
	}
}

const float SkillButton::getTopPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().top + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().top - offset;
	}
}

const float SkillButton::getBottomPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().top + this->button_.getGlobalBounds().height + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().top + this->button_.getGlobalBounds().height - offset;
	}
}