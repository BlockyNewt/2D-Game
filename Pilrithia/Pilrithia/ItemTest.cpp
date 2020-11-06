#include "ItemTest.h"

ItemTest::ItemTest()
{
	/*
		WILL NOT BE USING DEFAULT CONSTRUCTOR
	*/
}

ItemTest::ItemTest(float posX, float posY)
{
	this->b_A_.setSettings(50.f, 50.f, posX, posY, sf::Color::Blue, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 18, "Test item", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);

	this->item_Type_ = ITEMTYPE::ARMOR;
}

ItemTest::~ItemTest()
{
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
	if (this->b_A_.updateBoundariesValue(mousePositionWindow))
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
}

const sf::FloatRect ItemTest::getItemGlobalBoundaries() const
{
	return this->b_A_.getGlobalBounds();
}
