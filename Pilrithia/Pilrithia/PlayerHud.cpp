#include "PlayerHud.h"

PlayerHud::PlayerHud()
{
	this->camera_ = new Camera(0, 0);

	this->health_Bar_Back_.setPosition(sf::Vector2f(10.f, 10.f));
	this->health_Bar_Back_.setSize(sf::Vector2f(300.f, 20.f));
	this->health_Bar_Back_.setFillColor(sf::Color::White);
	this->health_Bar_Back_.setOutlineThickness(1.f);
	this->health_Bar_Back_.setOutlineColor(sf::Color::White);

	this->health_Bar_Front_.setPosition(sf::Vector2f(this->health_Bar_Back_.getPosition().x + 5.f, this->health_Bar_Back_.getPosition().y + 5.f));
	this->health_Bar_Front_.setSize(sf::Vector2f(this->health_Bar_Back_.getSize().x - 10.f, this->health_Bar_Back_.getSize().y - 10.f));
	this->health_Bar_Front_.setFillColor(sf::Color::Green);
	this->health_Bar_Front_.setOutlineThickness(1.f);
	this->health_Bar_Front_.setOutlineColor(sf::Color::Green);

	this->mana_Bar_Back_.setPosition(sf::Vector2f(this->health_Bar_Back_.getPosition().x, this->health_Bar_Back_.getGlobalBounds().top + this->health_Bar_Back_.getGlobalBounds().height + 10.f));
	this->mana_Bar_Back_.setSize(sf::Vector2f(this->health_Bar_Back_.getSize().x, this->health_Bar_Back_.getSize().y));
	this->mana_Bar_Back_.setFillColor(sf::Color::White);
	this->mana_Bar_Back_.setOutlineThickness(1.f);
	this->mana_Bar_Back_.setOutlineColor(sf::Color::White);

	this->mana_Bar_Front_.setPosition(sf::Vector2f(this->mana_Bar_Back_.getPosition().x + 5.f, this->mana_Bar_Back_.getPosition().y + 5.f));
	this->mana_Bar_Front_.setSize(sf::Vector2f(this->mana_Bar_Back_.getSize().x - 10.f, this->mana_Bar_Back_.getSize().y - 10.f));
	this->mana_Bar_Front_.setFillColor(sf::Color::Blue);
	this->mana_Bar_Front_.setOutlineThickness(1.f);
	this->mana_Bar_Front_.setOutlineColor(sf::Color::Blue);

	this->character_B_A_.setSettings(60.f, 60.f, 400.f, 10.f, sf::Color::Blue, 1.f, sf::Color::White, true);
	this->character_B_B_.setSettings(60.f, 60.f, this->character_B_A_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color::Blue, 1.f, sf::Color::White, true);
	this->character_B_C_.setSettings(60.f, 60.f, this->character_B_B_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color::Blue, 1.f, sf::Color::White, true);
	this->character_B_D_.setSettings(60.f, 60.f, this->character_B_C_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color::Blue, 1.f, sf::Color::White, true);

	this->character_T_A_.setSettings("Font/arial.ttf", 12, "Inventory", sf::Vector2f(this->character_B_A_.getLeftPosition(), this->character_B_A_.getTopPosition()), true);
	this->character_T_B_.setSettings("Font/arial.ttf", 12, "Bag", sf::Vector2f(this->character_B_B_.getLeftPosition(), this->character_B_B_.getTopPosition()), true);
	this->character_T_C_.setSettings("Font/arial.ttf", 12, "Quests", sf::Vector2f(this->character_B_C_.getLeftPosition(), this->character_B_C_.getTopPosition()), true);
	this->character_T_D_.setSettings("Font/arial.ttf", 12, "Skill Tree", sf::Vector2f(this->character_B_D_.getLeftPosition(), this->character_B_D_.getTopPosition()), true);
	this->character_T_E_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);

	this->skill_B_A_.setSettings(60.f, 60.f, 400.f, 650.f, sf::Color::Blue, 1.f, sf::Color::White, true);
	this->skill_B_B_.setSettings(60.f, 60.f, this->skill_B_A_.getRightPosition(true, 10.f), this->skill_B_A_.getTopPosition(), sf::Color::Blue, 1.f, sf::Color::White, true);
	this->skill_B_C_.setSettings(60.f, 60.f, this->skill_B_B_.getRightPosition(true, 10.f), this->skill_B_A_.getTopPosition(), sf::Color::Blue, 1.f, sf::Color::White, true);
		  
	this->skill_T_A_.setSettings("Font/arial.ttf", 12, "Skill 1", sf::Vector2f(this->skill_B_A_.getLeftPosition(), this->skill_B_A_.getTopPosition()), true);
	this->skill_T_B_.setSettings("Font/arial.ttf", 12, "Skill 2", sf::Vector2f(this->skill_B_B_.getLeftPosition(), this->skill_B_B_.getTopPosition()), true);
	this->skill_T_C_.setSettings("Font/arial.ttf", 12, "Skill 3", sf::Vector2f(this->skill_B_C_.getLeftPosition(), this->skill_B_C_.getTopPosition()), true);

	this->skill_D_A_.setHoverBoundaries(this->skill_B_A_.getGlobalBounds());

	this->is_Hiding_Hud_ = true;
}

