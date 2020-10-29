#include "PlayerTest.h"

PlayerTest::PlayerTest()
{
	this->player_Model_.setSize(sf::Vector2f(20.f, 20.f));
	this->player_Model_.setPosition(sf::Vector2f(0.f, 0.f));
	this->player_Model_.setFillColor(sf::Color::Cyan);

	this->next_Position_.setSize(sf::Vector2f(this->player_Model_.getSize().x, this->player_Model_.getSize().y));
	this->next_Position_.setPosition(sf::Vector2f(this->player_Model_.getPosition().x, this->player_Model_.getPosition().y));
	this->next_Position_.setFillColor(sf::Color::Transparent);
	this->next_Position_.setOutlineThickness(1.f);
	this->next_Position_.setOutlineColor(sf::Color::Red);
	
	this->velocity_.x = 0.f;
	this->velocity_.y = 0.f;
	this->movement_Speed_ = 200.f;
	this->gravity_ = 20.f;

	this->is_Falling_ = false;
}

PlayerTest::~PlayerTest()
{
}

void PlayerTest::updatePollEvent(sf::Event& ev, const float& dt)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::W && !this->is_Falling_)
		{
			this->velocity_.y -= this->movement_Speed_ * dt;
		}
		else if (ev.key.code == sf::Keyboard::S && !this->is_Falling_)
		{
			this->velocity_.y += this->movement_Speed_ * dt;
		}
		if (ev.key.code == sf::Keyboard::A)
		{
			this->velocity_.x -= this->movement_Speed_ * dt;
		}
		else if (ev.key.code == sf::Keyboard::D)
		{
			this->velocity_.x += this->movement_Speed_ * dt;
		}

		if (ev.key.code == sf::Keyboard::Space)
		{
			
		}
	}

	if (this->is_Falling_)
	{
		this->velocity_.y += this->gravity_ * dt;
	}
}

void PlayerTest::update()
{
	player_Model_.move(this->velocity_);

	this->player_Bounds_ = this->player_Model_.getGlobalBounds();

	this->next_Position_Bounds_ = this->player_Bounds_;

	this->next_Position_Bounds_.left += this->velocity_.x;
	this->next_Position_Bounds_.top += this->velocity_.y;

	this->next_Position_.setPosition(this->next_Position_Bounds_.left, this->next_Position_Bounds_.top);

	

	if (!this->is_Falling_)
	{
		this->velocity_.y = 0.f;
	}
	this->velocity_.x = 0.f;
}

void PlayerTest::render(sf::RenderTarget& target)
{
	target.draw(this->player_Model_);
	target.draw(this->next_Position_);
}

void PlayerTest::setVelocityX(float x)
{
	this->velocity_.x = x;
}

void PlayerTest::setVelocityY(float y)
{
	this->velocity_.y = y;
}

void PlayerTest::setIsFalling(bool isFalling)
{
	this->is_Falling_ = isFalling;
}

sf::RectangleShape& PlayerTest::getPlayerModel()
{
	return this->player_Model_;
}

const sf::FloatRect& PlayerTest::getPlayerGlobalBounds() const
{
	return this->player_Bounds_;
}

const sf::FloatRect& PlayerTest::getNextPositionGlobalBounds() const
{
	return this->next_Position_Bounds_;
}

const bool& PlayerTest::getIsFalling() const
{
	return this->is_Falling_;
}
