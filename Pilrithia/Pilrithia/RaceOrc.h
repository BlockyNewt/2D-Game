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

	

	/*
		BASE STATS SETTERS
	*/
	int& setHealthMax() override;
	int& setHealth() override;
	int& setManaMax() override;
	int& setMana() override;
	int& setStrength() override;
	int& setDexerity() override;
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
	

	void setIconTexture(const sf::Texture& texture) override;
	void setRunTexture(const sf::Texture& texture) override;
	void setIdleTexture(const sf::Texture& texture) override;
	void setAttackTexture(const sf::Texture& texture) override;
	void setJumpTexture(const sf::Texture& texture) override;

	//TESTING WILL HAVE TO CHANGE THIS LATER
	const std::string getName() const override;
	const std::string getSummary() const override;
	const sf::RectangleShape& getModel() const override;
	const sf::Texture& getIconTexture() const override;
	const sf::Texture& getRunTexture() const override;
	const sf::Texture& getIdleTexture() const override;
	const sf::Texture& getAttackTexture() const override;
	const sf::Texture& getJumpTexture() const override;

	const sf::IntRect& getRunRect() const override;
	const sf::IntRect& getIdleRect() const override;
	const sf::IntRect& getAttackRect() const override;
	virtual const sf::IntRect& getJumpRect() const override;

	const int& getRunSheetWidth() const override;
	const int& getIdleSheetWidth() const override;
	const int& getAttackSheetWidth() const override;
	const int& getJumpSheetWidth() const override;



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
	int intelligence_;
	int perception_;
	int wisdom_;

	int cold_;
	int fire_;
	int lightning_;
	int poison_;

	//TESTING
	sf::Texture* icon_Texture_;
	sf::Texture* run_Texture_;
	sf::Texture* idle_Texture_;
	sf::Texture* attack_Texture_;
	sf::Texture* jump_Texture_;

	sf::IntRect run_Rect_;
	sf::IntRect idle_Rect_;
	sf::IntRect attack_Rect_;
	sf::IntRect jump_Rect_;

	int run_Sheet_Width_;
	int idle_Sheet_Width_;
	int attack_Sheet_Width_;
	int jump_Sheet_Width_;
};

#endif