#include "SkillPoisonRain.h"

SkillPoisonRain::SkillPoisonRain()
{
	this->name_ = "Fireball";
	this->summary_ = "Shoot a fireball at your enemy";

	this->is_Unlocked_ = false;

	this->mana_Cost_ = 2;

	this->min_Damage_ = 1;
	this->max_Damage_ = 3;
	this->damage_ = 0;
	this->cooldown_ = 2.f;

	this->is_Cooldown_ = false;

	this->skill_Type_ = SKILLTYPE::STRENGTH;

	this->range_Box_.setSize(sf::Vector2f(125.f, 50.f));
	this->range_Box_.setPosition(sf::Vector2f(0.f, 0.f));
	this->range_Box_.setFillColor(sf::Color::Transparent);
	this->range_Box_.setOutlineThickness(1.f);
	this->range_Box_.setOutlineColor(sf::Color::Magenta);

	this->is_Visible_ = false;

	//TESTING
	if (!this->icon_Texture_.loadFromFile("Texture/Fireball_.png"))
	{
		std::cout << "DEBUG::SKILLPOISON::SKILLPOISON() -> Could not load icon for skill." << std::endl;
	}

}

SkillPoisonRain::~SkillPoisonRain()
{
	std::cout << "DEBUG::SKILLPOISONRAIN::~SKILLPOISONRAIN() -> Deconstructed" << std::endl;
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

void SkillPoisonRain::setIsCooldown(bool isCooldown)
{
	this->is_Cooldown_ = isCooldown;
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

const float& SkillPoisonRain::getCooldown() const
{
	return this->cooldown_;
}

const bool& SkillPoisonRain::getIsCooldown() const
{
	return this->is_Cooldown_;
}

const int& SkillPoisonRain::getManaCost() const
{
	return this->mana_Cost_;
}

const sf::Texture& SkillPoisonRain::getTexture() const
{
	return this->icon_Texture_;
}
