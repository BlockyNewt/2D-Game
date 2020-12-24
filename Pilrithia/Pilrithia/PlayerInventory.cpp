#include "PlayerInventory.h"

void PlayerInventory::initializeStats(ResourceFont* resourceFont)
{
	/*
		SET SETTINGS FOR STAT RELATED OBJECTS
	*/
	this->stats_B_A_.setSettings(150.f, 40.f, this->inventory_Background_Sprite_.getGlobalBounds().left + 345.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 23.f, sf::Color::Transparent, 1.f, sf::Color::Transparent, true);

	this->stats_T_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Stats", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 25.f), true);
	this->stats_T_B_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Health", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f), true);
	this->stats_T_C_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Mana", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f), true);
	this->stats_T_D_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Strength", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f), true);
	this->stats_T_E_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Dexerity", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f), true);
	this->stats_T_G_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Intelligence", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 357.f), true);
	this->stats_T_H_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Perception", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 402.f), true);
	this->stats_T_I_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Wisdom", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 447.f), true);

	this->stats_T_J_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f), true);
	this->stats_T_K_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f), true);
	this->stats_T_L_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f), true);
	this->stats_T_M_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f), true);
	this->stats_T_N_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 357.f), true);
	this->stats_T_O_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 402.f), true);
	this->stats_T_P_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 447.f), true);

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

void PlayerInventory::initializeResistances(ResourceFont* resourceFont)
{
	/*
		SET SETTINGS FOR RESISTANCE RELATED OBJECTS
	*/
	this->resistances_B_A_.setSettings(150.f, 40.f, this->inventory_Background_Sprite_.getGlobalBounds().left + 495.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 23.f, sf::Color::Transparent, 1.f, sf::Color::Transparent, true);

	this->resistances_T_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Resistances", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 503.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 25.f), true);
	this->resistances_T_B_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "Cold: ", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f), true);
	this->resistances_T_C_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "Fire: ", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f), true);
	this->resistances_T_D_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "Lightning: ", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f), true);
	this->resistances_T_E_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "Poison: ", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f), true);

	this->resistances_T_F_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "0", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f), true);
	this->resistances_T_G_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "0", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f), true);
	this->resistances_T_H_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "0", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f), true);
	this->resistances_T_I_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 22, "0", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f), true);

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

void PlayerInventory::initializeIcons(ResourceFont* resourceFont)
{
	/*
		INITIALIZE INVENTORY SLOT ICONS
	*/
	this->helm_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 53.f));
	this->helm_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->helm_Icon_.setFillColor(sf::Color::Transparent);
	this->helm_Icon_.setOutlineThickness(1.f);
	this->helm_Icon_.setOutlineColor(sf::Color::Transparent);

	this->shoulder_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 112.f));
	this->shoulder_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->shoulder_Icon_.setFillColor(sf::Color::Transparent);
	this->shoulder_Icon_.setOutlineThickness(1.f);
	this->shoulder_Icon_.setOutlineColor(sf::Color::Transparent);

	this->chest_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 170.f));
	this->chest_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->chest_Icon_.setFillColor(sf::Color::Transparent);
	this->chest_Icon_.setOutlineThickness(1.f);
	this->chest_Icon_.setOutlineColor(sf::Color::Transparent);

	this->glove_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 228.f));
	this->glove_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->glove_Icon_.setFillColor(sf::Color::Transparent);
	this->glove_Icon_.setOutlineThickness(1.f);
	this->glove_Icon_.setOutlineColor(sf::Color::Transparent);

	this->leg_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 286.f));
	this->leg_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->leg_Icon_.setFillColor(sf::Color::Transparent);
	this->leg_Icon_.setOutlineThickness(1.f);
	this->leg_Icon_.setOutlineColor(sf::Color::Transparent);

	this->feet_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 344.f));
	this->feet_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->feet_Icon_.setFillColor(sf::Color::Transparent);
	this->feet_Icon_.setOutlineThickness(1.f);
	this->feet_Icon_.setOutlineColor(sf::Color::Transparent);

	this->weapon_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 119.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 401.f));
	this->weapon_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->weapon_Icon_.setFillColor(sf::Color::Transparent);
	this->weapon_Icon_.setOutlineThickness(1.f);
	this->weapon_Icon_.setOutlineColor(sf::Color::Transparent);

	this->offhand_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 176.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 402.f));
	this->offhand_Icon_.setSize(sf::Vector2f(50.f, 50.f));
	this->offhand_Icon_.setFillColor(sf::Color::Transparent);
	this->offhand_Icon_.setOutlineThickness(1.f);
	this->offhand_Icon_.setOutlineColor(sf::Color::Transparent);
}

