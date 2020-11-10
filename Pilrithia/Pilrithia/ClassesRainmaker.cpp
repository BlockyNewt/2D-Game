#include "ClassesRainmaker.h"

ClassesRainmaker::ClassesRainmaker()
{
	this->name_ = "Rainmaker";
	this->summary_ = "A conjurer of the weather that cast hash conditions on their foes.";

	this->class_Type_ = CLASSTYPE::MENTAL;

	this->strength_ = 0;
	this->dexerity_ = 0;
	this->constitution_ = 4;
	this->intelligence_ = 5;
	this->perception_ = 0;
	this->wisdom_ = 5;

	this->cold_ = 0;
	this->fire_ = 0;
	this->lightning_ = 0;
	this->poison_ = 0;

	this->skill_One_ = new SkillPoisonRain();
}

ClassesRainmaker::~ClassesRainmaker()
{
	delete this->skill_One_;
}

void ClassesRainmaker::setStrength(int& value)
{
	this->strength_ = value;
}

void ClassesRainmaker::setDexerity(int& value)
{
	this->dexerity_ = value;
}

void ClassesRainmaker::setConstitution(int& value)
{
	this->constitution_ = value;
}

void ClassesRainmaker::setIntelligence(int& value)
{
	this->intelligence_ = value;
}

void ClassesRainmaker::setPerception(int& value)
{
	this->perception_ = value;
}

void ClassesRainmaker::setWisdom(int& value)
{
	this->wisdom_ = value;
}

void ClassesRainmaker::setCold(int& value)
{
	this->cold_ = value;
}

void ClassesRainmaker::setFire(int& value)
{
	this->fire_ = value;
}

void ClassesRainmaker::setLightning(int& value)
{
	this->lightning_ = value;
}

void ClassesRainmaker::setPoison(int& value)
{
	this->poison_ = value;
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

Skill& ClassesRainmaker::getSkillOne() const
{
	return *this->skill_One_;
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
