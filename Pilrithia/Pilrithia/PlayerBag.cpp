#include "PlayerBag.h"

PlayerBag::PlayerBag()
{
	this->is_Hiding_Bag_ = true;


	this->x_A_.setSettings(800.f, 500.f, 0.f, 0.f, sf::Color::Green, 1.f, sf::Color::White, true);

	this->b_A_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 18, "Close", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings("Font/arial.ttf", 28, "Bag", sf::Vector2f(this->x_A_.getLeftPosition(true, 400.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_C_.setSettings("Font/arial.ttf", 28, "Gold", sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getBottomPosition(false, 40.f)), true);
	this->t_D_.setSettings("Font/arial.ttf", 28, "Silver", sf::Vector2f(this->t_C_.getRightPosition(true, 200.f), this->x_A_.getBottomPosition(false, 40.f)), true);
	this->t_E_.setSettings("Font/arial.ttf", 28, "Copper", sf::Vector2f(this->t_D_.getRightPosition(true, 200.f), this->x_A_.getBottomPosition(false, 40.f)), true);
}

PlayerBag::~PlayerBag()
{
}

void PlayerBag::initializeBag(int maxBagSize)
{
	/*
		SET SIZE OF BAG 
	*/

	this->max_Bag_Size_ = maxBagSize;

	this->items_.resize(13, std::vector<Item*>());
	for (int x = 0; x < 13; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			this->items_[x].resize(5, NULL);
		}
	}

	for (int x = 0; x < 13; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			this->items_[x][y] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + x * 60.f, this->x_A_.getTopPosition(true, 100.f) + y * 60.f);
		}
	}
}

void PlayerBag::updatePollEvent(sf::Event& ev)
{
	/*
		UPDATE POLL EVENTS FOR BAG 
	*/

	if (!this->is_Hiding_Bag_)
	{
		/*
			CLOSE BUTTON
		*/
		if (this->b_A_.updatePollEvent(ev))
		{
			this->is_Hiding_Bag_ = true;
		}

		/*
			IF AN ITEM IS CLICKED THEN SHOW THE DROP DOWN LIST
		*/
		for (int x = 0; x < 13; ++x)
		{
			for (int y = 0; y < 5; ++y)
			{
				if (this->items_[x][y]->updatePollEvent(ev))
				{
					if (!this->l_A_.getIsHovering())
					{
						this->l_A_.setSettings(1, this->items_[x][y]->getItemGlobalBoundaries());
						this->l_A_.setIsVisible(true);

						this->selected_Item_X_ = x;
						this->selected_Item_Y_ = y;
					}
				}
			}
		}

		/*
			UPDATE DROP DOWN LIST POLL EVENTS
		*/
		this->l_A_.updatePollEvent(ev);
	}
}

void PlayerBag::update(const sf::Vector2i& mousePositionWindow)
{
	if (!this->is_Hiding_Bag_)
	{
		this->b_A_.updateBoundaries(mousePositionWindow);

		/*
			UPDATE POSITION OF HOVER DESCRIPTION
		*/
		for (auto& x : this->items_)
		{
			for (auto& y : x)
			{
				if (y->update(mousePositionWindow))
				{
					this->d_A_.update(mousePositionWindow);
					this->d_A_.setHoverBoundaries(y->getItemGlobalBoundaries());

					//SEND ITEM NAME, DESCIPRITON, AND EFFECTS IF ANY HERE
					this->d_A_.setString("Testing");
				}
				
			}
		}

		/*
			IF THE DROP DOWN LIST IS VISIBLE THEN UPDATE THAT 
		*/
		if (this->l_A_.getIsVisible())
		{
			this->items_[this->selected_Item_X_][this->selected_Item_Y_]->update(mousePositionWindow);
			this->l_A_.update(mousePositionWindow, this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemGlobalBoundaries());
		}
	}
}

void PlayerBag::render(sf::RenderTarget& target)
{
	if (!this->is_Hiding_Bag_)
	{
		this->x_A_.render(target);

		for (auto& x : this->items_)
		{
			for (auto& y : x)
			{
				y->render(target);
			}
		}
		

		this->l_A_.render(target);

		this->b_A_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);
		this->t_C_.render(target);
		this->t_D_.render(target);
		this->t_E_.render(target);

		this->d_A_.render(target);

	}
}

void PlayerBag::setIsHidingBag(bool isHidingBag)
{
	this->is_Hiding_Bag_ = isHidingBag;
}

const bool& PlayerBag::getIsHidingBag() const
{
	return this->is_Hiding_Bag_;
}
