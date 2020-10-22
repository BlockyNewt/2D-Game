#ifndef MENUPAUSE_H
#define MENUPAUSE_H

#include "Button.h"
#include "Text.h"
#include "Box.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class MenuPause
{
public:
	MenuPause(sf::RenderWindow* window);
	~MenuPause();

	bool UpdatePollEvent(sf::Event& ev);
	void Update(const sf::Vector2i& mousePositionWindow);
	void Render(sf::RenderTarget& target);

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