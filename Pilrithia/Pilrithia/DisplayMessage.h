#ifndef DISPLAYMESSAGE_H
#define DISPLAYMESSAGE_H

#include "Text.h"

#include "ResourceFont.h"

#include <iostream>
#include <string>

class DisplayMessage
{
public:
	DisplayMessage(const sf::Window* window, const ResourceFont& resourceFont);
	~DisplayMessage();

	void updateLevelUp(const std::string& playerLevel);
	void updateBagFull();
	void updateLeftCombat(); 

	void render(sf::RenderTarget& target);

	void setIsLevelingUp(bool isLevelingUp);

	const bool& getIsLevelingUp() const;

private:

private:
	sf::Clock level_Up_display_Timer_;
	sf::Clock adding_Item_To_Bag_display_Timer_;
	sf::Clock left_Combat_Display_Timer_;
	float time_;

	Text level_Up_Text_;
	Text adding_Item_To_Bag_Text_;
	Text left_Combat_Text_;

	bool is_Leveling_Up_;
	bool is_Adding_Item_To_Bag_;
	bool has_Left_Combat_;
};

#endif // !DISPLAYMESSAGE_H
