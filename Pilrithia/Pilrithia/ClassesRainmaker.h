#ifndef CLASSESRAINMAKER_H
#define CLASSESRAINMAKER_H

#include "Classes.h"

#include "SkillPoisonRain.h"

class ClassesRainmaker 
	: public Classes
{
public:
	ClassesRainmaker();
	virtual ~ClassesRainmaker();

	const std::string& getName() const override;
	const std::string& getSummary() const override;
	Skill& getSkillOne() const override;

private:

private:
	std::string name_;
	std::string summary_;

	Skill* skill_One_;

};

#endif // !CLASSESRAINMAKER_H
