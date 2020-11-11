#ifndef SKILLBUTTON_H
#define SKILLBUTTON_H

#include "CircleButton.h"
#include "Text.h"
#include "HoverDescription.h"

enum class STATNAME
{
	DEFUALT = 0,

	STRENGTH,
	DEXERITY,
	CONSTITUTION,

	INTELLIGENCE,
	PERCEPTION,
	WISDOM
};

class SkillButton
{
public:
	SkillButton();
	~SkillButton();

	void setSettings(float radius, float x, float y, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, const std::string& title, const std::string& description, STATNAME statName, int statIncrease);
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

#endif SKILLBUTTON_H