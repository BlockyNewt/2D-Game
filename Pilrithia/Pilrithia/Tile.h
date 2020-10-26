#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <string>

class Tile
{
public:
	Tile(float positionX, float positionY, const float tileSizeXY);
	~Tile();

	void Render(sf::RenderTarget& target);

	void SetColor(const sf::Color& fillColor);

private:

private:
	sf::RectangleShape tile_;

};

#endif // !TILE_H
