#include "PlayerInventory.h"

void PlayerInventory::initializeStats(const ResourceFont& resourceFont)
{
	/*
		SET SETTINGS FOR STAT RELATED OBJECTS
	*/
	this->stats_T_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Stats", sf::Vector2f(this->x_B_.getLeftPosition(false, 200.f), this->x_B_.getTopPosition(true, 40.f)), true);
	this->stats_T_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Health: ", sf::Vector2f(this->stats_T_A_.getLeftPosition(false, 0.f), this->stats_T_A_.getTopPosition(true, 40.f)), true);
	this->stats_T_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Mana: ", sf::Vector2f(this->stats_T_A_.getLeftPosition(false, 0.f), this->stats_T_B_.getTopPosition(true, 30.f)), true);
	this->stats_T_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Strength: ", sf::Vector2f(this->stats_T_A_.getLeftPosition(false, 0.f), this->stats_T_C_.getTopPosition(true, 30.f)), true);
	this->stats_T_E_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Dexerity: ", sf::Vector2f(this->stats_T_B_.getLeftPosition(), this->stats_T_D_.getTopPosition(true, 30.f)), true);
	this->stats_T_G_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Intelligence: ", sf::Vector2f(this->stats_T_B_.getLeftPosition(), this->stats_T_E_.getTopPosition(true, 30.f)), true);
	this->stats_T_H_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Perception: ", sf::Vector2f(this->stats_T_B_.getLeftPosition(), this->stats_T_G_.getTopPosition(true, 30.f)), true);
	this->stats_T_I_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Wisdom: ", sf::Vector2f(this->stats_T_B_.getLeftPosition(), this->stats_T_H_.getTopPosition(true, 30.f)), true);

	this->stats_D_B_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_B_.getGlobalBounds(), this->stats_T_B_.getGlobalBounds());
	this->stats_D_C_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_C_.getGlobalBounds(), this->stats_T_C_.getGlobalBounds());
	this->stats_D_D_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_D_.getGlobalBounds(), this->stats_T_D_.getGlobalBounds());
	this->stats_D_E_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_E_.getGlobalBounds(), this->stats_T_E_.getGlobalBounds());
	this->stats_D_G_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_G_.getGlobalBounds(), this->stats_T_G_.getGlobalBounds());
	this->stats_D_H_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_H_.getGlobalBounds(), this->stats_T_H_.getGlobalBounds());
	this->stats_D_I_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_I_.getGlobalBounds(), this->stats_T_I_.getGlobalBounds());

	this->stats_D_B_.setTextFont(resourceFont);
	this->stats_D_C_.setTextFont(resourceFont);
	this->stats_D_D_.setTextFont(resourceFont);
	this->stats_D_E_.setTextFont(resourceFont);
	this->stats_D_G_.setTextFont(resourceFont);
	this->stats_D_H_.setTextFont(resourceFont);
	this->stats_D_I_.setTextFont(resourceFont);

	this->stats_D_B_.setString(DESCRIPTIONTYPE::STAT, "", "Increase hit points");
	this->stats_D_C_.setString(DESCRIPTIONTYPE::STAT, "", "Increase energy pool");
	this->stats_D_D_.setString(DESCRIPTIONTYPE::STAT, "", "Increase physical damage, and carry capcity");
	this->stats_D_E_.setString(DESCRIPTIONTYPE::STAT, "", "Increase attack speed and dodge");
	this->stats_D_G_.setString(DESCRIPTIONTYPE::STAT, "", "Increase mana and damage done with magic spells");
	this->stats_D_H_.setString(DESCRIPTIONTYPE::STAT, "", "Increase detection of traps and clues, increase accuracy of ranges attacks");
	this->stats_D_I_.setString(DESCRIPTIONTYPE::STAT, "", "Increase restoration spell effects");
}

