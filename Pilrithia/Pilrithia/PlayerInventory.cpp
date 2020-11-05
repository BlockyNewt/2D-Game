#include "PlayerInventory.h"

void PlayerInventory::initializeStats()
{
	this->stats_T_A_.setSettings("Font/arial.ttf", 28, "Stats", sf::Vector2f(this->x_B_.getRightPosition(true, 80.f), this->x_B_.getTopPosition(true, 10.f)), true);
	this->stats_T_B_.setSettings("Font/arial.ttf", 18, "Strength: ", sf::Vector2f(this->stats_T_A_.getLeftPosition(false, 50.f), this->stats_T_A_.getTopPosition(true, 40.f)), true);
	this->stats_T_C_.setSettings("Font/arial.ttf", 18, "Dexerity: ", sf::Vector2f(this->stats_T_B_.getLeftPosition(), this->stats_T_B_.getTopPosition(true, 40.f)), true);
	this->stats_T_D_.setSettings("Font/arial.ttf", 18, "Constitution: ", sf::Vector2f(this->stats_T_C_.getLeftPosition(), this->stats_T_C_.getTopPosition(true, 40.f)), true);
	this->stats_T_E_.setSettings("Font/arial.ttf", 18, "Intelligence: ", sf::Vector2f(this->stats_T_D_.getLeftPosition(), this->stats_T_D_.getTopPosition(true, 40.f)), true);
	this->stats_T_F_.setSettings("Font/arial.ttf", 18, "Perception: ", sf::Vector2f(this->stats_T_E_.getLeftPosition(), this->stats_T_E_.getTopPosition(true, 40.f)), true);
	this->stats_T_G_.setSettings("Font/arial.ttf", 18, "Wisdom: ", sf::Vector2f(this->stats_T_F_.getLeftPosition(), this->stats_T_F_.getTopPosition(true, 40.f)), true);

	this->stats_D_B_.setHoverBoundaries(this->stats_T_B_.getGlobalBounds());
	this->stats_D_C_.setHoverBoundaries(this->stats_T_C_.getGlobalBounds());
	this->stats_D_D_.setHoverBoundaries(this->stats_T_D_.getGlobalBounds());
	this->stats_D_E_.setHoverBoundaries(this->stats_T_E_.getGlobalBounds());
	this->stats_D_F_.setHoverBoundaries(this->stats_T_F_.getGlobalBounds());
	this->stats_D_G_.setHoverBoundaries(this->stats_T_G_.getGlobalBounds());

	this->stats_D_B_.setString("Increase physical damage, and carry capcity");
	this->stats_D_C_.setString("Increase attack speed and dodge");
	this->stats_D_D_.setString("Increase health");
	this->stats_D_E_.setString("Increase damage done with magic spells");
	this->stats_D_F_.setString("Increase detection of traps and clues, increase accuracy of ranges attacks");
	this->stats_D_G_.setString("Increase restoration spell effects");
}

void PlayerInventory::initializeResistances()
{
	this->resistances_T_A_.setSettings("Font/arial.ttf", 28, "Resistances", sf::Vector2f(this->stats_T_A_.getLeftPosition(true, 250.f), this->x_B_.getTopPosition(true, 10.f)), true);
	this->resistances_T_B_.setSettings("Font/arial.ttf", 18, "Cold: ", sf::Vector2f(this->resistances_T_A_.getLeftPosition(), this->resistances_T_A_.getTopPosition(true, 40.f)), true);
	this->resistances_T_C_.setSettings("Font/arial.ttf", 18, "Fire: ", sf::Vector2f(this->resistances_T_B_.getLeftPosition(), this->resistances_T_B_.getTopPosition(true, 40.f)), true);
	this->resistances_T_D_.setSettings("Font/arial.ttf", 18, "Lightning: ", sf::Vector2f(this->resistances_T_C_.getLeftPosition(), this->resistances_T_C_.getTopPosition(true, 40.f)), true);
	this->resistances_T_E_.setSettings("Font/arial.ttf", 18, "Poison: ", sf::Vector2f(this->resistances_T_D_.getLeftPosition(), this->resistances_T_D_.getTopPosition(true, 40.f)), true);

	this->resistances_D_B_.setHoverBoundaries(this->resistances_T_B_.getGlobalBounds());
	this->resistances_D_C_.setHoverBoundaries(this->resistances_T_C_.getGlobalBounds());
	this->resistances_D_D_.setHoverBoundaries(this->resistances_T_D_.getGlobalBounds());
	this->resistances_D_E_.setHoverBoundaries(this->resistances_T_E_.getGlobalBounds());

	this->resistances_D_B_.setString("Increase resistance to anything that's cold");
	this->resistances_D_C_.setString("Increase resistance to anything that's fire");
	this->resistances_D_D_.setString("Increase resistance to anything that's lightning");
	this->resistances_D_E_.setString("Increase resistance to anything that's poison");
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
}

PlayerInventory::~PlayerInventory()
{
}

void PlayerInventory::initializeInventory(const std::string& name, const std::string& className, const std::map<std::string, int>& stats, const std::map<std::string, int>& resistances)
{
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
