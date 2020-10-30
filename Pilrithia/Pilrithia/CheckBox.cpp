#include "CheckBox.h"

CheckBox::CheckBox()
{
	this->is_Hovering_ = false;
	this->is_Enabled_ = false;
	this->is_Visible_ = false;
}

CheckBox::~CheckBox()
{
}

void CheckBox::setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible, bool isEnabled)
{
	/*
		SET SETTINGS FOR CHECKBOX
	*/
	this->box_.setSize(sf::Vector2f(sizeX, sizeY));
	this->box_.setPosition(sf::Vector2f(posX, posY));
	this->box_.setFillColor(fillColor);
	this->box_.setOutlineThickness(outlineThickness);
	this->box_.setOutlineColor(outlineColor);

	this->check_.setSize(sf::Vector2f(this->box_.getSize().x - 15.f, this->box_.getSize().y - 15.f));
	this->check_.setPosition(sf::Vector2f(this->getLeftPosition(true, 8), this->getTopPosition(true, 8)));
	this->check_.setFillColor(sf::Color::Red);
	this->check_.setOutlineThickness(outlineThickness);
	this->check_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;

	this->is_Enabled_ = isEnabled;
	this->is_Visible_ = isVisible;
}

bool CheckBox::updatePollEvent(sf::Event& ev)
{
	/*
		IF YOU ARE HOVERING THEN YOU CAN CLICK THE CHECKBOX
	*/
	if (this->is_Hovering_)
	{
		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.key.code == sf::Mouse::Left)
			{
				//std::cout << "Left mouse button is being pressed on checkbox" << std::endl;

				this->is_Hovering_ = false;

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
	else
	{
		return false;
	}
}

void CheckBox::updateBoundaries(const sf::Vector2i& mousePositionWindow)
{
	/*
		IF THE MOUSE POSITION OF THE WINDOW IS WITHIN THE BOUNDARIES OF THIS CHECKBOX THEN CHANGE THE COLOR
	*/
	if (this->box_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->box_.setFillColor(sf::Color::Green);

		this->is_Hovering_ = true;
	}
	else
	{
		this->box_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;
	}
}

void CheckBox::render(sf::RenderTarget& target)
{
	/*
		DRAW THE CHECKBOX ONLY IF IT IS VISIBLE
	*/
	if (this->is_Visible_)
	{
		target.draw(this->box_);

		if (this->is_Enabled_)
		{
			target.draw(this->check_);
		}
	}
}

void CheckBox::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void CheckBox::setIsEnabled(bool isEnabled)
{
	this->is_Enabled_ = isEnabled;
}

const sf::Vector2f& CheckBox::getPosition() const
{
	return this->box_.getPosition();
}

const sf::FloatRect CheckBox::getGlobalBounds() const
{
	return this->box_.getGlobalBounds();
}

const float CheckBox::getLeftPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->box_.getGlobalBounds().left + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().left - offset;
	}
}

const float CheckBox::getRightPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->box_.getGlobalBounds().left + this->box_.getGlobalBounds().width + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().left + this->box_.getGlobalBounds().width - offset;
	}
}

const float CheckBox::getTopPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->box_.getGlobalBounds().top + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().top - offset;
	}
}

const float CheckBox::getBottomPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->box_.getGlobalBounds().top + this->box_.getGlobalBounds().height + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().top + this->box_.getGlobalBounds().height - offset;
	}
}

const bool& CheckBox::getIsEnabled() const
{
	return this->is_Enabled_;
}

const bool& CheckBox::getIsVisible() const
{
	return this->is_Visible_;
}

