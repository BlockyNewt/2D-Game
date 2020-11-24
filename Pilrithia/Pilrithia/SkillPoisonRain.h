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

	const bool& getIsUnlocked() const override;
	const int& getDamage(const int& playerStrength, const int& playerIntelligence, const int& playerWisdom)  override;
	const sf::FloatRect getSkillBoundaries() const override;
	const bool& getIsVisible() const override;

private:

private:

private:
	std::string name_;
	std::string summary_;

	int mana_Cost_;
	int min_Damage_;
	int max_Damage_;
	int damage_;

	sf::RectangleShape range_Box_;

	bool is_Unlocked_;

	bool is_Visible_;

	SKILLTYPE skill_Type_;
};

#endif // !SKILLPOISONRAIN_H
