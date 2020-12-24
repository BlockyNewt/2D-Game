#include "PlayerQuest.h"

PlayerQuest::PlayerQuest(const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud)
{
	this->selected_Quest_ = NULL;

	this->is_Hiding_Quest_ = true;
	this->max_Quest_ = 5;
	this->current_Quest_ = 0;

	this->x_B_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0, 0, 0, 200), 1.f, sf::Color::Transparent, true);

	this->quest_Background_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::WINDOW));
	this->quest_Background_Sprite_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 800.f / 2.f, window->getSize().y / 2.f - 500.f / 2.f));

	this->b_B_.setSettings(34.f, 34.f, this->quest_Background_Sprite_.getGlobalBounds().left + this->quest_Background_Sprite_.getGlobalBounds().width - 38.f, this->quest_Background_Sprite_.getGlobalBounds().top + 4.f, sf::Color::White, 0.f, sf::Color::Transparent, true);
	this->b_B_.setTexture(resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::CLOSE));

	this->t_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 28, "Quests", sf::Vector2f(this->quest_Background_Sprite_.getGlobalBounds().left + 350.f, this->quest_Background_Sprite_.getGlobalBounds().top + 10.f), true);
}

PlayerQuest::~PlayerQuest()
{
	delete this->selected_Quest_;

	std::cout << "DEBUG::PLAYERQUEST::~PLAYERQUEST() -> Deconstructed." << std::endl;
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

			this->selected_Quest_ = this->quests_[i];

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

	this->quests_.back()->setTextPosition(this->quest_Background_Sprite_.getGlobalBounds().left + 10.f, this->quest_Background_Sprite_.getGlobalBounds().top + 10.f + this->current_Quest_ * 30.f);
	this->quests_.back()->wrapText(this->quest_Background_Sprite_.getGlobalBounds());
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
		this->x_B_.render(target);
		target.draw(this->quest_Background_Sprite_);

		this->b_B_.render(target);

		this->t_A_.render(target);

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

Quest* PlayerQuest::setSelectedQuest()
{
	return this->selected_Quest_;
}

void PlayerQuest::setPositionOnResize(const sf::RenderWindow* window)
{
	this->x_B_.setSize(window->getSize().x, window->getSize().y);

	this->quest_Background_Sprite_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 800.f / 2.f, window->getSize().y / 2.f - 500.f / 2.f));

	this->b_B_.setPosition(sf::Vector2f(this->quest_Background_Sprite_.getGlobalBounds().left + this->quest_Background_Sprite_.getGlobalBounds().width - 38.f, this->quest_Background_Sprite_.getGlobalBounds().top + 4.f));

	this->t_A_.setPosition(this->quest_Background_Sprite_.getGlobalBounds().left + 350.f, this->quest_Background_Sprite_.getGlobalBounds().top + 10.f);
}

const bool& PlayerQuest::getIsHidingQuest() const
{
	return this->is_Hiding_Quest_;
}

const std::vector<Quest*>& PlayerQuest::getQuest() const
{
	return this->quests_;
}

const Quest* PlayerQuest::getSelectedQuest() const
{
	return this->selected_Quest_;
}
