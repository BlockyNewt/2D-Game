#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "SFML/Graphics.hpp"

#include <iostream>	

class PlayerTest
{	
public:
	PlayerTest();
	~PlayerTest();

	void updatePollEvent(sf::Event& ev, const float& dt);
	void update();
	void render(sf::RenderTarget& target);


	void setVelocityX(float x);
	void setVelocityY(float y);
	void setIsFalling(bool isFalling);

	sf::RectangleShape& getPlayerModel();
	const sf::Vector2f& getVelocity() const;
	const sf::FloatRect getPlayerGlobalBounds() const;
	const sf::FloatRect getNextPositionGlobalBounds() const;
	const bool& getIsFalling() const;
	const bool& getIsJumping() const;

private:

private:
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
