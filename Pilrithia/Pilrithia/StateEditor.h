#ifndef STATEEDITOR_H
#define STATEEDITOR_H

#include "State.h"

#include "Camera.h"
#include "Tilemap.h"

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

	//INSTRUCTIONS PANEL
	Box x_A_;
	//RIGHT SIDE BUTTON PANEL
	Box x_B_;

	//MOUSE POSITIONS
	Text t_A_;
	Text t_B_;

	Button b_A_;
	Button b_B_;
	Button b_C_;
	Button b_D_;
	std::vector<Button> panel_Buttons_;

	Text t_C_;
	Text t_E_;
	std::vector<Text> panel_Texts_;

	Box x_C_;
	Text t_D_;
	Text t_F_;
	Text t_G_;
	Text t_H_;
	//INPUT BOX
	Button i_A_;
	Button i_B_;
	Button i_C_;

	//TESTING ONLY
	Camera* camera_;
	Tilemap* tilemap_;
	Text window_Position_;
	Text grid_Position_;
	Box tile_Box_;

};


#endif // !