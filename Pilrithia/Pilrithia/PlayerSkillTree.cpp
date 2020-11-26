#include "PlayerSkillTree.h"

void PlayerSkillTree::initializeClassOneSelect(const ResourceFont& resourceFont)
{
	this->class_T_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Select a class", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);

	this->class_B_A_.setSettings(30.f, this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 100.f), sf::Color::White, 1.f, sf::Color::White, true);
	this->class_B_A_.setTexture(this->classes_Rain_->getClassIcon());
	this->class_B_B_.setSettings(30.f, this->class_B_A_.getRightPosition(), this->class_B_A_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->class_B_C_.setSettings(30.f, this->class_B_A_.getLeftPosition(), this->class_B_A_.getBottomPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->class_B_D_.setSettings(30.f, this->class_B_B_.getLeftPosition(), this->class_B_C_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);

	this->class_X_A_.setSettings(500.f, 400.f, this->class_B_B_.getRightPosition(true, 20.f), this->class_B_B_.getTopPosition(), sf::Color(195,203,113), 1.f, sf::Color::White, true);
	this->class_X_B_.setSettings(200.f, 400.f, this->class_X_A_.getRightPosition(true, 20.f), this->class_X_A_.getTopPosition(), sf::Color(195,203,113), 1.f, sf::Color::White, true);

	this->class_T_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Class Summary", sf::Vector2f(this->class_X_A_.getLeftPosition(true, 100.f), this->class_X_A_.getTopPosition(true, 10.f)), true);
	this->class_T_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "class summary goes here", sf::Vector2f(this->class_X_A_.getLeftPosition(true, 20.f), this->class_X_A_.getTopPosition(true, 80.f)), true);

	this->speccing_Progress_Bar_Max_ = 99;
	this->speccing_Progress_Bar_Amount_ = 0;
}

void PlayerSkillTree::resizeProgressBar()
{
	float progressMaxToFloat = static_cast<float>(this->speccing_Progress_Bar_Max_);
	float progressAmountToFloat = static_cast<float>(this->speccing_Progress_Bar_Amount_);

	this->speccing_Progress_Bar_Front_.setSize(sf::Vector2f(40, -(progressAmountToFloat / progressMaxToFloat) * 500.f));
}

PlayerSkillTree::PlayerSkillTree(const ResourceFont& resourceFont)
{
	/*
	
		NOTES FOR THINGS TO ADD LATER DOWN THE LINE...

		MAKE A BOOL THAT WILL PERMANENTLY MAKE CHANGES ON ACCEPT BUTTON CLICK.
		THAT BOOL WILL BECOME TRUE AGAIN ON LEVEL UP.
		IF THE PLAYER HAS UNALLOCATED SKILLS POINTS OR THE BOOL IS TRUE THEN THE USER CAN ALLOCATE POINTS FREELY

	*/

	this->classes_Rain_ = new ClassesRainmaker();
	this->player_Class_One_ = NULL;
	this->player_Class_Two_ = NULL;
	this->is_Hiding_Skill_Tree_ = true;

	//this->x_A_.setSettings(1280, 720, 0.f, 0.f, sf::Color::Black, 1.f, sf::Color::White, true);
	this->x_A_.setSettings(900.f, 600.f, 1280.f / 2.f - 900.f / 2.f, 720.f / 2.f - 600.f / 2.f, sf::Color(150, 150, 150), 1.f, sf::Color::White, true);
	this->x_B_.setSettings(1280.f, 720.f, 0.f, 0.f, sf::Color(0, 0, 0, 200), 1.f, sf::Color::White, true);

	this->b_A_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);

	
	this->initializeClassOneSelect(resourceFont);



	this->speccing_Progress_Bar_Back_.setSize(sf::Vector2f(50.f, 500.f));
	this->speccing_Progress_Bar_Back_.setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getBottomPosition(false, 560.f)));
	this->speccing_Progress_Bar_Back_.setFillColor(sf::Color::White);
	this->speccing_Progress_Bar_Back_.setOutlineThickness(1.f);
	this->speccing_Progress_Bar_Back_.setOutlineColor(sf::Color::Black);

	this->speccing_Progress_Bar_Front_.setSize(sf::Vector2f(this->speccing_Progress_Bar_Back_.getSize().x - 10.f, this->speccing_Progress_Bar_Back_.getSize().y - 10.f));
	this->speccing_Progress_Bar_Front_.setPosition(sf::Vector2f(this->speccing_Progress_Bar_Back_.getGlobalBounds().left + 5.f, this->speccing_Progress_Bar_Back_.getGlobalBounds().top + this->speccing_Progress_Bar_Back_.getGlobalBounds().height - 5.f));
	this->speccing_Progress_Bar_Front_.setFillColor(sf::Color(90, 82, 85));
	this->speccing_Progress_Bar_Front_.setOutlineThickness(1.f);
	this->speccing_Progress_Bar_Front_.setOutlineColor(sf::Color::Black);

	this->speccing_B_A_.setSettings(50.f, 50.f, this->speccing_Progress_Bar_Back_.getGlobalBounds().left, this->speccing_Progress_Bar_Back_.getGlobalBounds().top + this->speccing_Progress_Bar_Back_.getGlobalBounds().height, sf::Color(174, 90, 65), 1.f, sf::Color::Blue, true);


	this->speccing_B_B_.setSettings(20.f, this->x_A_.getLeftPosition(true, 200.f), this->x_A_.getBottomPosition(false, 100.f), sf::Color(195, 203, 113), 1.f, sf::Color::Blue, 1, resourceFont);



	this->speccing_T_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Increase", sf::Vector2f(this->speccing_B_A_.getLeftPosition(true, 10.f), this->speccing_B_A_.getTopPosition(true, 10.f)), true);
	this->speccing_T_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "SP:", sf::Vector2f(this->speccing_Progress_Bar_Back_.getGlobalBounds().left, this->speccing_Progress_Bar_Back_.getGlobalBounds().top - 30.f), true);


	this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);

	this->b_C_.setSettings(125.f, 40.f, this->x_A_.getLeftPosition(true, 20), this->class_X_A_.getBottomPosition(false, 50), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Select", sf::Vector2f(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f)), true);


	this->t_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Skill point allocation", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);


	this->is_Selecting_Class_One_ = true;
	this->is_Speccing_Class_One_Points_ = false;


}

