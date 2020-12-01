#ifndef STATEEDITOR_H
#define STATEEDITOR_H

#include "State.h"

#include "Camera.h"
#include "Tilemap.h"

class StateEditor 
	: public State
{
public:
	StateEditor(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont = nullptr, ResourceHud* resourceHud = nullptr, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	virtual ~StateEditor();


	void updatePollEvent(sf::Event& ev) override;
	void update() override;
	void render(sf::RenderTarget& target) override;

private:
	void initializeInstructionsPanel();
	void initializeRightSidePanel();
	void initializeTilemapSettings();
	void initializeSave();
	void initializeLoad();

	void instructionsPollEvent(sf::Event& ev);
	void rightPanelPollEvent(sf::Event& ev);
	void tilemapSettingsPollEvent(sf::Event& ev);
	void savePollEvent(sf::Event& ev);
	void loadPollEvent(sf::Event& ev);

private:
	/*
		OTHER
	*/
	Camera* camera_;
	Tilemap* tilemap_;
	Box tile_Box_;


	/*
		MOUSE POSITIONS
	*/
	Text window_Position_;
	Text grid_Position_;
	Text tile_Type_;
	Text tile_Layer_;


	/*
		INSTRUCTIONS PANEL 
	*/
	Box instruction_Panel_X_A_;

	Text t_A_;
	Text t_B_;


	/*
		RIGHT SIDE PANEL
	*/
	Box right_Side_Panel_X_A_;

	Button right_Side_Panel_B_A_;
	Button right_Side_Panel_B_B_;
	Button right_Side_Panel_B_C_;
	Button right_Side_Panel_B_D_;
	Button right_Side_Panel_B_E_;
	std::vector<Button> right_Side_Panel_Buttons_;

	Text right_Side_Panel_T_A_;
	Text right_Side_Panel_T_B_;
	Text right_Side_Panel_T_C_;
	Text right_Side_Panel_T_D_;
	Text right_Side_Panel_T_E_;
	std::vector<Text> right_Side_Panel_Texts_;


	/*
		TILE MAP SETTINGS
	*/
	Box tilemap_Settings_X_A_;

	Button tilemap_Settings_B_A_;
	Button tilemap_Settings_B_B_;

	Text tilemap_Settings_T_A_;
	Text tilemap_Settings_T_B_;
	Text tilemap_Settings_T_C_;
	Text tilemap_Settings_T_D_;
	Text tilemap_Settings_T_E_;
	Text tilemap_Settings_T_F_;
	Text tilemap_Settings_T_G_;
	
	InputBox tilemap_Settings_I_A_;
	InputBox tilemap_Settings_I_B_;
	InputBox tilemap_Settings_I_C_;

	CheckBox tilemap_Settings_C_A_;


	/*
		SAVE BOX
	*/
	Box save_X_A_;

	Button save_B_A_;
	Button save_B_B_;

	Text save_T_A_;
	Text save_T_B_;
	Text save_T_C_;
	Text save_T_D_;

	InputBox save_I_A_;


	/*
		LOAD BOX
	*/
	Box load_X_A_;

	Button load_B_A_;
	Button load_B_B_;

	Text load_T_A_;
	Text load_T_B_;
	Text load_T_C_;
	Text load_T_D_;
	Text load_T_E_;

	InputBox load_I_A_;
	InputBox load_I_B_;

	/*
		TEXTURE SELECTOR
	*/
	Box texture_X_A_;

	Box texture_Box_;

};


#endif // !