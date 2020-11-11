#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "RaceOrc.h"

#include "PlayerHud.h"
#include "PlayerInventory.h"
#include "PlayerBag.h"
#include "PlayerQuest.h"
#include "PlayerSkillTree.h"

#include "QuestTest.h"

#include <math.h>

class PlayerTest
{	
public:
	PlayerTest();
	~PlayerTest();

	void initializeCharacter(Race* race, const std::string& name);

	void updatePollEvent(sf::Event& ev, const float& dt);
	void update(const sf::Vector2i& mousePositionWindow, const Camera& camera);
	void renderHudItems(sf::RenderTarget& target);
	void renderPlayerModel(sf::RenderTarget& target);


	void addQuest(Quest& quest);

	void setPosition(float x, float y);
	void setVelocityX(float x);
	void setVelocityY(float y);
	void setIsFalling(bool isFalling);
	void setIsJumping(bool isJumping);
	PlayerQuest& setPlayerQuest();

	sf::RectangleShape& getPlayerModel();
	const sf::Vector2f& getVelocity() const;
	const float& getGravity() const;
	const sf::FloatRect getPlayerGlobalBounds() const;
	const sf::FloatRect getNextPositionGlobalBounds() const;
	const bool& getIsFalling() const;
	const bool& getIsJumping() const;
	const PlayerInventory& getPlayerInventory() const;
	const PlayerBag& getPlayerBag() const;
	const PlayerQuest& getPlayerQuest() const;
	const PlayerSkillTree& getPlayerSkillTree() const;

private:
	void initializeHud();

private:
	Camera* camera_;
	Race* race_;
	PlayerHud* player_Hud_;
	PlayerInventory player_Inventory_;
	PlayerBag player_Bag_;
	PlayerQuest player_Quest_;
	PlayerSkillTree player_Skill_Tree_;

	std::string name_;
	std::map<std::string, int> stats_;
	std::map<std::string, int> resistances_;


	sf::RectangleShape player_Model_;
	sf::RectangleShape next_Position_;

	sf::FloatRect next_Position_Bounds_;
	float position_Before_Jump_;

	sf::Vector2f velocity_;
	float movement_Speed_;
	float gravity_;
	float jump_Speed_;
	float max_Jump_Height_;

	bool is_Falling_;
	bool is_Jumping_;

	int level_;
	float max_Exp_;
	float exp_;

};

#endif // !PLAYERTEST_H
