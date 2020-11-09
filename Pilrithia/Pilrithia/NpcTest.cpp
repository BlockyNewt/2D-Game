#include "NpcTest.h"

NpcTest::NpcTest()
{
	this->quest_ = new QuestTest();

	this->dialog_Box_Str_ = "This is the first quest. Click the expand button to see more of what this quest has to offer.";
	
	this->npc_Model_.setSize(sf::Vector2f(30.f, 30.f));
	this->npc_Model_.setPosition(sf::Vector2f(30.f, 120.f));
	this->npc_Model_.setFillColor(sf::Color::Magenta);

	this->npc_Range_.setSize(sf::Vector2f(90.f, 30.f));
	this->npc_Range_.setPosition(sf::Vector2f(this->npc_Model_.getPosition().x - 30, this->npc_Model_.getPosition().y));
	this->npc_Range_.setFillColor(sf::Color::Transparent);
	this->npc_Range_.setOutlineThickness(1.f);
	this->npc_Range_.setOutlineColor(sf::Color::Red);

	this->dialog_Box_.setSettings(300.f, 200.f, this->npc_Model_.getPosition().x - 300.f / 2.f, this->npc_Model_.getPosition().y - 205, sf::Color::Blue, 1.f, sf::Color::Magenta, this->dialog_Box_Str_, false);
	this->dialog_Box_.setString(this->dialog_Box_Str_);

	this->npc_Name_ = "Test NPC";
	this->name_.setSettings("Font/arial.ttf", 18, this->npc_Name_, sf::Vector2f(this->npc_Model_.getGlobalBounds().left - 25.f, this->npc_Model_.getGlobalBounds().top - 25.f), true);

	this->is_Within_Range_ = false;

	this->camera_ = new Camera(0.f, 0.f);
}

NpcTest::~NpcTest()
{
	delete this->camera_;
}

void NpcTest::setSettings(const sf::Vector2u& windowSize)
{
	//this->quest_Box_.setSettings(windowSize.x / 2.f, windowSize.y / 2.f, sf::Color::Red, 1.f, sf::Color::Green, false);
	this->quest_Box_.setSettings(windowSize.x / 2.f, windowSize.y / 2.f, sf::Color::Red, 1.f, sf::Color::Green, this->quest_->getQuestTitle() + "\n\n" + this->quest_->getQuestSummary());
	this->quest_Box_.setString(this->quest_->getQuestTitle() + "\n\n" + this->quest_->getQuestSummary());
}

