#ifndef ENEMYTEST_H
#define ENEMYTEST_H

#include "Enemy.h"

#include "Text.h"


class EnemyTest
	: public Enemy
{
public:
	EnemyTest();
	EnemyTest(const sf::Vector2f& position, const int& range, const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceEnemy* resourceEnemy, ResourceItem* resourceItem);
	virtual ~EnemyTest();

	void updatePollEvent(sf::Event& ev, std::vector<std::vector<Item*>>& playerBag, const int& maxBagSizeX, const int& maxBagSizeY, const sf::FloatRect playerBoundaries) override;
	void update(const sf::Vector2i& mousePositionWindow, Camera** camera, const sf::FloatRect playerBounds, const float& dt, int& playerHealth, int& playerExp, bool& playerIsCombat, sf::Clock& playerLeaveCombatTimer) override;
	void render(sf::RenderTarget& target) override;

	void setVelocityX(float x) override;
	void setVelocityY(float y) override;
	void setDirection(DIRECTION direction) override;
	void setIsBottomColliding(bool isBottomColliding) override;
	void setHealth(const int& damage) override;
	void setIsFalling(bool isFalling) override;

	sf::RectangleShape& getEnemyModel() override;
	const sf::FloatRect getEnemyGlobalBounds() const override;
	const sf::FloatRect getNextPositionGlobalBounds() override;
	const sf::Vector2f& getVelocity() const override;
	const float& getGravity() const override;
	const DIRECTION& getDirection() override;
	const bool& getIsBottomColliding() const override;
	const bool& getHasLootTimerStarted() const;
	const bool& getIsDead() const override;
	const int& getHealth() const override;
	const bool& getIsFalling() const override;


private:
	void initializeStats() override;
	void initializeModel(const sf::Vector2f& position, const int& range, ResourceEnemy* resourceEnemy) override;
	void initializeHealthBar() override;

	void updateAutoMovement(const float& dt) override;
	void updateHealth() override;


private:
	Animation animation_;

	sf::RectangleShape enemy_Model_;
	sf::RectangleShape next_Position_;

	sf::FloatRect next_Position_Bounds_;

	int range_;
	sf::RectangleShape attack_Range_;

	Text t_A_;

	sf::Vector2f velocity_;
	float movement_Speed_;
	float gravity_;

	DIRECTION direction_;
	bool is_Top_Colliding_;
	bool is_Bottom_Colliding_;
	bool is_Left_Colliding_;
	bool is_Right_Colliding_;

	std::string name_;

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

	int level_;
	int exp_;
	int exp_Tick_;

	sf::RectangleShape health_Bar_Back_;
	sf::RectangleShape health_Bar_Front_;

	sf::Clock attack_Cooldown_Clock_;
	bool is_attack_Cooldown_;


	bool is_Dead_;
	sf::Clock loot_Timer_;
	float loot_Timer_Max_;
	bool has_Loot_Timer_Started_;

	LootWindow* loot_Window_;
	Camera* camera_;


	//TESTING
	Item* item_One_;
	Item* item_Two_;
	std::vector<Item*> items_;

	Box loot_X_A_;
	Text loot_T_A_;

	sf::Texture* walk_Texture_;
	sf::Texture* attack_Texture_;
	sf::Texture* death_Texture_;

	sf::IntRect walk_Rect_;
	sf::IntRect attack_Rect_;
	sf::IntRect death_Rect_;

	int walk_Sheet_Width_;
	int attack_Sheet_Width_;
	int death_Sheet_Width_;

	bool is_Walk_Texture_Set_;
	bool is_Attack_Texture_Set_;
	bool is_Death_Texture_Set_;

	bool is_Falling_;

	ResourceEnemy* resource_Enemy_;

};

#endif // !ENEMYTEST_H
