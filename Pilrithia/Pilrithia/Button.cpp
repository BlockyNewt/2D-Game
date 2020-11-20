#include "Button.h"

Button::Button()
{
	this->is_Hovering_ = false;

	this->is_Visible_ = true;
}

Button::~Button()
{
}

void Button::setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible)
{
	this->button_.setSize(sf::Vector2f(sizeX, sizeY));
	this->button_.setPosition(sf::Vector2f(posX, posY));
	this->button_.setFillColor(fillColor);
	this->button_.setOutlineThickness(outlineThickness);
	this->button_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;

	this->is_Visible_ = isVisible;
}

bool Button::updatePollEvent(sf::Event& ev)
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

bool Button::updateRightClickPollEvent(sf::Event& ev)
{
	/*
		IF YOU ARE HOVERING THEN YOU CANT CLICK THE BUTTON
	*/
	if (this->is_Hovering_)
	{
		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.key.code == sf::Mouse::Right)
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

void Button::updateBoundaries(const sf::Vector2i& mousePositionWindow)
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

bool Button::updateBoundariesValue(const sf::Vector2i& mousePositionWindow)
{
	/*
		IF THE MOUSE POSITION OF THE WINDOW IS WITHIN THE BOUNDARIES OF THIS BUTTON THEN CHANGE THE COLOR
	*/
	if (this->button_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->button_.setFillColor(sf::Color::Green);

		this->is_Hovering_ = true;

		return true;
	}
	else
	{
		this->button_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;

		return false;
	}
}

void Button::render(sf::RenderTarget& target)
{
	/*
		DRAW THE BOX ONLY IF IT IS VISIBLE
	*/
	if (this->is_Visible_)
	{
		target.draw(this->button_);
	}
}

const sf::Vector2f& Button::setPositionOfText(sf::Text& text)
{
	text.setPosition(sf::Vector2f(this->getLeftPosition() + 10.f, this->getTopPosition() + 10.f));

	return text.getPosition();
}

void Button::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void Button::setPosition(const sf::Vector2f& position)
{
	this->button_.setPosition(position);
}

const sf::Vector2f& Button::getPosition() const
{
	return this->button_.getPosition();
}

const sf::FloatRect Button::getGlobalBounds() const
{
	return this->button_.getGlobalBounds();
}

const float Button::getLeftPosition(bool pOrM, float offset) const
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

const float Button::getRightPosition(bool pOrM, float offset) const
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

const float Button::getTopPosition(bool pOrM, float offset) const
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

const float Button::getBottomPosition(bool pOrM, float offset) const
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

const bool& Button::getIsVisible() const
{
	return this->is_Visible_;
}

const bool& Button::getIsHovering() const
{
	return this->is_Hovering_;
}
