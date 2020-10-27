#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <string>

class Tile
{
public:
	Tile(float positionX, float positionY, const float tileSizeXY, bool hasColor);
	~Tile();

	void render(sf::RenderTarget& target);

	void setColor(const sf::Color& fillColor);
	void setHasColor(bool hasColor);

	const bool& getHasColor() const;

private:

private:
	sf::RectangleShape tile_;

	bool has_Color_;

};

#endif // !TILE_H
