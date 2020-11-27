#include "LootWindow.h"

LootWindow::LootWindow(const ResourceFont& resourceFont)
{
	this->x_A_.setSettings(400.f, 500.f, 420.f, 100.f, sf::Color(90, 82, 85), 1.f, sf::Color::White, true);
	this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Loot", sf::Vector2f(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f)), true);

	this->b_B_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);
	this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);

	this->is_Visible_ = false;

	this->selected_Item_X_ = 0;

	this->resource_Font_ = resourceFont;

}

LootWindow::~LootWindow()
{
	for (int i = 0; i < this->loot_.size(); ++i)
	{
		if (this->loot_[i] != NULL)
		{
			delete this->loot_[i];
		}
		else
		{
			std::cout << "DEBUG::LOOTWINDOW::~LOOTWINDOW() -> It was null." << std::endl;
		}
	}
}

void LootWindow::addEnemyItems(std::vector<Item*>& enemyItems)
{
	/*
		ADD THE ITEMS THE ENEMY HAS INTO THE LOOT WINDOW (CALL THIS IN ENEMY CONSTRUCTOR
	*/
	for (int i = 0; i < enemyItems.size(); ++i)
	{
		this->loot_.push_back(enemyItems[i]);
		this->loot_[i]->setPosition(sf::Vector2f(this->x_A_.getLeftPosition(true, 5.f), this->x_A_.getTopPosition(true, 100.f) + i * 60.f));
	}

	for (int i = 0; i < this->loot_.size(); ++i)
	{
		std::cout << this->loot_[i]->getName() << std::endl;
	}
}

void LootWindow::updatePollEvent(sf::Event& ev, std::vector<std::vector<Item*>>& playerBag, const int& maxBagSizeX, const int& maxBagSizeY)
{
	if (this->is_Visible_)
	{
		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Visible_ = false;
		}

		/*
			ITEM DROP DOWN LIST POLL UPDATES
		*/
		for (int x = 0; x < this->loot_.size(); ++x)
		{
			if (this->loot_[x] != NULL)
			{
				if (this->loot_[x]->updatePollEvent(ev))
				{
					this->l_A_.setSettings(LISTUSE::LOOT, this->loot_[x]->getItemGlobalBoundaries(), this->resource_Font_);
					this->l_A_.setIsVisible(true);

					this->selected_Item_X_ = x;
				}
			}
		}

		/*
			ITEM DROP DOWN LIST TAKE POLL UPDATE
		*/
		if (this->l_A_.updateTakePollEvent(ev))
		{
			bool isBreaking = false;
			for (int x = 0; x < maxBagSizeX; ++x)
			{
				for (int y = 0; y < maxBagSizeY; ++y)
				{
					if (playerBag[x][y] == NULL)
					{
						playerBag[x][y] = this->loot_[this->selected_Item_X_]->getNewItem();

						delete this->loot_[this->selected_Item_X_];
						this->loot_[this->selected_Item_X_] = NULL;

						this->loot_.erase(this->loot_.begin() + this->selected_Item_X_);

						isBreaking = true;

						break;
					}
				}

				if (isBreaking)
				{
					break;
				}
			}

			this->l_A_.setIsVisible(false);
			this->l_A_.setIsHovering(false);
		}
	}
}

void LootWindow::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Visible_)
	{
		this->b_B_.updateBoundaries(mousePositionWindow);

		/*
			CHANGE HOVER DESCRIPTION BASED ON THE ITEM YOU ARE HOVERING OVER
		*/
		for (auto& b : this->loot_)
		{
			if (b != NULL)
			{
				if (b->update(mousePositionWindow))
				{
					b->setItemHoverDescriptionSettings(HOVERPOSITION::LEFT, b->getItemGlobalBoundaries(), this->x_A_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, b->getName(), b->getDescription());
				}
			}
		}

		if (this->l_A_.getIsVisible())
		{
			if (this->loot_[this->selected_Item_X_] != NULL)
			{
				this->loot_[this->selected_Item_X_]->update(mousePositionWindow);	

				this->l_A_.update(mousePositionWindow, this->loot_[this->selected_Item_X_]->getItemGlobalBoundaries());
			}
		}
	}
}

void LootWindow::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->x_A_.render(target);
		this->t_A_.render(target);

		this->b_B_.render(target);
		this->t_B_.render(target);

		for (auto& l : this->loot_)
		{
			if (l != NULL)
			{
				l->render(target);
			}
		}

		this->l_A_.render(target);
	}
}

void LootWindow::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;

}

const int& LootWindow::getSize() const
{
	return this->loot_.size();
}

const bool& LootWindow::getIsVisible() const
{
	return this->is_Visible_;
}
