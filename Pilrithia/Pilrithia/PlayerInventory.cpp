#include "PlayerInventory.h"

void PlayerInventory::initializeStats()
{
	/*
		SET SETTINGS FOR STAT RELATED OBJECTS
	*/

	this->stats_T_A_.setSettings("Font/arial.ttf", 28, "Stats", sf::Vector2f(this->x_B_.getRightPosition(true, 80.f), this->x_B_.getTopPosition(true, 10.f)), true);
	this->stats_T_B_.setSettings("Font/arial.ttf", 18, "Strength: ", sf::Vector2f(this->stats_T_A_.getLeftPosition(false, 50.f), this->stats_T_A_.getTopPosition(true, 40.f)), true);
	this->stats_T_C_.setSettings("Font/arial.ttf", 18, "Dexerity: ", sf::Vector2f(this->stats_T_B_.getLeftPosition(), this->stats_T_B_.getTopPosition(true, 40.f)), true);
	this->stats_T_D_.setSettings("Font/arial.ttf", 18, "Constitution: ", sf::Vector2f(this->stats_T_C_.getLeftPosition(), this->stats_T_C_.getTopPosition(true, 40.f)), true);
	this->stats_T_E_.setSettings("Font/arial.ttf", 18, "Intelligence: ", sf::Vector2f(this->stats_T_D_.getLeftPosition(), this->stats_T_D_.getTopPosition(true, 40.f)), true);
	this->stats_T_F_.setSettings("Font/arial.ttf", 18, "Perception: ", sf::Vector2f(this->stats_T_E_.getLeftPosition(), this->stats_T_E_.getTopPosition(true, 40.f)), true);
	this->stats_T_G_.setSettings("Font/arial.ttf", 18, "Wisdom: ", sf::Vector2f(this->stats_T_F_.getLeftPosition(), this->stats_T_F_.getTopPosition(true, 40.f)), true);

	this->stats_D_B_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_B_.getGlobalBounds(), this->stats_T_B_.getGlobalBounds());
	this->stats_D_C_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_C_.getGlobalBounds(), this->stats_T_C_.getGlobalBounds());
	this->stats_D_D_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_D_.getGlobalBounds(), this->stats_T_D_.getGlobalBounds());
	this->stats_D_E_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_E_.getGlobalBounds(), this->stats_T_E_.getGlobalBounds());
	this->stats_D_F_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_F_.getGlobalBounds(), this->stats_T_F_.getGlobalBounds());
	this->stats_D_G_.setHoverBoundaries(HOVERPOSITION::TOP, this->stats_T_G_.getGlobalBounds(), this->stats_T_G_.getGlobalBounds());

	this->stats_D_B_.setString(DESCRIPTIONTYPE::STAT, "", "Increase physical damage, and carry capcity");
	this->stats_D_C_.setString(DESCRIPTIONTYPE::STAT, "", "Increase attack speed and dodge");
	this->stats_D_D_.setString(DESCRIPTIONTYPE::STAT, "", "Increase health");
	this->stats_D_E_.setString(DESCRIPTIONTYPE::STAT, "", "Increase damage done with magic spells");
	this->stats_D_F_.setString(DESCRIPTIONTYPE::STAT, "", "Increase detection of traps and clues, increase accuracy of ranges attacks");
	this->stats_D_G_.setString(DESCRIPTIONTYPE::STAT, "", "Increase restoration spell effects");
}

void PlayerInventory::initializeResistances()
{
	/*
		SET SETTINGS FOR RESISTANCE RELATED OBJECTS
	*/

	this->resistances_T_A_.setSettings("Font/arial.ttf", 28, "Resistances", sf::Vector2f(this->stats_T_A_.getLeftPosition(true, 250.f), this->x_B_.getTopPosition(true, 10.f)), true);
	this->resistances_T_B_.setSettings("Font/arial.ttf", 18, "Cold: ", sf::Vector2f(this->resistances_T_A_.getLeftPosition(), this->resistances_T_A_.getTopPosition(true, 40.f)), true);
	this->resistances_T_C_.setSettings("Font/arial.ttf", 18, "Fire: ", sf::Vector2f(this->resistances_T_B_.getLeftPosition(), this->resistances_T_B_.getTopPosition(true, 40.f)), true);
	this->resistances_T_D_.setSettings("Font/arial.ttf", 18, "Lightning: ", sf::Vector2f(this->resistances_T_C_.getLeftPosition(), this->resistances_T_C_.getTopPosition(true, 40.f)), true);
	this->resistances_T_E_.setSettings("Font/arial.ttf", 18, "Poison: ", sf::Vector2f(this->resistances_T_D_.getLeftPosition(), this->resistances_T_D_.getTopPosition(true, 40.f)), true);

	this->resistances_D_B_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_B_.getGlobalBounds(), this->resistances_T_B_.getGlobalBounds());
	this->resistances_D_C_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_C_.getGlobalBounds(), this->resistances_T_C_.getGlobalBounds());
	this->resistances_D_D_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_D_.getGlobalBounds(), this->resistances_T_D_.getGlobalBounds());
	this->resistances_D_E_.setHoverBoundaries(HOVERPOSITION::TOP, this->resistances_T_E_.getGlobalBounds(), this->resistances_T_E_.getGlobalBounds());

	this->resistances_D_B_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's cold");
	this->resistances_D_C_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's fire");
	this->resistances_D_D_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's lightning");
	this->resistances_D_E_.setString(DESCRIPTIONTYPE::STAT, "", "Increase resistance to anything that's poison");
}

