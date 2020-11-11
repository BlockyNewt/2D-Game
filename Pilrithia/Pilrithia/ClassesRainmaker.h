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

	int& setHealthMax() override;
	int& setHealth() override;
	int& setManaMax() override;
	int& setMana() override;
	int& setStrength() override;
	int& setDexerity() override;
	int& setConstitution() override;
	int& setIntelligence() override;
	int& setPerception() override;
	int& setWisdom() override;

	const std::string& getName() const override;
	const std::string& getSummary() const override;
	Skill& getSkillOne() const override;
	const int& getHealthMax() const override;
	const int& getHealth() const override;
	const int& getManaMax() const override;
	const int& getMana() const override;
	const int& getStrength() const override;
	const int& getDexerity() const override;
	const int& getConstitution() const override;
	const int& getIntelligence() const override;
	const int& getPerception() const override;
	const int& getWisdom() const override;



	void setCold(int& value) override;
	void setFire(int& value) override;
	void setLightning(int& value) override;
	void setPoison(int& value) override;

	const int& getCold() const override;
	const int& getFire() const override;
	const int& getLightning() const override;
	const int& getPoison() const override;

private:

private:
	std::string name_;
	std::string summary_;

	CLASSTYPE class_Type_;

	int health_Max_;
	int health_;
	int mana_Max_;
	int mana_;
	int strength_;
	int dexerity_;
	int constitution_;
	int intelligence_;
	int perception_;
	int wisdom_;

	int cold_;
	int fire_;
	int lightning_;
	int poison_;

	Skill* skill_One_;

};

#endif // !CLASSESRAINMAKER_H
