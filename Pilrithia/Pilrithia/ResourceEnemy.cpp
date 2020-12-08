#include "ResourceEnemy.h"

ResourceEnemy::ResourceEnemy()
{
}

ResourceEnemy::~ResourceEnemy()
{
}

void ResourceEnemy::loadAllEnemyTextures()
{
	this->loadEnemyTexture("skeleton_Idle_.png", ENEMYTYPE::SKELETONTEXTURE);
}

const sf::Texture* ResourceEnemy::getEnemyTexture(ENEMYTYPE enemyType) const
{
	auto findPos = this->enemy_Textures_.find(enemyType);

	if (findPos != this->enemy_Textures_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceEnemy::loadEnemyTexture(const std::string& enemyTextureFileName, ENEMYTYPE enemyType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + enemyTextureFileName))
	{
		this->AddToMap(texture, enemyType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEENEMY::LOADENEMYTEXTURE() -> Couldn't load texture from file " << enemyTextureFileName << std::endl;
	}
}

void ResourceEnemy::AddToMap(const sf::Texture* enemyTexture, ENEMYTYPE enemyType)
{
	this->enemy_Textures_.insert(std::make_pair(enemyType, *enemyTexture));
}
