#include "RaceOrc.h"

RaceOrc::RaceOrc()
{
	this->name_ = "Orc";
	this->summary_ = "This is an Orc.";
}

RaceOrc::~RaceOrc()
{
}

void RaceOrc::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(50.f, 50.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::Red);
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
