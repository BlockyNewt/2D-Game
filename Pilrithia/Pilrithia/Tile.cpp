#include "Tile.h"

Tile::Tile(float positionX, float positionY, const float tileSizeXY, bool hasColor)
{
	this->tile_.setPosition(sf::Vector2f(positionX, positionY));
	this->tile_.setSize(sf::Vector2f(tileSizeXY, tileSizeXY));

	this->has_Color_ = hasColor;

	if (this->has_Color_)
	{
		this->tile_.setFillColor(sf::Color::Yellow);
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

void Tile::setColor(const sf::Color& fillColor)
{
	this->tile_.setFillColor(fillColor);
}

void Tile::setHasColor(bool hasColor)
{
	this->has_Color_ = hasColor;
}

const bool& Tile::getHasColor() const
{
	return this->has_Color_;
}
