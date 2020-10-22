#ifndef STATEEDITOR_H
#define STATEEDITOR_H

#include "State.h"

class StateEditor 
	: public State
{
public:
	StateEditor(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	virtual ~StateEditor();

	void UpdatePollEvent(sf::Event& ev) override;
	void Update() override;
	void Render(sf::RenderTarget& target) override;

private:

private:

	Box x_A_;
	Box x_B_;

	Text t_A_;

	Button b_A_;
	Button b_B_;
	Button b_C_;
	Button b_D_;
	std::vector<Button> buttons_;
};


#endif // !