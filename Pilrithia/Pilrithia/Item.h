#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"

#include <iostream>
#include <string>

enum class ITEMTYPE
{
	DEFAULT = 0,

	HELM,
	CHEST,
	SHOULDER,
	GLOVE,
	LEG,
	FEET,

	WEAPON,
	OFFHAND,
	JEWELRY,
	POTION,
	FOOD
};

class Item
{
public:
	Item();
	Item(float posX, float posY, ITEMTYPE itemType, const std::string& name, const std::string& description, const ResourceFont& resourceFont);
	virtual ~Item();

	virtual void setItemHoverDescriptionSettings(HOVERPOSITION hoverPosition, const sf::FloatRect boundaries, const sf::FloatRect boundariesOffset, DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description) = 0;
	virtual void increaseStatsOnEquip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances) = 0;
	virtual void descreaseStatsOnUnequip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances) = 0;


	virtual bool updatePollEvent(sf::Event& ev) = 0;
	virtual bool update(const sf::Vector2i& mousePositionWindow) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual int& setGoldPrice() = 0;
	virtual int& setSilverPrice() = 0;
	virtual int& setCopperPrice() = 0;

	virtual const sf::FloatRect getItemGlobalBoundaries() const = 0;
	virtual const ITEMTYPE& getItemType() const = 0;
	virtual const Button& getButton() const = 0;
	//DELETE ONCE DONE WITH TESTING
	virtual const std::string& getName()const = 0;
	virtual const std::string& getDescription()const = 0;
	virtual const sf::FloatRect getHoverDescriptionGlobalBounds() const = 0;
	virtual Item* getNewItem() = 0;
	virtual const int& getGoldPrice() const = 0;
	virtual const int& getSilverPrice() const = 0;
	virtual const int& getCopperPrice() const = 0;
	virtual const sf::Vector2f& getPosition() const = 0;


private:

private:

};

#endif // !ITEM_H
