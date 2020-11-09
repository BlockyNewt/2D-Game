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

	bool updateEquipPollEvent(sf::Event& ev);
	bool updateUnequipPollEvent(sf::Event& ev);
	bool updateDeletePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);
	void setIsHovering(bool isHovering);
	
	const bool& getIsVisible() const;
	const bool& getIsHovering() const;

private:

private:
	Button b_A_;
	Button b_B_;
	Button b_C_;

	Text t_A_;
	Text t_B_;
	Text t_C_;

	bool is_Visible_;
	bool is_Hovering_;

};

#endif // !ITEMDROPDOWNLIST_H
