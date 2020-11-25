#ifndef PLAYERBAG_H
#define PLAYERBAG_H

#include "SFML/Graphics.hpp"

#include "Item.h"	
#include "ItemTest.h"

#include "Camera.h"

#include "ResourceFont.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"
#include "ItemDropDownList.h"

#include <iostream>	
#include <vector>
#include <string>

class PlayerBag
{
public:
	PlayerBag(const ResourceFont& resourceFont);
	~PlayerBag();

	void initializeBag();
	void realignItems();

	void updatePollEvent(sf::Event& ev, std::vector<Item*>& equipment, std::map<std::string, int>& stats, std::map<std::string, int>& resistances);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingBag(bool isHidingBag);
	void setMaxBagSizeY(int value);
	std::vector<std::vector<Item*>>& setItem();

	const bool& getIsHidingBag() const;
	const unsigned& getBagSizeX() const;
	const unsigned& getBagSizeY() const;

private:

private:
	unsigned int max_Bag_Size_X_;
	unsigned int max_Bag_Size_Y_;

	HoverDescription d_A_;
	ItemDropDownList l_A_;


	Box x_A_;

	Button b_A_;
	
	Text t_A_;
	Text t_B_;
	Text t_C_;
	Text t_D_;
	Text t_E_;

	std::vector < std::vector<Item*> > items_;

	int selected_Item_X_;
	int selected_Item_Y_;

	bool is_Hiding_Bag_;

	ResourceFont resource_Font_;
};

#endif // !PLAYERBAG_H
