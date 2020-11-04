#include "ClassesRainmaker.h"

ClassesRainmaker::ClassesRainmaker()
{
	this->name_ = "Rainmaker";
	this->summary_ = "A conjurer of the weather that cast hash conditions on their foes.";

	this->skill_One_ = new SkillPoisonRain();
}

ClassesRainmaker::~ClassesRainmaker()
{
	delete this->skill_One_;
}

const std::string& ClassesRainmaker::getName() const
{
	return this->name_;
}

const std::string& ClassesRainmaker::getSummary() const
{
	return this->summary_;
}

Skill& ClassesRainmaker::getSkillOne() const
{
	return *this->skill_One_;
}
