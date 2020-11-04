#ifndef RACE_H
#define RACE_H

#include "SFML/Graphics.hpp"

#include "Classes.h"

#include <iostream>
#include <string>

class Race
{
public:
	Race();
	virtual ~Race();

	virtual void initializeRace(const float& posX, const float& posY) = 0;

	virtual const std::string getName() const = 0;
	virtual const std::string getSummary() const = 0;
	virtual const sf::RectangleShape& getModel() const = 0;
	virtual Classes& getClassesOne() const = 0;
	virtual Classes& getClassesTwo() const = 0;

private:

private:

};

#endif // !RACE_H
