#ifndef SKILLPOISONRAIN_H
#define SKILLPOISONRAIN_H

#include "Skill.h"

class SkillPoisonRain
	: public Skill
{
public:
	SkillPoisonRain();
	virtual ~SkillPoisonRain();

	const std::string& getName() const override;
	const std::string& getSummary() const override;

	void setIsUnlocked(bool isUnlocked) override;

	const bool& getIsUnlocked() const override;
	const int& getDamage(const int& playerStrength, const int& playerIntelligence, const int& playerWisdom)  override;

private:

private:

private:
	std::string name_;
	std::string summary_;

	int mana_Cost_;
	int min_Damage_;
	int max_Damage_;
	int damage_;

	bool is_Unlocked_;

	SKILLTYPE skill_Type_;
};

#endif // !SKILLPOISONRAIN_H
