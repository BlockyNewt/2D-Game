#ifndef PLAYERSKILLTREE_H
#define PLAYERSKILLTREE_H

#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Text.h"
#include "Button.h"
#include "CircleButton.h"
#include "HoverDescription.h"

#include "Camera.h"

#include <iostream>
#include <string>

class PlayerSkillTree
{
public:
	PlayerSkillTree();
	~PlayerSkillTree();

	void updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingSkillTree(bool value);

	const bool& getIsHidingSkillTree() const;
	const sf::View& getView() const;

private:

private:
	Camera* camera_;

	Box x_A_;
	Box x_B_;

	Button b_B_;

	CircleButton strength_C_A_;
	CircleButton strength_C_B_;
	CircleButton strength_C_C_;
	CircleButton strength_C_D_;
	CircleButton strength_C_E_;
	CircleButton strength_C_F_;
	CircleButton strength_C_G_;
	CircleButton strength_C_H_;
	CircleButton strength_C_I_;
	CircleButton strength_C_J_;
	CircleButton strength_C_K_;
	CircleButton strength_C_L_;

	Text t_A_;
	Text t_B_;


	bool is_Hiding_Skill_Tree_;

};

#endif // !PLAYERSKILLTREE_H
