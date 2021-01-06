#ifndef ZONETEST_H
#define ZONETEST_H

#include "Zone.h"	

class ZoneTest 
	: public Zone
{
public:
	ZoneTest();
	ZoneTest(sf::RenderWindow* window, ResourceFont* resourceFont, ResourceEnemy* resourceEnemy, ResourceNpc* resourceNpc, ResourceItem* resourceItem, ResourceHud* resourceHud);
	virtual ~ZoneTest();

	void zoneUpdatePollEvent(sf::Event& ev, PlayerTest* playerTest) override;
	void zoneUpdate(const sf::Vector2i& mousePositionWindow, Camera** camera, PlayerTest* playerTest, const float& dt) override;
	void zoneRender(sf::RenderTarget& target) override;

private:
	void updateEnemies(const sf::Vector2i& mousePositionWindow, Camera** camera, PlayerTest* playerTest, const float& dt) override;
	void updateGather(const sf::Vector2i& mousePositionWindow, PlayerTest* playerTest) override;

private:
	Tilemap* tilemap_;
	sf::RenderWindow* window_;
	ResourceFont* resource_Font_;
	ResourceEnemy* resource_Enemy_;
	ResourceItem* resource_Item_;
	ResourceHud* resource_Hud_;

	NpcTest* npc_Test_;
	EnemyTest* enemy_Test_;
	Merchant* merchant_Test_;

	/*Gather* gather_Test_;
	Gather* gather_Test_One_;
	Gather* gather_Test_Two_;*/
	std::vector<Gather*> gathers_;
	int gather_Type_Increment_;

	int max_Enemies_;
	std::vector<Enemy*> enemies_;

	sf::RectangleShape teleporter_Rec_;
};

#endif // !ZONETEST_H
