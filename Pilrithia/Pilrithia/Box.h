#ifndef BOX_H
#define BOX_H

#include "SFML/Graphics.hpp"

#include <iostream>

class Box
{
public:
	Box();
	~Box();

	void setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible);

	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);
	void setPosition(float x, float y);
	void setSize(float x, float y);

	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f& getSize() const;
	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;
	const bool& getIsVisible() const;

private:

private:
	sf::RectangleShape box_;
	bool is_Visible_;

};


#endif // !BOX_H