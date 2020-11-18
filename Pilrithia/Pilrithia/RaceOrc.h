#ifndef RACEORC_H
#define RACEORC_H

#include "Race.h"

#include "ClassesRainmaker.h"

class RaceOrc
	: public Race
{
public:
	RaceOrc();
	virtual ~RaceOrc();

	void initializeRace(const float& posX, const float& posY) override;

	//void setPlayerClasses(Classes& classes) override;

	const std::string getName() const override;
	const std::string getSummary() const override;
	const sf::RectangleShape& getModel() const override;
	

	/*
		BASE STATS SETTERS
	*/
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

	/*
		BASE STATS GETTERS
	*/
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

	/*
		RESISTANCES SETTERS
	*/
	int& setCold() override;
	int& setFire() override;
	int& setLightning() override;
	int& setPoison() override;

	/*
		RESISTANCES GETTERS
	*/
	const int& getCold() const override;
	const int& getFire() const override;
	const int& getLightning() const override;
	const int& getPoison() const override;
	
private:

private:
	std::string name_;
	std::string summary_;

	sf::RectangleShape model_;

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

	/*Classes* classes_One_;
	Classes* classes_One_Advanced_;
	Classes* classes_Two_;
	Classes* classes_Two_Advanced_;

	Classes* player_Classes_;*/

};

#endif