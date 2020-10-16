#ifndef ENGINE_H
#define ENGINE_H

#include "State.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Run();

private:
	void UpdatePollEvent();
	void Update();
	void Render();

private:
	sf::VideoMode vm_;
	sf::RenderWindow* window_;
	sf::Event ev_;

	//MAKE STACK HERE LATER FOR STATES
	std::stack<State*> states_;

};

#endif // !ENGINE_H
