#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Camera.h"

#include "LootWindow.h"

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
	Enemy(const sf::Vector2f& position, const int& range, const ResourceFont& resourceFont);
	virtual ~Enemy();

	virtual void updatePollEvent(sf::Event& ev, std::vector<std::vector<Item*>>& playerBag, const int& maxBagSizeX, const int& maxBagSizeY, const sf::FloatRect playerBoundaries) = 0;
	virtual void update(const sf::Vector2i& mousePositionWindow, Camera** camera, const sf::FloatRect playerBounds, const float& dt, int& playerHealth) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual void setVelocityX(float x) = 0;
	virtual void setVelocityY(float y) = 0;
	virtual void setDirection(DIRECTION direction) = 0;
	virtual void setIsBottomColliding(bool isBottomColliding) = 0;
	virtual void setHealth(const int& damage) = 0;


	virtual sf::RectangleShape& getEnemyModel() = 0;
	virtual const sf::FloatRect getEnemyGlobalBounds() const = 0;
	virtual const sf::FloatRect getNextPositionGlobalBounds() = 0;
	virtual const sf::Vector2f& getVelocity() const = 0;
	virtual const float& getGravity() const = 0;
	virtual const DIRECTION& getDirection() = 0;
	virtual const bool& getIsBottomColliding() const = 0;
	virtual const bool& getHasLootTimerStarted() const = 0;
	virtual const bool& getIsDead() const = 0;


private:
	virtual void initializeStats() = 0;
	virtual void initializeModel(const sf::Vector2f& position, const int& range) = 0;
	virtual void initializeHealthBar() = 0;

	virtual void updateAutoMovement(const float& dt) = 0;
	virtual void updateHealth() = 0;


private:
};

#endif // !1
