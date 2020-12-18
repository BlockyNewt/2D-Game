#include "PlayerBag.h"

PlayerBag::PlayerBag(const sf::RenderWindow* window, const ResourceFont& resourceFont, const ResourceHud& resourceHud, const ResourceItem& resourceItem)
{
	this->is_Hiding_Bag_ = true;

	this->resource_Font_ = resourceFont;
	this->resource_Item_ = resourceItem;

	this->bag_Background_Sprite_.setTexture(*resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::BAG));
	this->bag_Background_Sprite_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 800.f / 2.f, window->getSize().y / 2.f - 500.f / 2.f));

	this->x_B_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0, 0, 0, 200), 1.f, sf::Color::Transparent, true);

	this->b_A_.setSettings(34.f, 34.f, this->bag_Background_Sprite_.getGlobalBounds().left + this->bag_Background_Sprite_.getGlobalBounds().width - 38.f, this->bag_Background_Sprite_.getGlobalBounds().top + 4.f, sf::Color::White, 0.f, sf::Color::Transparent, true);
	this->b_A_.setTexture(resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::CLOSE));

	this->t_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 28, "Bag", sf::Vector2f(this->bag_Background_Sprite_.getGlobalBounds().left + 400.f, this->bag_Background_Sprite_.getGlobalBounds().top + 10.f), true);
	


	this->selected_Item_X_ = 0;
	this->selected_Item_Y_ = 0;

	this->max_Bag_Size_X_ = 7;
	this->max_Bag_Size_Y_ = 3;


	this->gold_ = 0;
	this->silver_ = 1;
	this->copper_ = 99;

	this->t_C_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 28, "Gold: " + std::to_string(this->gold_), sf::Vector2f(this->bag_Background_Sprite_.getGlobalBounds().left + 100.f, this->bag_Background_Sprite_.getGlobalBounds().top + this->bag_Background_Sprite_.getGlobalBounds().height - 50.f), true);
	this->t_D_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 28, "Silver: " + std::to_string(this->silver_), sf::Vector2f(this->t_C_.getLeftPosition(true, 200.f), this->bag_Background_Sprite_.getGlobalBounds().top + this->bag_Background_Sprite_.getGlobalBounds().height - 50.f), true);
	this->t_E_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 28, "Copper: " + std::to_string(this->copper_), sf::Vector2f(this->t_D_.getLeftPosition(true, 200.f), this->bag_Background_Sprite_.getGlobalBounds().top + this->bag_Background_Sprite_.getGlobalBounds().height - 50.f), true);
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

	/*
		USE THIS WAY FOR NOW SO WE CAN TEST ITEMS
	*/
	this->items_[0][0] = new ItemTest(0.f, 0.f, ITEMTYPE::HELM, "Steel helmet", "Helmet", this->resource_Font_, this->resource_Item_);
	this->items_[1][0] = new ItemTest(0.f, 0.f, ITEMTYPE::SHOULDER, "Shoulders", "Shoulders", this->resource_Font_, this->resource_Item_);
	this->items_[2][0] = new ItemTest(0.f, 0.f, ITEMTYPE::CHEST, "Chest", "Chest", this->resource_Font_, this->resource_Item_);
	this->items_[3][0] = new ItemTest(0.f, 0.f, ITEMTYPE::GLOVE, "Glove", "Glove", this->resource_Font_, this->resource_Item_);
	this->items_[4][0] = new ItemTest(0.f, 0.f, ITEMTYPE::LEG, "Leg", "Leg", this->resource_Font_, this->resource_Item_);
	this->items_[5][0] = new ItemTest(0.f, 0.f, ITEMTYPE::FEET, "Feet", "Feet", this->resource_Font_, this->resource_Item_);
	this->items_[6][0] = new ItemTest(0.f, 0.f, ITEMTYPE::OFFHAND, "Offhand", "Offhand", this->resource_Font_, this->resource_Item_);

}

void PlayerBag::realignItems()
{
	/*
		WHEN OPENING UP BAG ALIGN ITEMS
	*/
	float rightValue = 0.f;
	for (int x = 0; x < this->max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
		{
			if (this->items_[x][y] != NULL)
			{
				rightValue = 0.f;
				rightValue = (x * 52.f) + (x * 52.f) + 52.f;

				this->items_[x][y]->setPosition(sf::Vector2f(this->bag_Background_Sprite_.getGlobalBounds().left + rightValue, this->bag_Background_Sprite_.getGlobalBounds().top + 73.f + y * 73.f));
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
							this->l_A_.setSettings(LISTUSE::BAG , this->items_[x][y]->getItemGlobalBoundaries(), this->resource_Font_);
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
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::WEAPON)
			{
				equipment[6] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[6]->increaseStatsOnEquip(stats, resistances);
			}
			else if (this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemType() == ITEMTYPE::OFFHAND)
			{
				equipment[7] = this->items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();
				equipment[7]->increaseStatsOnEquip(stats, resistances);
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
						y->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, y->getItemGlobalBoundaries(), this->bag_Background_Sprite_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, y->getName(), y->getDescription());
					}
				}
			}
		}

		//GOING TO WANT TO MAKE A FUNCTION TO SE THIS ON OPENING OF WINDOW
		this->t_C_.setString("Gold: " + std::to_string(this->gold_));
		this->t_D_.setString("Silver: " + std::to_string(this->silver_));
		this->t_E_.setString("Copper: " + std::to_string(this->copper_));


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
		this->x_B_.render(target);
		//this->x_A_.render(target);
		target.draw(this->bag_Background_Sprite_);


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

int& PlayerBag::setGold()
{
	return this->gold_;
}

int& PlayerBag::setSilver()
{
	return this->silver_;
}

int& PlayerBag::setCopper()
{
	return this->copper_;
}

void PlayerBag::setPositionOnResize(const sf::RenderWindow* window)
{
	this->bag_Background_Sprite_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 800.f / 2.f, window->getSize().y / 2.f - 500.f / 2.f));

	this->x_B_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0, 0, 0, 200), 1.f, sf::Color::Transparent, true);

	this->b_A_.setPosition(sf::Vector2f(this->bag_Background_Sprite_.getGlobalBounds().left + this->bag_Background_Sprite_.getGlobalBounds().width - 38.f, this->bag_Background_Sprite_.getGlobalBounds().top + 4.f));

	this->t_B_.setPosition(this->bag_Background_Sprite_.getGlobalBounds().left + 400.f, this->bag_Background_Sprite_.getGlobalBounds().top + 10.f);

	this->t_C_.setPosition(this->bag_Background_Sprite_.getGlobalBounds().left + 100.f, this->bag_Background_Sprite_.getGlobalBounds().top + this->bag_Background_Sprite_.getGlobalBounds().height - 50.f);
	this->t_D_.setPosition(this->t_C_.getLeftPosition(true, 200.f), this->bag_Background_Sprite_.getGlobalBounds().top + this->bag_Background_Sprite_.getGlobalBounds().height - 50.f);
	this->t_E_.setPosition(this->t_D_.getLeftPosition(true, 200.f), this->bag_Background_Sprite_.getGlobalBounds().top + this->bag_Background_Sprite_.getGlobalBounds().height - 50.f);
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

const int& PlayerBag::getGold() const
{
	return this->gold_;
}

const int& PlayerBag::getSilver() const
{
	return this->silver_;
}

const int& PlayerBag::getCopper() const
{
	return this->copper_;
}

const std::vector<std::vector<Item*>>& PlayerBag::getItem() const
{
	return this->items_;
}
