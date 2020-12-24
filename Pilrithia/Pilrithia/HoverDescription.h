#ifndef HOVERDESCRIPTION_H
#define HOVERDESCRIPTION_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Box.h"
#include "Text.h"

#include <iostream>
#include <string>

enum class HOVERPOSITION
{
	DEFAULT = 0,

	TOP,
	BOTTOM,
	LEFT,
	RIGHT
};

enum class DESCRIPTIONTYPE
{
	DEFUALT = 0,

	ITEM,
	SKILL,
	STAT
};

class HoverDescription
{
public:
	HoverDescription();
	~HoverDescription();

	void setTextFont(ResourceFont* resourceFont);

	void setHoverBoundaries(HOVERPOSITION hoverPosition, const sf::FloatRect itemBoundaries, const sf::FloatRect itemBoundariesOffset);
	void setString(DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description);

	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);

	const sf::FloatRect getGlobalBounds() const;
private:

private:
	sf::FloatRect boundaries_;
	sf::FloatRect boundaries_Offset_;

	Box description_Box_;

	Text title_;
	Text description_;

	bool is_Visible_;
};

#endif // !HOVERDESCRIPTION_H