PlayerInventory::PlayerInventory()
{
	this->x_A_.setSettings(800.f, 500.f, 0.f, 0.f, sf::Color::Cyan, 1.f, sf::Color::White, true);
	this->x_B_.setSettings(225.f, 400.f, this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 95.f), sf::Color::Black, 1.f, sf::Color::Red, true);

	this->b_B_.setSettings(50.f, 50.f, this->x_A_.getRightPosition(false, 50.f), this->x_A_.getTopPosition(), sf::Color::Red, 1.f, sf::Color::White, true);

	this->t_A_.setSettings("Font/arial.ttf", 28, "Inventory", sf::Vector2f(this->x_A_.getLeftPosition(true, 350.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings("Font/arial.ttf", 18, "Close", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);
	this->t_C_.setSettings("Font/arial.ttf", 18, "Name: ", sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->x_B_.getTopPosition(false, 60.f)), true);
	this->t_D_.setSettings("Font/arial.ttf", 18, "Class: ", sf::Vector2f(this->x_B_.getLeftPosition(true, 10.f), this->x_B_.getTopPosition(false, 30.f)), true);
	
	this->initializeStats();
	this->initializeResistances();

	this->is_Hiding_Inventory_ = true;

	this->selected_Equipment_ = ITEMTYPE::DEFAULT;

	this->equipment_.insert(std::make_pair(ITEMTYPE::HELM, new ItemTest(this->x_B_.getLeftPosition(true, 10.f), this->x_B_.getTopPosition(true, 25.f), ITEMTYPE::HELM)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::SHOULDER, new ItemTest(this->x_B_.getLeftPosition(true, 10.f), this->equipment_.at(ITEMTYPE::HELM)->getButton().getBottomPosition(true, 10.f), ITEMTYPE::SHOULDER)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::CHEST, new ItemTest(this->x_B_.getLeftPosition(true, 10.f), this->equipment_.at(ITEMTYPE::SHOULDER)->getButton().getBottomPosition(true, 10.f), ITEMTYPE::CHEST)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::GLOVE, new ItemTest(this->x_B_.getLeftPosition(true, 10.f), this->equipment_.at(ITEMTYPE::CHEST)->getButton().getBottomPosition(true, 10.f), ITEMTYPE::GLOVE)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::LEG, new ItemTest(this->x_B_.getLeftPosition(true, 10.f), this->equipment_.at(ITEMTYPE::GLOVE)->getButton().getBottomPosition(true, 10.f), ITEMTYPE::LEG)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::FEET, new ItemTest(this->x_B_.getLeftPosition(true, 10.f), this->equipment_.at(ITEMTYPE::LEG)->getButton().getBottomPosition(true, 10.f), ITEMTYPE::FEET)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::WEAPON, new ItemTest(this->equipment_.at(ITEMTYPE::FEET)->getButton().getRightPosition(true, 10.f), this->equipment_.at(ITEMTYPE::FEET)->getButton().getTopPosition(), ITEMTYPE::WEAPON)));
	this->equipment_.insert(std::make_pair(ITEMTYPE::OFFHAND, new ItemTest(this->equipment_.at(ITEMTYPE::WEAPON)->getButton().getRightPosition(true, 10.f), this->equipment_.at(ITEMTYPE::FEET)->getButton().getTopPosition(), ITEMTYPE::OFFHAND)));
}

PlayerInventory::~PlayerInventory()
{
}

void PlayerInventory::initializeInventory(const std::string& name, const std::string& className, const std::map<std::string, int>& stats, const std::map<std::string, int>& resistances)
{
	/*
		ON INVENTORY BUTTON CLICK SET ALL STATS AND RESISTANCES
	*/

	if (!this->is_Hiding_Inventory_)
	{
		this->t_C_.setString("Name: " + name);
		this->t_D_.setString("Class: " + className);

		if (!stats.empty())
		{
			this->stats_T_B_.setString("Strength: " + std::to_string(stats.find("strength")->second));
			this->stats_T_C_.setString("Dexerity: " + std::to_string(stats.find("dexerity")->second));
			this->stats_T_D_.setString("Constitution: " + std::to_string(stats.find("constitution")->second));
			this->stats_T_E_.setString("Intelligence: " + std::to_string(stats.find("intelligence")->second));
			this->stats_T_F_.setString("Perception: " + std::to_string(stats.find("perception")->second));
			this->stats_T_G_.setString("Wisdom: " + std::to_string(stats.find("wisdom")->second));
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

void PlayerInventory::updatePollEvent(sf::Event& ev)
{
	if (!this->is_Hiding_Inventory_)
	{
		if (this->b_B_.updatePollEvent(ev))
		{
			this->is_Hiding_Inventory_ = true;
		}

		if (!this->equipment_.empty())
		{
			if (this->equipment_.at(ITEMTYPE::HELM)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::HELM;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::SHOULDER)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::SHOULDER;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::CHEST)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::CHEST;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::GLOVE)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::GLOVE;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::LEG)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::LEG;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::FEET)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::FEET;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::WEAPON)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::WEAPON;

				}
			}
			else if (this->equipment_.at(ITEMTYPE::OFFHAND)->updatePollEvent(ev))
			{
				if (!this->l_A_.getIsHovering())
				{
					this->selected_Equipment_ = ITEMTYPE::OFFHAND;

				}
			}

			if (this->selected_Equipment_ != ITEMTYPE::DEFAULT)
			{
				this->l_A_.setSettings(1, this->equipment_.at(this->selected_Equipment_)->getItemGlobalBoundaries());
				this->l_A_.setIsVisible(true);
			}
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
		this->stats_D_F_.update(mousePositionWindow);
		this->stats_D_G_.update(mousePositionWindow);

		this->resistances_D_B_.update(mousePositionWindow);
		this->resistances_D_C_.update(mousePositionWindow);
		this->resistances_D_D_.update(mousePositionWindow);
		this->resistances_D_E_.update(mousePositionWindow);

		if (!this->equipment_.empty())
		{
			for (auto& e : this->equipment_)
			{
				if (e.second->update(mousePositionWindow))
				{
					e.second->setItemHoverDescriptionSettings(HOVERPOSITION::RIGHT, e.second->getItemGlobalBoundaries(), this->x_A_.getGlobalBounds(), DESCRIPTIONTYPE::ITEM, "Test", "description");
				}
			}
		}

		if (this->l_A_.getIsVisible())
		{
			if (this->equipment_.at(this->selected_Equipment_) != NULL)
			{
				this->equipment_.at(this->selected_Equipment_)->update(mousePositionWindow);

				this->l_A_.update(mousePositionWindow, this->equipment_.at(this->selected_Equipment_)->getItemGlobalBoundaries());
			}
		}
	}
}

void PlayerInventory::render(sf::RenderTarget& target)
{
	if (!this->is_Hiding_Inventory_)
	{
		target.setView(target.getDefaultView());

		this->x_A_.render(target);
		this->x_B_.render(target);

		this->b_B_.render(target);

		this->t_A_.render(target);
		this->t_B_.render(target);
		this->t_C_.render(target);
		this->t_D_.render(target);

		if (!this->equipment_.empty())
		{
			for (auto& e : this->equipment_)
			{
				e.second->render(target);
			}
		}

		this->l_A_.render(target);
		
		this->stats_T_A_.render(target);
		this->stats_T_B_.render(target);
		this->stats_T_C_.render(target);
		this->stats_T_D_.render(target);
		this->stats_T_E_.render(target);
		this->stats_T_F_.render(target);
		this->stats_T_G_.render(target);

		this->stats_D_B_.render(target);
		this->stats_D_C_.render(target);
		this->stats_D_D_.render(target);
		this->stats_D_E_.render(target);
		this->stats_D_F_.render(target);
		this->stats_D_G_.render(target);

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

const bool& PlayerInventory::getIsHidingInventory() const
{
	return this->is_Hiding_Inventory_;
}
