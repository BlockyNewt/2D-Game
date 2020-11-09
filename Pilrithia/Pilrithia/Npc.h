#ifndef NPC_H
#define NPC_H

#include "SFML/Graphics.hpp"

#include "PlayerTest.h"

#include "DialogBox.h"
#include "QuestBox.h"
#include "Camera.h"

#include <iostream>
#include <string>
#include <vector>

class Npc
{
public:
	Npc();
	virtual ~Npc();

	virtual void updatePollEvent(sf::Event& ev, PlayerTest& playerTest) = 0;
	virtual void update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, PlayerTest& playerTest) = 0;
	virtual void render(sf::RenderTarget& target) = 0;


private:

private:
};

#endif // !NPC_H