void PlayerInventory::initializeResistances(const ResourceFont& resourceFont)
{
	/*
		SET SETTINGS FOR RESISTANCE RELATED OBJECTS
	*/
	this->resistances_T_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Resistances", sf::Vector2f(this->x_B_.getRightPosition(true, 50.f), this->x_B_.getTopPosition(true, 40.f)), true);
	this->resistances_T_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Cold: ", sf::Vector2f(this->resistances_T_A_.getLeftPosition(), this->resistances_T_A_.getTopPosition(true, 40.f)), true);
	this->resistances_T_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Fire: ", sf::Vector2f(this->resistances_T_B_.getLeftPosition(), this->resistances_T_B_.getTopPosition(true, 30.f)), true);
	this->resistances_T_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Lightning: ", sf::Vector2f(this->resistances_T_C_.getLeftPosition(), this->resistances_T_C_.getTopPosition(true, 30.f)), true);
	this->resistances_T_E_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Poison: ", sf::Vector2f(this->resistances_T_D_.getLeftPosition(), this->resistances_T_D_.getTopPosition(true, 30.f)), true);

	this->resistances_D_B_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_B_.getGlobalBounds(), this->resistances_T_B_.getGlobalBounds());
	this->resistances_D_C_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_C_.getGlobalBounds(), this->resistances_T_C_.getGlobalBounds());
	this->resistances_D_D_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_D_.getGlobalBounds(), this->resistances_T_D_.getGlobalBounds());
	this->resistances_D_E_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_E_.getGlobalBounds(), this->resistances_T_E_.getGlobalBounds());

	this->resistances_D_B_.setTextFont(resourceFont);
	this->resistances_D_C_.setTextFont(resourceFont);
	this->resistances_D_D_.setTextFont(resourceFont);
	this->resistances_D_E_.setTextFont(resourceFont);

	this->resistances_D_B_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's cold");
	this->resistances_D_C_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's fire");
	this->resistances_D_D_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's lightning");
	this->resistances_D_E_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's poison");
}

void PlayerInventory::initializeIcons(const ResourceFont& resourceFont)
{
	/*
		INITIALIZE INVENTORY SLOT ICONS
	*/
	this->helm_Icon_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->x_B_.getTopPosition(true, 25.f)));
	this->helm_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->helm_Icon_.setFillColor(sf::Color(174, 90, 65));
	this->helm_Icon_.setOutlineThickness(1.f);
	this->helm_Icon_.setOutlineColor(sf::Color::White);

	this->shoulder_Icon_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->helm_Icon_.getGlobalBounds().top + this->helm_Icon_.getGlobalBounds().height + 10.f));
	this->shoulder_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->shoulder_Icon_.setFillColor(sf::Color(174, 90, 65));
	this->shoulder_Icon_.setOutlineThickness(1.f);
	this->shoulder_Icon_.setOutlineColor(sf::Color::White);

	this->chest_Icon_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->shoulder_Icon_.getGlobalBounds().top + this->shoulder_Icon_.getGlobalBounds().height + 10.f));
	this->chest_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->chest_Icon_.setFillColor(sf::Color(174, 90, 65));
	this->chest_Icon_.setOutlineThickness(1.f);
	this->chest_Icon_.setOutlineColor(sf::Color::White);

	this->glove_Icon_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->chest_Icon_.getGlobalBounds().top + this->chest_Icon_.getGlobalBounds().height + 10.f));
	this->glove_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->glove_Icon_.setFillColor(sf::Color(174, 90, 65));
	this->glove_Icon_.setOutlineThickness(1.f);
	this->glove_Icon_.setOutlineColor(sf::Color::White);

	this->leg_Icon_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->glove_Icon_.getGlobalBounds().top + this->glove_Icon_.getGlobalBounds().height + 10.f));
	this->leg_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->leg_Icon_.setFillColor(sf::Color(174, 90, 65));
	this->leg_Icon_.setOutlineThickness(1.f);
	this->leg_Icon_.setOutlineColor(sf::Color::White);

	this->feet_Icon_.setPosition(sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->leg_Icon_.getGlobalBounds().top + this->leg_Icon_.getGlobalBounds().height + 10.f));
	this->feet_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->feet_Icon_.setFillColor(sf::Color(174, 90, 65));
	this->feet_Icon_.setOutlineThickness(1.f);
	this->feet_Icon_.setOutlineColor(sf::Color::White);
}

