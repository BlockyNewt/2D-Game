#ifndef STATEEDITOR_H
#define STATEEDITOR_H

#include "MenuPause.h"

class StateEditor 
	: public State
{
public:
	StateEditor(std::stack<State*>* states, sf::RenderWindow* window);
	virtual ~StateEditor();

	void UpdatePollEvent(sf::Event& ev) override;
	void Update() override;
	void Render(sf::RenderTarget& target) override;

private:

private:
	MenuPause menu_Pause_;

	Box x_A_;

	Text t_A_;
};


#endif // !