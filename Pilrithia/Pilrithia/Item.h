#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

#include "Button.h"
#include "Text.h"

#include <iostream>
#include <string>

enum class ITEMTYPE
{
	DEFAULT = 0,

	ARMOR,
	WEAPON,
	JEWELRY,
	POTION,
	FOOD
};

class Item
{
public:
	Item();
	Item(float posX, float posY);
	virtual ~Item();

	virtual bool updatePollEvent(sf::Event& ev) = 0;
	virtual bool update(const sf::Vector2i& mousePositionWindow) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual const sf::FloatRect getItemGlobalBoundaries() const = 0;

private:

private:

};

#endif // !ITEM_H
