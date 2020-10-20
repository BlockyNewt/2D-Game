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
	Button b_B_, b_C_;
	std::vector<Button> buttons_;

	Text t_A_;
	Text t_B_, t_C_;
	std::vector<Text> texts_;
};

#endif