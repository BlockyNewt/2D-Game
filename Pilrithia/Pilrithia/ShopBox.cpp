#include "ShopBox.h"

ShopBox::ShopBox(const ResourceFont& resourceFont, const ResourceItem& resourceItem, const ResourceNpc& resourceNpc)
{
	this->resource_Npc_ = resourceNpc;

	this->x_A_.setSettings(400.f, 500.f, 10.f, 720.f / 2.f - 500.f / 2.f, sf::Color(85, 158, 131), 1.f, sf::Color::White, true);
	this->x_B_.setSettings(620.f, 500.f, this->x_A_.getRightPosition(true, 10.f), 720.f / 2.f - 500.f / 2.f, sf::Color(85, 158, 131), 1.f, sf::Color::White, true);
	this->x_C_.setSettings(1280.f, 720.f, 0.f, 0.f, sf::Color(0, 0, 0, 200), 1.f, sf::Color::Transparent, true);

	this->b_A_.setSettings(50.f, 50.f, this->x_B_.getRightPosition(false, 50.f), this->x_B_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);

	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Shop", sf::Vector2f(this->x_B_.getLeftPosition(true, 100.f), this->x_B_.getTopPosition(true, 10.f)), true);
	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_A_.getLeftPosition(true, 10.f), this->b_A_.getTopPosition(true, 10.f)), true);

	this->is_Visible_ = false;

	this->resource_Font_ = resourceFont;

	this->d_A_.setTextFont(resourceFont);

	this->max_Bag_Size_X_ = 13;
	this->max_Bag_Size_Y_ = 1;
	this->selected_Item_X_ = 0;
	this->selected_Item_Y_ = 0;

	this->player_Max_Bag_Size_X_ = 0;
	this->player_Max_Bag_Size_Y_ = 0;
	this->player_Selected_Item_X_ = 0;
	this->player_Selected_Item_Y_ = 0;

	this->scroll_ = 0;


	/*
		SET SIZE OF BAG
	*/
	this->shop_Items_.resize(this->max_Bag_Size_X_, std::vector<Item*>());
	for (int x = 0; x < this->max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
		{
			this->shop_Items_[x].resize(this->max_Bag_Size_Y_, NULL);
		}
	}

	/*for (int x = 0; x < this->max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
		{
			this->shop_Items_[x][y] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + x * 60.f, this->x_B_.getTopPosition(true, 100.f) + y * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel");
		}
	}*/

	/*
		USE THIS WAY FOR NOW SO WE CAN TEST ITEMS
	*/
	this->shop_Items_[0][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 0 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[1][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 1 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::SHOULDER, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[2][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 2 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::CHEST, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[3][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 3 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::GLOVE, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[4][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 4 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::LEG, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[5][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 5 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::FEET, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[6][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 6 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
	this->shop_Items_[7][0] = new ItemTest(this->x_B_.getLeftPosition(true, 14.f) + 7 * 60.f, this->x_B_.getTopPosition(true, 100.f) + 0 * 60.f, ITEMTYPE::HELM, "Steel helmet", "Made from scrap steel", resourceFont, resourceItem);
}

ShopBox::~ShopBox()
{
	for (auto& x : this->shop_Items_)
	{
		for (auto& y : x)
		{
			if (y != NULL)
			{
				delete y;
			}
		}
	}
}

void ShopBox::alignPlayerBagItems(std::vector<std::vector<Item*>>& playerBag, const int& playerBagMaxSizeX, const int& playerBagMaxSizeY)
{
	this->player_Max_Bag_Size_X_ = playerBagMaxSizeX;
	this->player_Max_Bag_Size_Y_ = playerBagMaxSizeY;

	int xx = 6;
	int xxx = 13;
	for (int x = 0; x < this->player_Max_Bag_Size_X_; ++x)
	{
		for (int y = 0; y < this->player_Max_Bag_Size_Y_; ++y)
		{
			if (playerBag[x][y] != NULL)
			{
				if (y == 0)
				{
					playerBag[x][y]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 10.f) + x * 60.f));
				}
				else if (y == 1)
				{
					xx++;

					playerBag[x][y]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 10.f) + x + 1 + xx * 60.f));
				}
				else if (y == 2)
				{
					xxx++;

					playerBag[x][y]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 10.f) + x + 2 + xxx * 60.f));
				}
			}
		}
	}
}

