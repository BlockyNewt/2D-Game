#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include "Camera.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"

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

	void updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingInventory(bool isHidingInventory);

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

	HoverDescription stats_D_B_;
	HoverDescription stats_D_C_;
	HoverDescription stats_D_D_;
	HoverDescription stats_D_E_;
	HoverDescription stats_D_F_;
	HoverDescription stats_D_G_;
	
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

};

#endif // !PLAYERINVENTORY_H
