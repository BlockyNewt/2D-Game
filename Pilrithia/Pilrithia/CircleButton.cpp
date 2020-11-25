#include "CircleButton.h"

CircleButton::CircleButton()
{
}

CircleButton::~CircleButton()
{
}

void CircleButton::setSettings(float radius, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible)
{
	this->button_.setRadius(radius);
	this->button_.setPosition(sf::Vector2f(posX, posY));
	this->button_.setFillColor(fillColor);
	this->button_.setOutlineThickness(outlineThickness);
	this->button_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;

	this->is_Visible_ = isVisible;
}

bool CircleButton::updatePollEvent(sf::Event& ev)
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

void CircleButton::updateBoundaries(const sf::Vector2i& mousePositionWindow)
{
	/*
		IF THE MOUSE POSITION OF THE WINDOW IS WITHIN THE BOUNDARIES OF THIS BUTTON THEN CHANGE THE COLOR
	*/
	if (this->button_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->button_.setFillColor(sf::Color(85, 158, 131));

		this->is_Hovering_ = true;
	}
	else
	{
		this->button_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;
	}
}

void CircleButton::render(sf::RenderTarget& target)
{
	/*
		DRAW THE BOX ONLY IF IT IS VISIBLE
	*/
	if (this->is_Visible_)
	{
		target.draw(this->button_);
	}
}

const sf::Vector2f& CircleButton::setPositionOfText(sf::Text& text)
{
	text.setPosition(sf::Vector2f(this->getLeftPosition() + 10.f, this->getTopPosition() + 10.f));

	return text.getPosition();
}

void CircleButton::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void CircleButton::setTexture(const sf::Texture& texture)
{
	this->button_.setTexture(&texture);
}

const sf::Vector2f& CircleButton::getPosition() const
{
	return this->button_.getPosition();
}

const sf::FloatRect CircleButton::getGlobalBounds() const
{
	return this->button_.getGlobalBounds();
}

const float CircleButton::getLeftPosition(bool pOrM, float offset) const
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

const float CircleButton::getRightPosition(bool pOrM, float offset) const
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

const float CircleButton::getTopPosition(bool pOrM, float offset) const
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

const float CircleButton::getBottomPosition(bool pOrM, float offset) const
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

const bool& CircleButton::getIsVisible() const
{
	return this->is_Visible_;
}

const bool& CircleButton::getIsHovering() const
{
	return this->is_Hovering_;
}
