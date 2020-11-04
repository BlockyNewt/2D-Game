#ifndef CLASSESBERSERKER_H
#define CLASSESBERSERKER_H

#include "Classes.h"


class ClassesBerserker
	: public Classes
{
public:
	ClassesBerserker();
	virtual ~ClassesBerserker();

	const std::string& getName() const override;
	const std::string& getSummary() const override;
	Skill& getSkillOne() const override;

private:

private:
	std::string name_;
	std::string summary_;

	Skill* skill_One_;


};

#endif // !CLASSESBERSERKER_H
