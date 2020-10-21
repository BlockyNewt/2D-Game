#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

#include "Button.h"
#include "Text.h"
#include "Box.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class State
{
public:
	State(std::stack<State*>* states, sf::RenderWindow* window);
	virtual ~State();

	virtual void UpdatePollEvent(sf::Event& ev) = 0;
	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget& target) = 0;

	void UpdateMousePosition();

protected:
	std::stack<State*>* states_;
	sf::Vector2i mouse_Position_Window_;
	sf::RenderWindow* window_;

private:

private:
};

#endif // !STATE_H
