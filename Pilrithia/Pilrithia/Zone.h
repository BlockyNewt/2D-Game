#ifndef ZONE_H
#define ZONE_H

#include "PlayerTest.h"

#include "Tilemap.h"
#include "Camera.h"

#include "ResourceEnemy.h"
#include "ResourceNpc.h"

#include "Npc.h"
#include "NpcTest.h"

#include "Merchant.h"
#include "MerchantTest.h"

#include "Gather.h"
#include "GatherTest.h"

class Zone
{
public:
	Zone();
	Zone(sf::RenderWindow* window, ResourceFont* resourceFont, ResourceEnemy* resourceEnemy, ResourceNpc* resourceNpc, ResourceItem* resourceItem, ResourceHud* resourceHud);
	virtual ~Zone();

	virtual void zoneUpdatePollEvent(sf::Event& ev, PlayerTest* playerTest) = 0;
	virtual void zoneUpdate(const sf::Vector2i& mousePositionWindow, Camera** camera, PlayerTest* playerTest, const float& dt) = 0;
	virtual void zoneRender(sf::RenderTarget& target) = 0;

private:
	virtual void updateEnemies(const sf::Vector2i& mousePositionWindow, Camera** camera, PlayerTest* playerTest, const float& dt) = 0;
	virtual void updateGather(const sf::Vector2i& mousePositionWindow, PlayerTest* playerTest) = 0;

private:

};

#endif