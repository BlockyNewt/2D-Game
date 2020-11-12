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

	this->selected_Item_X_ = 0;
	this->selected_Item_Y_ = 0;

	this->max_Bag_Size_X_ = 13;
	this->max_Bag_Size_Y_ = 1;
}

PlayerBag::~PlayerBag()
{
}

void PlayerBag::initializeBag()
{
	/*
		SET SIZE OF BAG 
	*/

	this->items_.resize(this->max_Bag_Size_X_, std::vector<Item*>());
	for (int x = 0; x < this->max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
		{
			this->items_[x].resize(this->max_Bag_Size_Y_, NULL);
		}
	}

	/*for (int x = 0; x < this->max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
		{
			this->items_[x][y] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + x * 60.f, this->x_A_.getTopPosition(true, 100.f) + y * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel");
		}
	}*/

	this->items_[0][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 0 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel");
	this->items_[1][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 1 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::SHOULDER, "Steel helmet", "Made from scrap steel");
	this->items_[2][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 2 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::CHEST, "Steel helmet", "Made from scrap steel");
	this->items_[3][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 3 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::GLOVE, "Steel helmet", "Made from scrap steel");
	this->items_[4][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 4 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::LEG, "Steel helmet", "Made from scrap steel");
	this->items_[5][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 5 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::FEET, "Steel helmet", "Made from scrap steel");
	this->items_[6][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 6 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel");
	this->items_[7][0] = new ItemTest(this->x_A_.getLeftPosition(true, 14.f) + 7 * 60.f, this->x_A_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel");

}

void PlayerBag::realignItems()
{
	for (int x = 0; x < this->max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
		{
			if (this->items_[x][y] != NULL)
			{
				this->items_[x][y]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 14.f) + x * 60.f, this->x_A_.getTopPosition(true, 100.f) + y * 60.f));
			}
		}
	}
}

void PlayerBag::updatePollEvent(sf::Event& ev, std::vector<Item*>& equipment, std::map<std::string, int>& stats, std::map<std::string, int>& resistances)
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
		for (int x = 0; x < this->max_Bag_Size_X_; ++x)
		{
			for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
			{
				if (this->items_[x][y] != NULL)
				{
					if (this->items_[x][y]->updatePollEvent(ev))
					{
						if (!this->l_A_.getIsHovering())
						{
							this->l_A_.setSettings(LISTUSE::BAG , this->items_[x][y]->getItemGlobalBoundaries());
							this->l_A_.setIsVisible(true);

							this->selected_Item_X_ = x;
							this->selected_Item_Y_ = y;
						}
					}
				}
			}
		}

		
		/*
			DROP DOWN LIST EQUIP POLL EVENT
		*/
		if (this->l_A_.updateEquipPollEvent(ev))
		{
			//EQUIP ITEM
			//PROBABLY MAKE FUNCTION FOR THIS
			if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::HELM)
			{
				equipment[0] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[0]->increaseStatsOnEquip(stats, resistances);
			}
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::SHOULDER)
			{
				equipment[1] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[1]->increaseStatsOnEquip(stats, resistances);
			}
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::CHEST)
			{
				equipment[2] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[2]->increaseStatsOnEquip(stats, resistances);
			}
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::GLOVE)
			{
				equipment[3] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[3]->increaseStatsOnEquip(stats, resistances);
			}
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::LEG)
			{
				equipment[4] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[4]->increaseStatsOnEquip(stats, resistances);
			}
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::FEET)
			{
				equipment[5] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[5]->increaseStatsOnEquip(stats, resistances);
			}
			else
			{
				std::cout << "Not an item" << std::endl;
			}

			delete this->items_[this->selected_Item_X_][this->selected_Item_Y_];
			this->items_[this->selected_Item_X_][this->selected_Item_Y_] = NULL;


			this->l_A_.setIsHovering(false);
			this->l_A_.setIsVisible(false);
		}

		/*
			DROP DOWN LIST UNEQUIP POLL EVENT
		*/
		if (this->l_A_.updateUnequipPollEvent(ev))
		{
			//UNEQUIP ITEM
		}

		/*
			DROP DOWN LIST DELETE POLL EVENT
		*/
		if (this->l_A_.updateDeletePollEvent(ev))
		{
			//DELETE ITEM
			
			delete this->items_[this->selected_Item_X_][this->selected_Item_Y_];
			this->items_[this->selected_Item_X_][this->selected_Item_Y_] = NULL;

			this->l_A_.setIsHovering(false);
			this->l_A_.setIsVisible(false);
		}
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
				if (y != NULL)
				{
					if (y->update(mousePositionWindow))
					{
						//this->d_A_.update(mousePositionWindow);
						//this->d_A_.setHoverBoundaries(HOVERPOSITION::RIGHT, this->x_A_.getGlobalBounds());

						////SEND ITEM NAME, DESCIPRITON, AND EFFECTS IF ANY HERE
						//this->d_A_.setString(DESCRIPTIONTYPE::ITEM, "Item", "Test");

						y->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, y->getItemGlobalBoundaries(), this->x_A_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, y->getName(), y->getDescription());
					}
				}
			}
		}


		/*
			IF THE DROP DOWN LIST IS VISIBLE THEN UPDATE THAT 
		*/
		if (this->l_A_.getIsVisible())
		{
			if (this->items_[this->selected_Item_X_][this->selected_Item_Y_] != NULL)
			{
				this->items_[this->selected_Item_X_][this->selected_Item_Y_]->update(mousePositionWindow);
				
				this->l_A_.update(mousePositionWindow, this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemGlobalBoundaries());
			}
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
				if (y != NULL)
				{
					y->render(target);
				}
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

void PlayerBag::setMaxBagSizeY(int value)
{
	this->max_Bag_Size_Y_ = value;
}

std::vector<std::vector<Item*>>& PlayerBag::setItem()
{
	return this->items_;
}

const bool& PlayerBag::getIsHidingBag() const
{
	return this->is_Hiding_Bag_;
}

const unsigned& PlayerBag::getBagSizeX() const
{
	return this->max_Bag_Size_X_;
}

const unsigned& PlayerBag::getBagSizeY() const
{
	return this->max_Bag_Size_Y_;
}
