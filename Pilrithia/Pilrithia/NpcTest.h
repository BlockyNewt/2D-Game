#ifndef	NPCTEST_H
#define NPCTEST_H

#include "Npc.h"

#include "QuestTest.h"


class NpcTest 
	: public Npc
{
public:
	NpcTest();
	NpcTest(const sf::RenderWindow* window, const ResourceFont& resourceFont, const ResourceNpc& resourceNpc);
	virtual ~NpcTest();

	void setSettings(const sf::Vector2u& windowSize, const ResourceFont& resourceFont);

	void updatePollEvent(sf::Event& ev, PlayerTest& playerTest) override;
	void update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, PlayerTest& playerTest) override;
	void render(sf::RenderTarget& target) override;

private:
	void updatePollEventQuest(sf::Event& ev, PlayerTest& playerTest, Quest* quest) override;

private:
	sf::RectangleShape npc_Model_;
	sf::RectangleShape npc_Range_;

	DialogBox dialog_Box_;
	QuestBox quest_Box_;

	Text name_;

	Camera* camera_;

	bool is_Within_Range_;

	std::string dialog_Box_Str_;

	std::string npc_Name_;

	//TESTING
	Quest* quest_;

	Animation animation_;

	sf::IntRect idle_Rect_;

	int idle_Sheet_Width_;
};

#endif