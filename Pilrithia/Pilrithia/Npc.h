#ifndef NPC_H
#define NPC_H

#include "SFML/Graphics.hpp"

#include "ResourceNpc.h"

#include "Animation.h"

#include "PlayerTest.h"

#include "Quest.h"

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
	Npc(const ResourceFont& resourceFont, const ResourceNpc& resourceNpc);
	virtual ~Npc();

	virtual void setSettings(const sf::Vector2u& windowSize, const ResourceFont& resourceFont) = 0;

	virtual void updatePollEvent(sf::Event& ev, PlayerTest& playerTest) = 0;
	virtual void update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, PlayerTest& playerTest) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	
private:
	virtual void updatePollEventQuest(sf::Event& ev, PlayerTest& playerTest, Quest* quest) = 0;

private:
};

#endif // !NPC_H
