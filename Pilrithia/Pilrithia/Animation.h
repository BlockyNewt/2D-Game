#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

#include <iostream>

class Animation
{
public:
	Animation();
	~Animation();

	void update(sf::RectangleShape& sprite, const sf::IntRect& textureRect, const int& sheetWidth, float time);

private:

private:
	sf::Clock animation_Clock_;

};

#endif // !ANIMATION_H
