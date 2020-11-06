#include "ItemDropDownList.h"

ItemDropDownList::ItemDropDownList()
{
	this->is_Visible_ = false;
}

ItemDropDownList::~ItemDropDownList()
{
}

void ItemDropDownList::setSettings(int itemType, const sf::FloatRect itemBoundaries)
{
	if (itemType == 1)
	{
		this->b_A_.setSettings(150.f, 40.f, itemBoundaries.left + itemBoundaries.width, itemBoundaries.top, sf::Color::Red, 1.f, sf::Color::White, true);
		this->b_B_.setSettings(150.f, 40.f, this->b_A_.getLeftPosition(), this->b_A_.getBottomPosition(true, 1.f), sf::Color::Red, 1.f, sf::Color::White, true);

		this->t_A_.setSettings("Font/arial.ttf", 18, "Equip", sf::Vector2f(this->b_A_.getGlobalBounds().left + 10.f, this->b_A_.getGlobalBounds().top + 10.f), true);
		this->t_B_.setSettings("Font/arial.ttf", 18, "Unequip", sf::Vector2f(this->b_B_.getGlobalBounds().left + 10.f, this->b_B_.getGlobalBounds().top + 10.f), true);
	}
}

void ItemDropDownList::updatePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->is_Hovering_)
		{
			if (this->b_A_.updatePollEvent(ev))
			{
				//std::cout << "Equip clicked" << std::endl;
			}

			else if (this->b_B_.updatePollEvent(ev))
			{
				//std::cout << "Unequip clicked" << std::endl;
			}
		}
	}
}

bool ItemDropDownList::update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect itemBoundaries)
{
	if (this->is_Visible_)
	{
		if(this->b_A_.updateBoundariesValue(mousePositionWindow) ||
		   this->b_B_.updateBoundariesValue(mousePositionWindow) ||
		   itemBoundaries.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
		{
			this->is_Hovering_ = true;

			return true;
		}
		else
		{
			this->is_Hovering_ = false;

			this->is_Visible_ = false;

			return false;
		}
	}
	else
	{
		return false;
	}
}

void ItemDropDownList::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->b_A_.render(target);
		this->b_B_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);
	}
}

void ItemDropDownList::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const bool& ItemDropDownList::getIsVisible() const
{
	return this->is_Visible_;
}

const bool& ItemDropDownList::getIsHovering() const
{
	return this->is_Hovering_;
}
