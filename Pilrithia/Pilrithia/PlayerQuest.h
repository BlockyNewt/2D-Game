#ifndef PLAYERQUEST_H
#define PLAYERQUEST_H

#include "SFML/Graphics.hpp"

#include "ResourceHud.h"

#include "Quest.h"
#include "QuestTest.h"

#include "Button.h"
#include "Box.h"

#include <iostream>
#include <string>
#include <vector>

class PlayerQuest
{
public:
	PlayerQuest(const sf::RenderWindow* window, const ResourceFont& resourceFont, const ResourceHud& resourceHud);
	~PlayerQuest();


	bool isThisQuestTaken(Quest& quest);
	void addQuest(Quest& quest);

	void updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingQuest(bool isHidingQuest);
	Quest* setSelectedQuest();
	void setPositionOnResize(const sf::RenderWindow* window);

	const bool& getIsHidingQuest() const;
	const std::vector<Quest*>& getQuest() const;
	const Quest* getSelectedQuest() const;

private:

private:
	Box x_B_;

	Button b_B_;

	Text t_A_;

	int max_Quest_;
	int current_Quest_;
	

	std::vector<Quest*> quests_;

	bool is_Hiding_Quest_;

	Quest* selected_Quest_;

	sf::Sprite quest_Background_Sprite_;
};

#endif // !
