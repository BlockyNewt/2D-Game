#include "Box.h"

Box::Box()
{
	this->is_Visible_ = true;
}

Box::~Box()
{
}

void Box::SetSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible)
{
	this->box_.setSize(sf::Vector2f(sizeX, sizeY));
	this->box_.setPosition(sf::Vector2f(posX, posY));
	this->box_.setFillColor(fillColor);
	this->box_.setOutlineThickness(outlineThickness);
	this->box_.setOutlineColor(outlineColor);

	this->is_Visible_ = isVisible;
}

void Box::Render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		target.draw(this->box_);
	}
}

void Box::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const sf::Vector2f& Box::getPosition() const
{
	return this->box_.getPosition();
}

const float& Box::getLeftPosition(bool pOrM, float offset) const
{
	if (pOrM)
	{
		return this->box_.getGlobalBounds().left + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().left - offset;
	}
}

const float& Box::getRightPosition(bool pOrM, float offset) const
{
	if (pOrM)
	{
		return this->box_.getGlobalBounds().left + this->box_.getGlobalBounds().width + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().left + this->box_.getGlobalBounds().width - offset;
	}
}

const float& Box::getTopPosition(bool pOrM, float offset) const
{
	if (pOrM)
	{
		return this->box_.getGlobalBounds().top + offset;
	}
	else
	{
		return this->box_.getGlobalBounds().top - offset;
	}
}

const float& Box::getBottomPosition(bool pOrM, float offset) const
{
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