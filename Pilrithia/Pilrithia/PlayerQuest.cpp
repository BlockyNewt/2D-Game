#include "PlayerQuest.h"

PlayerQuest::PlayerQuest()
{
	this->is_Hiding_Quest_ = true;
	this->max_Quest_ = 5;
	this->current_Quest_ = 0;

	this->x_A_.setSettings(800.f, 500.f, 0.f, 0.f, sf::Color::Yellow, 1.f, sf::Color::White, true);

	this->b_B_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);
	
	this->t_A_.setSettings("Font/arial.ttf", 28, "Quests", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings("Font/arial.ttf", 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);
}

PlayerQuest::~PlayerQuest()
{
}

bool PlayerQuest::isThisQuestTaken(Quest& quest)
{
	/*
		PASS THE NPCS QUEST AND CHECK IF THE THE ENUM NAME IS EQUAL TO THAT OF THE
		QUEST THE PLAYER HAS. IF PLAYER ALREADY HAS IT, THEN BREAK OUT OF LOOP
	*/

	bool questAlreadyAccepted = false;

	for (int i = 0; i < this->quests_.size(); ++i)
	{
		if (this->quests_[i]->getQuestName() == quest.getQuestName())
		{
			questAlreadyAccepted = true;

			break;
		}
	}

	if (questAlreadyAccepted)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayerQuest::isQuestTaskCompleted(Quest& quest)
{
	/*
		PASS NPCS QUEST AND CHECK IF THE TASK IS COMPLETED. IF NOT BREAK
		OUT OF LOOP
	*/
	for (int i = 0; i < this->quests_.size(); ++i)
	{
		if (this->quests_[i]->getQuestName() == quest.getQuestName() &&
			this->quests_[i]->getIsTaskCompleted())
		{
			//std::cout << "Quest task has been completed. " << std::endl;

			break;

			return true;
		}
		else
		{
			return false;
		}
	}
}

bool PlayerQuest::isQuestTurnedInCompleted(Quest& quest)
{
	
	for (int i = 0; i < this->quests_.size(); ++i)
	{
		if (this->quests_[i]->getQuestName() == quest.getQuestName() &&
			this->quests_[i]->getIsQuestTurnedIn())
		{
			//std::cout << "Quest task has been completed. " << std::endl;

			break;

			return true;
		}
		else
		{
			return false;
		}
	}
}

void PlayerQuest::addQuest(Quest& quest)
{
	/*
		PASS NPCS QUEST AND ADD IT TO THE PLAYERS QUEST VECTOR
	*/

	/*
		THIS IS JUST FOR TEXT POSITION WITHIN THE WINDOW
	*/
	this->current_Quest_++;

	this->quests_.push_back(&quest);

	this->quests_.back()->setTextPosition(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 10.f) + this->current_Quest_ * 30.f);
	this->quests_.back()->wrapText(this->x_A_.getGlobalBounds());
}

void PlayerQuest::completeQuest(Quest& quest)
{
	/*
		PASS NPCS QUEST TO FIND THE CORRECT ONE WITH THE PLAYERS OWNED QUEST AND 
		CHANGE TURNED IN BOOL TO TRUE
	*/
	for (int i = 0; i < this->quests_.size(); ++i)
	{
		if (this->quests_[i]->getQuestName() == quest.getQuestName())
		{
			this->quests_[i]->setIsQuestTurnedIn(true);
		}
	}
}

void PlayerQuest::updatePollEvent(sf::Event& ev)
{
	if (!this->is_Hiding_Quest_)
	{
		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Hiding_Quest_ = true;
		}
	}
}

void PlayerQuest::update(const sf::Vector2i& mousePositionWindow)
{
	if (!this->is_Hiding_Quest_)
	{
		this->b_B_.updateBoundaries(mousePositionWindow);
	}

	for (int i = 0; i < this->quests_.size(); ++i)
	{
		this->quests_[i]->update();
	}
}

void PlayerQuest::render(sf::RenderTarget& target)
{
	if (!this->is_Hiding_Quest_)
	{
		this->x_A_.render(target);

		this->b_B_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);

		if (!this->quests_.empty())
		{
			for (auto& q : this->quests_)
			{
				q->render(target);
			}
		}
	}
}

void PlayerQuest::setIsHidingQuest(bool isHidingQuest)
{
	this->is_Hiding_Quest_ = isHidingQuest;
}

const bool& PlayerQuest::getIsHidingQuest() const
{
	return this->is_Hiding_Quest_;
}

const std::vector<Quest*>& PlayerQuest::getQuest() const
{
	return this->quests_;
}
