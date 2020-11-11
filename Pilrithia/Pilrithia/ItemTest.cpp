#include "ItemTest.h"

ItemTest::ItemTest()
{
	/*
		WILL NOT BE USING DEFAULT CONSTRUCTOR
	*/
}

ItemTest::ItemTest(float posX, float posY, ITEMTYPE itemType)
{
	this->b_A_.setSettings(50.f, 50.f, posX, posY, sf::Color::Blue, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);

	this->item_Type_ = itemType;

	if (this->item_Type_ == ITEMTYPE::HELM)
	{
		this->t_A_.setString("Helm");
	}
	else if (this->item_Type_ == ITEMTYPE::SHOULDER)
	{
		this->t_A_.setString("Shoulder");
	}
	else if (this->item_Type_ == ITEMTYPE::CHEST)
	{
		this->t_A_.setString("Chest");
	}
	else if (this->item_Type_ == ITEMTYPE::GLOVE)
	{
		this->t_A_.setString("Glove");
	}
	else if (this->item_Type_ == ITEMTYPE::LEG)
	{
		this->t_A_.setString("Leg");
	}
	else if (this->item_Type_ == ITEMTYPE::FEET)
	{
		this->t_A_.setString("Feet");
	}
	else if (this->item_Type_ == ITEMTYPE::WEAPON)
	{
		this->t_A_.setString("Weapon");
	}
	else if (this->item_Type_ == ITEMTYPE::OFFHAND)
	{
		this->t_A_.setString("Offhand");
	}
}

ItemTest::~ItemTest()
{
}

void ItemTest::setItemHoverDescriptionSettings(HOVERPOSITION hoverPosition, const sf::FloatRect boundaries, const sf::FloatRect boundariesOffset, DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description)
{
	this->d_A_.setHoverBoundaries(hoverPosition, boundaries, boundariesOffset);
	this->d_A_.setString(descriptionType, title, description);
}

bool ItemTest::updatePollEvent(sf::Event& ev)
{
	if (this->b_A_.updatePollEvent(ev))
	{
		//OPEN MENU
		std::cout << "Clicked item" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool ItemTest::update(const sf::Vector2i& mousePositionWindow)
{
	this->b_A_.updateBoundaries(mousePositionWindow);
	this->d_A_.update(mousePositionWindow);

	if (this->b_A_.getIsHovering())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ItemTest::render(sf::RenderTarget& target)
{
	this->b_A_.render(target);
	
	this->t_A_.render(target);

	this->d_A_.render(target);
}

const sf::FloatRect ItemTest::getItemGlobalBoundaries() const
{
	return this->b_A_.getGlobalBounds();
}

const ITEMTYPE& ItemTest::getItemType() const
{
	return this->item_Type_;
}

const Button& ItemTest::getButton() const
{
	return this->b_A_;
}