PlayerInventory::PlayerInventory(const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceRace* resourceRace)
{
	this->x_C_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0,0,0,200), 1.f, sf::Color::Transparent, true);

	this->inventory_Background_Sprite_.setTexture(*resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::INVENTORY_WINDOW));
	this->inventory_Background_Sprite_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 800.f / 2.f, window->getSize().y / 2.f - 500.f / 2.f));

	this->b_B_.setSettings(34.f, 34.f, this->inventory_Background_Sprite_.getGlobalBounds().left + 764.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 3.f, sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->b_B_.setTexture(resourceHud->getHudTexture(HUD_TEXTURE_TYPE_::CLOSE));

	this->t_C_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Name: ", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 74.f), true);
	this->t_D_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Race: ", sf::Vector2f(this->t_C_.getRightPosition(true, 120.f), this->inventory_Background_Sprite_.getGlobalBounds().top + 74.f), true);
	this->t_E_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Class: ", sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->t_C_.getTopPosition(true, 40.f)), true);
	this->t_F_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Level: ", sf::Vector2f(this->t_E_.getRightPosition(true, 120.f), this->t_E_.getTopPosition()), true);
	
	this->initializeStats(resourceFont);
	this->initializeResistances(resourceFont);
	this->initializeIcons(resourceFont);

	this->is_Hiding_Inventory_ = true;

	this->selected_Equipment_ = 0;

	this->equipment_.resize(8, NULL);

	this->d_A_.setTextFont(resourceFont);

	this->resource_Font_ = resourceFont;

	this->is_Stats_Visible_ = true;
	this->is_Resistances_Visible_ = false;
}

PlayerInventory::~PlayerInventory()
{
	if (!this->equipment_.empty())
	{
		for (int x = 0; x < this->equipment_.size(); ++x)
		{
			delete this->equipment_[x];
			this->equipment_.erase(this->equipment_.begin() + x);
		}
	}

	std::cout << "DEBUG::PLAYERINVENTORY::~PLAYERINVENTORY() -> Deconstructed." << std::endl;
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
			this->stats_T_J_.setString(std::to_string(stats.find("health")->second) + " / " + std::to_string(stats.find("healthMax")->second));
			this->stats_T_K_.setString(std::to_string(stats.find("mana")->second) + " / " + std::to_string(stats.find("manaMax")->second));
			this->stats_T_L_.setString(std::to_string(stats.find("strength")->second));
			this->stats_T_M_.setString(std::to_string(stats.find("dexerity")->second));
			this->stats_T_N_.setString(std::to_string(stats.find("intelligence")->second));
			this->stats_T_O_.setString(std::to_string(stats.find("perception")->second));
			this->stats_T_P_.setString(std::to_string(stats.find("wisdom")->second));
		}

		if (!resistances.empty())
		{
			this->resistances_T_F_.setString(std::to_string(resistances.find("cold")->second));
			this->resistances_T_G_.setString(std::to_string(resistances.find("fire")->second));
			this->resistances_T_H_.setString(std::to_string(resistances.find("lightning")->second));
			this->resistances_T_I_.setString(std::to_string(resistances.find("poison")->second));
		}
	}
}

