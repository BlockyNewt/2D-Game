#ifndef SKILLPOISONRAIN_H
#define SKILLPOISONRAIN_H

#include "Skill.h"

class SkillPoisonRain
	: public Skill
{
public:
	SkillPoisonRain();
	virtual ~SkillPoisonRain();

	void update(const sf::Vector2f& playerPosition, const sf::FloatRect playerBoundaries) override;
	void render(sf::RenderTarget& target) override;

	const std::string& getName() const override;
	const std::string& getSummary() const override;

	void setIsUnlocked(bool isUnlocked) override;
	void setIsVisible(bool isVisible) override;
	void setIsCooldown(bool isCooldown) override;

	const bool& getIsUnlocked() const override;
	const int& getDamage(const int& playerStrength, const int& playerIntelligence, const int& playerWisdom)  override;
	const sf::FloatRect getSkillBoundaries() const override;
	const bool& getIsVisible() const override;
	const float& getCooldown() const override;
	const bool& getIsCooldown() const override;
	const int& getManaCost() const override;

	//TESTING WILL HAVE TO CHANGE THIS LATER
	const sf::Texture& getTexture() const;

private:

private:

private:
	std::string name_;
	std::string summary_;

	int mana_Cost_;
	int min_Damage_;
	int max_Damage_;
	int damage_;

	float cooldown_;

	sf::RectangleShape range_Box_;

	bool is_Unlocked_;
	bool is_Cooldown_;

	bool is_Visible_;

	SKILLTYPE skill_Type_;

	sf::Texture icon_Texture_;
};

#endif // !SKILLPOISONRAIN_H
