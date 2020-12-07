#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::update(sf::RectangleShape& sprite, const sf::IntRect& textureRect, const int& sheetWidth, float time)
{	
	if (this->animation_Clock_.getElapsedTime().asMilliseconds() >= time)
	{
		if (sprite.getTextureRect().left >= sheetWidth - textureRect.width)
		{
			sprite.setTextureRect(sf::IntRect(0, 0, textureRect.width, textureRect.height));
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(sprite.getTextureRect().left + textureRect.width, sprite.getTextureRect().top, textureRect.width, textureRect.height));

			//std::cout << sprite.getTextureRect().left << std::endl;
		}


		this->animation_Clock_.restart();
	}
}
