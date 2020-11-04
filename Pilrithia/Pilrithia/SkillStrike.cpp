#include "SkillStrike.h"

SkillStrike::SkillStrike()
{
	this->name_ = "Strike";
	this->summary_ = "";
}

SkillStrike::~SkillStrike()
{
}

const std::string& SkillStrike::getName() const
{
	return this->name_;
}

const std::string& SkillStrike::getSummary() const
{
	return this->summary_;
}
