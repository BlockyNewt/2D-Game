#include "NpcTest.h"

NpcTest::NpcTest()
{
}

NpcTest::NpcTest(const ResourceFont& resourceFont)
{
	this->dialog_Box_Str_ = "This is the first quest. Click the expand button to see more of what this quest has to offer.";
	
	this->npc_Model_.setSize(sf::Vector2f(50.f, 50.f));
	this->npc_Model_.setPosition(sf::Vector2f(50.f, 100.f));
	this->npc_Model_.setFillColor(sf::Color::Magenta);

	this->npc_Range_.setSize(sf::Vector2f(90.f, 30.f));
	this->npc_Range_.setPosition(sf::Vector2f(this->npc_Model_.getPosition().x - 30, this->npc_Model_.getPosition().y));
	this->npc_Range_.setFillColor(sf::Color::Transparent);
	this->npc_Range_.setOutlineThickness(1.f);
	this->npc_Range_.setOutlineColor(sf::Color::Red);

	this->dialog_Box_.setSettings(300.f, 200.f, this->npc_Model_.getPosition().x - 300.f / 2.f, this->npc_Model_.getPosition().y - 205, sf::Color(27, 133, 184), 1.f, sf::Color::Magenta, this->dialog_Box_Str_, resourceFont, false);
	this->dialog_Box_.setString(this->dialog_Box_Str_);

	this->npc_Name_ = "N.P.C One";
	this->name_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, this->npc_Name_, sf::Vector2f(this->npc_Model_.getGlobalBounds().left - 25.f, this->npc_Model_.getGlobalBounds().top - 25.f), true);

	this->is_Within_Range_ = false;
	
	this->quest_ = new QuestTest(resourceFont);
	this->quest_->setTargetNpcName("N.P.C Two");

	this->camera_ = new Camera(0.f, 0.f);
}

NpcTest::~NpcTest()
{
	delete this->camera_;
}

void NpcTest::setSettings(const sf::Vector2u& windowSize, const ResourceFont& resourceFont)
{
	/*
		MUST CALL THIS SO WE CAN PASS RESOURCE FONT TO SET TEXT FONT OR ELSE WE WILL NOT BE ABLE TO SEE TEXT
	*/
	this->quest_Box_.setSettings(windowSize.x / 2.f, windowSize.y / 2.f, sf::Color(174, 90, 65), 1.f, sf::Color::Green, this->quest_->getQuestTitle() + "\n\n" + this->quest_->getQuestSummary(), resourceFont);
	this->quest_Box_.setString(this->quest_->getQuestTitle() + "\n\n" + this->quest_->getQuestSummary());
}

