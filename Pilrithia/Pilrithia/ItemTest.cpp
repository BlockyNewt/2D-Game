#include "ItemTest.h"

ItemTest::ItemTest()
{
	/*
		WILL NOT BE USING DEFAULT CONSTRUCTOR
	*/
}

ItemTest::ItemTest(float posX, float posY, ITEMTYPE itemType, const std::string& name, const std::string& description)
{
	this->b_A_.setSettings(50.f, 50.f, posX, posY, sf::Color::Blue, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);

	this->item_Type_ = itemType;

	this->name_ = name;
	this->description_ = description;

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
	else
	{
		std::cout << "fuck me in the dick" << std::endl;
	}


	this->health_Max_ = 200;
	this->mana_Max_ = 0;
	this->strength_ = 100;
	this->dexerity_ = 0;
	this->constitution_ = 0;
	this->intelligence_ = 0;
	this->constitution_ = 0;
	this->perception_ = 30;
	this->wisdom_ = 0;
	

	this->cold_ = 5;
	this->fire_ = 5;
	this->lightning_ = 5;
	this->poison_ = 5;
}

ItemTest::~ItemTest()
{
}

void ItemTest::setItemHoverDescriptionSettings(HOVERPOSITION hoverPosition, const sf::FloatRect boundaries, const sf::FloatRect boundariesOffset, DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description)
{
	this->d_A_.setHoverBoundaries(hoverPosition, boundaries, boundariesOffset);
	this->d_A_.setString(descriptionType, title, description);
}

void ItemTest::increaseStatsOnEquip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances)
{
	if (!stats.empty())
	{
		stats.find("health")->second += this->health_Max_;
		stats.find("mana")->second += this->mana_Max_;
		stats.find("strength")->second += this->strength_;
		stats.find("dexerity")->second += this->dexerity_;
		stats.find("constitution")->second += this->constitution_;
		stats.find("intelligence")->second += this->intelligence_;
		stats.find("perception")->second += this->perception_;
		stats.find("wisdom")->second += this->wisdom_;
	}

	if (!resistances.empty())
	{
		resistances.find("cold")->second += this->cold_;
		resistances.find("fire")->second += this->fire_;
		resistances.find("lightning")->second += this->lightning_;
		resistances.find("poison")->second += this->poison_;
	}
}

void ItemTest::descreaseStatsOnUnequip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances)
{
	if (!stats.empty())
	{
		stats.find("health")->second -= this->health_Max_;
		stats.find("mana")->second -= this->mana_Max_;
		stats.find("strength")->second -= this->strength_;
		stats.find("dexerity")->second -= this->dexerity_;
		stats.find("constitution")->second -= this->constitution_;
		stats.find("intelligence")->second -= this->intelligence_;
		stats.find("perception")->second -= this->perception_;
		stats.find("wisdom")->second -= this->wisdom_;
	}

	if (!resistances.empty())
	{
		resistances.find("cold")->second -= this->cold_;
		resistances.find("fire")->second -= this->fire_;
		resistances.find("lightning")->second -= this->lightning_;
		resistances.find("poison")->second -= this->poison_;
	}
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

void ItemTest::setPosition(const sf::Vector2f& position)
{
	this->b_A_.setPosition(position);
	this->t_A_.setPosition(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f));
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

const std::string& ItemTest::getName() const
{
	return this->name_;
}

const std::string& ItemTest::getDescription() const
{
	return this->description_;
}

Item* ItemTest::getNewItem()
{
	return new ItemTest(0.f, 0.f, this->item_Type_, this->name_, this->description_);
}
