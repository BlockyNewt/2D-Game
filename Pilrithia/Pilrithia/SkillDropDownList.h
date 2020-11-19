#ifndef SKILLDROPDOWNLIST_H
#define SKILLDROPDOWNLIST_H

#include "SFML/Graphics.hpp"

#include "Classes.h"

#include "Button.h"
#include "Text.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class SkillDropDownList
{
public:
	SkillDropDownList();
	~SkillDropDownList();

	void setSettings(const sf::FloatRect itemBoundaries, Classes* playerClasses);

	void updatePollEvent(sf::Event& ev, Classes* playerClasses, Skill** hudSkillSlot);
	void update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries);
	void render(sf::RenderTarget& target);


	void setIsVisible(bool isVisible);

	const bool& getIsVisible() const;

private:

private:
	bool is_Visible_;
	bool is_Hovering_;

	std::vector<Button*> buttons_;
	std::vector<Text*> texts_;


};

#endif // !SKILLDROPDOWNLIST_H]
