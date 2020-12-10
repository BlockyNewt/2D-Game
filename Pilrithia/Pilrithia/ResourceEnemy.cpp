#include "ResourceEnemy.h"

ResourceEnemy::ResourceEnemy()
{
}

ResourceEnemy::~ResourceEnemy()
{
}

void ResourceEnemy::loadAllEnemyTextures()
{
	/*
		LOAD ALL TEXTURES FOR ENEMIES
	*/
	this->loadEnemyTexture("skeleton_Walk_.png", ENEMY_TEXTURE_TYPE_::SKELETON_WALK_TEXTURE);
	this->loadEnemyTexture("skeleton_Attack_.png", ENEMY_TEXTURE_TYPE_::SKELETON_ATTACK_TEXTURE);
	this->loadEnemyTexture("skeleton_Death_.png", ENEMY_TEXTURE_TYPE_::SKELETON_DEATH_TEXTURE);
}

void ResourceEnemy::loadAllEnemySounds()
{
	/*
		LOAD ALL SOUNDS FOR ENEMIES
	*/
	this->loadEnemySound("enemy_Attack_.wav", ENEMY_SOUND_TYPE_::ENEMY_ATTACK);
}

const sf::Texture* ResourceEnemy::getEnemyTexture(ENEMY_TEXTURE_TYPE_ enemyTextureType) const
{
	auto findPos = this->enemy_Textures_.find(enemyTextureType);

	if (findPos != this->enemy_Textures_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

sf::Sound* ResourceEnemy::getEnemySound(ENEMY_SOUND_TYPE_ enemySoundType) 
{
	auto findPos = this->enemy_Sounds_.find(enemySoundType);

	if (findPos != this->enemy_Sounds_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceEnemy::loadEnemyTexture(const std::string& enemyTextureFileName, ENEMY_TEXTURE_TYPE_ enemyTextureType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + enemyTextureFileName))
	{
		this->AddToTextureMap(texture, enemyTextureType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEENEMY::LOADENEMYTEXTURE() -> Couldn't load texture from file " << enemyTextureFileName << std::endl;
	}
}

void ResourceEnemy::loadEnemySound(const std::string& enemyTextureFileName, ENEMY_SOUND_TYPE_ enemySoundType)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

	if (soundBuffer->loadFromFile("Sound/" + enemyTextureFileName))
	{
		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(*soundBuffer);

		this->AddToSoundMap(sound, enemySoundType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDSOUND() -> Couldn't load sound from file " << enemyTextureFileName << std::endl;
	}
}

void ResourceEnemy::AddToTextureMap(const sf::Texture* enemyTexture, ENEMY_TEXTURE_TYPE_ enemyTextureType)
{
	this->enemy_Textures_.insert(std::make_pair(enemyTextureType, *enemyTexture));
}

void ResourceEnemy::AddToSoundMap(const sf::Sound* enemySound, ENEMY_SOUND_TYPE_ enemySoundType)
{
	this->enemy_Sounds_.insert(std::make_pair(enemySoundType, *enemySound));
}

