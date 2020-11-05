#ifndef RACEHUMAN_H
#define RACEHUMAN_H

#include "Race.h"

class RaceHuman
	: public Race
{
public:
	RaceHuman();
	virtual ~RaceHuman();

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
	Classes* classes_Two_;

	Classes* player_Classes_;

};

#endif // !RACEHUMAN_H
