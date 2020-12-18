#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Text.h"

#include <iostream>

class Animation
{
public:
	Animation();
	~Animation();

	void update(sf::RectangleShape& sprite, const sf::IntRect& textureRect, const int& sheetWidth, float time);
	void updateDeath(sf::RectangleShape& sprite, const sf::IntRect& textureRect, const int& sheetWidth, float time);

private:

private:
	sf::Clock animation_Clock_;

	bool is_Animation_Complete_;
};

#endif // !ANIMATION_H
