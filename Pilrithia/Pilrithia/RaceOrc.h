#ifndef RACEORC_H
#define RACEORC_H

#include "Race.h"

#include "ClassesSavage.h"
#include "ClassesBerserker.h"
#include "ClassesRainmaker.h"
#include "ClassesWitchDoctor.h"

class RaceOrc
	: public Race
{
public:
	RaceOrc();
	virtual ~RaceOrc();

	void initializeRace(const float& posX, const float& posY) override;

	const std::string getName() const override;
	const std::string getSummary() const override;
	const sf::RectangleShape& getModel() const override;
	Classes& getClassesOne() const override;
	Classes& getClassesTwo() const override;

private:

private:
	std::string name_;
	std::string summary_;

	sf::RectangleShape model_;

	Classes* classes_One_;
	Classes* classes_Advanced_One_;
	Classes* classes_Two_;
	Classes* classes_Advanced_Two_;


};

#endif