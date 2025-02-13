#include "Box.h"

Box::Box()
{
	this->is_Visible_ = true;
}

Box::~Box()
{
}

void Box::setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible)
{
	/*
		SET SETTINGS FOR THE BOX HERE
	*/
	this->box_.setSize(sf::Vector2f(sizeX, sizeY));
	this->box_.setPosition(sf::Vector2f(posX, posY));
	this->box_.setFillColor(fillColor);
	this->box_.setOutlineThickness(outlineThickness);
	this->box_.setOutlineColor(outlineColor);

	this->is_Visible_ = isVisible;
}

void Box::render(sf::RenderTarget& target)
{
	/*
		DRAW THE BOX ONLY IF IT IS VISIBLE
	*/
	if (this->is_Visible_)
	{
		target.draw(this->box_);
	}
}

void Box::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void Box::setSize(float x, float y)
{
	this->box_.setSize(sf::Vector2f(x, y));
}

void Box::setTexture(const sf::Texture* texture)
{
	this->box_.setTexture(texture);
}

void Box::setPosition(float x, float y)
{
	this->box_.setPosition(sf::Vector2f(x, y));
}

const sf::Vector2f& Box::getPosition() const
{
	return this->box_.getPosition();
}

const sf::FloatRect Box::getGlobalBounds() const
{
	return this->box_.getGlobalBounds();
}

const sf::Vector2f& Box::getSize() const
{
	return this->box_.getSize();
}

const float Box::getLeftPosition(bool pOrM, float offset) const
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

const float Box::getRightPosition(bool pOrM, float offset) const
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

const float Box::getTopPosition(bool pOrM, float offset) const
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

const float Box::getBottomPosition(bool pOrM, float offset) const
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

const bool& Box::getIsVisible() const
{
	return this->is_Visible_;
}
