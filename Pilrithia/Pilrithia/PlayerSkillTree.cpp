#include "PlayerSkillTree.h"

PlayerSkillTree::PlayerSkillTree()
{
	this->camera_ = new Camera(1280, 720);

	this->is_Hiding_Skill_Tree_ = true;

	this->x_A_.setSettings(1280, 720, 0.f, 0.f, sf::Color::Green, 1.f, sf::Color::White, true);
	this->x_B_.setSettings(2560, 1440, 0.f, 0.f, sf::Color::Yellow, 1.f, sf::Color::White, true);

	this->b_B_.setSettings(50.f, 50.f, 1230.f, this->x_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);

	this->strength_C_A_.setSettings(30.f, 0.f, 0.f, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_B_.setSettings(30.f, 50, 126, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_C_.setSettings(30.f, 126, 50, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_D_.setSettings(30.f, 175, 177, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_E_.setSettings(30.f, 156, 351, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_F_.setSettings(30.f, 351, 156, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_G_.setSettings(30.f, 303, 398, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_H_.setSettings(30.f, 398, 303, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_I_.setSettings(30.f, 382, 523, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_J_.setSettings(30.f, 523, 382, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_K_.setSettings(30.f, 506, 605, sf::Color::Red, 1.f, sf::Color::White, true);
	this->strength_C_L_.setSettings(30.f, 605, 506, sf::Color::Red, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 28, "Skill Tree", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings("Font/arial.ttf", 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);
}

PlayerSkillTree::~PlayerSkillTree()
{
}

void PlayerSkillTree::updatePollEvent(sf::Event& ev)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		this->camera_->updatePollEvent(ev);

		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Hiding_Skill_Tree_ = true;
		}
	}
}

void PlayerSkillTree::update(const sf::Vector2i& mousePositionWindow)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		this->b_B_.updateBoundaries(mousePositionWindow);

		this->strength_C_A_.updateBoundaries(mousePositionWindow);
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
		target.setView(this->camera_->getView());

		this->x_B_.render(target);


		this->strength_C_A_.render(target);
		this->strength_C_B_.render(target);
		this->strength_C_C_.render(target);
		this->strength_C_D_.render(target);
		this->strength_C_E_.render(target);
		this->strength_C_F_.render(target);
		this->strength_C_G_.render(target);
		this->strength_C_H_.render(target);
		this->strength_C_I_.render(target);
		this->strength_C_J_.render(target);
		this->strength_C_K_.render(target);
		this->strength_C_L_.render(target);

		

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

const sf::View& PlayerSkillTree::getView() const
{
	return this->camera_->getView();
}
