#ifndef STATBUTTON_H
#define STATBUTTON_H

#include "SFML/Graphics.hpp"

#include "Text.h"
#include "HoverDescription.h"

#include <iostream>
#include <string>

enum class STATNAME
{
	DEFUALT = 0,

	HEALTH,
	MANA,

	STRENGTH,
	DEXERITY,
	CONSTITUTION,

	INTELLIGENCE,
	PERCEPTION,
	WISDOM,

	CLASSES
};

class StatButton
{
public:

	StatButton();
	~StatButton();

	void setSettings(float radius, float x, float y, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, STATNAME statName, int statIncrease);
	void manageStatAllocation(bool pOrM, std::map<std::string, int>& stats);

	void updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;

private:

private:
	//AMOUNT OF POINTS YOU CAN PUT INTO THE SKILL
	int max_Amount_;
	int amount_;
	//HOW MUCH ONE POINT INVESTMENT WILL INCREASE THE STAT
	int stat_Increase_;

	int cost_;

	//CircleButton c_A_;
	sf::CircleShape button_;

	Text t_A_;

	HoverDescription h_A_;

	sf::Color fill_Color_;

	STATNAME stat_Name_;

	bool is_Hovering_;

};

#endif // !STATBUTTON_H