PlayerInventory::PlayerInventory(const ResourceFont& resourceFont)
{
	this->x_A_.setSettings(800.f, 500.f, 1280.f / 2.f - 800.f / 2.f, 720.f / 2.f - 500.f / 2.f, sf::Color(27, 133, 184), 1.f, sf::Color(27, 133, 184), true);
	this->x_B_.setSettings(250.f, 400.f, this->x_A_.getRightPosition() / 2.f , this->x_A_.getTopPosition(true, 95.f), sf::Color::Black, 1.f, sf::Color::Red, true);
	this->x_C_.setSettings(1280.f, 720.f, 0.f, 0.f, sf::Color(0,0,0,200), 1.f, sf::Color::Transparent, true);

	this->b_B_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color(174, 90, 65), 1.f, sf::Color::White, true);

	this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 28, "Inventory", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);
	this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Name: ", sf::Vector2f(this->x_B_.getLeftPosition(false, 190.f), this->x_B_.getTopPosition(false, 35.f)), true);
	this->t_D_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Race: ", sf::Vector2f(this->t_C_.getRightPosition(true, 120.f), this->x_B_.getTopPosition(false, 35.f)), true);
	this->t_E_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Class: ", sf::Vector2f(this->t_D_.getRightPosition(true, 120.f), this->x_B_.getTopPosition(false, 35.f)), true);
	this->t_F_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Level: ", sf::Vector2f(this->t_E_.getRightPosition(true, 120.f), this->x_B_.getTopPosition(false, 35.f)), true);
	
	this->initializeStats(resourceFont);
	this->initializeResistances(resourceFont);
	this->initializeIcons(resourceFont);

	this->is_Hiding_Inventory_ = true;

	this->selected_Equipment_ = 0;

	this->equipment_.resize(6, NULL);

	this->d_A_.setTextFont(resourceFont);

	this->resource_Font_ = resourceFont;
}

PlayerInventory::~PlayerInventory()
{
}

void PlayerInventory::initializeInventory(const std::string& name, const std::string& raceName, const std::string& className, const int& level, const std::map<std::string, int>& stats, const std::map<std::string, int>& resistances)
{
	/*
		ON INVENTORY BUTTON CLICK SET ALL STATS AND RESISTANCES
	*/

	if (!this->is_Hiding_Inventory_)
	{
		this->t_C_.setString("Name: " + name);
		this->t_D_.setString("Race: " + raceName);
		this->t_E_.setString("Class: " + className);
		this->t_F_.setString("Level: " + std::to_string(level));


		if (!stats.empty())
		{
			this->stats_T_B_.setString("Health: " + std::to_string(stats.find("health")->second) + " / " + std::to_string(stats.find("healthMax")->second));
			this->stats_T_C_.setString("Mana: " + std::to_string(stats.find("mana")->second) + " / " + std::to_string(stats.find("manaMax")->second));
			this->stats_T_D_.setString("Strength: " + std::to_string(stats.find("strength")->second));
			this->stats_T_E_.setString("Dexerity: " + std::to_string(stats.find("dexerity")->second));
			this->stats_T_G_.setString("Intelligence: " + std::to_string(stats.find("intelligence")->second));
			this->stats_T_H_.setString("Perception: " + std::to_string(stats.find("perception")->second));
			this->stats_T_I_.setString("Wisdom: " + std::to_string(stats.find("wisdom")->second));
		}

		if (!resistances.empty())
		{
			this->resistances_T_B_.setString("Cold: " + std::to_string(resistances.find("cold")->second));
			this->resistances_T_C_.setString("Fire: " + std::to_string(resistances.find("fire")->second));
			this->resistances_T_D_.setString("Lightning: " + std::to_string(resistances.find("lightning")->second));
			this->resistances_T_E_.setString("Poison: " + std::to_string(resistances.find("poison")->second));
		}
	}
}

void PlayerInventory::realignEquipment()
{
	/*
		WHEN OPENING INVENTORY ALIGN ITEMS
	*/
	for (int x = 0; x < 6; ++x)
	{
		if (this->equipment_[x] != NULL)
		{
			if (this->equipment_[x]->getItemType() == ITEMTYPE::HELM)
			{
				this->equipment_[x]->setPosition(this->helm_Icon_.getPosition());
			}
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::SHOULDER)
			{
				this->equipment_[x]->setPosition(this->shoulder_Icon_.getPosition());
			}
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::CHEST)
			{
				this->equipment_[x]->setPosition(this->chest_Icon_.getPosition());
			}
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::GLOVE)
			{
				this->equipment_[x]->setPosition(this->glove_Icon_.getPosition());
			}
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::LEG)
			{
				this->equipment_[x]->setPosition(this->leg_Icon_.getPosition());
			}
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::FEET)
			{
				this->equipment_[x]->setPosition(this->feet_Icon_.getPosition());
			}
		}
	}
}

