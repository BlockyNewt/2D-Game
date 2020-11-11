#ifndef PLAYERSKILLTREE_H
#define PLAYERSKILLTREE_H

#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Text.h"
#include "Button.h"
#include "CircleButton.h"
#include "HoverDescription.h"
#include "SkillButton.h"

#include <iostream>
#include <string>

class PlayerSkillTree
{
public:
	PlayerSkillTree();
	~PlayerSkillTree();

	void updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsHidingSkillTree(bool value);

	const bool& getIsHidingSkillTree() const;

private:

private:
	Box x_A_;

	Button b_B_;

	SkillButton defence_B_A_;
	SkillButton defence_B_B_;
	SkillButton defence_B_C_;

	Text t_A_;
	Text t_B_;


	bool is_Hiding_Skill_Tree_;

};

#endif // !PLAYERSKILLTREE_H
