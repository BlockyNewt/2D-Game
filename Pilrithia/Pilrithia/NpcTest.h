#ifndef	NPCTEST_H
#define NPCTEST_H

#include "Npc.h"

class NpcTest 
	: public Npc
{
public:
	NpcTest();
	virtual ~NpcTest();

	void updatePollEvent(sf::Event& ev) override;
	void update(sf::FloatRect playerBounds) override;
	void render(sf::RenderTarget& target) override;

private:

private:
	sf::RectangleShape npc_Model_;
	sf::RectangleShape npc_Range_;
};

#endif