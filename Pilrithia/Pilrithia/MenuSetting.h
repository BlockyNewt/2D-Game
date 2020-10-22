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

	bool UpdatePollEvent(sf::Event& ev);
	void Update(const sf::Vector2i& mousePositionWindow);
	void Render(sf::RenderTarget& target);

private:

private:

};

#endif // !MENUSETTING_H
