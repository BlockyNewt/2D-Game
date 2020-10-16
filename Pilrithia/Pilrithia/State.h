#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <stack>

class State
{
public:
	State(std::stack<State*>* states);
	virtual ~State();

	virtual void UpdatePollEvent(sf::Event& ev) = 0;
	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget& target) = 0;

private:

private:
	std::stack<State*>* states_;
};

#endif // !STATE_H