void PlayerInventory::realignEquipment()
{
	/*
		WHEN OPENING INVENTORY ALIGN ITEMS
	*/
	for (int x = 0; x < 8; ++x)
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
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::WEAPON)
			{
				this->equipment_[x]->setPosition(this->weapon_Icon_.getPosition());
			}
			else if (this->equipment_[x]->getItemType() == ITEMTYPE::OFFHAND)
			{
				this->equipment_[x]->setPosition(this->offhand_Icon_.getPosition());
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
		this->stats_T_J_.setString(std::to_string(stats.find("health")->second) + " / " + std::to_string(stats.find("healthMax")->second));
		this->stats_T_K_.setString(std::to_string(stats.find("mana")->second) + " / " + std::to_string(stats.find("manaMax")->second));
		this->stats_T_L_.setString(std::to_string(stats.find("strength")->second));
		this->stats_T_M_.setString(std::to_string(stats.find("dexerity")->second));
		this->stats_T_N_.setString(std::to_string(stats.find("intelligence")->second));
		this->stats_T_O_.setString(std::to_string(stats.find("perception")->second));
		this->stats_T_P_.setString(std::to_string(stats.find("wisdom")->second));
	}

	if (!resistances.empty())
	{
		this->resistances_T_F_.setString(std::to_string(resistances.find("cold")->second));
		this->resistances_T_G_.setString(std::to_string(resistances.find("fire")->second));
		this->resistances_T_H_.setString(std::to_string(resistances.find("lightning")->second));
		this->resistances_T_I_.setString(std::to_string(resistances.find("poison")->second));
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

		if (this->stats_B_A_.updatePollEvent(ev))
		{
			this->is_Resistances_Visible_ = false;
			this->is_Stats_Visible_ = true;
		}

		if (this->resistances_B_A_.updatePollEvent(ev))
		{
			this->is_Stats_Visible_ = false;
			this->is_Resistances_Visible_ = true;
		}


		/*
			UPDATE ITEM DROP DOWN LIST
		*/
		for (int x = 0; x < 8; ++x)
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
		this->stats_B_A_.updateBoundaries(mousePositionWindow);
		this->resistances_B_A_.updateBoundaries(mousePositionWindow);

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
					x->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, x->getItemGlobalBoundaries(), this->inventory_Background_Sprite_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, x->getName(), x->getDescription());
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
		target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));

		this->x_C_.render(target);

		target.draw(this->inventory_Background_Sprite_);

		this->b_B_.render(target);
		this->stats_B_A_.render(target);
		this->resistances_B_A_.render(target);

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
		target.draw(this->weapon_Icon_);
		target.draw(this->offhand_Icon_);
		
		for (auto& e : this->equipment_)
		{
			if (e != NULL)
			{
				e->render(target);
			}
		}

		

		this->l_A_.render(target);
		this->stats_T_A_.render(target);

		if (this->is_Stats_Visible_)
		{
			this->stats_T_B_.render(target);
			this->stats_T_C_.render(target);
			this->stats_T_D_.render(target);
			this->stats_T_E_.render(target);
			this->stats_T_G_.render(target);
			this->stats_T_H_.render(target);
			this->stats_T_I_.render(target);

			this->stats_T_J_.render(target);
			this->stats_T_K_.render(target);
			this->stats_T_L_.render(target);
			this->stats_T_M_.render(target);
			this->stats_T_N_.render(target);
			this->stats_T_O_.render(target);
			this->stats_T_P_.render(target);

			this->stats_D_B_.render(target);
			this->stats_D_C_.render(target);
			this->stats_D_D_.render(target);
			this->stats_D_E_.render(target);
			this->stats_D_G_.render(target);
			this->stats_D_H_.render(target);
			this->stats_D_I_.render(target);
		}
		
		this->resistances_T_A_.render(target);

		if (this->is_Resistances_Visible_)
		{
			this->resistances_T_B_.render(target);
			this->resistances_T_C_.render(target);
			this->resistances_T_D_.render(target);
			this->resistances_T_E_.render(target);

			this->resistances_T_F_.render(target);
			this->resistances_T_G_.render(target);
			this->resistances_T_H_.render(target);
			this->resistances_T_I_.render(target);

			this->resistances_D_B_.render(target);
			this->resistances_D_C_.render(target);
			this->resistances_D_D_.render(target);
			this->resistances_D_E_.render(target);
		}
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

