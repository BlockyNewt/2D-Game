#include "ClassesBerserker.h"

ClassesBerserker::ClassesBerserker()
{
	this->name_ = "Berserker";
	this->summary_ = "A deadly fighter that does not follow the rules and will do what it takes to kill.";

	this->skill_One_ = NULL;
}

ClassesBerserker::~ClassesBerserker()
{
	delete this->skill_One_;
}

const std::string& ClassesBerserker::getName() const
{
	return this->name_;
}

const std::string& ClassesBerserker::getSummary() const
{
	return this->summary_;
}

Skill& ClassesBerserker::getSkillOne() const
{
	return *this->skill_One_;
}
