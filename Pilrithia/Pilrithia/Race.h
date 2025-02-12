#ifndef RACE_H
#define RACE_H

#include "SFML/Graphics.hpp"

//#include "Classes.h"

class Race
{
public:
	Race();
	virtual ~Race();

	virtual void initializeRace(const float& posX, const float& posY) = 0;

	


	/*
		BASE STATS SETTERS
	*/
	virtual int& setHealthMax() = 0;
	virtual int& setHealth() = 0;
	virtual int& setManaMax() = 0;
	virtual int& setMana() = 0;
	virtual int& setStrength() = 0;
	virtual int& setDexerity() = 0;
	virtual int& setIntelligence() = 0;
	virtual int& setPerception() = 0;
	virtual int& setWisdom() = 0;

	/*
		BASE STATS GETTERS
	*/
	virtual const int& getHealthMax() const = 0;
	virtual const int& getHealth() const = 0;
	virtual const int& getManaMax() const = 0;
	virtual const int& getMana() const = 0;
	virtual const int& getStrength() const = 0;
	virtual const int& getDexerity() const = 0;
	virtual const int& getIntelligence() const = 0;
	virtual const int& getPerception() const = 0;
	virtual const int& getWisdom() const = 0;

	/*
		RESISTANCES SETTERS
	*/
	virtual int& setCold() = 0;
	virtual int& setFire() = 0;
	virtual int& setLightning() = 0;
	virtual int& setPoison() = 0;

	/*
		RESISTANCES GETTERS
	*/
	virtual const int& getCold() const = 0;
	virtual const int& getFire() const = 0;
	virtual const int& getLightning() const = 0;
	virtual const int& getPoison() const = 0;
	

	virtual void setIconTexture(const sf::Texture& texture) = 0;
	virtual void setRunTexture(const sf::Texture& texture) = 0;
	virtual void setIdleTexture(const sf::Texture& texture) = 0;
	virtual void setAttackTexture(const sf::Texture& texture) = 0;
	virtual void setJumpTexture(const sf::Texture& texture) = 0;

	//virtual void setPlayerClasses(Classes& classes) = 0;
	virtual const std::string getName() const = 0;
	virtual const std::string getSummary() const = 0;
	virtual const sf::RectangleShape& getModel() const = 0;
	virtual const sf::Texture& getIconTexture() const = 0;
	virtual const sf::Texture& getRunTexture() const = 0;
	virtual const sf::Texture& getIdleTexture() const = 0;
	virtual const sf::Texture& getAttackTexture() const = 0;
	virtual const sf::Texture& getJumpTexture() const = 0;
	virtual const sf::IntRect& getRunRect() const = 0;
	virtual const sf::IntRect& getIdleRect() const = 0;
	virtual const sf::IntRect& getAttackRect() const = 0;
	virtual const sf::IntRect& getJumpRect() const = 0;

	virtual const int& getRunSheetWidth() const = 0;
	virtual const int& getIdleSheetWidth() const = 0;
	virtual const int& getAttackSheetWidth() const = 0;
	virtual const int& getJumpSheetWidth() const = 0;


private:

private:

};

#endif // !RACE_H
