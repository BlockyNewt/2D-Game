#ifndef SKILLBUTTON_H
#define SKILLBUTTON_H

#include "CircleButton.h"
#include "Text.h"
#include "HoverDescription.h"

class SkillButton
{
public:
	SkillButton();
	~SkillButton();

	void setSettings(float radius, float x, float y, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, int maxAllocation);
	void setHoverDescription(const std::string& skillName, const std::string& skillSummary);

	void updatePollEvent(sf::Event& ev, int& playerSkillPoints);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	const int& getAmount() const;
	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;

private:

private:
	//AMOUNT OF POINTS YOU CAN PUT INTO THE SKILL
	int max_Amount_;
	int amount_;

	//CircleButton c_A_;
	sf::CircleShape button_;

	Text t_A_;

	HoverDescription h_A_;

	sf::Color fill_Color_;

	bool is_Hovering_;
};

#endif SKILLBUTTON_H