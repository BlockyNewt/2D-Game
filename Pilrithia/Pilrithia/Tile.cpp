#include "Tile.h"

Tile::Tile(float positionX, float positionY, const float tileSizeXY)
{
	this->tile_.setPosition(sf::Vector2f(positionX, positionY));
	this->tile_.setSize(sf::Vector2f(tileSizeXY, tileSizeXY));

	this->tile_.setFillColor(sf::Color::Blue);
	this->tile_.setOutlineThickness(1.f);
	this->tile_.setOutlineColor(sf::Color::Red);
}

Tile::~Tile()
{
}

void Tile::Render(sf::RenderTarget& target)
{
	target.draw(this->tile_);
}
