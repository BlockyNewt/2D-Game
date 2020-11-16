#ifndef ENEMYTEST_H
#define ENEMYTEST_H

#include "Enemy.h"

#include "Text.h"

class EnemyTest
	: public Enemy
{
public:
	EnemyTest();
	virtual ~EnemyTest();

	void update(const float& dt) override;
	void render(sf::RenderTarget& target) override;

	void setVelocityX(float x) override;
	void setVelocityY(float y) override;
	void setDirection(DIRECTION direction) override;
	void setIsBottomColliding(bool isBottomColliding) override;

	sf::RectangleShape& getEnemyModel() override;
	const sf::FloatRect getEnemyGlobalBounds() const override;
	const sf::FloatRect getNextPositionGlobalBounds() override;
	const sf::Vector2f& getVelocity() override;
	const float& getGravity() const override;
	const DIRECTION& getDirection() override;
	const bool& getIsBottomColliding() const override;

private:

private:
	sf::RectangleShape enemy_Model_;

	sf::RectangleShape next_Position_;

	sf::FloatRect next_Position_Bounds_;

	std::string name_;

	Text t_A_;

	sf::Vector2f velocity_;
	float movement_Speed_;
	float gravity_;

	DIRECTION direction_;

	bool is_Bottom_Colliding_;
};

#endif // !ENEMYTEST_H
