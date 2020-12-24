#include "PlayerGather.h"

PlayerGather::PlayerGather(const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceItem* resourceItem)
{
	this->x_A_.setSettings(800.f, 500.f, window->getSize().x / 2.f - 800 / 2.f, window->getSize().y / 2.f - 500.f / 2.f, sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->x_A_.setTexture(resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::WINDOW));
	this->x_B_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0,0,0,200), 1.f, sf::Color::Transparent, true);
	this->t_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 28, "Resources", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);

	this->b_B_.setSettings(35.f, 35.f, this->x_A_.getRightPosition(false, 39.f), this->x_A_.getTopPosition(true, 4.f), sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->b_B_.setTexture(resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::CLOSE));

	this->is_Visible_ = false;

	//this->gathered_Items_.resize(3, NULL);

	this->ore_ = new ItemTest(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 40.f), ITEMTYPE::ORE, "Ore", "This is used for crafting armors, weapons, and jewelry.", resourceFont, resourceItem);
	this->wood_ = new ItemTest(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 100.f), ITEMTYPE::WOOD, "Wood", "This is used for crafting arrows, staffs, and bows.", resourceFont, resourceItem);
	this->plant_ = new ItemTest(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 160.f), ITEMTYPE::PLANT, "Plant", "This is used for crafting elixers and poisons.", resourceFont, resourceItem);

	this->ore_->setQuantity() = 0;
	this->wood_->setQuantity() = 0;
	this->plant_->setQuantity() = 0;

	this->ore_->setShowGatherBox(true);
	this->wood_->setShowGatherBox(true);
	this->plant_->setShowGatherBox(true);

	this->gathered_Items_.push_back(this->wood_);
	this->gathered_Items_.push_back(this->ore_);
	this->gathered_Items_.push_back(this->plant_);
}

PlayerGather::~PlayerGather()
{
	if (!this->gathered_Items_.empty())
	{
		for (int x = 0; x < this->gathered_Items_.size(); ++x)
		{
			delete this->gathered_Items_[x];
			this->gathered_Items_.erase(this->gathered_Items_.begin() + x);
		}
	}

	std::cout << "DEBUG::PLAYERGATHER::~PLAYERGATHER() -> Deconstructed." << std::endl;
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
