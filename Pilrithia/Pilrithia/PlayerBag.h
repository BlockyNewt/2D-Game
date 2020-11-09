#ifndef PLAYERBAG_H
#define PLAYERBAG_H

#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"
#include "ItemDropDownList.h"

#include "Item.h"
#include "ItemTest.h"

#include <iostream>
#include <string>
#include <vector>

class PlayerBag
{
public:
	PlayerBag();
	~PlayerBag();

	void initializeBag(int maxBagSizeY);

	void updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingBag(bool isHidingBag);

	const bool& getIsHidingBag() const;

private:

private:
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

};

#endif // !PLAYERBAG_H
