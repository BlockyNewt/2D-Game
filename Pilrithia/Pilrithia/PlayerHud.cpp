#include "PlayerHud.h"

PlayerHud::PlayerHud(unsigned int windowSizeX, unsigned int windowSizeY, const ResourceFont& resourceFont, const ResourceHud& resourceHud, const ResourceRace& resourceRace)
{
	this->camera_ = new Camera(0, 0);
	
	this->resource_Font_ = resourceFont;

	this->window_Size_X_ = windowSizeX;
	this->window_Size_Y_ = windowSizeY;

	this->bars_Sprite_.setTexture(*resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::BAR));
	this->bars_Sprite_.setPosition(sf::Vector2f(10.f, 10.f));

	this->health_Bar_Back_.setPosition(sf::Vector2f(this->bars_Sprite_.getGlobalBounds().left + 115.f, this->bars_Sprite_.getGlobalBounds().top + 22.f));
	this->health_Bar_Back_.setSize(sf::Vector2f(210.f, 10.f));
	this->health_Bar_Back_.setFillColor(sf::Color::Black);
	this->health_Bar_Back_.setOutlineThickness(1.f);
	this->health_Bar_Back_.setOutlineColor(sf::Color::Black);

	this->health_Bar_Front_.setPosition(sf::Vector2f(this->bars_Sprite_.getGlobalBounds().left + 115.f, this->bars_Sprite_.getGlobalBounds().top + 22.f));
	this->health_Bar_Front_.setSize(sf::Vector2f(210.f, 10.f));
	this->health_Bar_Front_.setFillColor(sf::Color::Green);
	this->health_Bar_Front_.setOutlineThickness(1.f);
	this->health_Bar_Front_.setOutlineColor(sf::Color::Green);

	this->mana_Bar_Back_.setPosition(sf::Vector2f(this->health_Bar_Front_.getGlobalBounds().left, this->health_Bar_Front_.getGlobalBounds().top + this->health_Bar_Front_.getGlobalBounds().height + 28.f));
	this->mana_Bar_Back_.setSize(sf::Vector2f(210.f, 10.f));
	this->mana_Bar_Back_.setFillColor(sf::Color::Black);
	this->mana_Bar_Back_.setOutlineThickness(1.f);
	this->mana_Bar_Back_.setOutlineColor(sf::Color::Black);

	this->mana_Bar_Front_.setPosition(sf::Vector2f(this->health_Bar_Front_.getGlobalBounds().left, this->health_Bar_Front_.getGlobalBounds().top + this->health_Bar_Front_.getGlobalBounds().height + 28.f));
	this->mana_Bar_Front_.setSize(sf::Vector2f(210.f, 10.f));
	this->mana_Bar_Front_.setFillColor(sf::Color::Blue);
	this->mana_Bar_Front_.setOutlineThickness(1.f);
	this->mana_Bar_Front_.setOutlineColor(sf::Color::Blue);
		  
	this->experience_Bar_Back_.setPosition(sf::Vector2f(this->mana_Bar_Front_.getGlobalBounds().left, this->mana_Bar_Front_.getGlobalBounds().top + this->mana_Bar_Front_.getGlobalBounds().height + 30.f));
	this->experience_Bar_Back_.setSize(sf::Vector2f(210.f, 10.f));
	this->experience_Bar_Back_.setFillColor(sf::Color::Black);
	this->experience_Bar_Back_.setOutlineThickness(1.f);
	this->experience_Bar_Back_.setOutlineColor(sf::Color::Black);

	this->experience_Bar_Front_.setPosition(sf::Vector2f(this->mana_Bar_Front_.getGlobalBounds().left, this->mana_Bar_Front_.getGlobalBounds().top + this->mana_Bar_Front_.getGlobalBounds().height + 30.f));
	this->experience_Bar_Front_.setSize(sf::Vector2f(210.f, 10.f));
	this->experience_Bar_Front_.setFillColor(sf::Color(195, 203, 113));
	this->experience_Bar_Front_.setOutlineThickness(1.f);
	this->experience_Bar_Front_.setOutlineColor(sf::Color::Yellow);



	this->health_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 14, "", sf::Vector2f(this->health_Bar_Front_.getGlobalBounds().left + 4.f, this->health_Bar_Front_.getGlobalBounds().top + 15.f), true);
	this->mana_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 14, "", sf::Vector2f(this->mana_Bar_Front_.getGlobalBounds().left + 4.f, this->mana_Bar_Front_.getGlobalBounds().top + 15.f), true);
	this->experience_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 14, "", sf::Vector2f(this->experience_Bar_Front_.getGlobalBounds().left + 4.f, this->experience_Bar_Front_.getGlobalBounds().top + 15.f), true);



	this->character_B_A_.setSettings(60.f, 60.f, 400.f, 10.f, sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->character_B_A_.setTexture(resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::INVENTORY_ICON));
	this->character_B_B_.setSettings(60.f, 60.f, this->character_B_A_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->character_B_B_.setTexture(resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::BAG_ICON));
	this->character_B_C_.setSettings(60.f, 60.f, this->character_B_B_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->character_B_C_.setTexture(resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::QUEST_ICON));
	this->character_B_D_.setSettings(60.f, 60.f, this->character_B_C_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color::White, 1.f, sf::Color::Transparent, true);
	this->character_B_D_.setTexture(resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::SKILL_ICON));
	this->character_B_F_.setSettings(60.f, 60.f, this->character_B_D_.getRightPosition(true, 10.f), this->character_B_A_.getTopPosition(), sf::Color(27, 133, 184), 1.f, sf::Color::White, true);

	this->character_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Inventory", sf::Vector2f(this->character_B_A_.getLeftPosition(), this->character_B_A_.getTopPosition()), true);
	this->character_T_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Bag", sf::Vector2f(this->character_B_B_.getLeftPosition(), this->character_B_B_.getTopPosition()), true);
	this->character_T_C_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Quests", sf::Vector2f(this->character_B_C_.getLeftPosition(), this->character_B_C_.getTopPosition()), true);
	this->character_T_D_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Skill Tree", sf::Vector2f(this->character_B_D_.getLeftPosition(), this->character_B_D_.getTopPosition()), true);
	this->character_T_E_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "", sf::Vector2f(0.f, 0.f), true);
	this->character_T_F_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Gathering", sf::Vector2f(this->character_B_F_.getLeftPosition(), this->character_B_F_.getTopPosition()), true);

	this->skill_Hotbar_Sprite_.setTexture(*resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::HOTBAR));
	this->skill_Hotbar_Sprite_.setPosition(sf::Vector2f(400.f, 595.f));

	this->skill_B_A_.setSettings(50.f, 50.f, this->skill_Hotbar_Sprite_.getGlobalBounds().left + 10.f, this->skill_Hotbar_Sprite_.getGlobalBounds().top + 65.f, sf::Color::Transparent, 1.f, sf::Color::Transparent, true);
	this->skill_B_B_.setSettings(50.f, 50.f, this->skill_Hotbar_Sprite_.getGlobalBounds().left + 68.f, this->skill_B_A_.getTopPosition(true, 1.f), sf::Color::Transparent, 1.f, sf::Color::Transparent, true);
	this->skill_B_C_.setSettings(50.f, 50.f, this->skill_Hotbar_Sprite_.getGlobalBounds().left + 126.f, this->skill_B_A_.getTopPosition(true, 1.f), sf::Color::Transparent, 1.f, sf::Color::Transparent, true);
	
	this->skill_X_A_.setSettings(this->skill_B_A_.getSize().x, 0.f, this->skill_B_A_.getPosition().x, this->skill_B_A_.getBottomPosition(), sf::Color(0, 0, 0, 200), 1.f, sf::Color::Transparent, true);

	this->skill_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Skill 1", sf::Vector2f(this->skill_B_A_.getLeftPosition(), this->skill_B_A_.getTopPosition()), true);
	this->skill_T_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Skill 2", sf::Vector2f(this->skill_B_B_.getLeftPosition(), this->skill_B_B_.getTopPosition()), true);
	this->skill_T_C_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 12, "Skill 3", sf::Vector2f(this->skill_B_C_.getLeftPosition(), this->skill_B_C_.getTopPosition()), true);

	this->skill_D_A_.setHoverBoundaries(HOVERPOSITION::TOP, this->skill_B_A_.getGlobalBounds(), this->skill_B_A_.getGlobalBounds());
	this->skill_D_A_.setTextFont(resourceFont);

	this->is_Hiding_Hud_ = true;

	this->skill_One_ = NULL;
}

