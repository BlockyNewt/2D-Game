#include "Tile.h"

Tile::Tile(float positionX, float positionY, const float tileSizeXY, bool hasColor, int type)
{
	this->tile_.setPosition(sf::Vector2f(positionX, positionY));
	this->tile_.setSize(sf::Vector2f(tileSizeXY, tileSizeXY));
	this->tile_.setOutlineColor(sf::Color::Transparent);
	this->tile_.setOutlineThickness(1.f);

	this->has_Color_ = hasColor;

	if (this->has_Color_)
	{
		this->tile_.setFillColor(sf::Color::Yellow);
	}
	
	this->type_Conversion_ = type;

	switch (this->type_Conversion_)
	{
	case 1:
		this->type_ = TYPE::BOUNDARY;
		break;
	default:
		break;
	}

	/*this->tile_.setFillColor(sf::Color::Blue);
	this->tile_.setOutlineThickness(1.f);
	this->tile_.setOutlineColor(sf::Color::Red);*/
}

Tile::~Tile()
{
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->tile_);
}

void Tile::setFillColor(const sf::Color& fillColor)
{
	this->tile_.setFillColor(fillColor);
}

void Tile::setOutlineColor(const sf::Color& outlineColor)
{
	this->tile_.setOutlineColor(outlineColor);
}

void Tile::setHasColor(bool hasColor)
{
	this->has_Color_ = hasColor;
}

const bool& Tile::getHasColor() const
{
	return this->has_Color_;
}

const sf::Vector2f& Tile::getPosition() const
{
	return this->tile_.getPosition();
}

const TYPE& Tile::getType() const
{
	return this->type_;
}

const int& Tile::getTypeConversion() const
{
	return this->type_Conversion_;
}

const float& Tile::getLeftPosition() const
{
	return this->tile_.getGlobalBounds().left;
}

const float& Tile::getRightPosition() const
{
	return this->tile_.getGlobalBounds().left + this->tile_.getGlobalBounds().width;
}

const float& Tile::getTopPosition() const
{
	return this->tile_.getGlobalBounds().top;
}

const float& Tile::getBottomPosition() const
{
	return this->tile_.getGlobalBounds().top + this->tile_.getGlobalBounds().height;
}
