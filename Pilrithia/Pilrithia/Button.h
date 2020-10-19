#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"

#include <iostream>

class Button
{
public:
	Button();
	~Button();

	void SetSettings(float sizeX, float sizeY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor);

	void UpdatePollEvent(sf::Event& ev);

	void UpdateBoundaries(const sf::Vector2i& mousePositionWindow);

	void Render(sf::RenderTarget& target);

private:

private:
	sf::RectangleShape button_;
	sf::Color fill_Color_;

	bool is_Hovering_;

};

#endif // !