void ShopBox::handleMoney(bool bOrS, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag)
{
	/*
		bOrS means "Buy or Sell". True for "Buy" and false for "Sell".
	*/

	this->has_Enough_Money_ = false;

	if (bOrS)
	{
		int originalCopper = playerCopper;
		int originalSilver = playerSilver;
		int originalGold = playerGold;

		//COPPER
		if (playerCopper <= this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_]->getCopperPrice())
		{
			int excessCopper = playerCopper - this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_]->getCopperPrice();

			if (playerSilver > 0)
			{
				playerCopper = 99 + excessCopper;

				if (playerSilver - 1 <= 0 &&
					playerGold > 0)
				{
					playerSilver = 99 - 1;

					if (playerGold > 0)
					{
						playerGold--;
						this->has_Enough_Money_ = true;
					}
					else
					{
						//NOT ENOUGH DOUGH
						playerCopper = originalCopper;
						playerSilver = originalSilver;
						playerGold = originalGold;
						std::cout << "DEBUG::SHOPBOX::HANDLEMONEY() -> Not enough gold" << std::endl;
						this->has_Enough_Money_ = false;
					}
				}
				else
				{
					playerSilver--;
					this->has_Enough_Money_ = true;
				}
			}
			else
			{
				//NOT ENOUGH DOUGH
				playerCopper = originalCopper;
				playerSilver = originalSilver;
				playerGold = originalGold;
				std::cout << "DEBUG::SHOPBOX::HANDLEMONEY() -> Not enough silver." << std::endl;
				this->has_Enough_Money_ = false;
			}
		}
		else
		{
			playerCopper -= this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_]->getCopperPrice();
			this->has_Enough_Money_ = true;
		}
	}
	else
	{
		//COPPER 
		if (playerCopper + playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_]->getCopperPrice() > 99)
		{
			int excessCopper = playerCopper - playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_]->getCopperPrice();

			playerCopper = 0 + excessCopper;

			if (playerSilver + 1 >= 99)
			{
				playerSilver = 0;

				if (playerGold + 1 >= 99)
				{
					playerGold = 0;
				}
				else
				{
					playerGold++;
				}
			}
			else
			{
				playerSilver++;
			}
		}
		else
		{
			playerCopper += playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_]->getCopperPrice();
		}

	}
}

void ShopBox::updatePollEvent(sf::Event& ev, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag)
{
	if (this->is_Visible_)
	{
		if (this->b_A_.updatePollEvent(ev))
		{
			this->scroll_ = 0;

			this->is_Visible_ = false;
		}


		/*
			UPDATING WHERE TO POSITION ITEM DROP DOWN LIST ON BUTTON CLICK
		*/
		for (int x = 0; x < this->max_Bag_Size_X_; ++x)
		{
			for (int y = 0; y < this->max_Bag_Size_Y_; ++y)
			{
				if (this->shop_Items_[x][y] != NULL)
				{
					if (this->shop_Items_[x][y]->updatePollEvent(ev))
					{
						if (!this->l_A_.getIsHovering())
						{
							this->l_A_.setSettings(LISTUSE::SHOPBUY, this->shop_Items_[x][y]->getItemGlobalBoundaries(), this->resource_Font_);
							this->l_A_.setIsVisible(true);

							this->selected_Item_X_ = x;
							this->selected_Item_Y_ = y;
						}
					}
				}
			}
		}

		/*
			UPDATING WHERE TO POSITION ITEM DROP DOWN LIST ON BUTTON CLICK
		*/
		for (int x = 0; x < this->player_Max_Bag_Size_X_; ++x)
		{
			for (int y = 0; y < this->player_Max_Bag_Size_Y_; ++y)
			{
				if (playerBag[x][y] != NULL)
				{
					if (playerBag[x][y]->updatePollEvent(ev))
					{
						if (!this->l_A_.getIsHovering())
						{
							this->l_B_.setSettings(LISTUSE::SHOPSELL, playerBag[x][y]->getItemGlobalBoundaries(), this->resource_Font_);
							this->l_B_.setIsVisible(true);

							//HIDE ITEM HOVER DESCRIPTION 

							this->player_Selected_Item_X_ = x;
							this->player_Selected_Item_Y_ = y;
						}
					}
				}
			}
		}



		/*
			BUY POLL EVENT FROM ITEM DROP DOWN LIST
		*/
		if (this->l_A_.updateBuyPollEvent(ev))
		{
			bool purchaseBreak = false;

			this->handleMoney(true, playerGold, playerSilver, playerCopper, playerBag);

			if (this->has_Enough_Money_)
			{
				if (this->resource_Npc_.getNpcSound(NPC_SOUND_TYPE_::PURCHASE)->getStatus() != sf::Sound::Playing)
				{
					this->resource_Npc_.getNpcSound(NPC_SOUND_TYPE_::PURCHASE)->play();
				}

				for (auto& x : playerBag)
				{
					for (auto& y : x)
					{
						if (y == NULL)
						{
							y = this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_]->getNewItem();

							delete this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_];
							this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_] = NULL;

							this->l_A_.setIsVisible(false);
							this->l_A_.setIsHovering(false);

							purchaseBreak = true;

							this->scroll_ = 0;

							this->alignPlayerBagItems(playerBag, this->player_Max_Bag_Size_X_, this->player_Max_Bag_Size_Y_);

							break;
						}
					}

					if (purchaseBreak)
					{
						break;
					}
				}
			}
		}

		/*
			SELL POLL EVENT FROM ITEM DROP DOWN LIST
		*/
		if (this->l_B_.updateSellPollEvent(ev))
		{
			this->handleMoney(false, playerGold, playerSilver, playerCopper, playerBag);

			if (this->resource_Npc_.getNpcSound(NPC_SOUND_TYPE_::PURCHASE)->getStatus() != sf::Sound::Playing)
			{
				this->resource_Npc_.getNpcSound(NPC_SOUND_TYPE_::PURCHASE)->play();
			}

			delete playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_];
			playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_] = NULL;

			this->l_B_.setIsVisible(false);
			this->l_B_.setIsHovering(false);
		}




		if (ev.type == sf::Event::MouseWheelScrolled)
		{
			for (int x = 0; x < this->player_Max_Bag_Size_X_; ++x)
			{
				for (int y = 0; y < this->player_Max_Bag_Size_Y_; ++y)
				{
					if (playerBag[x][y] != NULL)
					{
						if (ev.mouseWheelScroll.delta == 1)
						{
							this->scroll_ = 40;

							playerBag[x][y]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), playerBag[x][y]->getPosition().y + this->scroll_));
						}

						if (ev.mouseWheelScroll.delta == -1)
						{
							this->scroll_ = -40;

							playerBag[x][y]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), playerBag[x][y]->getPosition().y +  this->scroll_));
						}
					}
				}
			}
		}
	}
}

