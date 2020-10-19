#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include "State.h"

class StateMainMenu
	: public State
{
public:
	StateMainMenu(std::stack<State*>* states, sf::RenderWindow* window);
	virtual ~StateMainMenu();

	void UpdatePollEvent(sf::Event& ev) override;
	void Update() override;
	void Render(sf::RenderTarget& target) override;

private:

private:
	Button b_1_;
	Text t_1_;

};

#endif