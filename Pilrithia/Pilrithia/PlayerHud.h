#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include "Classes.h"

#include "Camera.h"

#include "ResourceFont.h"
#include "ResourceHud.h"
#include "ResourceRace.h"

#include "DisplayMessage.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"
#include "SkillDropDownList.h"

#include "SkillPoisonRain.h"

#include "Enemy.h"

#include <iostream>	
#include <string>

class PlayerHud
{
public:
	PlayerHud(const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace);
	~PlayerHud();


	//ONLY FOR TESTING
	void intializeHud(const std::string& name, const int& healthMax, const int& health, const int& manaMax, const int& mana, const int& expMax, const int& exp, const sf::Texture& playerRaceIcon);
	void initializeSkills(Classes* playerClass);

	bool updateInventoryPollEvent(sf::Event& ev);
	bool updateBagPollEvent(sf::Event& ev);
	bool updateQuestPollEvent(sf::Event& ev);
	bool updateSkillTreePollEvent(sf::Event& ev);
	bool updateGatherPollEvent(sf::Event& ev);
	void updateSkillOnePollEvent(sf::Event& ev, Classes* playerClass, std::vector<Enemy*>& enemies, const std::map<std::string, int>& playerStats, int& playerMana, bool& playerIsCombat);
	void updatePollEvent(sf::Event& ev, int& health, const int& healthMax);
	void updateNamePosition(const sf::Vector2f& playerPosition);
	void update(const sf::Vector2i& mousePositionWindow, const Camera& camera, const sf::Vector2f& playerPosition, const sf::FloatRect playerBoundaries, std::vector<Enemy*>& enemies, bool& playerIsCombat, bool& isPlayerAttack, bool& isPlayerAttackTextureSet, const sf::FloatRect playerAutoAttackRange);
	void render(sf::RenderTarget& target);

	const float percentToPixel(const float size);

	void setWidthOfBars(const int& healthMax, const int& health, const int& manaMax, const int& mana, const int& expMax, const int& exp);
	Skill& setSkillOne();
	sf::Clock& setLeaveCombatTimer();
	void setPositionOnResize(const sf::RenderWindow* window);


private:
	void skillCooldownBoxHeight();

private:
	Camera* camera_;
	DisplayMessage* display_Message_;

	//MAYBE MAKE GUI FOR THIS LATER (COULD ALSO USE WITH ENEMIES
	sf::RectangleShape health_Bar_Back_;
	sf::RectangleShape health_Bar_Front_;

	sf::RectangleShape mana_Bar_Back_;
	sf::RectangleShape mana_Bar_Front_;

	sf::RectangleShape experience_Bar_Back_;
	sf::RectangleShape experience_Bar_Front_;

	Text health_T_A_;
	Text mana_T_A_;
	Text experience_T_A_;

	Button character_B_A_;
	Button character_B_B_;
	Button character_B_C_;
	Button character_B_D_;
	Button character_B_F_;

	Text character_T_A_;
	Text character_T_B_;
	Text character_T_C_;
	Text character_T_D_;
	Text character_T_E_;
	Text character_T_F_;

	sf::Sprite skill_Hotbar_Sprite_;

	Button skill_B_A_;
	Button skill_B_B_;
	Button skill_B_C_;

	Box skill_X_A_;

	Text skill_T_A_;
	Text skill_T_B_;
	Text skill_T_C_;

	HoverDescription skill_D_A_;


	bool is_Hiding_Hud_;

	unsigned int window_Size_X_;
	unsigned int window_Size_Y_;

	SkillDropDownList skill_Dropdown_List_;

	Skill* skill_One_;

	sf::Clock skill_One_CD_Timer_;

	sf::Clock auto_Attack_Timer_;
	sf::Clock leave_Combat_Timer_;
	

	ResourceFont* resource_Font_;
	ResourceHud* resource_Hud_;

	//TESTING
	sf::Sprite race_Icon_Sprite_;
	sf::Sprite bars_Sprite_;
};

#endif // !PLAYERHUD_H
