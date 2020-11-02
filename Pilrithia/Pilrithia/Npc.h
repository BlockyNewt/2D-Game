#ifndef NPC_H
#define NPC_H

#include "SFML/Graphics.hpp"

#include "DialogBox.h"
#include "QuestBox.h"
#include "Camera.h"

#include <iostream>
#include <string>

class Npc
{
public:
	Npc();
	virtual ~Npc();

	virtual void updatePollEvent(sf::Event& ev) = 0;
	virtual void update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera) = 0;
	virtual void render(sf::RenderTarget& target) = 0;


private:

private:
};

#endif // !NPC_H
