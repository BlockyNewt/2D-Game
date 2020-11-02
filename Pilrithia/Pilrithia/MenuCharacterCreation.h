#ifndef MENUCHARACTERCREATION_H
#define MENUCHARACTERCREATION_H

#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "InputBox.h"

#include "Race.h"
#include "RaceOrc.h"
#include "RaceHuman.h"

class MenuCharacterCreation
{
public:
	MenuCharacterCreation(const unsigned int windowSizeX, const unsigned int windowSizeY);
	~MenuCharacterCreation();

	bool updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);


	void setIsCreatingCharacter(bool isCreatingCharacter);

	const bool& getIsCreatingCharacter() const;
	Race& getRace() const;

private:

private:
	//TESTING 
	Race* race_;
	RaceOrc race_Orc_;
	RaceHuman race_Human_;

	sf::RectangleShape race_Model_;

	Box x_A_;
	Box x_B_;
	Box x_C_;
	Box x_D_;

	Text t_A_;
	Text t_B_;
	Text t_C_;
	Text t_D_;
	Text t_E_;
	Text t_F_;
	Text t_G_;
	Text t_H_;
	Text t_I_;
	Text t_J_;

	InputBox i_A_;

	Button b_A_;
	Button b_B_;
	Button b_C_;
	Button b_D_;
	Button b_E_;
	Button b_F_;


	bool is_Creating_Character_;

};

#endif // !MENUCHARACTERCREATION_H
