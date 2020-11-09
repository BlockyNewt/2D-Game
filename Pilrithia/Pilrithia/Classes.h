#ifndef CLASSES_H
#define CLASSES_H

#include "Skill.h"

class Classes
{
public:
	Classes();
	virtual ~Classes();

	virtual const std::string& getName() const = 0;
	virtual const std::string& getSummary() const = 0;

	virtual Skill& getSkillOne() const = 0;

private:

private:

};

#endif // !CLASSES_H
