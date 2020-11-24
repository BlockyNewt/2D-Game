#ifndef SKILL_H
#define SKILL_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <math.h>

enum class SKILLTYPE
{
	DEFAULT = 0,

	STRENGTH,
	INTELLIGENCE,
	WISDOM
};

class Skill
{
public:
	Skill();
	virtual ~Skill();


	virtual void update(const sf::Vector2f& playerPosition, const sf::FloatRect playerBoundaries) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual const std::string& getName() const = 0;
	virtual const std::string& getSummary() const = 0;

	virtual void setIsUnlocked(bool isUnlocked) = 0;
	virtual void setIsVisible(bool isVisible) = 0;

	virtual const bool& getIsUnlocked() const = 0;
	virtual const int& getDamage(const int& playerStrength, const int& playerIntelligence, const int& playerWisdom)  = 0;
	virtual const sf::FloatRect getSkillBoundaries() const = 0;
	virtual const bool& getIsVisible() const = 0;
	

private:

private:

};

#endif // !SKILL_H