PlayerSkillTree::~PlayerSkillTree()
{
}

void PlayerSkillTree::updateClassOneSelectPollEvent(sf::Event& ev, std::map<std::string, int>& stats, int& playerSkillPoints)
{
	if (this->is_Selecting_Class_One_)
	{
		if (this->class_B_A_.updatePollEvent(ev))
		{
			this->class_T_B_.setString(this->classes_Rain_->getName());
			this->class_T_C_.setString(this->classes_Rain_->getSummary());

			this->class_T_C_.wrapText(this->class_X_A_.getGlobalBounds());

			this->classes_Rain_->setIsSelected(true);

			this->player_Class_One_ = this->classes_Rain_;

			std::cout << this->player_Class_One_->getName() << std::endl;
		}

		if (this->class_B_A_.updatePollEvent(ev))
		{
			this->class_T_B_.setString("");
			this->class_T_C_.setString("");
		}

		if (this->b_C_.updatePollEvent(ev))
		{
			std::cout << this->player_Class_One_->getName() << std::endl;
			if (this->player_Class_One_ != NULL)
			{
				if (this->player_Class_One_->getName() == this->classes_Rain_->getName())
				{
					this->speccing_B_B_.setHoverDescription(this->classes_Rain_->getSkillOne()->getName(), this->classes_Rain_->getSkillOne()->getSummary());
				}


				this->is_Selecting_Class_One_ = false;
				this->is_Speccing_Class_One_Points_ = true;
			}
		}
	}
}

void PlayerSkillTree::updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats, int& playerSkillPoints)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		if (this->b_A_.updatePollEvent(ev))
		{
			this->is_Hiding_Skill_Tree_ = true;
		}

		this->updateClassOneSelectPollEvent(ev, stats, playerSkillPoints);

		if (this->is_Speccing_Class_One_Points_)
		{
			//PROGRESS BAR
			if (this->speccing_B_A_.updatePollEvent(ev))
			{
				if (playerSkillPoints > 0)
				{
					this->speccing_Progress_Bar_Amount_++;
					playerSkillPoints--;
				}
			}


			//SKILL ONE 
			if (this->speccing_Progress_Bar_Amount_ >= 1)
			{
				this->speccing_B_B_.updatePollEvent(ev, playerSkillPoints, this->player_Class_One_->setSkillOne());
			}
		}
	}
}

void PlayerSkillTree::updateClassOneSelect(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Selecting_Class_One_)
	{
		this->class_B_A_.updateBoundaries(mousePositionWindow);
	}
}

void PlayerSkillTree::update(const sf::Vector2i& mousePositionWindow, int& playerSkillPoints)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		this->b_A_.updateBoundaries(mousePositionWindow);

		this->updateClassOneSelect(mousePositionWindow);

		if (this->is_Speccing_Class_One_Points_)
		{
			this->speccing_T_B_.setString("SP: " + std::to_string(playerSkillPoints));

			this->speccing_B_A_.updateBoundaries(mousePositionWindow);
			this->speccing_B_B_.update(mousePositionWindow);
		}

		this->b_C_.updateBoundaries(mousePositionWindow);

		this->resizeProgressBar();
	}
}

void PlayerSkillTree::render(sf::RenderTarget& target)
{
	if (!this->is_Hiding_Skill_Tree_)
	{
		target.setView(target.getDefaultView());

		this->x_B_.render(target);
		this->x_A_.render(target);

		this->b_A_.render(target);
		this->t_A_.render(target);

		

		if (this->is_Selecting_Class_One_)
		{
			this->class_T_A_.render(target);

			this->class_B_A_.render(target);
			this->class_B_B_.render(target);
			this->class_B_C_.render(target);
			this->class_B_D_.render(target);

			this->class_X_A_.render(target);
			this->class_X_B_.render(target);

			this->class_T_B_.render(target);
			this->class_T_C_.render(target);

			this->b_C_.render(target);
			this->t_C_.render(target);
		}
		
		if (this->is_Speccing_Class_One_Points_)
		{
			this->t_D_.render(target);

			target.draw(this->speccing_Progress_Bar_Back_);
			target.draw(this->speccing_Progress_Bar_Front_);

			this->speccing_B_A_.render(target);
			this->speccing_B_B_.render(target);

			this->speccing_T_A_.render(target);
			this->speccing_T_B_.render(target);
		}
		
		

		target.setView(target.getDefaultView());
	}

	
}

void PlayerSkillTree::setIsHidingSkillTree(bool value)
{
	this->is_Hiding_Skill_Tree_ = value;
}

Classes* PlayerSkillTree::setClassesOne()
{
	return this->player_Class_One_;
}

Classes* PlayerSkillTree::setClassesTwo()
{
	return this->player_Class_Two_;
}

const bool& PlayerSkillTree::getIsHidingSkillTree() const
{
	return this->is_Hiding_Skill_Tree_;
}

const Classes* PlayerSkillTree::getClassesOne() const
{
	return this->player_Class_One_;
}

const Classes* PlayerSkillTree::getClassesTwo() const
{
	return this->player_Class_Two_;
}
