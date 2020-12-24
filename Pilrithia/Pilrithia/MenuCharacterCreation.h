#ifndef MENUCHARACTERCREATION_H
#define MENUCHARACTERCREATION_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"
#include "ResourceHud.h"
#include "ResourceRace.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "InputBox.h"
#include "HoverDescription.h"

#include "Race.h"
#include "RaceOrc.h"



class MenuCharacterCreation
{
public:
	MenuCharacterCreation(sf::Vector2u windowSize, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace);
	~MenuCharacterCreation();

	void updateRacePollEvent(sf::Event& ev);
	bool updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsCreatingCharacter(bool isCreatingCharacter);
	void setObjectsBasedOnRace();

	const bool& getIsCreatingCharacter() const;
	Race& getRace() const;
	const std::string& getName() const;

	void repositionGui(const sf::RenderWindow* window);


private:
	void initializeNameGui(ResourceFont* resourceFont, ResourceHud* resourceHud);
	void initializeRaceGui(ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace);

private:
	//TESTING 
	Race* race_;
	RaceOrc race_Orc_;

	sf::RectangleShape race_Model_;



	Text title_T_A_;

	Box background_X_A_;
	Box model_Preview_X_A_;
	Box race_X_A_;
	Box class_X_A_;

	//NAME
	Button name_B_B_;

	Text name_T_A_;
	Text name_T_B_;

	InputBox name_I_A_;

	//RACE
	sf::Sprite race_A_Sprite_;
	sf::Sprite race_B_Sprite_;
	sf::Sprite race_C_Sprite_;
	sf::Sprite race_D_Sprite_;
	sf::Sprite race_E_Sprite_;

	Button race_B_A_;
	Button race_B_B_;
	Button race_B_C_;
	Button race_B_D_;
	Button race_B_E_;

	Text race_T_A_;
	Text race_T_B_;
	Text race_T_C_;
	Text race_T_D_;
	Text race_T_E_;
	Text race_T_F_;
	Text race_T_G_;


	ResourceRace* resource_Race_;

	bool is_Creating_Character_;
};

#endif // !MENUCHARACTERCREATION_H
