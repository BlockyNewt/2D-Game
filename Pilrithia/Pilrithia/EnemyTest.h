#ifndef ENEMYTEST_H
#define ENEMYTEST_H

#include "Enemy.h"

#include "Text.h"

class EnemyTest
	: public Enemy
{
public:
	EnemyTest();
	EnemyTest(const sf::Vector2f& position, const int& range);
	virtual ~EnemyTest();

	void update(const sf::FloatRect playerBounds, const float& dt, int& playerHealth) override;
	void render(sf::RenderTarget& target) override;

	void setVelocityX(float x) override;
	void setVelocityY(float y) override;
	void setDirection(DIRECTION direction) override;
	void setIsBottomColliding(bool isBottomColliding) override;
	int& setHealth() override;

	sf::RectangleShape& getEnemyModel() override;
	const sf::FloatRect getEnemyGlobalBounds() const override;
	const sf::FloatRect getNextPositionGlobalBounds() override;
	const sf::Vector2f& getVelocity() const override;
	const float& getGravity() const override;
	const DIRECTION& getDirection() override;
	const bool& getIsBottomColliding() const override;
	const bool& getIsDead() const override;

private:
	void initializeStats() override;
	void initializeModel(const sf::Vector2f& position, const int& range) override;
	void initializeHealthBar() override;

	void updateAutoMovement(const float& dt) override;
	void updateHealth() override;


private:
	sf::RectangleShape enemy_Model_;

	sf::RectangleShape next_Position_;

	sf::FloatRect next_Position_Bounds_;

	int range_;
	sf::RectangleShape attack_Range_;

	std::string name_;

	Text t_A_;

	sf::Vector2f velocity_;
	float movement_Speed_;
	float gravity_;

	DIRECTION direction_;

	sf::RectangleShape health_Bar_Back_;
	sf::RectangleShape health_Bar_Front_;

	bool is_Top_Colliding_;
	bool is_Bottom_Colliding_;
	bool is_Left_Colliding_;
	bool is_Right_Colliding_;

	int health_Max_;
	int health_;
	int mana_Max_;
	int mana_;
	int strength_;
	int dexerity_;
	int constitution_;
	int intelligence_;
	int perception_;
	int wisdom_;

	int cold_;
	int fire_;
	int lightning_;
	int poison_;

	sf::Clock attack_Cooldown_Clock_;
	bool is_attack_Cooldown_;


	bool is_Dead_;
};

#endif // !ENEMYTEST_H
