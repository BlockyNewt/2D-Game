#include "SkillPoisonRain.h"

SkillPoisonRain::SkillPoisonRain()
{
	this->name_ = "Poison Rain";
	this->summary_ = "Make infectious poison rain from dark clouds.";

	this->is_Unlocked_ = false;

	this->mana_Cost_ = 4;

	this->min_Damage_ = 1;
	this->max_Damage_ = 3;
	this->damage_ = 0;

	this->skill_Type_ = SKILLTYPE::STRENGTH;

	this->range_Box_.setSize(sf::Vector2f(125.f, 50.f));
	this->range_Box_.setPosition(sf::Vector2f(0.f, 0.f));
	this->range_Box_.setFillColor(sf::Color::Transparent);
	this->range_Box_.setOutlineThickness(1.f);
	this->range_Box_.setOutlineColor(sf::Color::Magenta);

	this->is_Visible_ = false;
}

SkillPoisonRain::~SkillPoisonRain()
{
}

void SkillPoisonRain::update(const sf::Vector2f& playerPosition, const sf::FloatRect playerBoundaries)
{
	this->range_Box_.setPosition(sf::Vector2f(playerBoundaries.left - this->range_Box_.getSize().x / 2.f + playerBoundaries.width / 2.f, playerBoundaries.top));
}

void SkillPoisonRain::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		target.draw(this->range_Box_);
	}
}

const std::string& SkillPoisonRain::getName() const
{
	return this->name_;
}

const std::string& SkillPoisonRain::getSummary() const
{
	return this->summary_;
}

void SkillPoisonRain::setIsUnlocked(bool isUnlocked)
{
	this->is_Unlocked_ = isUnlocked;
}

void SkillPoisonRain::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const bool& SkillPoisonRain::getIsUnlocked() const
{
	return this->is_Unlocked_;
}

const int& SkillPoisonRain::getDamage(const int& playerStrength, const int& playerIntelligence, const int& playerWisdom)
{
	if (this->skill_Type_ == SKILLTYPE::STRENGTH)
	{
		this->damage_ = std::floor((std::pow(playerStrength, 1.2) - this->min_Damage_ * playerStrength + this->max_Damage_));
	}
	else if (this->skill_Type_ == SKILLTYPE::STRENGTH)
	{
		this->damage_ = std::floor((std::pow(playerIntelligence, 1.2) - this->min_Damage_ * playerIntelligence + this->max_Damage_));
	}
	else if (this->skill_Type_ == SKILLTYPE::STRENGTH)
	{
		this->damage_ = std::floor((std::pow(playerWisdom, 1.2) - this->min_Damage_ * playerWisdom + this->max_Damage_));
	}

	return this->damage_;
}

const sf::FloatRect SkillPoisonRain::getSkillBoundaries() const
{
	return this->range_Box_.getGlobalBounds();
}

const bool& SkillPoisonRain::getIsVisible() const
{
	return this->is_Visible_;
}
