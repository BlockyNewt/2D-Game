#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include "SFML/Graphics.hpp"

#include "Camera.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"

#include <iostream>	


class PlayerHud
{
public:
	PlayerHud();
	~PlayerHud();

	void updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow, const Camera& camera);
	void render(sf::RenderTarget& target);

private:

private:
	Camera* camera_;

	//MAYBE MAKE GUI FOR THIS LATER (COULD ALSO USE WITH ENEMIES
	sf::RectangleShape health_Bar_Back_;
	sf::RectangleShape health_Bar_Front_;

	sf::RectangleShape mana_Bar_Back_;
	sf::RectangleShape mana_Bar_Front_;

	Button character_B_A_;
	Button character_B_B_;
	Button character_B_C_;
	Button character_B_D_;

	Text character_T_A_;
	Text character_T_B_;
	Text character_T_C_;
	Text character_T_D_;

	Button skill_B_A_;
	Button skill_B_B_;
	Button skill_B_C_;

	Text skill_T_A_;
	Text skill_T_B_;
	Text skill_T_C_;

	bool is_Hiding_Hud_;
};

#endif // !PLAYERHUD_H
