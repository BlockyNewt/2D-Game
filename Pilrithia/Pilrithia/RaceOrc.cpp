#include "RaceOrc.h"

RaceOrc::RaceOrc()
{
	this->name_ = "Orc";
	this->summary_ = "Savage and huge beasts that care not for who or what you are, but only themselves. They will fight until their last breath.";

	this->classes_One_ = new ClassesSavage();
	this->classes_Advanced_One_ = new ClassesBerserker();

	this->classes_Two_ = new ClassesRainmaker();
	this->classes_Advanced_Two_ = new ClassesWitchDoctor();
}

RaceOrc::~RaceOrc()
{
	delete this->classes_One_;
	delete this->classes_Advanced_One_;
	delete this->classes_Two_;
	delete this->classes_Advanced_Two_;
}

void RaceOrc::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(50.f, 50.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::Red);
	this->model_.setOutlineThickness(1.f);
	this->model_.setOutlineColor(sf::Color::Red);
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

Classes& RaceOrc::getClassesOne() const
{
	return *this->classes_One_;
}

Classes& RaceOrc::getClassesTwo() const
{
	return *this->classes_Two_;
}
