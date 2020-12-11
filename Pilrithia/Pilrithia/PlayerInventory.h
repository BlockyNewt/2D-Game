#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include "Item.h"	
#include "ItemTest.h"

#include "Camera.h"

#include "ResourceFont.h"
#include "ResourceHud.h"
#include "ResourceRace.h"

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
	PlayerInventory(const sf::RenderWindow* window, const ResourceFont& resourceFont, const ResourceHud& resourceHud, const ResourceRace& resourceRace);
	~PlayerInventory();

	void initializeInventory(const std::string& name, const std::string& raceName, const std::string& className, const int& level, const std::map<std::string, int>& stats, const std::map<std::string, int>& resistances);
	void realignEquipment();
	void updateText(std::map<std::string, int>& stats, std::map<std::string, int>& resistances);

	void updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats, std::map<std::string, int>& resistances, std::vector<std::vector<Item*>>&items, const unsigned& maxBagSizeX, const unsigned& maxBagSizeY);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingInventory(bool isHidingInventory);
	std::vector<Item*>& setEquipment();
	void setPositionOnResize(const sf::RenderWindow* window);

	const bool& getIsHidingInventory() const;
	const std::vector<Item*>& getEquipment() const;

	
	

private:
	void initializeStats(const ResourceFont& resourceFont);
	void initializeResistances(const ResourceFont& resourceFont);
	void initializeIcons(const ResourceFont& resourceFont);

private:
	Box x_C_;
	sf::Sprite inventory_Background_Sprite_;

	Button b_B_;

	Text t_C_;
	Text t_D_;
	Text t_E_;
	Text t_F_;
	
	Button stats_B_A_;
	Text stats_T_A_;
	Text stats_T_B_;
	Text stats_T_C_;
	Text stats_T_D_;
	Text stats_T_E_;
	Text stats_T_G_;
	Text stats_T_H_;
	Text stats_T_I_;

	Text stats_T_J_;
	Text stats_T_K_;
	Text stats_T_L_;
	Text stats_T_M_;
	Text stats_T_N_;
	Text stats_T_O_;
	Text stats_T_P_;

	HoverDescription stats_D_B_;
	HoverDescription stats_D_C_;
	HoverDescription stats_D_D_;
	HoverDescription stats_D_E_;
	HoverDescription stats_D_G_;
	HoverDescription stats_D_H_;
	HoverDescription stats_D_I_;
	
	Button resistances_B_A_;
	Text resistances_T_A_;
	Text resistances_T_B_;
	Text resistances_T_C_;
	Text resistances_T_D_;
	Text resistances_T_E_;

	Text resistances_T_F_;
	Text resistances_T_G_;
	Text resistances_T_H_;
	Text resistances_T_I_;

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

	ResourceFont resource_Font_;

	bool is_Stats_Visible_;
	bool is_Resistances_Visible_;
};

#endif // !PLAYERINVENTORY_H
