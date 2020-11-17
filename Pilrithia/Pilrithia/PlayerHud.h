#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include "Race.h"

#include "Camera.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"

#include <iostream>	
#include <string>

class PlayerHud
{
public:
	PlayerHud(unsigned int windowSizeX, unsigned int windowSizeY);
	~PlayerHud();

	//ONLY FOR TESTING
	void intializeHud(const std::string& name, const Classes* classes, const int& healthMax, const int& health, const int& manaMax, const int& mana);

	bool updateInventoryPollEvent(sf::Event& ev);
	bool updateBagPollEvent(sf::Event& ev);
	bool updateQuestPollEvent(sf::Event& ev);
	bool updateSkillTreePollEvent(sf::Event& ev);
	bool updateSkillOnePollEvent(sf::Event& ev);
	void updatePollEvent(sf::Event& ev, int& health, const int& healthMax);
	void updateNamePosition(const sf::Vector2f& playerPosition);
	void update(const sf::Vector2i& mousePositionWindow, const Camera& camera, const sf::Vector2f& playerPosition);
	void render(sf::RenderTarget& target);

	void setWidthOfBars(const int& healthMax, int& health, const int& manaMax, int& mana, const int& expMax, int& exp);

	const float percentToPixel(const float size);

private:

private:
	Camera* camera_;

	//MAYBE MAKE GUI FOR THIS LATER (COULD ALSO USE WITH ENEMIES
	sf::RectangleShape health_Bar_Back_;
	sf::RectangleShape health_Bar_Front_;

	sf::RectangleShape mana_Bar_Back_;
	sf::RectangleShape mana_Bar_Front_;

	sf::RectangleShape experience_Bar_Back_;
	sf::RectangleShape experience_Bar_Front_;

	Button character_B_A_;
	Button character_B_B_;
	Button character_B_C_;
	Button character_B_D_;

	Text character_T_A_;
	Text character_T_B_;
	Text character_T_C_;
	Text character_T_D_;
	Text character_T_E_;

	Button skill_B_A_;
	Button skill_B_B_;
	Button skill_B_C_;

	Text skill_T_A_;
	Text skill_T_B_;
	Text skill_T_C_;

	HoverDescription skill_D_A_;

	HoverDescription experience_D_A_;

	bool is_Hiding_Hud_;

	unsigned int window_Size_X_;
	unsigned int window_Size_Y_;
};

#endif // !PLAYERHUD_H
