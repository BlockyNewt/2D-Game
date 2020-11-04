#ifndef CLASSESWITCHDOCTOR_H
#define CLASSESWITCHDOCTOR_H

#include "Classes.h"

class ClassesWitchDoctor
	: public Classes
{
public:
	ClassesWitchDoctor();
	virtual ~ClassesWitchDoctor();

	const std::string& getName() const override;
	const std::string& getSummary() const override;
	Skill& getSkillOne() const override;

private:

private:
	std::string name_;
	std::string summary_;

	Skill* skill_One_;

};

#endif // !CLASSESWITCHDOCTOR
