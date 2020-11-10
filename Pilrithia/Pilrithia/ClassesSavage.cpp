#include "ClassesSavage.h"

ClassesSavage::ClassesSavage()
{
	this->name_ = "Savage";
	this->summary_ = "Growl and yell while you swing your blades relentlessly inflicting grave phsyical damage upon your foe.";

	this->class_Type_ = CLASSTYPE::PHYSICAL;

	this->strength_ = 6;
	this->dexerity_ = 2;
	this->constitution_ = 5;
	this->intelligence_ = 0;
	this->perception_ = 1;
	this->wisdom_ = 0;

	this->cold_ = 0;
	this->fire_ = 0;
	this->lightning_ = 0;
	this->poison_ = 0;

	this->skill_One_ = new SkillStabyWab();
}

ClassesSavage::~ClassesSavage()
{
	delete this->skill_One_;
}

void ClassesSavage::setStrength(int& value)
{
	this->strength_ = value;
}

void ClassesSavage::setDexerity(int& value)
{
	this->dexerity_ = value;
}

void ClassesSavage::setConstitution(int& value)
{
	this->constitution_ = value;
}

void ClassesSavage::setIntelligence(int& value)
{
	this->intelligence_ = value;
}

void ClassesSavage::setPerception(int& value)
{
	this->perception_ = value;
}

void ClassesSavage::setWisdom(int& value)
{
	this->wisdom_ = value;
}

void ClassesSavage::setCold(int& value)
{
	this->cold_ = value;
}

void ClassesSavage::setFire(int& value)
{
	this->fire_ = value;
}

void ClassesSavage::setLightning(int& value)
{
	this->lightning_ = value;
}

void ClassesSavage::setPoison(int& value)
{
	this->poison_ = value;
}

const int& ClassesSavage::getCold() const
{
	return this->cold_;
}

const int& ClassesSavage::getFire() const
{
	return this->fire_;
}

const int& ClassesSavage::getLightning() const
{
	return this->lightning_;
}

const int& ClassesSavage::getPoison() const
{
	return this->poison_;
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

const int& ClassesSavage::getStrength() const
{
	return this->strength_;
}

const int& ClassesSavage::getDexerity() const
{
	return this->dexerity_;
}

const int& ClassesSavage::getConstitution() const
{
	return this->constitution_;
}

const int& ClassesSavage::getIntelligence() const
{
	return this->intelligence_;
}

const int& ClassesSavage::getPerception() const
{
	return this->perception_;
}

const int& ClassesSavage::getWisdom() const
{
	return this->wisdom_;
}
