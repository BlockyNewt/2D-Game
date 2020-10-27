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


	void updatePollEvent(sf::Event& ev) override;
	void update() override;
	void render(sf::RenderTarget& target) override;

private:
	void initializeInstructionsPanel();
	void initializeRightSidePanel();
	void initializeTilemapSettings();

	void instructionsPollEvent(sf::Event& ev);
	void rightPanelPollEvent(sf::Event& ev);
	void tilemapSettingsPollEvent(sf::Event& ev);

private:

	//INSTRUCTIONS PANEL
	Box instruction_Panel_X_A_;


	//MOUSE POSITIONS
	Text t_A_;
	Text t_B_;



	//RIGHT SIDE PANEL
	Box right_Side_Panel_X_A_;

	Button right_Side_Panel_B_A_;
	Button right_Side_Panel_B_B_;
	Button right_Side_Panel_B_C_;
	Button right_Side_Panel_B_D_;
	std::vector<Button> right_Side_Panel_Buttons_;

	Text right_Side_Panel_T_A_;
	Text right_Side_Panel_T_B_;
	Text right_Side_Panel_T_C_;
	Text right_Side_Panel_T_D_;
	std::vector<Text> right_Side_Panel_Texts_;




	//TILE MAP SETTINGS
	Box tilemap_Settings_X_A_;

	Button tilemap_Settings_B_A_;
	Button tilemap_Settings_B_B_;

	Text tilemap_Settings_T_A_;
	Text tilemap_Settings_T_B_;
	Text tilemap_Settings_T_C_;
	Text tilemap_Settings_T_D_;
	Text tilemap_Settings_T_E_;
	Text tilemap_Settings_T_F_;
	
	InputBox tilemap_Settings_I_A_;
	InputBox tilemap_Settings_I_B_;
	InputBox tilemap_Settings_I_C_;

	//TESTING ONLY
	Camera* camera_;
	Tilemap* tilemap_;
	Text window_Position_;
	Text grid_Position_;
	Box tile_Box_;

};


#endif // !