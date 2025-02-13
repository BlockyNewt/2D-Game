#include "Animation.h"

Animation::Animation()
{
	this->is_Animation_Complete_ = false;
}

Animation::~Animation()
{
	std::cout << "DEBUG::ANIMATION::~ANIMATION() -> Deconstructed" << std::endl;
}

void Animation::update(sf::RectangleShape& sprite, const sf::IntRect& textureRect, const int& sheetWidth, float time)
{	
	/*
		USED FOR ANY ANIMATIONS BESIDES DEATH
	*/
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

void Animation::updateDeath(sf::RectangleShape& sprite, const sf::IntRect& textureRect, const int& sheetWidth, float time)
{
	/*
		USED SPECIFICALLY FOR DYING ANIMATIONS
	*/
	if (!this->is_Animation_Complete_)
	{
		if (this->animation_Clock_.getElapsedTime().asMilliseconds() >= time)
		{
			if (sprite.getTextureRect().left >= sheetWidth - textureRect.width)
			{
				this->is_Animation_Complete_ = true;
			}
			else
			{
				sprite.setTextureRect(sf::IntRect(sprite.getTextureRect().left + textureRect.width, sprite.getTextureRect().top, textureRect.width, textureRect.height));

				//std::cout << sprite.getTextureRect().left << std::endl;
			}

			this->animation_Clock_.restart();
		}
	}
}

