#include "ItemTest.h"

ItemTest::ItemTest()
{
	/*
		WILL NOT BE USING DEFAULT CONSTRUCTOR
	*/
}

ItemTest::ItemTest(float posX, float posY, ITEMTYPE itemType, const std::string& name, const std::string& description, const ResourceFont& resourceFont, const ResourceItem& resourceItem)
{
	std::cout << "A" << std::endl;	
	this->resource_Font_ = resourceFont;
	this->resource_Item_ = resourceItem;
	std::cout << "B" << std::endl;

	this->b_A_.setSettings(50.f, 50.f, posX, posY, sf::Color::White, 0.f, sf::Color::Transparent, true);
	this->b_A_.setTexture(this->resource_Item_.getItemTexture(ITEM_TEXTURE_TYPE_::ITEM_TEST));
	std::cout << "C" << std::endl;


	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "", sf::Vector2f(this->b_A_.getRightPosition(false, 10.f), this->b_A_.getBottomPosition(false, 20.f)), true);
	std::cout << "D" << std::endl;

	this->item_Type_ = itemType;

	this->name_ = name;
	this->description_ = description;

	this->item_Range_.setSize(sf::Vector2f(150.f, 50.f));
	this->item_Range_.setPosition(sf::Vector2f(this->b_A_.getLeftPosition() - 150.f / 2.f + this->b_A_.getSize().x / 2.f, this->b_A_.getTopPosition()));
	this->item_Range_.setFillColor(sf::Color::Transparent);
	this->item_Range_.setOutlineThickness(1.f);
	this->item_Range_.setOutlineColor(sf::Color::Yellow);

	
	if (this->item_Type_ == ITEMTYPE::HELM)
	{
		//this->t_A_.setString("Helm");
		this->b_A_.setTextureRect(sf::IntRect(32, 224, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::SHOULDER)
	{
		this->t_A_.setString("Shoulder");
	}
	else if (this->item_Type_ == ITEMTYPE::CHEST)
	{
		//this->t_A_.setString("Chest");
		this->b_A_.setTextureRect(sf::IntRect(128, 224, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::GLOVE)
	{
		//this->t_A_.setString("Glove");
		this->b_A_.setTextureRect(sf::IntRect(32, 256, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::LEG)
	{
		//this->t_A_.setString("Leg");
		this->b_A_.setTextureRect(sf::IntRect(352, 224, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::FEET)
	{
		//this->t_A_.setString("Feet");
		this->b_A_.setTextureRect(sf::IntRect(64, 256, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::WEAPON)
	{
		//this->t_A_.setString("Weapon");
		this->b_A_.setTextureRect(sf::IntRect(64, 160, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::OFFHAND)
	{
		//this->t_A_.setString("Offhand");
		this->b_A_.setTextureRect(sf::IntRect(0, 192, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::ORE)
	{
		//this->t_A_.setString("Ore");
		this->b_A_.setTextureRect(sf::IntRect(65, 545, 32, 32));

	}
	else if (this->item_Type_ == ITEMTYPE::WOOD)
	{
		//this->t_A_.setString("Wood");
		this->b_A_.setTextureRect(sf::IntRect(0, 544, 32, 32));
	}
	else if (this->item_Type_ == ITEMTYPE::PLANT)
	{
		//this->t_A_.setString("Plant");
		this->b_A_.setTextureRect(sf::IntRect(416, 352, 32, 32));
	}
	else
	{
		std::cout << "DEBUG::ITEMTEST::ITEMTEST() -> Fuck me in the dick." << std::endl;
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

	this->gold_Price_ = 0;
	this->silver_Price_ = 0;
	this->copper_Price_ = 50;

	this->quantity_ = 1;
	this->is_Gather_Box_ = false;
}

ItemTest::~ItemTest()
{
}

void ItemTest::setItemHoverDescriptionSettings(HOVERPOSITION hoverPosition, const sf::FloatRect boundaries, const sf::FloatRect boundariesOffset, DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description)
{
	this->d_A_.setHoverBoundaries(hoverPosition, boundaries, boundariesOffset);
	this->d_A_.setTextFont(this->resource_Font_);
	this->d_A_.setString(descriptionType, title, description);
}

void ItemTest::increaseStatsOnEquip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances)
{
	/*
		CALL THIS WHEN EQUIPPING AN ITEM
		WILL INCREASE STATS ACCORDING ON WHAT THE ITEM HAS
	*/
	if (!stats.empty())
	{
		stats.find("healthMax")->second += this->health_Max_;
		stats.find("manaMax")->second += this->mana_Max_;
		stats.find("strength")->second += this->strength_;
		stats.find("dexerity")->second += this->dexerity_;
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
	/*
		CALL THIS WHEN UNEQUIPPING AN ITEM
		WILL DECREASE STATS ACCORDING ON WHAT THE ITEM HAS
	*/
	if (!stats.empty())
	{
		stats.find("healthMax")->second -= this->health_Max_;
		if (stats.find("health")->second >= stats.find("healthMax")->second)
		{
			stats.find("health")->second = stats.find("healthMax")->second;
		}

		stats.find("manaMax")->second -= this->mana_Max_;
		if (stats.find("mana")->second >= stats.find("manaMax")->second)
		{
			stats.find("mana")->second = stats.find("manaMax")->second;
		}

		stats.find("strength")->second -= this->strength_;
		stats.find("dexerity")->second -= this->dexerity_;
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
		//std::cout << "Clicked item" << std::endl;
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

	this->t_B_.setString(std::to_string(this->quantity_));

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

	if (this->item_Type_ == ITEMTYPE::ORE ||
		this->item_Type_ == ITEMTYPE::WOOD ||
		this->item_Type_ == ITEMTYPE::PLANT)
	{
		if (!this->is_Gather_Box_)
		{
			target.draw(this->item_Range_);
		}

		this->t_B_.render(target);
	}

	if (b_A_.getIsHovering())
	{
		this->d_A_.render(target);
	}
}

void ItemTest::setPosition(const sf::Vector2f& position)
{
	this->b_A_.setPosition(position);
	this->t_A_.setPosition(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f));
}

int& ItemTest::setGoldPrice()
{
	return this->gold_Price_;
}

int& ItemTest::setSilverPrice()
{
	return this->silver_Price_;
}

int& ItemTest::setCopperPrice()
{
	return this->copper_Price_;
}

int& ItemTest::setQuantity()
{
	return this->quantity_;
}

void ItemTest::setShowGatherBox(bool showGatherBox)
{
	this->is_Gather_Box_ = showGatherBox;
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

const sf::FloatRect ItemTest::getHoverDescriptionGlobalBounds() const
{
	return this->d_A_.getGlobalBounds();
}

Item* ItemTest::getNewItem()
{
	return new ItemTest(0.f, 0.f, this->item_Type_, this->name_, this->description_, this->resource_Font_, this->resource_Item_);
}

const int& ItemTest::getGoldPrice() const
{
	return this->gold_Price_;
}

const int& ItemTest::getSilverPrice() const
{
	return this->silver_Price_;
}

const int& ItemTest::getCopperPrice() const
{
	return this->copper_Price_;
}

const sf::Vector2f& ItemTest::getPosition() const
{
	return this->b_A_.getPosition();
}

const sf::FloatRect ItemTest::getItemRange() const
{
	return this->item_Range_.getGlobalBounds();
}

const int& ItemTest::getQuantity() const
{
	return this->quantity_;
}
