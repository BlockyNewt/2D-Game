#include "SkillDropDownList.h"

SkillDropDownList::SkillDropDownList()
{
	this->is_Visible_ = false;
	this->is_Hovering_ = false;
}

SkillDropDownList::~SkillDropDownList()
{
}

void SkillDropDownList::setSettings(const sf::FloatRect itemBoundaries, Classes* playerClasses)
{
	if (playerClasses->getSkillOne()->getIsUnlocked())
	{
		this->b_A_.setSettings(200.f, 40.f, itemBoundaries.left - 40.f, itemBoundaries.top - 40.f, sf::Color::Yellow, 1.f, sf::Color::White, true);

		this->t_A_.setSettings("Font/arial.ttf", 18, playerClasses->getSkillOne()->getName(), sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);
	}
}

void SkillDropDownList::updatePollEvent(sf::Event& ev, Classes* playerClasses, Skill** hudSkillOne)
{
	if (this->b_A_.updatePollEvent(ev))
	{
		*hudSkillOne = playerClasses->getSkillOne();
	}
}

void SkillDropDownList::update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries)
{
	if (this->is_Visible_)
	{
		this->b_A_.updateBoundaries(mousePositionWindow);
	}
	else
	{
		this->is_Hovering_ = false;
	}
}

void SkillDropDownList::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->b_A_.render(target);
		this->t_A_.render(target);
	}
}

void SkillDropDownList::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}
