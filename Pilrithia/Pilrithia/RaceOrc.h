#ifndef RACEORC_H
#define RACEORC_H

#include "Race.h"

#include "ClassesSavage.h"
#include "ClassesRainmaker.h"

class RaceOrc
	: public Race
{
public:
	RaceOrc();
	virtual ~RaceOrc();

	void initializeRace(const float& posX, const float& posY) override;

	void setPlayerClasses(Classes& classes) override;

	const std::string getName() const override;
	const std::string getSummary() const override;
	const sf::RectangleShape& getModel() const override;
	Classes& getClassesOne() const override;
	Classes& getClassesTwo() const override;
	Classes& getPlayerClass() const override;
	
private:

private:
	std::string name_;
	std::string summary_;

	sf::RectangleShape model_;

	Classes* classes_One_;
	Classes* classes_One_Advanced_;
	Classes* classes_Two_;
	Classes* classes_Two_Advanced_;

	Classes* player_Classes_;

};

#endif