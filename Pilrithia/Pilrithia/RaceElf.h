#ifndef RACEELF_H
#define RACEELF_H

#include "Race.h"

class RaceElf
	: public Race
{
public:
	RaceElf();
	virtual ~RaceElf();

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
	Classes* classes_Two_;
};

#endif // !RACEELF_H
