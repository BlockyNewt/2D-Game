#include "SkillStabyWab.h"

SkillStabyWab::SkillStabyWab()
{
	this->name_ = "Staby Wab";
	this->summary_ = "Stab the enemy like he is a plaything";
}

SkillStabyWab::~SkillStabyWab()
{
}

const std::string& SkillStabyWab::getName() const
{
	return this->name_;
}

const std::string& SkillStabyWab::getSummary() const
{
	return this->summary_;
}
