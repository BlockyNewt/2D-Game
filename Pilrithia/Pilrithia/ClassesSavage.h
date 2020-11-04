#ifndef CLASSESSAVAGE_H
#define CLASSESSAVAGE_H

#include "Classes.h"

#include "SkillStabyWab.h"

class ClassesSavage
	: public Classes
{
public:
	ClassesSavage();
	virtual ~ClassesSavage();

	const std::string& getName() const override;
	const std::string& getSummary() const override;
	Skill& getSkillOne() const override;

private:

private:
	std::string name_;
	std::string summary_;

	Skill* skill_One_;

};

#endif // !CLASSESSAVAGE_H