void ShopBox::update(const sf::Vector2i mousePositionWindow, const std::vector<Item*>& playerInventory, std::vector<std::vector<Item*>>& playerBag)
{
	if (this->is_Visible_)
	{
		this->b_A_.updateBoundaries(mousePositionWindow);

		this->player_Bag_ = playerBag;

		for (auto& x : this->shop_Items_)
		{
			for (auto& y : x)
			{
				if (y != NULL)
				{
					if (y->update(mousePositionWindow))
					{
						//UPDATE HOVER DESCRIPTION HERE 
						y->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, y->getItemGlobalBoundaries(), this->x_B_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, y->getName(), y->getDescription());
						


						for (auto a : playerInventory)
						{
							if (a != NULL)
							{
								if (a->getItemType() == y->getItemType())
								{
									this->d_A_.setHoverBoundaries(HOVERPOSITION::BOTTOM, y->getItemGlobalBoundaries(), y->getHoverDescriptionGlobalBounds());
									this->d_A_.setString(DESCRIPTIONTYPE::ITEM, a->getName(), a->getDescription());
								}
							}
						}
					}
				}
			}
		}

		for (auto& x : playerBag)
		{
			for (auto& y : x)
			{
				if (y != NULL)
				{
					if (y->update(mousePositionWindow))
					{
						y->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, y->getItemGlobalBoundaries(), y->getItemGlobalBoundaries(), DESCRIPTIONTYPE::ITEM, y->getName(), y->getDescription());
					}
				}
			}
		}

		this->d_A_.update(mousePositionWindow);

		if (this->l_A_.getIsVisible())
		{
			if (this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_] != NULL)
			{
				this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_]->update(mousePositionWindow);	

				this->l_A_.update(mousePositionWindow, this->shop_Items_[this->selected_Item_X_][this->selected_Item_Y_]->getItemGlobalBoundaries());
			}
		}

		if (this->l_B_.getIsVisible())
		{
			if (playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_] != NULL)
			{
				playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_]->update(mousePositionWindow);

				this->l_B_.update(mousePositionWindow, playerBag[this->player_Selected_Item_X_][this->player_Selected_Item_Y_]->getItemGlobalBoundaries());
			}
		}
	}
}

void ShopBox::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->x_C_.render(target);

		this->x_A_.render(target);
		this->x_B_.render(target);

		this->b_A_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);

		for (auto& x : this->shop_Items_)
		{
			for (auto& y : x)
			{
				if (y != NULL)
				{
					y->render(target);
				}
			}
		}

		for (auto& x : this->player_Bag_)
		{
			for (auto& y : x)
			{
				if (y != NULL)
				{
					if (y->getItemGlobalBoundaries().top >= this->x_A_.getTopPosition() &&
						y->getItemGlobalBoundaries().top + y->getItemGlobalBoundaries().height <= this->x_A_.getBottomPosition())
					{
						y->render(target);
					}
				}
			}
		}


		this->l_A_.render(target);
		this->l_B_.render(target);

		this->d_A_.render(target);
	}
}

void ShopBox::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const bool& ShopBox::getIsVisible() const
{
	return this->is_Visible_;
}
