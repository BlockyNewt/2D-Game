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

	void setStrength(int& value) override;
	void setDexerity(int& value) override;
	void setConstitution(int& value) override;
	void setIntelligence(int& value) override;
	void setPerception(int& value) override;
	void setWisdom(int& value) override;

	const std::string& getName() const override;
	const std::string& getSummary() const override;
	Skill& getSkillOne() const override;
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

#endif // !CLASSESSAVAGE_H
