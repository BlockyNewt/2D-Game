#ifndef ENGINE_H
#define ENGINE_H

#include "State.h"
#include "StateMainMenu.h"

class Engine
{
public:
	Engine();
	~Engine();

	void run();

private:
	void updatePollEvent();
	void update();
	void render();

private:
	sf::VideoMode vm_;
	sf::RenderWindow* window_;
	sf::Event ev_;

	std::stack<State*> states_;

};

#endif // !ENGINE_H
