#ifndef STATETESTZONE_H
#define STATETESTZONE_H

#include "State.h"

#include "Tilemap.h"
#include "Camera.h"

#include "PlayerTest.h"

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

private:
	Box load_X_A_;

	Button load_B_A_;
	Button load_B_B_;

	Text load_T_A_;
	Text load_T_B_;
	Text load_T_C_;
	Text load_T_D_;

	InputBox load_I_A_;

	Tilemap* tilemap_;
	Camera* camera_;

	//TESTING
	PlayerTest player_Test_;
};

#endif // !STATETESTZONE_H
