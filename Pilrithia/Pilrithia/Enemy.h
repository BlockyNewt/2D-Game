#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>

enum class DIRECTION
{
	DEFAULT = 0,

	UP, 
	DOWN,
	LEFT,
	RIGHT
};

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual void setVelocityX(float x) = 0;
	virtual void setVelocityY(float y) = 0;
	virtual void setDirection(DIRECTION direction) = 0;
	virtual void setIsBottomColliding(bool isBottomColliding) = 0;


	virtual sf::RectangleShape& getEnemyModel() = 0;
	virtual const sf::FloatRect getEnemyGlobalBounds() const = 0;
	virtual const sf::FloatRect getNextPositionGlobalBounds() = 0;
	virtual const sf::Vector2f& getVelocity() = 0;
	virtual const float& getGravity() const = 0;
	virtual const DIRECTION& getDirection() = 0;
	virtual const bool& getIsBottomColliding() const = 0;


private:

private:

};

#endif // !1
