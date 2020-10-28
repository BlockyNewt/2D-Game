#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>

class CheckBox
{
public:
	CheckBox();
	~CheckBox();

	void setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible, bool isEnabled);

	bool updatePollEvent(sf::Event& ev);

	void updateBoundaries(const sf::Vector2i& mousePositionWindow);

	void render(sf::RenderTarget& target);

	void setIsEnabled(bool isEnabled);
	void setIsVisible(bool isVisible);

	const sf::Vector2f& getPosition() const;
	const sf::FloatRect& getGlobalBounds() const;
	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;
	const bool& getIsEnabled() const;
	const bool& getIsVisible() const;

private:

private:
	sf::RectangleShape box_;
	sf::RectangleShape check_;

	sf::Color fill_Color_;

	bool is_Hovering_;
	bool is_Enabled_;
	bool is_Visible_;

};

#endif // !CHECKBOX_H
