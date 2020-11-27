#ifndef QUESTTEST_H
#define QUESTTEST_H

#include "Quest.h"

class QuestTest 
	: public Quest
{
public:
	QuestTest();
	QuestTest(const ResourceFont& resourceFont);
	virtual ~QuestTest();

	void update() override;
	void render(sf::RenderTarget& target) override;

	void wrapText(const sf::FloatRect boundaries) override;

	void setKillCount() override;
	void setTextPosition(float posX, float posY) override;
	void setIsQuestTaken(bool isQuestTaken) override;
	void setIsTaskCompleted(bool isTaskCompleted) override;
	void setIsQuestTurnedIn(bool isQuestTurnedIn) override;
	void setTargetNpcName(const std::string& npcName) override;

	const Text& getText() const override;
	const QUESTNAME& getQuestName() const override;
	const bool& getIsQuestTaken() const override;
	const std::string& getQuestTitle() const override;
	const std::string& getQuestSummary() const override;
	const std::string& getQuestFinishedSummary() const override;
	const bool& getIsTaskCompleted() const override;
	const bool& getIsQuestTurnedIn() const override;
	const QUESTTYPE& getQuestType() const override;
	const std::string& getTargetNpcName() const override;


private:

private:
	Text t_A_;

	std::string quest_Dialog_Str_;

	std::string quest_Title_;
	std::string quest_Summary_;
	std::string quest_Finish_Summary_;

	int max_Kill_Count_;
	int current_Kill_Count_;

	bool is_Task_Completed_;
	bool is_Quest_Turned_In_;
	bool is_Quest_Taken_;

	QUESTNAME quest_Name_;
	QUESTTYPE quest_Type_;

	std::string npc_Name_;
};

#endif // !QUESTTEST_H
