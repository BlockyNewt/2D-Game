#include "NpcTest.h"

NpcTest::NpcTest()
{
	this->npc_Model_.setSize(sf::Vector2f(30.f, 30.f));
	this->npc_Model_.setPosition(sf::Vector2f(30.f, 120.f));
	this->npc_Model_.setFillColor(sf::Color::Magenta);

	this->npc_Range_.setSize(sf::Vector2f(90.f, 30.f));
	this->npc_Range_.setPosition(sf::Vector2f(this->npc_Model_.getPosition().x - 30, this->npc_Model_.getPosition().y));
	this->npc_Range_.setFillColor(sf::Color::Transparent);
	this->npc_Range_.setOutlineThickness(1.f);
	this->npc_Range_.setOutlineColor(sf::Color::Red);
}

NpcTest::~NpcTest()
{
}

void NpcTest::updatePollEvent(sf::Event& ev)
{
}

void NpcTest::update(sf::FloatRect playerBounds)
{
	if (this->npc_Range_.getGlobalBounds().intersects(playerBounds))
	{
		std::cout << "WITHIN RANGE OF NPC" << std::endl;
	}
}

void NpcTest::render(sf::RenderTarget& target)
{
	target.draw(this->npc_Range_);
	target.draw(this->npc_Model_);
}
