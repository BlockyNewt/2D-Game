#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"
#include "ResourceHud.h"
#include "ResourceRace.h"
#include "ResourceItem.h"
#include "ResourceEnemy.h"
#include "ResourceNpc.h"

#include "MenuPause.h"
#include "MenuSetting.h"

class State
{
public:
	State(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont = nullptr, ResourceHud* resourceHud = nullptr, ResourceRace* resourceRace = nullptr, ResourceItem* resourceItem = nullptr, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	/*State(std::stack<State*>* states, sf::RenderWindow* window, ResourceFont* resourceFont = nullptr, ResourceHud* resourceHud = nullptr, ResourceRace* resourceRace = nullptr, ResourceItem* resourceItem = nullptr, ResourceEnemy* resourceEnemy = nullptr, ResourceNpc* resourceNpc = nullptr, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);*/
	virtual ~State();

	virtual void updatePollEvent(sf::Event& ev) = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	void updateMousePosition(const sf::View* view, const float tileSizeXY = 1.f);
	void updateTextureMousePosition(const sf::View* view, const float tileSizeXY = 1.f);
	void updateDeltaClock();

	const float percentToPixelX(const float sizeX);
	const float percentToPixelY(const float sizeY);

protected:
	std::stack<State*>* states_;
	
	sf::Vector2i mouse_Position_Window_;
	sf::Vector2f mouse_Position_View_;
	sf::Vector2u mouse_Position_Grid_;
	sf::Vector2u mouse_Position_Texture_Grid_;

	sf::RenderWindow* window_;

	MenuPause* menu_Pause_;
	MenuSetting* menu_Setting_;

	float dt_;

	ResourceFont* resource_Font_;
	ResourceHud* resource_Hud_;
	ResourceRace* resource_Race_;
	ResourceItem* resource_Item_;
	ResourceEnemy* resource_Enemy_;
	ResourceNpc* resource_Npc_;

private:

private:
	sf::Clock dt_Clock_;

};

#endif // !STATE_H
