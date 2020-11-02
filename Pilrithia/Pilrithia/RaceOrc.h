#ifndef RACEORC_H
#define RACEORC_H

#include "Race.h"

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

private:

private:
	std::string name_;
	std::string summary_;

	sf::RectangleShape model_;

};

#endif