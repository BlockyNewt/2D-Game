#include "SkillDropDownList.h"

SkillDropDownList::SkillDropDownList()
{
	this->is_Visible_ = false;
	this->is_Hovering_ = false;
}

SkillDropDownList::~SkillDropDownList()
{
}

void SkillDropDownList::setSettings(const sf::FloatRect itemBoundaries, Classes* playerClasses, const ResourceFont& resourceFont)
{
	/*
		IF BUTTONS IS EMPTY
	*/
	if (this->buttons_.empty())
	{
		//std::cout << "DEBUG::SKILLDROPDOWNLIST::SETSETTINGS() -> Size: " << playerClasses->getAvailableSkills().size() << std::endl;


		for (int x = 0; x < playerClasses->getAvailableSkills().size(); ++x)
		{
			/*
				ONLY ADD TEXT AND BUTTONS FOR SKILLS THAT HAVE BEEN UNLOCKED
			*/
			if (playerClasses->getAvailableSkills()[x]->getIsUnlocked())
			{
				Button* button = new Button();
				button->setSettings(200.f, 40.f, itemBoundaries.left - 40.f, itemBoundaries.top - 40.f, sf::Color(195, 203, 113), 1.f, sf::Color::White, true);

				Text* text = new Text();
				text->setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, playerClasses->getAvailableSkills()[x]->getName(), sf::Vector2f(button->getLeftPosition(true, 10.f), button->getTopPosition(true, 10.f)), true);

				this->buttons_.push_back(button);
				this->texts_.push_back(text);
			}
		}

		//std::cout << "DEBUG::SKILLDROPDOWNLIST::SETSETTINGS() -> Size: " << this->buttons_.size() << std::endl;
	}
	else
	{
		/*
			CLEAR AND DELETE POINTERS
		*/
		for (int i = 0; i < this->buttons_.size(); ++i)
		{
			delete this->buttons_[i];
			this->buttons_.erase(this->buttons_.begin() + i);

			delete this->texts_[i];
			this->texts_.erase(this->texts_.begin() + i);
		}

		this->buttons_.clear();
		this->texts_.clear();


		/*
			THEN ONLY ADD TEXT AND BUTTONS FOR SKILLS WHICH ARE UNLOCKED
		*/
		for (int x = 0; x < playerClasses->getAvailableSkills().size(); ++x)
		{
			if (playerClasses->getAvailableSkills()[x]->getIsUnlocked())
			{
				Button* button = new Button();
				button->setSettings(200.f, 40.f, itemBoundaries.left - 40.f, itemBoundaries.top - 40.f, sf::Color::Yellow, 1.f, sf::Color::White, true);

				Text* text = new Text();
				text->setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, playerClasses->getAvailableSkills()[x]->getName(), sf::Vector2f(button->getLeftPosition(true, 10.f), button->getTopPosition(true, 10.f)), true);

				this->buttons_.push_back(button);
				this->texts_.push_back(text);
			}
		}
	}
}

void SkillDropDownList::updatePollEvent(sf::Event& ev, Classes* playerClasses, Skill** hudSkillSlot)
{
	/*
		SINCE BUTTONS AND SKILLS VECTOR POSITION ARE THE SAME THEN YOU CAN JUST SET THE HUD SKILL BASED 
		OFF OF POSITION OF THE BUTTON CLICKED
	*/
	if (!playerClasses->getAvailableSkills().empty())
	{
		for (int i = 0; i < this->buttons_.size(); ++i)
		{
			if (this->buttons_[i]->updatePollEvent(ev))
			{
				if (playerClasses->getAvailableSkills()[i]->getIsUnlocked())
				{
					*hudSkillSlot = playerClasses->getAvailableSkills()[i];

					this->is_Visible_ = false;
				}
			}
		}
	}
	else
	{
		this->is_Visible_ = false;
	}
}

void SkillDropDownList::update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries)
{
	if (this->is_Visible_)
	{
		for (auto& b : this->buttons_)
		{
			b->updateBoundaries(mousePositionWindow);

			if (itemBoundaries.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)) || b->getIsHovering())
			{
				this->is_Hovering_ = true;
			}
			else
			{
				this->is_Hovering_ = false;
				this->is_Visible_ = false;
			}
		}
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
		for (int i = 0; i < this->buttons_.size(); ++i)
		{
			this->buttons_[i]->render(target);
			this->texts_[i]->render(target);
		}
	}
}

void SkillDropDownList::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const bool& SkillDropDownList::getIsVisible() const
{
	return this->is_Visible_;
}
