#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

#include "MenuPause.h"
#include "MenuSetting.h"

class State
{
public:
	State(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting = nullptr, MenuPause* menuPause = nullptr);
	virtual ~State();

	virtual void updatePollEvent(sf::Event& ev) = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	void updateMousePosition(const sf::View* view, const float tileSizeXY = 1.f);

protected:
	std::stack<State*>* states_;
	
	sf::Vector2i mouse_Position_Window_;
	sf::Vector2f mouse_Position_View_;
	sf::Vector2u mouse_Position_Grid_;

	sf::RenderWindow* window_;

	MenuPause* menu_Pause_;
	MenuSetting* menu_Setting_;
private:

private:
};

#endif // !STATE_H
