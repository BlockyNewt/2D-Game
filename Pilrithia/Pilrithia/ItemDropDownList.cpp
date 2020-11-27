#include "ItemDropDownList.h"

ItemDropDownList::ItemDropDownList()
{
	this->is_Visible_ = false;
}

ItemDropDownList::~ItemDropDownList()
{
}

void ItemDropDownList::setSettings(LISTUSE listUse, const sf::FloatRect itemBoundaries, const ResourceFont& resourceFont)
{
	/*
		DEPENDING ON WHAT USE IT IS, IT WILL SET A DIFFERENT LAYOUT 
	*/
	if (listUse == LISTUSE::INVENTORY)
	{
		this->b_A_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Transparent, 0.f, sf::Color::Transparent, false);
		this->b_B_.setSettings(150.f, 40.f, itemBoundaries.left + itemBoundaries.width, itemBoundaries.top, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
		this->b_C_.setSettings(150.f, 40.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 1.f), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
		this->b_D_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Transparent, 0.f, sf::Color::Transparent, false);

		this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);
		this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Unequip", sf::Vector2f(this->b_B_.getGlobalBounds().left + 10.f, this->b_B_.getGlobalBounds().top + 10.f), true);
		this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Delete", sf::Vector2f(this->b_C_.getGlobalBounds().left + 10.f, this->b_C_.getGlobalBounds().top + 10.f), true);
		this->t_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);

	}
	
	else if (listUse == LISTUSE::BAG)
	{
		this->b_A_.setSettings(150.f, 40.f, itemBoundaries.left + itemBoundaries.width, itemBoundaries.top, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
		this->b_B_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Transparent, 0.f, sf::Color::Transparent, false);
		this->b_C_.setSettings(150.f, 40.f, this->b_A_.getLeftPosition(), this->b_A_.getBottomPosition(true, 1.f), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
		this->b_D_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Transparent, 0.f, sf::Color::Transparent, false);

		this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Equip", sf::Vector2f(this->b_A_.getGlobalBounds().left + 10.f, this->b_A_.getGlobalBounds().top + 10.f), true);
		this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);
		this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Delete", sf::Vector2f(this->b_C_.getGlobalBounds().left + 10.f, this->b_C_.getGlobalBounds().top + 10.f), true);
		this->t_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);

	}

	else if (listUse == LISTUSE::LOOT)
	{
		this->b_A_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Red, 0.f, sf::Color::White, false);
		this->b_B_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Transparent, 0.f, sf::Color::Transparent, false);
		this->b_C_.setSettings(0.f, 0.f, 0.f, 0.f, sf::Color::Transparent, 0.f, sf::Color::Transparent, false);
		this->b_D_.setSettings(150.f, 40.f, itemBoundaries.left + itemBoundaries.width, itemBoundaries.top, sf::Color(174, 90, 65), 1.f, sf::Color::White, true);

		this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);
		this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);
		this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 0, "", sf::Vector2f(0.f, 0.f), false);
		this->t_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Take", sf::Vector2f(this->b_D_.getGlobalBounds().left + 10.f, this->b_D_.getGlobalBounds().top + 10.f), true);

	}
}

bool ItemDropDownList::updateEquipPollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->b_A_.getIsHovering())
		{
			if (this->b_A_.updatePollEvent(ev))
			{
				std::cout << "Equip clicked" << std::endl;

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

bool ItemDropDownList::updateUnequipPollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->b_B_.getIsHovering())
		{
			if (this->b_B_.updatePollEvent(ev))
			{
				std::cout << "Unequip clicked" << std::endl;

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

bool ItemDropDownList::updateDeletePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->b_C_.getIsHovering())
		{
			if (this->b_C_.updatePollEvent(ev))
			{
				//std::cout << "Delete" << std::endl;

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

bool ItemDropDownList::updateTakePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->b_D_.getIsHovering())
		{
			if (this->b_D_.updatePollEvent(ev))
			{
				std::cout << "take clicked" << std::endl;

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

void ItemDropDownList::update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries)
{
	if (this->is_Visible_)
	{
		this->b_A_.updateBoundaries(mousePositionWindow);
		this->b_B_.updateBoundaries(mousePositionWindow);
		this->b_C_.updateBoundaries(mousePositionWindow);
		this->b_D_.updateBoundaries(mousePositionWindow);

		if (itemBoundaries.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)) || this->b_A_.getIsHovering())
		{
			this->is_Hovering_ = true;

		}
		

		else if (itemBoundaries.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)) || this->b_B_.getIsHovering())
		{
			this->is_Hovering_ = true;

		}

		else if (itemBoundaries.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)) || this->b_C_.getIsHovering())
		{
			this->is_Hovering_ = true;

		}

		else if (itemBoundaries.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)) || this->b_D_.getIsHovering())
		{
			this->is_Hovering_ = true;

		}

		else
		{
			this->is_Hovering_ = false;
			this->is_Visible_ = false;
		}
	}
	else
	{
		this->is_Hovering_ = false;
	}
}

void ItemDropDownList::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->b_A_.render(target);
		this->b_B_.render(target);
		this->b_C_.render(target);
		this->b_D_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);
		this->t_C_.render(target);
		this->t_D_.render(target);
	}
}

void ItemDropDownList::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void ItemDropDownList::setIsHovering(bool isHovering)
{
	this->is_Hovering_ = false;
}

const bool& ItemDropDownList::getIsVisible() const
{
	return this->is_Visible_;
}

const bool& ItemDropDownList::getIsHovering() const
{
	return this->is_Hovering_;
}
