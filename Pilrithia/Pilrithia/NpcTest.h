#ifndef	NPCTEST_H
#define NPCTEST_H

#include "Npc.h"



class NpcTest 
	: public Npc
{
public:
	NpcTest();
	virtual ~NpcTest();

	void setSettings(const sf::Vector2u& windowSize);

	void updatePollEvent(sf::Event& ev) override;
	void update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera) override;
	void render(sf::RenderTarget& target) override;

private:

private:
	sf::RectangleShape npc_Model_;
	sf::RectangleShape npc_Range_;

	//MAKE CLASSES FOR DIALOG BOX
	DialogBox dialog_Box_;
	QuestBox quest_Box_;

	Camera* camera_;

	bool is_Within_Range_;
};

#endif