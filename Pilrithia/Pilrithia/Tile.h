#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <string>

enum class TYPE
{
	DEFAULT = 0, 

	BOUNDARY,
};

class Tile
{
public:
	Tile(float positionX, float positionY, const float tileSizeXY, bool hasColor, int type);
	~Tile();

	void render(sf::RenderTarget& target);

	void setFillColor(const sf::Color& fillColor);
	void setOutlineColor(const sf::Color& outlineColor);
	void setHasColor(bool hasColor);

	const bool& getHasColor() const;
	const sf::Vector2f& getPosition() const;
	const TYPE& getType() const;
	const int& getTypeConversion() const;

	//TESTING WITH PLAYER COLLISION
	const float& getLeftPosition() const;
	const float& getRightPosition() const;
	const float& getTopPosition() const;
	const float& getBottomPosition() const;

private:

private:
	sf::RectangleShape tile_;

	TYPE type_;
	int type_Conversion_;

	bool has_Color_;

};

#endif // !TILE_H
