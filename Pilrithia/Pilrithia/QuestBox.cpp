#include "QuestBox.h"

QuestBox::QuestBox()
{
	this->is_Visible_ = false;
	this->is_Accepted_ = false;
	this->is_Completed_ = false;
}

QuestBox::~QuestBox()
{
}

void QuestBox::setSettings(float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, const std::string& questText, const ResourceFont& resourceFont)
{
	/*
		SET SETTINGS OF THE QUEST BOX
	*/

	this->quest_Box_.setSettings(700.f, 400.f, posX - 350.f, posY - 200.f, fillColor, outlineThickness, outlineColor, true);

	this->quest_Text_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, questText, sf::Vector2f(this->quest_Box_.getLeftPosition(true, 10.f), this->quest_Box_.getTopPosition(true, 10)), true);

	this->accept_Button_.setSettings(150.f, 40.f, this->quest_Box_.getLeftPosition(true, 180.f), this->quest_Box_.getBottomPosition(false, 50), fillColor, outlineThickness, outlineColor, true);
	this->decline_Button_.setSettings(150.f, 40.f, this->accept_Button_.getRightPosition(true, 10.f), this->accept_Button_.getTopPosition(), fillColor, outlineThickness, outlineColor, true);
	this->complete_Button_.setSettings(150.f, 40.f, this->accept_Button_.getRightPosition(true, 10.f), this->accept_Button_.getTopPosition(), fillColor, outlineThickness, outlineColor, true);

	this->accept_Text_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Accept", sf::Vector2f(this->accept_Button_.getLeftPosition(true, 10.f), this->accept_Button_.getTopPosition(true, 10)), true);
	this->decline_Text_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Decline", sf::Vector2f(this->decline_Button_.getLeftPosition(true, 10.f), this->decline_Button_.getTopPosition(true, 10)), true);
	this->complete_Text_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Complete", sf::Vector2f(this->accept_Button_.getRightPosition(false, 10.f), this->decline_Button_.getTopPosition(true, 10)), true);

}

bool QuestBox::updateAcceptPollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->accept_Button_.updatePollEvent(ev))
		{
			//std::cout << "Accept button clicking" << std::endl;

			this->is_Accepted_ = true;

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool QuestBox::updateDeclinePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (!this->is_Accepted_)
		{
			if (this->decline_Button_.updatePollEvent(ev))
			{
				//std::cout << "Decline button clicking" << std::endl;

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool QuestBox::updateCompletePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (!this->is_Completed_ && this->is_Accepted_)
		{
			if (this->complete_Button_.updatePollEvent(ev))
			{
				//std::cout << "Complete button clicking" << std::endl;

				this->is_Completed_ = true;

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void QuestBox::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Visible_)
	{
		//std::cout << "updating boundaries for quest box buttons" << std::endl;
		if (!this->is_Accepted_)
		{
			this->accept_Button_.updateBoundaries(mousePositionWindow);
			this->decline_Button_.updateBoundaries(mousePositionWindow);
		}
		
		if (!this->is_Completed_ && this->is_Accepted_)
		{
			this->complete_Button_.updateBoundaries(mousePositionWindow);
		}
	}
}

void QuestBox::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->quest_Box_.render(target);

		this->quest_Text_.render(target);

		if (!this->is_Accepted_)
		{
			this->accept_Button_.render(target);
			this->decline_Button_.render(target);

			this->accept_Text_.render(target);
			this->decline_Text_.render(target);
		}

		if (!this->is_Completed_ && this->is_Accepted_)
		{
			this->complete_Button_.render(target);
			this->complete_Text_.render(target);
		}
	}
}

void QuestBox::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void QuestBox::setString(const std::string& string)
{
	/*
		SET THE STRING AND WORD WRAP IT IF IT GOES OUTSIDE OF THE BOUNDARIES OF THE HOVER BOX
	*/

	this->quest_Text_.setString(string);
	
	this->quest_Text_.wrapText(this->quest_Box_.getGlobalBounds());
}

void QuestBox::setIsAccepted(bool isAccepted)
{
	this->is_Accepted_ = isAccepted;
}

const bool& QuestBox::getIsVisible() const
{
	return this->is_Visible_;
}