void PlayerInventory::updateText(std::map<std::string, int>& stats, std::map<std::string, int>& resistances)
{
	/*
		WHEN OPENING INVENTORY RESET STATS TO PLAYER CURRENT STATS
	*/
	if (!stats.empty())
	{
		this->stats_T_B_.setString("Health: " + std::to_string(stats.find("health")->second) + " / " + std::to_string(stats.find("healthMax")->second));
		this->stats_T_C_.setString("Mana: " + std::to_string(stats.find("mana")->second) + " / " + std::to_string(stats.find("manaMax")->second));
		this->stats_T_D_.setString("Strength: " + std::to_string(stats.find("strength")->second));
		this->stats_T_E_.setString("Dexerity: " + std::to_string(stats.find("dexerity")->second));
		this->stats_T_G_.setString("Intelligence: " + std::to_string(stats.find("intelligence")->second));
		this->stats_T_H_.setString("Perception: " + std::to_string(stats.find("perception")->second));
		this->stats_T_I_.setString("Wisdom: " + std::to_string(stats.find("wisdom")->second));
	}

	if (!resistances.empty())
	{
		this->resistances_T_B_.setString("Cold: " + std::to_string(resistances.find("cold")->second));
		this->resistances_T_C_.setString("Fire: " + std::to_string(resistances.find("fire")->second));
		this->resistances_T_D_.setString("Lightning: " + std::to_string(resistances.find("lightning")->second));
		this->resistances_T_E_.setString("Poison: " + std::to_string(resistances.find("poison")->second));
	}
}


void PlayerInventory::updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats, std::map<std::string, int>& resistances, std::vector<std::vector<Item*>>& items, const unsigned& maxBagSizeX, const unsigned& maxBagSizeY)
{
	if (!this->is_Hiding_Inventory_)
	{
		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Hiding_Inventory_ = true;
		}


		/*
			UPDATE ITEM DROP DOWN LIST
		*/
		for (int x = 0; x < 6; ++x)
		{
			if (this->equipment_[x] != NULL)
			{
				if (this->equipment_[x]->updatePollEvent(ev))
				{
					if (!this->l_A_.getIsHovering())
					{
						this->l_A_.setSettings(LISTUSE::INVENTORY, this->equipment_[x]->getItemGlobalBoundaries(), this->resource_Font_);
						this->l_A_.setIsVisible(true);

						this->selected_Equipment_ = x;
					}
				}
			}
		}



		/*
			EQUIP BUTTON POLL EVENT
		*/
		if (this->l_A_.updateEquipPollEvent(ev))
		{

		}


		/*
			UNEQUIP BUTTON POLL EVENT
		*/
		if (this->l_A_.updateUnequipPollEvent(ev))
		{
			bool isBreaking = false;

			for (int x = 0; x < maxBagSizeX; ++x)
			{
				for (int y = 0; y < maxBagSizeY; ++y)
				{
					if (items[x][y] == NULL)
					{
						items[x][y] = this->equipment_[this->selected_Equipment_]->getNewItem();

						this->equipment_[this->selected_Equipment_]->descreaseStatsOnUnequip(stats, resistances);

						delete this->equipment_[this->selected_Equipment_];
						this->equipment_[this->selected_Equipment_] = NULL;

						isBreaking = true;

						break;
					}
				}

				if (isBreaking)
				{
					break;
				}
			}
			
			this->updateText(stats, resistances);

			this->l_A_.setIsVisible(false);
			this->l_A_.setIsHovering(false);
		}

		/*
			DELETE BUTTON POLL EVENT
		*/
		if (this->l_A_.updateDeletePollEvent(ev))
		{
			this->equipment_[this->selected_Equipment_]->descreaseStatsOnUnequip(stats, resistances);

			delete this->equipment_[this->selected_Equipment_];
			this->equipment_[this->selected_Equipment_] = NULL;

			this->l_A_.setIsVisible(false);
			this->l_A_.setIsHovering(false);

			this->updateText(stats, resistances);
		}
	}
}

