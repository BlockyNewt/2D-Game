#ifndef MENUPAUSE_H
#define MENUPAUSE_H

#include "ResourceFont.h"

#include "Button.h"
#include "Text.h"
#include "Box.h"
#include "InputBox.h"
#include "CheckBox.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class MenuPause
{
public:
	MenuPause(sf::RenderWindow* window, const ResourceFont& resourceFont);
	~MenuPause();

	bool updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setPositionOnResize(const sf::RenderWindow* window);

	const bool& getIsPaused() const;

private:

private:
	bool is_Paused_;
	
	Box x_A_;

	Button b_B_;
	Button b_C_;
	std::vector<Button>buttons_;

	Text t_A_;
	Text t_B_;
	Text t_C_;
	std::vector<Text>texts_;
};


#endif // !MENUPAUSE_H