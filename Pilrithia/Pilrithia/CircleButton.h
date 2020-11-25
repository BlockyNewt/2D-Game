#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include "SFML/Graphics.hpp"

#include <iostream>

class CircleButton
{
public:
	CircleButton();
	~CircleButton();

	void setSettings(float radius, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible);

	bool updatePollEvent(sf::Event& ev);

	void updateBoundaries(const sf::Vector2i& mousePositionWindow);

	void render(sf::RenderTarget& target);

	const sf::Vector2f& setPositionOfText(sf::Text& text);
	void setIsVisible(bool isVisible);
	void setTexture(const sf::Texture& texture);


	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;
	const bool& getIsVisible() const;
	const bool& getIsHovering()const;


private:

private:
	sf::CircleShape button_;
	sf::Color fill_Color_;

	bool is_Hovering_;
	bool is_Visible_;

};

#endif // !CIRCLEBUTTON_H
