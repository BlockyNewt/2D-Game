#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "SFML/Graphics.hpp"

class PlayerTest
{	
public:
	PlayerTest();
	~PlayerTest();

	void updatePollEvent(sf::Event& ev);
	void update();
	void render(sf::RenderTarget& target);

	sf::RectangleShape& getPlayerModel();

private:

private:
	sf::RectangleShape player_Model_;

};

#endif // !PLAYERTEST_H
