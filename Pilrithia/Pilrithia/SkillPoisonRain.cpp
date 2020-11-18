#include "SkillPoisonRain.h"

SkillPoisonRain::SkillPoisonRain()
{
	this->name_ = "Poison Rain";
	this->summary_ = "Make infectious poison rain from dark clouds.";

	this->is_Unlocked_ = false;
}

SkillPoisonRain::~SkillPoisonRain()
{
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

const bool& SkillPoisonRain::getIsUnlocked() const
{
	return this->is_Unlocked_;
}
