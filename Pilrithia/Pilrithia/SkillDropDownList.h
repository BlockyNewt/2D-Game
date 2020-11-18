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

	void updatePollEvent(sf::Event& ev, Classes* playerClasses, Skill** hudSkillOne);
	void update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries);
	void render(sf::RenderTarget& target);


	void setIsVisible(bool isVisible);

private:

private:
	Button b_A_;
	Text t_A_;

	bool is_Visible_;
	bool is_Hovering_;


};

#endif // !SKILLDROPDOWNLIST_H]
