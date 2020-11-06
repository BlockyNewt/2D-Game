#ifndef ITEMDROPDOWNLIST_H
#define ITEMDROPDOWNLIST_H

#include "SFML/Graphics.hpp"

#include "Button.h"
#include "Text.h"

#include <iostream>
#include <string>

class ItemDropDownList
{
public:
	ItemDropDownList();
	~ItemDropDownList();

	void setSettings(int itemType, const sf::FloatRect itemBoundaries);

	void updatePollEvent(sf::Event& ev);
	bool update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);
	
	const bool& getIsVisible() const;
	const bool& getIsHovering() const;

private:

private:
	Button b_A_;
	Button b_B_;

	Text t_A_;
	Text t_B_;

	bool is_Visible_;
	bool is_Hovering_;

};

#endif // !ITEMDROPDOWNLIST_H
