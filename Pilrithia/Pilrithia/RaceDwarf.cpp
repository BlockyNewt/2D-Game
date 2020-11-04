#include "RaceDwarf.h"

RaceDwarf::RaceDwarf()
{
	this->name_ = "Dwarf";
	this->summary_ = "Money and shiny things make their eyes glimmer. If the reward is as such, the will be sure to complete it, but don't let their greed get to you.";

	this->classes_One_ = NULL;
	this->classes_Two_ = NULL;
}

RaceDwarf::~RaceDwarf()
{
	delete this->classes_One_;
	delete this->classes_Two_;
}

void RaceDwarf::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(50.f, 50.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::Blue);
	this->model_.setOutlineThickness(1.f);
	this->model_.setOutlineColor(sf::Color::Blue);
}

const std::string RaceDwarf::getName() const
{
	return this->name_;
}

const std::string RaceDwarf::getSummary() const
{
	return this->summary_;
}

const sf::RectangleShape& RaceDwarf::getModel() const
{
	return this->model_;
}

Classes& RaceDwarf::getClassesOne() const
{
	return *this->classes_One_;
}

Classes& RaceDwarf::getClassesTwo() const
{
	return *this->classes_Two_;
}
