#include "EnemyTest.h"

EnemyTest::EnemyTest()
{
	this->enemy_Model_.setSize(sf::Vector2f(25.f, 50.f));
	this->enemy_Model_.setPosition(sf::Vector2f(600.f, 120.f));
	this->enemy_Model_.setFillColor(sf::Color::Red);
	this->enemy_Model_.setOutlineThickness(1.f);
	this->enemy_Model_.setOutlineColor(sf::Color::Transparent);

	this->next_Position_.setSize(sf::Vector2f(this->enemy_Model_.getSize().x, this->enemy_Model_.getSize().y));
	this->next_Position_.setPosition(sf::Vector2f(this->enemy_Model_.getPosition().x, this->enemy_Model_.getPosition().y));
	this->next_Position_.setFillColor(sf::Color::Transparent);
	this->next_Position_.setOutlineThickness(1.f);
	this->next_Position_.setOutlineColor(sf::Color::White);

	this->name_ = "Test Enemy";
	this->t_A_.setSettings("Font/arial.ttf", 18, this->name_, sf::Vector2f(this->enemy_Model_.getPosition().x, this->enemy_Model_.getPosition().y), true);

	this->velocity_.x = 1.f;
	this->velocity_.y = 0.f;
	this->movement_Speed_ = 100.f;
	this->gravity_ = 6.f;

	this->direction_ = DIRECTION::RIGHT;

	this->is_Bottom_Colliding_ = false;
}

EnemyTest::~EnemyTest()
{
}

void EnemyTest::update(const float& dt)
{
	this->velocity_.x = 0.f;

	if (this->is_Bottom_Colliding_)
	{
		std::cout << "False bitch" << std::endl;

		if (this->direction_ == DIRECTION::UP)
		{
			this->velocity_.y -= this->movement_Speed_ * dt;
		}
		else if (this->direction_ == DIRECTION::DOWN)
		{
			this->velocity_.y += this->movement_Speed_ * dt;
		}
		else if (this->direction_ == DIRECTION::LEFT &&
			this->direction_ != DIRECTION::RIGHT)
		{
			this->velocity_.x -= this->movement_Speed_ * dt;
		}
		else if (this->direction_ == DIRECTION::RIGHT &&
			this->direction_ != DIRECTION::LEFT)
		{
			this->velocity_.x += this->movement_Speed_ * dt;
		}
	}

	this->enemy_Model_.move(this->velocity_);

	this->next_Position_Bounds_ = this->enemy_Model_.getGlobalBounds();
	this->next_Position_Bounds_.left += this->velocity_.x;
	this->next_Position_Bounds_.top += this->velocity_.y;

	this->next_Position_.setPosition(sf::Vector2f(this->next_Position_Bounds_.left, this->next_Position_Bounds_.top));

	this->t_A_.setPosition(this->enemy_Model_.getGlobalBounds().left, this->enemy_Model_.getGlobalBounds().top - 20.f);
}

void EnemyTest::render(sf::RenderTarget& target)
{
	target.draw(this->next_Position_);

	target.draw(this->enemy_Model_);

	this->t_A_.render(target);
}

void EnemyTest::setVelocityX(float x)
{
	this->velocity_.x = x;
}

void EnemyTest::setVelocityY(float y)
{
	this->velocity_.y = y;
}

void EnemyTest::setDirection(DIRECTION direction)
{
	this->direction_ = direction;
}

void EnemyTest::setIsBottomColliding(bool isBottomColliding)
{
	this->is_Bottom_Colliding_ = isBottomColliding;
}

sf::RectangleShape& EnemyTest::getEnemyModel()
{
	return this->enemy_Model_;
}

const sf::FloatRect EnemyTest::getEnemyGlobalBounds() const
{
	return this->enemy_Model_.getGlobalBounds();
}

const sf::FloatRect EnemyTest::getNextPositionGlobalBounds()
{
	return this->next_Position_Bounds_;
}

const sf::Vector2f& EnemyTest::getVelocity()
{
	return this->velocity_;
}

const float& EnemyTest::getGravity() const
{
	return this->gravity_;
}

const DIRECTION& EnemyTest::getDirection()
{
	return this->direction_;
}

const bool& EnemyTest::getIsBottomColliding() const
{
	return this->is_Bottom_Colliding_;
}
