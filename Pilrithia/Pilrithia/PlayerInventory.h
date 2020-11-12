#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include "Item.h"	
#include "ItemTest.h"

#include "Camera.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"
#include "ItemDropDownList.h"

#include <iostream>	
#include <vector>
#include <string>
#include <map>

class PlayerInventory
{
public:
	PlayerInventory();
	~PlayerInventory();

	void initializeInventory(const std::string& name, const std::string& className, const std::map<std::string, int>& stats, const std::map<std::string, int>& resistances);
	void realignEquipment();
	void updateText(std::map<std::string, int>& stats, std::map<std::string, int>& resistances);

	void updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats, std::map<std::string, int>& resistances, std::vector<std::vector<Item*>>&items, const unsigned& maxBagSizeX, const unsigned& maxBagSizeY);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingInventory(bool isHidingInventory);
	std::vector<Item*>& setEquipment();

	const bool& getIsHidingInventory() const;
	
	

private:
	void initializeStats();
	void initializeResistances();

private:
	Box x_A_;
	Box x_B_;

	Button b_B_;

	Text t_A_;
	Text t_B_;
	Text t_C_;
	Text t_D_;
	
	Text stats_T_A_;
	Text stats_T_B_;
	Text stats_T_C_;
	Text stats_T_D_;
	Text stats_T_E_;
	Text stats_T_F_;
	Text stats_T_G_;
	Text stats_T_H_;
	Text stats_T_I_;

	HoverDescription stats_D_B_;
	HoverDescription stats_D_C_;
	HoverDescription stats_D_D_;
	HoverDescription stats_D_E_;
	HoverDescription stats_D_F_;
	HoverDescription stats_D_G_;
	HoverDescription stats_D_H_;
	HoverDescription stats_D_I_;
	
	Text resistances_T_A_;
	Text resistances_T_B_;
	Text resistances_T_C_;
	Text resistances_T_D_;
	Text resistances_T_E_;

	HoverDescription resistances_D_B_;
	HoverDescription resistances_D_C_;
	HoverDescription resistances_D_D_;
	HoverDescription resistances_D_E_;

	bool is_Hiding_Inventory_;

	sf::RectangleShape helm_Icon_;
	sf::RectangleShape shoulder_Icon_;
	sf::RectangleShape chest_Icon_;
	sf::RectangleShape glove_Icon_;
	sf::RectangleShape leg_Icon_;
	sf::RectangleShape feet_Icon_;

	std::vector<Item*>equipment_;

	int selected_Equipment_;

	HoverDescription d_A_;
	ItemDropDownList l_A_;
};

#endif // !PLAYERINVENTORY_H
