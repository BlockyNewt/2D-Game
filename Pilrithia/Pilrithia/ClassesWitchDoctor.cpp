#include "ClassesWitchDoctor.h"

ClassesWitchDoctor::ClassesWitchDoctor()
{
	this->name_ = "Rainmaker";
	this->summary_ = "Heal, cure and cast devistating diseases on your foes.";

	this->skill_One_ = NULL;
}

ClassesWitchDoctor::~ClassesWitchDoctor()
{
	delete this->skill_One_;
}

const std::string& ClassesWitchDoctor::getName() const
{
	return this->name_;
}

const std::string& ClassesWitchDoctor::getSummary() const
{
	return this->summary_;
}

Skill& ClassesWitchDoctor::getSkillOne() const
{
	return *this->skill_One_;
}
