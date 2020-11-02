#include "QuestBox.h"

QuestBox::QuestBox()
{
	this->is_Visible_ = false;
}

QuestBox::~QuestBox()
{
}

void QuestBox::setSettings(float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, const std::string& questText)
{
	this->quest_Box_.setSettings(700.f, 400.f, posX - 350.f, posY - 200.f, fillColor, outlineThickness, outlineColor, true);

	this->quest_Text_.setSettings("Font/arial.ttf", 18, questText, sf::Vector2f(this->quest_Box_.getLeftPosition(true, 10.f), this->quest_Box_.getTopPosition(true, 10)), true);

	this->accept_Button_.setSettings(150.f, 40.f, this->quest_Box_.getLeftPosition(true, 180.f), this->quest_Box_.getBottomPosition(false, 50), fillColor, outlineThickness, outlineColor, true);
	this->decline_Button_.setSettings(150.f, 40.f, this->accept_Button_.getRightPosition(true, 10.f), this->accept_Button_.getTopPosition(), fillColor, outlineThickness, outlineColor, true);

	this->accept_Text_.setSettings("Font/arial.ttf", 18, "Accept", sf::Vector2f(this->accept_Button_.getLeftPosition(true, 10.f), this->accept_Button_.getTopPosition(true, 10)), true);
	this->decline_Text_.setSettings("Font/arial.ttf", 18, "Decline", sf::Vector2f(this->decline_Button_.getLeftPosition(true, 10.f), this->decline_Button_.getTopPosition(true, 10)), true);

}

bool QuestBox::updatePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->decline_Button_.updatePollEvent(ev))
		{
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

void QuestBox::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Visible_)
	{
		//std::cout << "updating boundaries for quest box buttons" << std::endl;
		this->accept_Button_.updateBoundaries(mousePositionWindow);
		this->decline_Button_.updateBoundaries(mousePositionWindow);
	}
}

void QuestBox::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->quest_Box_.render(target);

		this->quest_Text_.render(target);

		this->accept_Button_.render(target);
		this->decline_Button_.render(target);

		this->accept_Text_.render(target);
		this->decline_Text_.render(target);
	}
}

void QuestBox::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const bool& QuestBox::getIsVisible() const
{
	return this->is_Visible_;
}
