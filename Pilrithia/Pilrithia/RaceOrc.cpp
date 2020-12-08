#include "RaceOrc.h"

RaceOrc::RaceOrc()
{
	this->name_ = "Orc";
	this->summary_ = "Green, huge, terrifying, and also a bit dim witted. They fight with pure strength and show no sign of weakness making one on one battles challenging for their opponents. Just their battlecrys and screams alone can bring terror into the most intellectual of warriors. They do not stop until their last breath and will wreak havoc on anything in their way before then. \n\nOrcs may be savages but when it comes to the people of their clan they show much care and affection towards one another.";

	this->health_Max_ = 20;
	this->health_ = this->health_Max_;
	this->mana_Max_ = 10;
	this->mana_ = this->mana_Max_;
	this->strength_ = 0;
	this->dexerity_ = 0;
	this->intelligence_ = 5;
	this->perception_ = 0;
	this->wisdom_ = 5;

	this->cold_ = 0;
	this->fire_ = 0;
	this->lightning_ = 0;
	this->poison_ = 0;

	this->icon_Texture_ = new sf::Texture();
	this->run_Texture_ = new sf::Texture();
	this->idle_Texture_ = new sf::Texture();
	this->attack_Texture_ = new sf::Texture();
	this->jump_Texture_ = new sf::Texture();

	this->run_Rect_ = sf::IntRect(0, 0, 96, 77);
	this->run_Sheet_Width_ = 1056;

	this->idle_Rect_ = sf::IntRect(0, 0, 96, 77);
	this->idle_Sheet_Width_ = 288;

	this->attack_Rect_ = sf::IntRect(0, 0, 96, 77);
	this->attack_Sheet_Width_ = 480;

	this->jump_Rect_ = sf::IntRect(0, 0, 96, 77);
	this->jump_Sheet_Width_ = 209;
}

RaceOrc::~RaceOrc()
{
	delete this->icon_Texture_;	
	delete this->run_Texture_;
	delete this->idle_Texture_;
	delete this->attack_Texture_;
	delete this->jump_Texture_;
}

void RaceOrc::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(96.f, 77.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::White);
	this->model_.setOutlineThickness(1.f);
	this->model_.setOutlineColor(sf::Color::White);
}

const std::string RaceOrc::getName() const
{
	return this->name_;
}

const std::string RaceOrc::getSummary() const
{
	return this->summary_;
}

const sf::RectangleShape& RaceOrc::getModel() const
{
	return this->model_;
}

const sf::Texture& RaceOrc::getIconTexture() const
{
	return *this->icon_Texture_;
}

const sf::Texture& RaceOrc::getRunTexture() const
{
	return *this->run_Texture_;
}

const sf::Texture& RaceOrc::getIdleTexture() const
{
	return *this->idle_Texture_;
}

const sf::Texture& RaceOrc::getAttackTexture() const
{
	return *this->attack_Texture_;
}

const sf::Texture& RaceOrc::getJumpTexture() const
{
	return *this->jump_Texture_;
}

const sf::IntRect& RaceOrc::getRunRect() const
{
	return this->run_Rect_;
}

const sf::IntRect& RaceOrc::getIdleRect() const
{
	return this->idle_Rect_;
}

const sf::IntRect& RaceOrc::getAttackRect() const
{
	return	this->attack_Rect_;
}

const sf::IntRect& RaceOrc::getJumpRect() const
{
	return this->jump_Rect_;
}

const int& RaceOrc::getRunSheetWidth() const
{
	return this->run_Sheet_Width_;
}

const int& RaceOrc::getIdleSheetWidth() const
{
	return this->idle_Sheet_Width_;
}

const int& RaceOrc::getAttackSheetWidth() const
{
	return this->attack_Sheet_Width_;
}

const int& RaceOrc::getJumpSheetWidth() const
{
	return this->jump_Sheet_Width_;
}

int& RaceOrc::setHealthMax()
{
	return this->health_Max_;
}

int& RaceOrc::setHealth()
{
	return this->health_;
}

int& RaceOrc::setManaMax()
{
	return this->mana_Max_;
}

int& RaceOrc::setMana()
{
	return this->mana_;
}

int& RaceOrc::setStrength()
{
	return this->strength_;
}

int& RaceOrc::setDexerity()
{
	return this->dexerity_;
}

int& RaceOrc::setIntelligence()
{
	return this->intelligence_;
}

int& RaceOrc::setPerception()
{
	return this->perception_;
}

int& RaceOrc::setWisdom()
{
	return this->wisdom_;
}

const int& RaceOrc::getHealthMax() const
{
	return this->health_Max_;
}

const int& RaceOrc::getHealth() const
{
	return this->health_;
}

const int& RaceOrc::getManaMax() const
{
	return this->mana_Max_;
}

const int& RaceOrc::getMana() const
{
	return this->mana_;
}

const int& RaceOrc::getStrength() const
{
	return this->strength_;
}

const int& RaceOrc::getDexerity() const
{
	return this->dexerity_;
}

const int& RaceOrc::getIntelligence() const
{
	return this->intelligence_;
}

const int& RaceOrc::getPerception() const
{
	return this->perception_;
}

const int& RaceOrc::getWisdom() const
{
	return this->wisdom_;
}

int& RaceOrc::setCold()
{
	return this->cold_;	
}

int& RaceOrc::setFire()
{
	return this->fire_;	
}

int& RaceOrc::setLightning()
{
	return this->lightning_;
}

int& RaceOrc::setPoison()
{
	return this->poison_;
}

const int& RaceOrc::getCold() const
{
	return this->cold_;
}

const int& RaceOrc::getFire() const
{
	return this->fire_;
}

const int& RaceOrc::getLightning() const
{
	return this->lightning_;
}

const int& RaceOrc::getPoison() const
{
	return this->poison_;
}

void RaceOrc::setIconTexture(const sf::Texture& texture)
{
	*this->icon_Texture_ = texture;
}

void RaceOrc::setRunTexture(const sf::Texture& texture)
{
	*this->run_Texture_ = texture;
}

void RaceOrc::setIdleTexture(const sf::Texture& texture)
{
	*this->idle_Texture_ = texture;	
}

void RaceOrc::setAttackTexture(const sf::Texture& texture)
{
	*this->attack_Texture_ = texture;
}

void RaceOrc::setJumpTexture(const sf::Texture& texture)
{
	*this->jump_Texture_ = texture;	
}

//Classes& RaceOrc::getClassesOne() const
//{
//	return *this->classes_One_;
//}
//
//Classes& RaceOrc::getClassesTwo() const
//{
//	return *this->classes_Two_;
//}
//
//Classes& RaceOrc::getPlayerClass() const
//{
//	return *this->player_Classes_;
//}
