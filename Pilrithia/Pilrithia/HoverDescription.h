#ifndef HOVERDESCRIPTION_H
#define HOVERDESCRIPTION_H

#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Text.h"

#include <iostream>
#include <string>

class HoverDescription
{
public:
	HoverDescription();
	~HoverDescription();

	void setHoverBoundaries(const sf::FloatRect itemBoundaries);
	void setString(const std::string& text);

	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

private:

private:
	sf::FloatRect boundaries_;

	Box description_Box_;
	Text text_;

	bool is_Visible_;
};

#endif // !HOVERDESCRIPTION_H
