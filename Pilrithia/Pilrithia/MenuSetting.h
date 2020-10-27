#ifndef MENUSETTING_H
#define MENUSETTING_H

#include "Button.h"
#include "Text.h"
#include "Box.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class MenuSetting
{
public:
	MenuSetting(sf::RenderWindow* window);
	~MenuSetting();

	bool updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

private:

private:

};

#endif // !MENUSETTING_H
