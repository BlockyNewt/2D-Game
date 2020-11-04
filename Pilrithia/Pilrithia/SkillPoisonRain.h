#ifndef SKILLPOISONRAIN_H
#define SKILLPOISONRAIN_H

#include "Skill.h"

class SkillPoisonRain
	: public Skill
{
public:
	SkillPoisonRain();
	virtual ~SkillPoisonRain();

	const std::string& getName() const override;
	const std::string& getSummary() const override;

private:

private:

private:
	std::string name_;
	std::string summary_;
};

#endif // !SKILLPOISONRAIN_H
