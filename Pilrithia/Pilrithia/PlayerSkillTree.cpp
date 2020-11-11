#include "PlayerSkillTree.h"

PlayerSkillTree::PlayerSkillTree()
{
	this->is_Hiding_Skill_Tree_ = true;

	this->x_A_.setSettings(1280, 720, 0.f, 0.f, sf::Color::Green, 1.f, sf::Color::White, true);

	this->b_B_.setSettings(50.f, 50.f, 1230.f, this->x_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);

	
	this->defence_B_A_.setSettings(20, 0.f, 150.f, sf::Color::Red, 1.f, sf::Color::White, "Skill", "Test description", STATNAME::CONSTITUTION, 1);
	this->defence_B_B_.setSettings(20, this->defence_B_A_.getRightPosition(true, 40.f), this->defence_B_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, "Skill", "Test description", STATNAME::CONSTITUTION, 1);
	this->defence_B_C_.setSettings(20, this->defence_B_B_.getRightPosition(true, 40.f), this->defence_B_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, "Skill", "Test description", STATNAME::CONSTITUTION, 1);

	this->t_A_.setSettings("Font/arial.ttf", 28, "Skill Tree", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings("Font/arial.ttf", 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);
}

PlayerSkillTree::~PlayerSkillTree()
{
}

void PlayerSkillTree::updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Hiding_Skill_Tree_ = true;
		}

		this->defence_B_A_.updatePollEvent(ev, stats);
		this->defence_B_B_.updatePollEvent(ev, stats);
		this->defence_B_C_.updatePollEvent(ev, stats);
	}
}

void PlayerSkillTree::update(const sf::Vector2i& mousePositionWindow)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		this->b_B_.updateBoundaries(mousePositionWindow);


		this->defence_B_A_.update(mousePositionWindow);
		this->defence_B_B_.update(mousePositionWindow);
		this->defence_B_C_.update(mousePositionWindow);
	}
}

void PlayerSkillTree::render(sf::RenderTarget& target)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		target.setView(target.getDefaultView());

		this->x_A_.render(target);

		this->b_B_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);


		this->defence_B_A_.render(target);
		this->defence_B_B_.render(target);
		this->defence_B_C_.render(target);

		target.setView(target.getDefaultView());

	}
}

void PlayerSkillTree::setIsHidingSkillTree(bool value)
{
	this->is_Hiding_Skill_Tree_ = value;
}

const bool& PlayerSkillTree::getIsHidingSkillTree() const
{
	return this->is_Hiding_Skill_Tree_;
}
