#ifndef CLASSES_H
#define CLASSES_H

#include "Skill.h"

#include <string>
#include <vector>

enum class CLASSTYPE
{
	DEFAULT = 0,

	PHYSICAL,
	MENTAL,
};

class Classes
{
public:
	Classes();
	virtual ~Classes();

	virtual void setIsSelected(bool isSelected) = 0;
	virtual const bool& getIsSelected() const = 0;
	virtual std::vector<Skill*>& setAvailableSkills() = 0;
	virtual Skill* setSkillOne() = 0;

	virtual const std::string& getName() const = 0;
	virtual const std::string& getSummary() const = 0;
	virtual const std::vector<Skill*>& getAvailableSkills() const = 0;
	virtual const sf::Texture& getClassIcon() const = 0;

	virtual const Skill* getSkillOne() const = 0;

	/*
		BASE STAT GETTERS
	*/
	
	virtual const int& getHealthMax() const = 0;
	virtual const int& getHealth() const = 0;
	virtual const int& getManaMax() const = 0;
	virtual const int& getMana() const = 0;
	virtual const int& getStrength() const = 0;
	virtual const int& getDexerity() const = 0;
	virtual const int& getConstitution() const = 0;
	virtual const int& getIntelligence() const = 0;
	virtual const int& getPerception() const = 0;
	virtual const int& getWisdom() const = 0;


	/*
		RESISTANCES GETTER
	*/
	virtual const int& getCold() const = 0;
	virtual const int& getFire() const = 0;
	virtual const int& getLightning() const = 0;
	virtual const int& getPoison() const = 0;
	


private:

private:

};

#endif // !CLASSES_H
