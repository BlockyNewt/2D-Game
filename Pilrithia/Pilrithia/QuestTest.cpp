#include "QuestTest.h"

QuestTest::QuestTest()
{
	this->quest_Title_ = "Test";
	this->quest_Summary_ = "This is the quest box. You can view here what a quest requires and what the reward is. Accept it and then talk to me again to turn it in.";
	this->quest_Finish_Summary_ = "You have completed your first quest, CONGRATULATIONS!";

	this->t_A_.setSettings("Font/arial.ttf", 18, this->quest_Title_ + "\n" + this->quest_Summary_, sf::Vector2f(0.f, 0.f), true);

	this->max_Kill_Count_ = 0;
	this->current_Kill_Count_ = 0;
	
	this->is_Task_Completed_ = false;

	this->is_Quest_Turned_In_ = false;

	this->is_Quest_Taken_ = false;

	this->quest_Name_ = QUESTNAME::TEST;
	this->quest_Type_ = QUESTTYPE::SPEAKTOSAMENPC;
	//this->quest_Type_ = QUESTTYPE::SPEAKTODIFFERENTNPC;
}

QuestTest::~QuestTest()
{
}

void QuestTest::update()
{
	if (!this->is_Quest_Turned_In_)
	{
		this->is_Task_Completed_ = true;
	}
	else
	{
		this->t_A_.setString("Completed");
	}
}

void QuestTest::render(sf::RenderTarget& target)
{
	this->t_A_.render(target);
}

void QuestTest::wrapText(const sf::FloatRect boundaries)
{
	this->t_A_.wrapText(boundaries);
}

void QuestTest::setKillCount()
{
	this->current_Kill_Count_++;
}

void QuestTest::setTextPosition(float posX, float posY)
{
	this->t_A_.setPosition(posX, posY);
}

void QuestTest::setIsQuestTaken(bool isQuestTaken)
{
	this->is_Quest_Taken_ = isQuestTaken;
}

void QuestTest::setIsTaskCompleted(bool isTaskCompleted)
{
	this->is_Task_Completed_ = isTaskCompleted;
}

void QuestTest::setIsQuestTurnedIn(bool isQuestTurnedIn)
{
	this->is_Quest_Turned_In_ = isQuestTurnedIn;
}

void QuestTest::setNpcName(const std::string& npcName)
{
	this->npc_Name_ = npcName;
}

const Text& QuestTest::getText() const
{
	return this->t_A_;
}

const QUESTNAME& QuestTest::getQuestName() const
{
	return this->quest_Name_;
}

const bool& QuestTest::getIsQuestTaken() const
{
	return this->is_Quest_Taken_;
}

const std::string& QuestTest::getQuestTitle() const
{
	return this->quest_Title_;
}

const std::string& QuestTest::getQuestSummary() const
{
	return this->quest_Summary_;
}

const std::string& QuestTest::getQuestFinishedSummary() const
{
	return this->quest_Finish_Summary_;
}

const bool& QuestTest::getIsTaskCompleted() const
{
	return this->is_Task_Completed_;
}

const bool& QuestTest::getIsQuestTurnedIn() const
{
	return this->is_Quest_Turned_In_;
}

const QUESTTYPE& QuestTest::getQuestType() const
{
	return this->quest_Type_;
}

const std::string& QuestTest::getNpcName() const
{
	return this->npc_Name_;
}
