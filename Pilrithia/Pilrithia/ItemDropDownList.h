#ifndef ITEMDROPDOWNLIST_H
#define ITEMDROPDOWNLIST_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Button.h"
#include "Text.h"

#include <iostream>
#include <string>

enum class LISTUSE
{
	DEFAULT = 0,

	INVENTORY,
	BAG,
	LOOT,
	SHOPBUY,
	SHOPSELL,
};

class ItemDropDownList
{
public:
	ItemDropDownList();
	~ItemDropDownList();

	void setSettings(LISTUSE listUse, const sf::FloatRect itemBoundaries, ResourceFont* resourceFont);

	bool updateEquipPollEvent(sf::Event& ev);
	bool updateUnequipPollEvent(sf::Event& ev);
	bool updateDeletePollEvent(sf::Event& ev);
	bool updateTakePollEvent(sf::Event& ev);
	bool updateBuyPollEvent(sf::Event& ev);
	bool updateSellPollEvent(sf::Event& ev);
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
	Button b_D_;
	Button b_E_;
	Button b_F_;

	Text t_A_;
	Text t_B_;
	Text t_C_;
	Text t_D_;
	Text t_E_;
	Text t_F_;

	bool is_Visible_;
	bool is_Hovering_;

};

#endif // !ITEMDROPDOWNLIST_H
