#include "RaceElf.h"

RaceElf::RaceElf()
{
	this->name_ = "Elf";
	this->summary_ = "Patient and farelly intelligent type of people that live deep within the woods. Their care for nature and the world is what makes them one of the most powerful races.";

	this->classes_One_ = NULL;
	this->classes_Two_ = NULL;
}

RaceElf::~RaceElf()
{
	delete this->classes_One_;
	delete this->classes_Two_;
}

void RaceElf::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(50.f, 50.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::Green);
	this->model_.setOutlineThickness(1.f);
	this->model_.setOutlineColor(sf::Color::Green);
}

const std::string RaceElf::getName() const
{
	return this->name_;
}

const std::string RaceElf::getSummary() const
{
	return this->summary_;
}

const sf::RectangleShape& RaceElf::getModel() const
{
	return this->model_;
}

Classes& RaceElf::getClassesOne() const
{
	return *this->classes_One_;
}

Classes& RaceElf::getClassesTwo() const
{
	return *this->classes_Two_;
}
