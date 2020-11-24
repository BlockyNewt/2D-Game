#ifndef LOOTWINDOW_H
#define LOOTWINDOW_H

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "ItemDropDownList.h"

#include "Item.h"
#include "ItemTest.h"

#include <iostream>
#include <vector>
#include <string>

class LootWindow
{
public:
	LootWindow();
	~LootWindow();

	void addEnemyItems(std::vector<Item*>& enemyItems);

	void updatePollEvent(sf::Event& ev, std::vector<std::vector<Item*>>& playerBag, const int& maxBagSizeX, const int& maxBagSizeY);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);

	const int& getSize() const;
	const bool& getIsVisible() const;

private:

private:
	Box	 x_A_;
	Text t_A_;

	Button b_B_;
	Text t_B_;

	bool is_Visible_;

	std::vector<Item*> loot_;

	ItemDropDownList l_A_;
	int selected_Item_X_;
};

#endif // !LOOTWINDOW_H