void PlayerInventory::update(const sf::Vector2i& mousePositionWindow)
{
	if (!this->is_Hiding_Inventory_)
	{
		this->b_B_.updateBoundaries(mousePositionWindow);

		this->stats_D_B_.update(mousePositionWindow);
		this->stats_D_C_.update(mousePositionWindow);
		this->stats_D_D_.update(mousePositionWindow);
		this->stats_D_E_.update(mousePositionWindow);
		this->stats_D_G_.update(mousePositionWindow);
		this->stats_D_H_.update(mousePositionWindow);
		this->stats_D_I_.update(mousePositionWindow);

		this->resistances_D_B_.update(mousePositionWindow);
		this->resistances_D_C_.update(mousePositionWindow);
		this->resistances_D_D_.update(mousePositionWindow);
		this->resistances_D_E_.update(mousePositionWindow);


		/*
			SET DESCRIPTION BOX SETTINGS ON ITEM HOVER
		*/
		for (auto& x : this->equipment_)
		{
			if (x != NULL)
			{
				if (x->update(mousePositionWindow))
				{
					x->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, x->getItemGlobalBoundaries(), this->x_A_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, x->getName(), x->getDescription());
				}
			}
		}

		/*
			SET DROP DOWN LIST SETTINGS IF AN ITEM HAS BEEN CLICKED
		*/
		if (this->l_A_.getIsVisible())
		{
			if (this->equipment_[this->selected_Equipment_] != NULL)
			{
				this->equipment_[this->selected_Equipment_]->update(mousePositionWindow);

				this->l_A_.update(mousePositionWindow, this->equipment_[this->selected_Equipment_]->getItemGlobalBoundaries());
			}
		}
	}
}

void PlayerInventory::render(sf::RenderTarget& target)
{
	if (!this->is_Hiding_Inventory_)
	{
		target.setView(target.getDefaultView());

		this->x_C_.render(target);
		this->x_A_.render(target);
		this->x_B_.render(target);

		this->b_B_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);
		this->t_C_.render(target);
		this->t_D_.render(target);
		this->t_E_.render(target);
		this->t_F_.render(target);


		target.draw(this->helm_Icon_);
		target.draw(this->shoulder_Icon_);
		target.draw(this->chest_Icon_);
		target.draw(this->glove_Icon_);
		target.draw(this->leg_Icon_);
		target.draw(this->feet_Icon_);
		
		for (auto& e : this->equipment_)
		{
			if (e != NULL)
			{
				e->render(target);
			}
		}

		

		this->l_A_.render(target);
		
		this->stats_T_A_.render(target);
		this->stats_T_B_.render(target);
		this->stats_T_C_.render(target);
		this->stats_T_D_.render(target);
		this->stats_T_E_.render(target);
		this->stats_T_G_.render(target);
		this->stats_T_H_.render(target);
		this->stats_T_I_.render(target);

		this->stats_D_B_.render(target);
		this->stats_D_C_.render(target);
		this->stats_D_D_.render(target);
		this->stats_D_E_.render(target);
		this->stats_D_G_.render(target);
		this->stats_D_H_.render(target);
		this->stats_D_I_.render(target);

		this->resistances_T_A_.render(target);
		this->resistances_T_B_.render(target);
		this->resistances_T_C_.render(target);
		this->resistances_T_D_.render(target);
		this->resistances_T_E_.render(target);

		this->resistances_D_B_.render(target);
		this->resistances_D_C_.render(target);
		this->resistances_D_D_.render(target);
		this->resistances_D_E_.render(target);
	}
}

void PlayerInventory::setIsHidingInventory(bool isHidingInventory)
{
	this->is_Hiding_Inventory_ = isHidingInventory;
}

std::vector<Item*>& PlayerInventory::setEquipment()
{
	return this->equipment_;
}

const bool& PlayerInventory::getIsHidingInventory() const
{
	return this->is_Hiding_Inventory_;
}

const std::vector<Item*>& PlayerInventory::getEquipment() const
{
	return this->equipment_;
}
