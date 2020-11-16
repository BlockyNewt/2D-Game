#ifndef STATETESTZONE_H
#define STATETESTZONE_H

#include "State.h"

#include "Tilemap.h"
#include "Camera.h"

#include "MenuCharacterCreation.h"
#include "PlayerTest.h"

#include "Npc.h"
#include "NpcTest.h"

#include "EnemyTest.h"

class StateTestZone
	: public State
{
public:
	StateTestZone(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	virtual ~StateTestZone();
	
	void updatePollEvent(sf::Event& ev) override;
	void update() override;
	void render(sf::RenderTarget& target) override;

private:
	void updateLoadPollEvent(sf::Event& ev);
	void updateCharacterCreationPollEvent(sf::Event& ev);


private:
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

	InputBox load_I_A_;


	Box character_Creation_X_A_;

	Button character_Creation_B_B_;
	Button character_Creation_B_C_;
	
	Text character_Creation_T_A_;
	Text character_Creation_T_B_;
	Text character_Creation_T_C_;



	/*
		OTHER
	*/
	Tilemap* tilemap_;
	Camera* camera_;


	//TESTING
	MenuCharacterCreation* menu_Character_Creation_;
	PlayerTest player_Test_;
	NpcTest npc_Test_;
	EnemyTest enemy_Test_;
};

#endif // !STATETESTZONE_H
