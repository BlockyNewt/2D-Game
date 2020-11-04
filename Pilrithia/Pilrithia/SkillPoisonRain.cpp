#include "SkillPoisonRain.h"

SkillPoisonRain::SkillPoisonRain()
{
	this->name_ = "Poison Rain";
	this->summary_ = "Make infectious poison rain from dark clouds.";
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