PlayerHud::~PlayerHud()
{
	delete this->camera_;
}

void PlayerHud::intializeHud(const std::string& name, const Classes* classes)
{
	this->character_T_E_.setString(name);

	if (classes != NULL)
	{
		this->skill_T_A_.setString(classes->getSkillOne().getName());
		this->skill_D_A_.setString(classes->getSkillOne().getSummary());
	}
}

void PlayerHud::updateInventoryPollEvent(sf::Event& ev, const std::string& name, const std::string& className, const std::map<std::string, int>& stats, const std::map<std::string, int>& resistances)
{
	if (this->character_B_A_.updatePollEvent(ev))
	{
		if (this->player_Inventory_.getIsHidingInventory())
		{
			this->player_Inventory_.setIsHidingInventory(false);

			this->player_Inventory_.initializeInventory(name, className, stats, resistances);
		}
	}
}

void PlayerHud::updatePollEvent(sf::Event& ev)
{
	/*
		MAY WANT TO MAKE THIS FUNCTION A RETURN A STRING ON BUTTON PRESSES  BACK TO THE PLAYERTEST SO THAT WE DONT HAVE TO
		PASS EVERYTHING FROM PLAYER INTO HERE. 
	*/

	this->player_Inventory_.updatePollEvent(ev);

	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::F2)
		{
			if (!this->is_Hiding_Hud_)
			{
				this->is_Hiding_Hud_ = true;
			}
			else
			{
				this->is_Hiding_Hud_ = false;
			}
		}
	}

	

	if (this->character_B_B_.updatePollEvent(ev))
	{

	}

	if (this->character_B_C_.updatePollEvent(ev))
	{

	}

	if (this->character_B_D_.updatePollEvent(ev))
	{

	}
}

void PlayerHud::updateNamePosition(const sf::Vector2f& playerPosition)
{
	this->character_T_E_.setPosition(playerPosition.x, playerPosition.y - 22.f);
}

void PlayerHud::update(const sf::Vector2i& mousePositionWindow, const Camera& camera, const sf::Vector2f& playerPosition)
{
	if (this->is_Hiding_Hud_)
	{
		*this->camera_ = camera;

		this->updateNamePosition(playerPosition);

		this->character_B_A_.updateBoundaries(mousePositionWindow);
		this->character_B_B_.updateBoundaries(mousePositionWindow);
		this->character_B_C_.updateBoundaries(mousePositionWindow);
		this->character_B_D_.updateBoundaries(mousePositionWindow);

		this->skill_B_A_.updateBoundaries(mousePositionWindow);
		this->skill_B_B_.updateBoundaries(mousePositionWindow);
		this->skill_B_C_.updateBoundaries(mousePositionWindow);

		this->skill_D_A_.update(mousePositionWindow);

		this->player_Inventory_.update(mousePositionWindow);
	}
}

void PlayerHud::render(sf::RenderTarget& target)
{
	if (this->is_Hiding_Hud_)
	{
		target.setView(target.getDefaultView());

		target.draw(this->health_Bar_Back_);
		target.draw(this->health_Bar_Front_);

		target.draw(this->mana_Bar_Back_);
		target.draw(this->mana_Bar_Front_);

		this->character_B_A_.render(target);
		this->character_B_B_.render(target);
		this->character_B_C_.render(target);
		this->character_B_D_.render(target);
		
		this->character_T_A_.render(target);
		this->character_T_B_.render(target);
		this->character_T_C_.render(target);
		this->character_T_D_.render(target);

		this->skill_B_A_.render(target);
		this->skill_B_B_.render(target);
		this->skill_B_C_.render(target);
			  
		this->skill_T_A_.render(target);
		this->skill_T_B_.render(target);
		this->skill_T_C_.render(target);

		this->skill_D_A_.render(target);



		this->player_Inventory_.render(target);

		target.setView(this->camera_->getView());

		this->character_T_E_.render(target);
	}
}