void NpcTest::updatePollEventQuest(sf::Event& ev, PlayerTest& playerTest, Quest* quest)
{
	/*
	
	FOR SPEAK TO DIFFERENT NPC QUESTS WE WILL HAVE TO CHANGE THIS A TAD BIT FOR THE TURN IN NPC

	REFERENCE FOR LATER:
	HIDE EXPAND BUTTON
	CHANGE DIALOG BOX STRING TO SOME OTHER DIALOG UNTIL QUEST IS TAKEN
	ONCE QUEST IS TAKEN UPDATE RECEIVING NPCS DIALOG 
	SHOW EXPAND BUTTON
	
	*/
	if (!quest->getIsQuestTurnedIn())
	{
		playerTest.setPlayerQuest().isThisQuestTaken(*quest);
	}

	if (this->dialog_Box_.updatePollEvent(ev))
	{
		
		if (!this->quest_Box_.getIsVisible())
		{
			if (quest->getQuestType() == QUESTTYPE::SPEAKTOSAMENPC)
			{
				//std::cout << "enabling" << std::endl;
				this->dialog_Box_.setIsVisible(false);
				this->quest_Box_.setIsVisible(true);
			}

			else if (quest->getQuestType() == QUESTTYPE::SPEAKTODIFFERENTNPC)
			{
				this->dialog_Box_.setIsVisible(false);
				this->quest_Box_.setIsVisible(true);
			}
		}
	}

	if (playerTest.setPlayerQuest().getSelectedQuest() != NULL)
	{
		if (playerTest.setPlayerQuest().getSelectedQuest()->getTargetNpcName() == this->npc_Name_)
		{
			this->quest_Box_.setIsAccepted(true);
		}
	}

	if (!quest->getIsQuestTurnedIn())
	{
		if (this->quest_Box_.getIsVisible())
		{
			if (this->quest_Box_.updateAcceptPollEvent(ev))
			{
				if (quest->getQuestType() == QUESTTYPE::SPEAKTOSAMENPC)
				{
					quest->setIsQuestTaken(true);
					quest->setIsTaskCompleted(true);

					playerTest.addQuest(*quest);

					this->dialog_Box_.setString("Quest has been accepted. Expand again to turn it in.");
					this->quest_Box_.setString(quest->getQuestTitle() + "\n" + quest->getQuestFinishedSummary());

					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);
				}

				else if (quest->getQuestType() == QUESTTYPE::SPEAKTODIFFERENTNPC)
				{
					quest->setIsQuestTaken(true);
					quest->setIsTaskCompleted(true);

					playerTest.addQuest(*quest);

					this->dialog_Box_.setString("You must talk to another npc to complete this quest.");
					this->quest_Box_.setString(quest->getQuestTitle() + "\n" + quest->getQuestFinishedSummary());

					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);

					this->dialog_Box_.setExpandButtonVisibility(false);
				}
			}

			if (this->quest_Box_.updateDeclinePollEvent(ev))
			{
				if (quest->getQuestType() == QUESTTYPE::SPEAKTOSAMENPC)
				{
					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);
				}

				else if (quest->getQuestType() == QUESTTYPE::SPEAKTODIFFERENTNPC)
				{
					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);
				}
			}

			if (this->quest_Box_.updateCompletePollEvent(ev))
			{
				if (quest->getQuestType() == QUESTTYPE::SPEAKTOSAMENPC)
				{
					playerTest.setPlayerQuest().setSelectedQuest()->setIsQuestTurnedIn(true);
					this->quest_->setIsQuestTurnedIn(true);

					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);

					this->dialog_Box_.setExpandButtonVisibility(false);

					this->dialog_Box_.setString("You have already completed the quest.");
				}

				else if (quest->getQuestType() == QUESTTYPE::SPEAKTODIFFERENTNPC)
				{
					playerTest.setPlayerQuest().setSelectedQuest()->setIsQuestTurnedIn(true);
					quest->setIsQuestTurnedIn(true);

					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);

					this->dialog_Box_.setExpandButtonVisibility(false);

					this->dialog_Box_.setString("You have already completed the quest.");
				}
			}
		}
	}
}

void NpcTest::updatePollEvent(sf::Event& ev, PlayerTest& playerTest)
{
	if (this->is_Within_Range_)
	{
		//START RECREATING HERE
		this->updatePollEventQuest(ev, playerTest, this->quest_);
	}
	else
	{
		this->quest_Box_.setIsVisible(false);
		this->dialog_Box_.setIsVisible(true);
	}
}

void NpcTest::update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, PlayerTest& playerTest)
{
	if (this->npc_Range_.getGlobalBounds().intersects(playerBounds))
	{
		*this->camera_ = camera;

		//std::cout << "WITHIN RANGE OF NPC" << std::endl;
		this->is_Within_Range_ = true;

		

		if (!this->quest_Box_.getIsVisible())
		{
			this->dialog_Box_.setIsVisible(true);
			this->dialog_Box_.update(mousePositionView);
		}
		else
		{
			this->dialog_Box_.setIsVisible(false);

			this->quest_Box_.update(mousePositionWindow);
		}

	}
	else
	{
		this->is_Within_Range_ = false;
		this->dialog_Box_.setIsVisible(false);
	}
}

void NpcTest::render(sf::RenderTarget& target)
{
	target.draw(this->npc_Range_);
	target.draw(this->npc_Model_);

	this->name_.render(target);

	if (this->is_Within_Range_)
	{
		this->dialog_Box_.render(target);

		target.setView(target.getDefaultView());

		this->quest_Box_.render(target);

		target.setView(this->camera_->getView());
	}
}
