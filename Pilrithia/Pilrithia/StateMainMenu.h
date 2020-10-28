#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include "StateEditor.h"
#include "StateTestZone.h"

class StateMainMenu
	: public State
{
public:
	StateMainMenu(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	virtual ~StateMainMenu();

	void updatePollEvent(sf::Event& ev) override;
	void update() override;
	void render(sf::RenderTarget& target) override;

private:

private:
	Button b_B_; 
	Button b_C_;
	Button b_D_;
	Button b_E_;
	Button b_F_;
	Button b_G_;
	std::vector<Button> buttons_;

	Text t_A_;
	Text t_B_;
	Text t_C_;
	Text t_D_;
	Text t_E_;
	Text t_F_;
	Text t_G_;
	std::vector<Text> texts_;
};

#endif