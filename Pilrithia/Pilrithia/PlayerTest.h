#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "RaceOrc.h"

#include "PlayerHud.h"


class PlayerTest
{	
public:
	PlayerTest();
	~PlayerTest();

	void initializeCharacter(Race* race, const std::string& name);

	void updatePollEvent(sf::Event& ev, const float& dt);
	void update(const sf::Vector2i& mousePositionWindow, const Camera& camera);
	void render(sf::RenderTarget& target);


	void setPosition(float x, float y);
	void setVelocityX(float x);
	void setVelocityY(float y);
	void setIsFalling(bool isFalling);
	void setIsJumping(bool isJumping);

	sf::RectangleShape& getPlayerModel();
	const sf::Vector2f& getVelocity() const;
	const sf::FloatRect getPlayerGlobalBounds() const;
	const sf::FloatRect getNextPositionGlobalBounds() const;
	const bool& getIsFalling() const;
	const bool& getIsJumping() const;

private:
	void initializeHud();

private:
	Race* race_;
	PlayerHud player_Hud_;

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


};

#endif // !PLAYERTEST_H
