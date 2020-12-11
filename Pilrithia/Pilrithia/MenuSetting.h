#ifndef MENUSETTING_H
#define MENUSETTING_H

#include "ResourceFont.h"

#include "Button.h"
#include "Text.h"
#include "Box.h"
#include "CheckBox.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class MenuSetting
{
public:
	MenuSetting(sf::RenderWindow* window, const ResourceFont& resourceFont);
	~MenuSetting();

	void updatePollEvent(sf::Event& ev, sf::RenderWindow* window);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void makeAllVisible(bool isInSettings);


	const bool& getIsInSettings() const;

private:
	void repositionGui(sf::RenderWindow* window);

private:
	bool is_In_Settings_;

	Box x_A_;

	Text t_A_;

	Text res_1920x1080_T_A_;
	CheckBox res_1920x1080_C_A_;

	Text res_1600x900_T_A_;
	CheckBox res_1600x900_C_A_;

	Text res_1280x720_T_A_;
	CheckBox res_1280x720_C_A_;


	Text t_B_;
	Button b_B_;
	Text t_C_;
	Button b_C_;

};

#endif // !MENUSETTING_H
