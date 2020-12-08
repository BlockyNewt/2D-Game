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
	WALL
};

class Tile
{
public:
	Tile(float positionX, float positionY, float tileSizeXY, int type);
	Tile(float positionX, float positionY, float tileSizeXY, const sf::Texture& texture, const sf::IntRect& textureBounds, int type);
	~Tile();

	void render(sf::RenderTarget& target);

	void setFillColor(const sf::Color& fillColor);
	void setOutlineColor(const sf::Color& outlineColor);

	const sf::Vector2f& getPosition() const;
	const TYPE& getType() const;
	const int& getTypeConversion() const;
	const sf::FloatRect getGlobalBounds() const;
	const float getLeftPosition() const;
	const float getRightPosition() const;
	const float getTopPosition() const;
	const float getBottomPosition() const;
	const sf::RectangleShape& getTile() const;
	const sf::IntRect& getTextureBounds() const;

private:

private:
	sf::RectangleShape tile_;

	TYPE type_;
	int type_Conversion_;

};

#endif // !TILE_H
