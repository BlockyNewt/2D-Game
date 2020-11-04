#include "ClassesSavage.h"

ClassesSavage::ClassesSavage()
{
	this->name_ = "Savage";
	this->summary_ = "Take your foes down by whatever it means as long as the outcome will be death.";

	this->skill_One_ = new SkillStabyWab();
}

ClassesSavage::~ClassesSavage()
{
	delete this->skill_One_;
}

const std::string& ClassesSavage::getName() const
{
	return this->name_;
}

const std::string& ClassesSavage::getSummary() const
{
	return this->summary_;
}

Skill& ClassesSavage::getSkillOne() const
{
	return *this->skill_One_;
}
