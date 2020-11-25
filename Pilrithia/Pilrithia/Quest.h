#ifndef QUEST_H
#define QUEST_H

#include "Text.h"

#include "Enemy.h"
#include "EnemyTest.h"

#include "ResourceFont.h"

#include <iostream>
#include <string>

enum class QUESTNAME
{
	DEFAULT = 0,
	TEST,

};

enum class QUESTTYPE
{
	DEFAULT = 0,
	KILL,
	SPEAKTOSAMENPC,
	SPEAKTODIFFERENTNPC,

};

class Quest
{
public:
	Quest();
	Quest(const ResourceFont& resourceFont);
	virtual ~Quest();

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual void wrapText(const sf::FloatRect boundaries) = 0;

	virtual void setKillCount() = 0;
	virtual void setTextPosition(float posX, float posY) = 0;
	virtual void setIsQuestTaken(bool isQuestTaken) = 0;
	virtual void setIsTaskCompleted(bool isTaskCompleted) = 0;
	virtual void setIsQuestTurnedIn(bool isQuestTurnedIn) = 0;
	virtual void setTargetNpcName(const std::string& npcName) = 0;

	virtual const Text& getText() const = 0;
	virtual const QUESTNAME& getQuestName() const = 0;
	virtual const bool& getIsQuestTaken() const = 0;
	virtual const std::string& getQuestTitle() const = 0;
	virtual const std::string& getQuestSummary() const = 0;
	virtual const std::string& getQuestFinishedSummary() const = 0;
	virtual const bool& getIsTaskCompleted() const = 0;
	virtual const bool& getIsQuestTurnedIn() const = 0;
	virtual const QUESTTYPE& getQuestType() const = 0;
	virtual const std::string& getTargetNpcName() const = 0;

};

#endif // !QUEST_H
