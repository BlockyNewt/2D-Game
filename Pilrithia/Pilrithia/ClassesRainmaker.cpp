#include "ClassesRainmaker.h"

ClassesRainmaker::ClassesRainmaker()
{
	this->name_ = "Rainmaker";
	this->summary_ = "A conjurer of the weather that cast hash conditions on their foes.";

	this->class_Type_ = CLASSTYPE::MENTAL;

	this->skill_One_ = new SkillPoisonRain();

	this->available_Skills_.push_back(this->skill_One_);

	this->is_Selected_ = false;
}

ClassesRainmaker::~ClassesRainmaker()
{
	delete this->skill_One_;
}

void ClassesRainmaker::setIsSelected(bool isSelected)
{
	this->is_Selected_ = isSelected;
}

const bool& ClassesRainmaker::getIsSelected() const
{
	return this->is_Selected_;
}

std::vector<Skill*>& ClassesRainmaker::setAvailableSkills()
{
	return this->available_Skills_;
}

Skill* ClassesRainmaker::setSkillOne()
{
	return this->skill_One_;
}

const int& ClassesRainmaker::getCold() const
{
	return this->cold_;
}

const int& ClassesRainmaker::getFire() const
{
	return this->fire_;
}

const int& ClassesRainmaker::getLightning() const
{
	return this->lightning_;
}

const int& ClassesRainmaker::getPoison() const
{
	return this->poison_;
}

const std::string& ClassesRainmaker::getName() const
{
	return this->name_;
}

const std::string& ClassesRainmaker::getSummary() const
{
	return this->summary_;
}

const Skill* ClassesRainmaker::getSkillOne() const
{
	return this->skill_One_;
}

const std::vector<Skill*>& ClassesRainmaker::getAvailableSkills() const
{
	return this->available_Skills_;
}

const int& ClassesRainmaker::getHealthMax() const
{
	return this->health_Max_;
}

const int& ClassesRainmaker::getHealth() const
{
	return this->health_;
}

const int& ClassesRainmaker::getManaMax() const
{
	return this->mana_Max_;
}

const int& ClassesRainmaker::getMana() const
{
	return this->mana_;
}

const int& ClassesRainmaker::getStrength() const
{
	return this->strength_;
}

const int& ClassesRainmaker::getDexerity() const
{
	return this->dexerity_;
}

const int& ClassesRainmaker::getConstitution() const
{
	return this->constitution_;
}

const int& ClassesRainmaker::getIntelligence() const
{
	return this->intelligence_;
}

const int& ClassesRainmaker::getPerception() const
{
	return this->perception_;
}

const int& ClassesRainmaker::getWisdom() const
{
	return this->wisdom_;
}
