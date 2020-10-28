#include "PlayerTest.h"

PlayerTest::PlayerTest()
{
	this->player_Model_.setSize(sf::Vector2f(30.f, 30.f));
	this->player_Model_.setPosition(sf::Vector2f(0.f, 0.f));
	this->player_Model_.setFillColor(sf::Color::Cyan);
}

PlayerTest::~PlayerTest()
{
}

void PlayerTest::updatePollEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::W)
		{
			this->player_Model_.move(sf::Vector2f(0.f, -5.f));
		}
		else if (ev.key.code == sf::Keyboard::S)
		{
			this->player_Model_.move(sf::Vector2f(0.f, 5.f));
		}
		if (ev.key.code == sf::Keyboard::A)
		{
			this->player_Model_.move(sf::Vector2f(-5.f, 0.f));
		}
		else if (ev.key.code == sf::Keyboard::D)
		{
			this->player_Model_.move(sf::Vector2f(5.f, 0.f));
		}
	}
}

void PlayerTest::update()
{
}

void PlayerTest::render(sf::RenderTarget& target)
{
	target.draw(this->player_Model_);
}

sf::RectangleShape& PlayerTest::getPlayerModel()
{
	return this->player_Model_;
}
