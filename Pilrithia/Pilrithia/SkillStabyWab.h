#ifndef SKILLSTABYWAB_H
#define SKILLSTABYWAB_H

#include "Skill.h"

#include <iostream>
#include <string>

class SkillStabyWab 
	: public Skill
{
public:
	SkillStabyWab();
	virtual ~SkillStabyWab();

	const std::string& getName() const override;
	const std::string& getSummary() const override;

private:

private:
	std::string name_;
	std::string summary_;

};

#endif // !SKILLSTABYWAB_H
