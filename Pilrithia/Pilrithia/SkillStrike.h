#ifndef SKILLSTRIKE_H
#define SKILLSTRIKE_H

#include "Skill.h"

class SkillStrike
	: public Skill	
{
public:
	SkillStrike();
	virtual ~SkillStrike();

	const std::string& getName() const override;
	const std::string& getSummary() const override;

private:

private:
	std::string name_;
	std::string summary_;
};

#endif // !SKILLSTRIKE_H
