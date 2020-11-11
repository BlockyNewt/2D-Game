#ifndef CLASSES_H
#define CLASSES_H

#include "Skill.h"

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

	/*
		BASE STATS SETTERS
	*/
	virtual int& setHealthMax() = 0;
	virtual int& setHealth() = 0;
	virtual int& setManaMax() = 0;
	virtual int& setMana() = 0;
	virtual int& setStrength() = 0;
	virtual int& setDexerity() = 0;
	virtual int& setConstitution() = 0;
	virtual int& setIntelligence() = 0;
	virtual int& setPerception() = 0;
	virtual int& setWisdom() = 0;

	/*
		BASE STATS GETTERS
	*/
	virtual const std::string& getName() const = 0;
	virtual const std::string& getSummary() const = 0;
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
		RESISTANCES SETTERS
	*/
	virtual void setCold(int& value) = 0;
	virtual void setFire(int& value) = 0;
	virtual void setLightning(int& value) = 0;
	virtual void setPoison(int& value) = 0;

	/*
		RESISTANCES GETTERS
	*/
	virtual const int& getCold() const = 0;
	virtual const int& getFire() const = 0;
	virtual const int& getLightning() const = 0;
	virtual const int& getPoison() const = 0;


	virtual Skill& getSkillOne() const = 0;

private:

private:

};

#endif // !CLASSES_H
