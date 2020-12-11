#include "PlayerGather.h"

PlayerGather::PlayerGather(const sf::RenderWindow* window, const ResourceFont& resourceFont)
{
	this->x_A_.setSettings(800.f, 500.f, window->getSize().x / 2.f - 800 / 2.f, window->getSize().y / 2.f - 500.f / 2.f, sf::Color::Green, 1.f, sf::Color::White, true);
	this->x_B_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0,0,0,200), 1.f, sf::Color::Transparent, true);
	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Resources", sf::Vector2f(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f)), true);

	this->b_B_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);
	this->t_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);

	this->is_Visible_ = false;

	this->gathered_Items_.resize(3, NULL);

	this->ore_ = new ItemTest(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 40.f), ITEMTYPE::ORE, "Ore", "This is used for crafting armors, weapons, and jewelry.", resourceFont);
	this->wood_ = new ItemTest(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 100.f), ITEMTYPE::WOOD, "Wood", "This is used for crafting arrows, staffs, and bows.", resourceFont);
	this->plant_ = new ItemTest(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 160.f), ITEMTYPE::PLANT, "Plant", "This is used for crafting elixers and poisons.", resourceFont);

	this->ore_->setOreQuantity() = 0;
	this->wood_->setWoodQuantity() = 0;
	this->plant_->setPlantQuantity() = 0;

	this->gathered_Items_.push_back(this->ore_);
	this->gathered_Items_.push_back(this->wood_);
	this->gathered_Items_.push_back(this->plant_);
}

PlayerGather::~PlayerGather()
{
}

void PlayerGather::updatePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Visible_ = false;
		}
	}
}

void PlayerGather::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Visible_)
	{
		this->b_B_.updateBoundaries(mousePositionWindow);

		for (auto& i : this->gathered_Items_)
		{
			if (i != NULL)
			{
				i->update(mousePositionWindow);
			}
		}
	}
}

void PlayerGather::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->x_B_.render(target);
		this->x_A_.render(target);
		this->t_A_.render(target);

		this->b_B_.render(target);
		this->t_B_.render(target);

		for (auto& i : this->gathered_Items_)
		{
			if (i != NULL)
			{
				i->render(target);
			}
		}
	}
}

void PlayerGather::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

std::vector<Item*>& PlayerGather::setGatheredItems()
{
	return this->gathered_Items_;
}

void PlayerGather::setPositionOnResize(const sf::RenderWindow* window)
{
	this->x_A_.setPosition(window->getSize().x / 2.f - 800 / 2.f, window->getSize().y / 2.f - 500.f / 2.f);
	this->x_B_.setSize(window->getSize().x, window->getSize().y);
	this->t_A_.setPosition(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f));

	this->b_B_.setPosition(sf::Vector2f(this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition()));
	this->t_B_.setPosition(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f));

	this->is_Visible_ = false;

	this->gathered_Items_.resize(3, NULL);

	this->ore_->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 40.f)));
	this->wood_->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 100.f)));
	this->plant_->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 160.f)));
}

const bool& PlayerGather::getIsVisible() const
{
	return this->is_Visible_;
}