void PlayerInventory::setPositionOnResize(const sf::RenderWindow* window)
{

	this->x_C_.setPosition(window->getSize().x, window->getSize().y);

	this->inventory_Background_Sprite_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 800.f / 2.f, window->getSize().y / 2.f - 500.f / 2.f));

	this->b_B_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 764.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 3.f));

	this->t_C_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 74.f);
	this->t_D_.setPosition(this->t_C_.getRightPosition(true, 120.f), this->inventory_Background_Sprite_.getGlobalBounds().top + 74.f);
	this->t_E_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->t_C_.getTopPosition(true, 40.f));
	this->t_F_.setPosition(this->t_E_.getRightPosition(true, 120.f), this->t_E_.getTopPosition());

	/*
		STATS
	*/
	this->stats_B_A_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 345.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 23.f));

	this->stats_T_A_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 25.f);
	this->stats_T_B_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f);
	this->stats_T_C_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f);
	this->stats_T_D_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f);
	this->stats_T_E_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f);
	this->stats_T_G_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 357.f);
	this->stats_T_H_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 402.f);
	this->stats_T_I_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 447.f);

	this->stats_T_J_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f);
	this->stats_T_K_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f);
	this->stats_T_L_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f);
	this->stats_T_M_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f);
	this->stats_T_N_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 357.f);
	this->stats_T_O_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 402.f);
	this->stats_T_P_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 447.f);

	this->stats_D_B_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_B_.getGlobalBounds(), this->stats_T_B_.getGlobalBounds());
	this->stats_D_C_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_C_.getGlobalBounds(), this->stats_T_C_.getGlobalBounds());
	this->stats_D_D_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_D_.getGlobalBounds(), this->stats_T_D_.getGlobalBounds());
	this->stats_D_E_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_E_.getGlobalBounds(), this->stats_T_E_.getGlobalBounds());
	this->stats_D_G_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_G_.getGlobalBounds(), this->stats_T_G_.getGlobalBounds());
	this->stats_D_H_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_H_.getGlobalBounds(), this->stats_T_H_.getGlobalBounds());
	this->stats_D_I_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_I_.getGlobalBounds(), this->stats_T_I_.getGlobalBounds());


	/*
		RESISTANCES
	*/
	this->resistances_B_A_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 495.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 23.f));

	this->resistances_T_A_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 503.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 25.f);
	this->resistances_T_B_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f);
	this->resistances_T_C_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f);
	this->resistances_T_D_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f);
	this->resistances_T_E_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 355.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f);

	this->resistances_T_F_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 175.f);
	this->resistances_T_G_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 220.f);
	this->resistances_T_H_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 266.f);
	this->resistances_T_I_.setPosition(this->inventory_Background_Sprite_.getGlobalBounds().left + 655.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 312.f);

	this->resistances_D_B_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_B_.getGlobalBounds(), this->resistances_T_B_.getGlobalBounds());
	this->resistances_D_C_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_C_.getGlobalBounds(), this->resistances_T_C_.getGlobalBounds());
	this->resistances_D_D_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_D_.getGlobalBounds(), this->resistances_T_D_.getGlobalBounds());
	this->resistances_D_E_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_E_.getGlobalBounds(), this->resistances_T_E_.getGlobalBounds());

	/*
		ICONS
	*/
	this->helm_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 53.f));

	this->shoulder_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 112.f));

	this->chest_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 170.f));

	this->glove_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 228.f));

	this->leg_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 286.f));

	this->feet_Icon_.setPosition(sf::Vector2f(this->inventory_Background_Sprite_.getGlobalBounds().left + 30.f, this->inventory_Background_Sprite_.getGlobalBounds().top + 344.f));
}

const bool& PlayerInventory::getIsHidingInventory() const
{
	return this->is_Hiding_Inventory_;
}

const std::vector<Item*>& PlayerInventory::getEquipment() const
{
	return this->equipment_;
}
