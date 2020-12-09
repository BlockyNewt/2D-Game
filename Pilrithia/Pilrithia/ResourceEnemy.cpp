#include "ResourceEnemy.h"

ResourceEnemy::ResourceEnemy()
{
}

ResourceEnemy::~ResourceEnemy()
{
}

void ResourceEnemy::loadAllEnemyTextures()
{
	this->loadEnemyTexture("skeleton_Walk_.png", ENEMY_TYPE_::SKELETON_WALK_TEXTURE);
	this->loadEnemyTexture("skeleton_Attack_.png", ENEMY_TYPE_::SKELETON_ATTACK_TEXTURE);
	this->loadEnemyTexture("skeleton_Death_.png", ENEMY_TYPE_::SKELETON_DEATH_TEXTURE);
}

const sf::Texture* ResourceEnemy::getEnemyTexture(ENEMY_TYPE_ enemyType) const
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

void ResourceEnemy::loadEnemyTexture(const std::string& enemyTextureFileName, ENEMY_TYPE_ enemyType)
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

void ResourceEnemy::AddToMap(const sf::Texture* enemyTexture, ENEMY_TYPE_ enemyType)
{
	this->enemy_Textures_.insert(std::make_pair(enemyType, *enemyTexture));
}
