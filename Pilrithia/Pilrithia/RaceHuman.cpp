#include "RaceHuman.h"

RaceHuman::RaceHuman()
{
	this->name_ = "Human";
	this->summary_ = "Selfish people that only care for themselves. Whether it sacrificing themselves to leave behind their name in history or becoming stronger leaving those close to them behind, they will do as they see fit.";

	this->classes_One_ = NULL;

	this->classes_Two_ = NULL;
}

RaceHuman::~RaceHuman()
{
	delete this->classes_One_;
	delete this->classes_Two_;
}

void RaceHuman::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(50.f, 50.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::White);
	this->model_.setOutlineThickness(1.f);
	this->model_.setOutlineColor(sf::Color::White);
}

void RaceHuman::setPlayerClasses(Classes& classes)
{
	this->player_Classes_ = &classes;
}

const std::string RaceHuman::getName() const
{
	return this->name_;
}

const std::string RaceHuman::getSummary() const
{
	return this->summary_;
}

const sf::RectangleShape& RaceHuman::getModel() const
{
	return this->model_;
}

Classes& RaceHuman::getClassesOne() const
{
	return *this->classes_One_;
}

Classes& RaceHuman::getClassesTwo() const
{
	return *this->classes_Two_;
}

Classes& RaceHuman::getPlayerClass() const
{
	return *this->player_Classes_;
}
