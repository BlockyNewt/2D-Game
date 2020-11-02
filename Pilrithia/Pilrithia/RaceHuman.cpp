#include "RaceHuman.h"

RaceHuman::RaceHuman()
{
	this->name_ = "Human";
	this->summary_ = "This is a Human.";
}

RaceHuman::~RaceHuman()
{
}

void RaceHuman::initializeRace(const float& posX, const float& posY)
{
	this->model_.setSize(sf::Vector2f(50.f, 50.f));
	this->model_.setPosition(sf::Vector2f(posX, posY));
	this->model_.setFillColor(sf::Color::White);
	this->model_.setOutlineThickness(1.f);
	this->model_.setOutlineColor(sf::Color::White);
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
