#ifndef NPC_H
#define NPC_H

#include "SFML/Graphics.hpp"

#include "PlayerTest.h"

#include <iostream>
#include <string>

class Npc
{
public:
	Npc();
	virtual ~Npc();

	virtual void updatePollEvent(sf::Event& ev) = 0;
	virtual void update(sf::FloatRect playerBounds) = 0;
	virtual void render(sf::RenderTarget& target) = 0;


private:

private:
};

#endif // !NPC_H
