#ifndef PLAYERSKILLTREE_H
#define PLAYERSKILLTREE_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Box.h"
#include "Text.h"
#include "Button.h"
#include "CircleButton.h"
#include "HoverDescription.h"
#include "SkillButton.h"

#include "ClassesRainmaker.h"

#include <iostream>
#include <string>

class PlayerSkillTree
{
public:
	PlayerSkillTree(const ResourceFont& resourceFont);
	~PlayerSkillTree();

	void updateClassOneSelectPollEvent(sf::Event& ev, std::map<std::string, int>& stats, int& playerSkillPoints);
	void updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats, int& playerSkillPoints);

	void updateClassOneSelect(const sf::Vector2i& mousePositionWindow);
	void update(const sf::Vector2i& mousePositionWindow, int& playerSkillPoints);
	void render(sf::RenderTarget& target);

	void setIsHidingSkillTree(bool value);
	Classes* setClassesOne();
	Classes* setClassesTwo();

	const bool& getIsHidingSkillTree() const;
	const Classes* getClassesOne() const;
	const Classes* getClassesTwo() const;

private:
	void initializeClassOneSelect(const ResourceFont& resourceFont);

	void resizeProgressBar();
private:
	Box x_A_;

	Button b_A_;
	Text t_A_;
	Text t_B_;
	Text t_D_;


	Button b_C_;
	Text t_C_;

	CircleButton class_B_A_;
	CircleButton class_B_B_;
	CircleButton class_B_C_;
	CircleButton class_B_D_;

	Box class_X_A_;
	Box class_X_B_;

	Text class_T_A_;
	Text class_T_B_;
	Text class_T_C_;

	
	sf::RectangleShape speccing_Progress_Bar_Back_;
	sf::RectangleShape speccing_Progress_Bar_Front_;

	Button speccing_B_A_;

	SkillButton speccing_B_B_;

	Text speccing_T_A_;
	Text speccing_T_B_;


	bool is_Hiding_Skill_Tree_;


	//TESTING
	ClassesRainmaker* classes_Rain_;
	bool is_Selecting_Class_One_;
	bool is_Speccing_Class_One_Points_;

	int speccing_Progress_Bar_Max_;
	int speccing_Progress_Bar_Amount_;

	Classes* player_Class_One_;
	Classes* player_Class_Two_;
};

#endif // !PLAYERSKILLTREE_H