void NpcTest::updatePollEvent(sf::Event& ev, PlayerTest& playerTest)
{
	if (this->is_Within_Range_)
	{
		if (this->dialog_Box_.updatePollEvent(ev))
		{
			if (!this->quest_Box_.getIsVisible())
			{
				//std::cout << "enabling" << std::endl;
				this->dialog_Box_.setIsVisible(false);
				this->quest_Box_.setIsVisible(true);
			}
			else
			{
				/*
					IF QUEST IS TAKEN, COMPLETED AND THE TYPE IS THE SAME OF THE NPCS QUEST THE SHOW QUEST BOX
				*/
				if (this->quest_->getIsQuestTaken() &&
					!playerTest.setPlayerQuest().isQuestTaskCompleted(*this->quest_) &&
					this->quest_->getQuestType() == QUESTTYPE::SPEAK)
				{
					this->dialog_Box_.setIsVisible(false);
					this->quest_Box_.setIsVisible(true);
				}
			}
		}

		/*
			IF QUEST BOXS ACCEPT BUTTON IS CLICKED
		*/
		if (this->quest_Box_.updateAcceptPollEvent(ev))
		{
			/*
				IF THE QUEST CONTAINER IS NOT EMPTY
			*/
			if (!playerTest.setPlayerQuest().getQuest().empty())
			{
				/*
					IF THE QUEST WE HAVE NOT YET TAKEN THE NPCS QUEST
				*/
				if (!playerTest.setPlayerQuest().isThisQuestTaken(*this->quest_))
				{
					/*
						SET NPCS QUEST TAKEN TO TRUE
					*/
					this->quest_->setIsQuestTaken(true);

					/*
						ADD QUEST TO PLAYERS QUEST CONTAINER
					*/
					playerTest.setPlayerQuest().addQuest(*this->quest_);

					/*
						HIDE QUEST BOX AND SHOW DIALOG BOX 
					*/
					this->quest_Box_.setIsVisible(false);
					this->dialog_Box_.setIsVisible(true);

					/*
						CHANGE THE DIALOG BOX STRING TO SHOW THAT THE QUEST HAS BEEN ACCEPTED
					*/
					this->dialog_Box_.setString("You have accepted the quest");
				}
			}
			else
			{
				/*
					ELSE IF THE CONTAINER IS NOT EMPTY JUST PUSH BACK THE QUEST
				*/

				this->quest_->setIsQuestTaken(true);

				playerTest.setPlayerQuest().addQuest(*this->quest_);

				this->dialog_Box_.setIsVisible(true);
				this->quest_Box_.setIsVisible(false);

				this->dialog_Box_.setString("You have accepted the quest");
			}
		}

		/*
			IF QUEST BOXS DECLINE BUTTON IS CLICKED
		*/
		if (this->quest_Box_.updateDeclinePollEvent(ev))
		{
			/*
				HID QUEST BOX AND SHOW DIALOG BOX
			*/
			this->dialog_Box_.setIsVisible(true);
			this->quest_Box_.setIsVisible(false);
		}

		/*
			IF QUEST BOXS COMPLETE BUTTON IS CLICKED
		*/
		if (this->quest_Box_.updateCompletePollEvent(ev))
		{
			/*
				CHANGE COMPLETED QUEST BOOL OF THE QUEST INSIDE OF THE VECTOR
			*/
			playerTest.setPlayerQuest().completeQuest(*this->quest_);

			/*
				SET THE NPCS QUEST TURNED IN BOOL TO TRUE AS WELL SO WE CAN NOT RETAKE
			*/
			this->quest_->setIsQuestTurnedIn(true);
			
			this->dialog_Box_.setIsVisible(true);
			this->quest_Box_.setIsVisible(false);
		}
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


		/*
			IF QUEST IS NOT TURNED IN
		*/
		if (!this->quest_->getIsQuestTurnedIn())
		{
			/*
				IF THE QUEST IS TAKEN AND THE QUEST TASK IS NOT COMPLETED
			*/
			if (this->quest_->getIsQuestTaken() && !playerTest.setPlayerQuest().isQuestTaskCompleted(*this->quest_))
			{
				/*
					HIDE THE DIALOG BOXS EXPAND BUTTON
				*/
				this->dialog_Box_.setExpandButtonVisibility(false);
			}

			/*
				IF QUEST IS TAKEN AND THE QUEST TYPE EQUALS TARGETED TYPE 
			*/
			if (this->quest_->getIsQuestTaken() && this->quest_->getQuestType() == QUESTTYPE::SPEAK)
			{
				/*
					LET PLAYER TALK TO NPC TO COMPLETE TASK
				*/
				this->dialog_Box_.setIsVisible(true);
				this->dialog_Box_.setExpandButtonVisibility(true);

				this->dialog_Box_.setString("Click the expand button and turn it in");
				this->quest_Box_.setString(this->quest_->getQuestTitle() + "\n" + this->quest_->getQuestFinishedSummary());
			}

			/*
				IF QUEST INSIDE PLAYERS QUEST VECTOR IS COMPLETED
			*/
			if (playerTest.setPlayerQuest().isQuestTaskCompleted(*this->quest_))
			{
				/*
					ALLOW PLAYER TO TURN IN QUEST 
				*/
				this->dialog_Box_.setIsVisible(true);
				this->dialog_Box_.setExpandButtonVisibility(true);

				this->dialog_Box_.setString("The task for this quest has been completed. Click the expand button and turn it in.");
				this->quest_Box_.setString(this->quest_->getQuestTitle() + "\n" + this->quest_->getQuestFinishedSummary());
			}
		}
		else
		{
			/*
				IF QUEST IS ALREADY COMPLETED THEN SHOW THAT IN NPCS DIALOG BOX
			*/
			this->dialog_Box_.setString("You have already completed this quest.");
			this->dialog_Box_.setExpandButtonVisibility(false);
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
