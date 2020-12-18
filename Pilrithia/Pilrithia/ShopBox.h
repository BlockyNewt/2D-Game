#ifndef SHOPBOX_H
#define SHOPBOX_H

#include "ResourceFont.h"
#include "ResourceNpc.h"

#include "Box.h"
#include "Button.h"
#include "ItemDropDownList.h"
#include "Text.h"

#include "Item.h"
#include "ItemTest.h"

#include <iostream>
#include <string>
#include <vector>

class ShopBox
{
public:
	ShopBox(const ResourceFont& resourceFont, const ResourceItem& resourceItem, const ResourceNpc& resourceNpc);
	~ShopBox();

	void alignPlayerBagItems(std::vector<std::vector<Item*>>& playerBag, const int& playerBagMaxSizeX, const int& playerBagMaxSizeY);
	void handleMoney(bool bOrS, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag);

	void updatePollEvent(sf::Event& ev, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag);
	void update(const sf::Vector2i mousePositionWindow, const std::vector<Item*>& playerInventory, std::vector<std::vector<Item*>>& playerBag);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);

	const bool& getIsVisible() const;

private:

private:
	ResourceNpc resource_Npc_;

	Box x_A_;
	Box x_B_;
	Box x_C_;

	Button b_A_;

	Text t_A_;
	Text t_B_;

	unsigned int max_Bag_Size_X_;
	unsigned int max_Bag_Size_Y_;
	int selected_Item_X_;
	int selected_Item_Y_;
	std::vector<std::vector<Item*>> shop_Items_;
	unsigned int player_Max_Bag_Size_X_;
	unsigned int player_Max_Bag_Size_Y_;
	int player_Selected_Item_X_;
	int player_Selected_Item_Y_;
	std::vector<std::vector<Item*>> player_Bag_;


	ItemDropDownList l_A_;
	ItemDropDownList l_B_;

	HoverDescription d_A_;

	int scroll_;

	bool has_Enough_Money_;

	bool is_Visible_;

	ResourceFont resource_Font_;
};

#endif // !SHOPBOX_H
