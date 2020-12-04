#ifndef STATETESTZONE_H
#define STATETESTZONE_H

#include "State.h"

#include "Tilemap.h"
#include "Camera.h"

#include "MenuCharacterCreation.h"
#include "PlayerTest.h"

#include "Npc.h"
#include "NpcTest.h"

#include "Merchant.h"
#include "MerchantTest.h"

#include "Gather.h"
#include "GatherTest.h"

class StateTestZone
	: public State
{
public:
	StateTestZone(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont = nullptr, ResourceHud* resourceHud = nullptr, ResourceRace* resourceRace = nullptr, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	virtual ~StateTestZone();
	
	void updatePollEvent(sf::Event& ev) override;
	void update() override;
	void render(sf::RenderTarget& target) override;

private:
	void updateLoadPollEvent(sf::Event& ev);
	void updateCharacterCreationPollEvent(sf::Event& ev);

	void updateEnemy();
	void updateCharacterCreation();
	void updateLoadTilemap();


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



	/*
		OTHER
	*/
	Tilemap* tilemap_;
	Camera* camera_;


	//TESTING
	MenuCharacterCreation* menu_Character_Creation_;
	PlayerTest* player_Test_;
	NpcTest* npc_Test_;
	EnemyTest* enemy_Test_;
	EnemyTest* enemy_Test_One_;
	Merchant* merchant_Test_;
	Gather* gather_Test_;

	int max_Enemies_;
	std::vector<Enemy*> enemies_;
};

#endif // !STATETESTZONE_H
