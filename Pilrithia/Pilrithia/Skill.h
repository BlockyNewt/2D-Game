#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <string>

class Skill
{
public:
	Skill();
	virtual ~Skill();

	virtual const std::string& getName() const = 0;
	virtual const std::string& getSummary() const = 0;

	virtual void setIsUnlocked(bool isUnlocked) = 0;

	virtual const bool& getIsUnlocked() const = 0;

private:

private:

};

#endif // !SKILL_H
