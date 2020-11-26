#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "RaceOrc.h"

#include "Classes.h"

#include "PlayerHud.h"
#include "PlayerInventory.h"
#include "PlayerBag.h"
#include "PlayerQuest.h"
#include "PlayerSkillTree.h"



#include <math.h>

class PlayerTest
{	
public:
	PlayerTest(const ResourceFont& resourceFont);
	~PlayerTest();

	void initializeCharacter(Race* race, const std::string& name);

	void setTextFont(const ResourceFont& resourceFont);

	void updateSkillsPollEvent(sf::Event& ev, std::vector<Enemy*>& enemies);
	void updatePollEvent(sf::Event& ev, const float& dt);
	//void updateEnemyAutoSelector(Enemy* enemy);
	void update(const sf::Vector2i& mousePositionWindow, const Camera& camera, std::vector<Enemy*>& enemies);
	void renderHudItems(sf::RenderTarget& target);
	void renderPlayerModel(sf::RenderTarget& target);


	void addQuest(Quest& quest);


	void setPosition(float x, float y);
	void setVelocityX(float x);
	void setVelocityY(float y);
	void setIsJumping(bool isJumping);
	PlayerQuest& setPlayerQuest();
	void setStat(const std::string& stat, int value);
	PlayerBag& setPlayerBag();
	int& setExp();
	bool& setIsCombat();

	sf::RectangleShape& getPlayerModel();
	const sf::Vector2f& getVelocity() const;
	const float& getGravity() const;
	const sf::FloatRect getPlayerGlobalBounds() const;
	const sf::FloatRect getNextPositionGlobalBounds() const;
	const bool& getIsJumping() const;
	const PlayerInventory& getPlayerInventory() const;
	const PlayerBag& getPlayerBag() const;
	const PlayerQuest& getPlayerQuest() const;
	const PlayerSkillTree& getPlayerSkillTree() const;
	const int& getStat(const std::string& stat) const;
	int& getStatForChange(const std::string& stat);
	

private:
	void levelUp();

private:
	Camera* camera_;
	Race* race_;
	PlayerHud* player_Hud_;
	PlayerInventory* player_Inventory_;
	PlayerBag* player_Bag_;
	PlayerQuest* player_Quest_;
	PlayerSkillTree* player_Skill_Tree_;

	Classes* class_One_;
	Classes* class_Two_;

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

	bool is_Jumping_;

	int level_;
	int max_Exp_;
	int exp_;

	int skill_Points_;

	bool is_Combat_;
	
	sf::Clock health_Regen_Timer;
	sf::Clock mana_Regen_Timer;


	Enemy* selected_Enemy_;

};

#endif // !PLAYERTEST_H