PlayerHud::~PlayerHud()
{
	delete this->camera_;
}

void PlayerHud::intializeHud(const std::string& name, const int& healthMax, const int& health, const int& manaMax, const int& mana, const int& expMax, const int& exp, const sf::Texture& playerRaceIcon)
{
	this->character_T_E_.setString(name);

	this->race_Icon_Sprite_.setTexture(playerRaceIcon);
	this->race_Icon_Sprite_.setPosition(sf::Vector2f(this->bars_Sprite_.getGlobalBounds().left + 6.f, this->bars_Sprite_.getGlobalBounds().top + 36.f));

	this->setWidthOfBars(healthMax, health, manaMax, mana, expMax, exp);
}

void PlayerHud::initializeSkills(Classes* playerClass)
{
	//SET SETTINGS FOR SKILL DROP DOWN HERE
	this->skill_Dropdown_List_.setSettings(this->skill_B_A_.getGlobalBounds(), playerClass, this->resource_Font_);

	this->skill_Dropdown_List_.setIsVisible(true);
}

bool PlayerHud::updateInventoryPollEvent(sf::Event& ev)
{
	if (this->character_B_A_.updatePollEvent(ev))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayerHud::updateBagPollEvent(sf::Event& ev)
{
	if (this->character_B_B_.updatePollEvent(ev))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayerHud::updateQuestPollEvent(sf::Event& ev)
{
	if (this->character_B_C_.updatePollEvent(ev))
	{
		//std::cout << "Showing quests" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayerHud::updateSkillTreePollEvent(sf::Event& ev)
{
	if (this->character_B_D_.updatePollEvent(ev))
	{
		std::cout << "DEBUG::PLAYERHUD::UPDATESKILLTREEPOLLEVENT() -> Showing skill tree" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayerHud::updateGatherPollEvent(sf::Event& ev)
{
	if (this->character_B_F_.updatePollEvent(ev))
	{
		//std::cout << "Showing quests" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

void PlayerHud::updateSkillOnePollEvent(sf::Event& ev, Classes* playerClass, std::vector<Enemy*>& enemies, const std::map<std::string, int>& playerStats, int& playerMana, bool& playerIsCombat)
{
	if (this->skill_One_ != NULL)
	{
		if (!this->skill_One_->getIsCooldown())
		{
			//LEFT CLICK (USE SKILL)
			if (this->skill_One_ != NULL)
			{
				//CHECK IF PLAYER HAS ENOUGH MANA FOR SKILL 
				if (playerStats.find("mana")->second >= this->skill_One_->getManaCost())
				{
					if (this->skill_B_A_.updatePollEvent(ev))
					{
						for (int i = 0; i < enemies.size(); ++i)
						{
							if (enemies[i] != NULL)
							{
								//IF ANY ENEMY INTERSECTS THE SKILL RANGE BOX THEN DAMAGE IT
								if (this->skill_One_->getSkillBoundaries().intersects(enemies[i]->getEnemyGlobalBounds()))
								{
									//ONLY IF THE ENEMIES HAS MORE THAN 0 HEALTH
									if (enemies[i]->getHealth() > 0)
									{
										enemies[i]->setHealth(this->skill_One_->getDamage(playerStats.find("strength")->second, playerStats.find("intelligence")->second, playerStats.find("wisdom")->second));

										playerMana -= this->skill_One_->getManaCost();
										playerIsCombat = true;

										this->skill_One_->setIsCooldown(true);

										this->skill_One_CD_Timer_.restart();
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//RIGHT CLICK (CHANGE SKILL)
	if (playerClass != NULL)
	{
		//DO NOT ALLOW PLAYER TO SWITCH SKILLS WHILE ON COOLDOWN
		if (this->skill_One_ != NULL)
		{
			if (!this->skill_One_->getIsCooldown())
			{
				if (this->skill_B_A_.updateRightClickPollEvent(ev))
				{
					this->initializeSkills(playerClass);
				}

				if (this->skill_Dropdown_List_.getIsVisible())
				{
					this->skill_Dropdown_List_.updatePollEvent(ev, playerClass, &this->skill_One_);
				}
			}
		}
		else
		{
			if (this->skill_B_A_.updateRightClickPollEvent(ev))
			{
				this->initializeSkills(playerClass);
			}

			if (this->skill_Dropdown_List_.getIsVisible())
			{
				this->skill_Dropdown_List_.updatePollEvent(ev, playerClass, &this->skill_One_);
			}
		}
		

		if (this->skill_One_ != NULL)
		{
			if (this->skill_One_->getIsUnlocked())
			{
				if (&this->skill_B_A_.getTexture() == NULL)
				{
					this->skill_B_A_.setFillColor(sf::Color::White);
					this->skill_B_A_.setTexture(&this->skill_One_->getTexture());

					this->skill_T_A_.setString(this->skill_One_->getName());

					this->skill_D_A_.setString(DESCRIPTIONTYPE::SKILL, this->skill_One_->getName(), this->skill_One_->getSummary());
				}
			}
			else
			{
				this->skill_One_ = NULL;
				//TESTING
				this->skill_B_A_.setFillColor(sf::Color::Transparent);
				this->skill_B_A_.setTexture(nullptr);
				
				this->skill_T_A_.setString("Skill 1");

				this->skill_D_A_.setString(DESCRIPTIONTYPE::SKILL, "", "");
			}
		}
	}
}

void PlayerHud::updatePollEvent(sf::Event& ev, int& health, const int& healthMax)
{
	/*
		MAY WANT TO MAKE THIS FUNCTION A RETURN A STRING ON BUTTON PRESSES  BACK TO THE PLAYERTEST SO THAT WE DONT HAVE TO
		PASS EVERYTHING FROM PLAYER INTO HERE. 
	*/

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
}

void PlayerHud::updateNamePosition(const sf::Vector2f& playerPosition)
{
	this->character_T_E_.setPosition(playerPosition.x, playerPosition.y - 22.f);
}

void PlayerHud::update(const sf::Vector2i& mousePositionWindow, const Camera& camera, const sf::Vector2f& playerPosition, const sf::FloatRect playerBoundaries, std::vector<Enemy*>& enemies, bool& playerIsCombat, bool& isPlayerAttack, bool& isPlayerAttackTextureSet, const sf::FloatRect playerAutoAttackRange)
{
	if (this->is_Hiding_Hud_)
	{
		*this->camera_ = camera;

		this->updateNamePosition(playerPosition);

		this->character_B_A_.updateBoundaries(mousePositionWindow);
		this->character_B_B_.updateBoundaries(mousePositionWindow);
		this->character_B_C_.updateBoundaries(mousePositionWindow);
		this->character_B_D_.updateBoundaries(mousePositionWindow);
		this->character_B_F_.updateBoundaries(mousePositionWindow);

		this->skill_B_A_.updateBoundaries(mousePositionWindow);
		this->skill_B_B_.updateBoundaries(mousePositionWindow);
		this->skill_B_C_.updateBoundaries(mousePositionWindow);

		if (this->skill_One_ != NULL)
		{
			if (this->skill_B_A_.getIsHovering())
			{
				this->skill_One_->setIsVisible(true);
			}
			else
			{
				this->skill_One_->setIsVisible(false);
			}

			this->skill_One_->update(playerPosition, playerBoundaries);

			//IF SKILL ONE TIMER EQUALS SKILL ONE COOLDOWN THEN SET SKILL FOR USE AGAIN 
			if (this->skill_One_->getIsCooldown())
			{
				//std::cout << "DEBUG::PLAYERHUD::UPDATE() -> TIMER: " << this->skill_One_CD_Timer_.getElapsedTime().asSeconds() << std::endl;
				if (this->skill_One_CD_Timer_.getElapsedTime().asSeconds() >= this->skill_One_->getCooldown())
				{
					std::cout << "DEBUG::PLAYERHUD::UPDATE() -> Skill one is off CD." << std::endl;
					
					this->skill_One_->setIsCooldown(false);

					this->skill_X_A_.setSize(this->skill_B_A_.getSize().x, 0.f);
				}
			}
		}

		//PLAYER AUTO ATTACKS
		for (int i = 0; i < enemies.size(); ++i)
		{
			if (enemies[i] != NULL)
			{
				//IF ANY ENEMY INTERSECTS THE SKILL RANGE BOX THEN DAMAGE IT
				if (playerAutoAttackRange.intersects(enemies[i]->getEnemyGlobalBounds()))
				{
					if (!enemies[i]->getIsFalling())
					{
						if (enemies[i]->getHasLootTimerStarted())
						{
							isPlayerAttack = false;
							isPlayerAttackTextureSet = false;
						}
						//ONLY IF THE ENEMIES HAS MORE THAN 0 HEALTH
						if (enemies[i]->getHealth() > 0)
						{
							isPlayerAttack = true;

							if (this->auto_Attack_Timer_.getElapsedTime().asSeconds() >= 1.f)
							{
								enemies[i]->setHealth(1);


								this->auto_Attack_Timer_.restart();
								this->leave_Combat_Timer_.restart();
							}
						}
					}
				}
			}
		}

		//PLAYER COMBAT TIMER 
		if (this->leave_Combat_Timer_.getElapsedTime().asSeconds() >= 5.f)
		{
			playerIsCombat = false;
		}
		else
		{
			//std::cout << "DEBUG::PLAYERHUD::UPDATE() -> TIMER: " << this->leave_Combat_Timer_.getElapsedTime().asSeconds() << std::endl;
		}

		this->skillCooldownBoxHeight();

		if (this->skill_One_ != NULL)
		{
			this->skill_D_A_.update(mousePositionWindow);
		}

		this->skill_Dropdown_List_.update(mousePositionWindow, this->skill_B_A_.getGlobalBounds());
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

		target.draw(this->experience_Bar_Back_);
		target.draw(this->experience_Bar_Front_);

		target.draw(this->race_Icon_Sprite_);

		target.draw(this->bars_Sprite_);

		this->health_T_A_.render(target);
		this->mana_T_A_.render(target);
		this->experience_T_A_.render(target);

		this->character_B_A_.render(target);
		this->character_B_B_.render(target);
		this->character_B_C_.render(target);
		this->character_B_D_.render(target);
		this->character_B_F_.render(target);
		
		this->character_T_A_.render(target);
		this->character_T_B_.render(target);
		this->character_T_C_.render(target);
		this->character_T_D_.render(target);
		this->character_T_F_.render(target);

		target.draw(this->skill_Hotbar_Sprite_);

		this->skill_B_A_.render(target);
		this->skill_B_B_.render(target);
		this->skill_B_C_.render(target);

		this->skill_X_A_.render(target);
			  
		this->skill_T_A_.render(target);
		this->skill_T_B_.render(target);
		this->skill_T_C_.render(target);

		if (!this->skill_Dropdown_List_.getIsVisible())
		{
			this->skill_D_A_.render(target);
		}

		this->skill_Dropdown_List_.render(target);

		target.setView(this->camera_->getView());

		this->character_T_E_.render(target);

		target.setView(target.getDefaultView());
	}
}

void PlayerHud::setWidthOfBars(const int& healthMax, const int& health, const int& manaMax, const int& mana, const int& expMax, const int& exp)
{
	this->health_T_A_.setString("HP: " + std::to_string(health) + " / " + std::to_string(healthMax));
	this->mana_T_A_.setString("MP: " + std::to_string(mana) + " / " + std::to_string(manaMax));
	this->experience_T_A_.setString("EXP: " + std::to_string(exp) + " / " + std::to_string(expMax));

	//std::cout << "DEBUG::PLAYERHUD::SETWIDTHOFBARS() -> health max: " << healthMax << std::endl;
	float healthMaxToFloat = static_cast<float>(healthMax);
	float healthToFloat = static_cast<float>(health);
	//std::cout << "DEBUG::PLAYERHUD::SETWIDTHOFBARS() -> health: " << health << std::endl;

	this->health_Bar_Front_.setSize(sf::Vector2f((healthToFloat / healthMaxToFloat) * 210.f, 10.f));

	float manaMaxToFloat = static_cast<float>(manaMax);
	float manaToFloat = static_cast<float>(mana);

	this->mana_Bar_Front_.setSize(sf::Vector2f((manaToFloat / manaMaxToFloat) * 210.f, 10.f));

	float expMaxToFloat = static_cast<float>(expMax);
	float expToFloat = static_cast<float>(exp);

	this->experience_Bar_Front_.setSize(sf::Vector2f((expToFloat / expMaxToFloat) * 210.f, 10.f));
}

const float PlayerHud::percentToPixel(const float size)
{
	return std::floor(static_cast<float>(this->window_Size_X_)) * (size / 100.f);
}

Skill& PlayerHud::setSkillOne()
{
	return *this->skill_One_;
}

sf::Clock& PlayerHud::setLeaveCombatTimer()
{
	return this->leave_Combat_Timer_;
}

void PlayerHud::skillCooldownBoxHeight()
{
	if (this->skill_One_ != NULL)
	{
		if (this->skill_One_->getIsCooldown())
		{
			this->skill_X_A_.setSize(this->skill_X_A_.getSize().x, -(this->skill_One_CD_Timer_.getElapsedTime().asSeconds() / this->skill_One_->getCooldown()) * this->skill_B_A_.getSize().y);
		}
	}
	
}

