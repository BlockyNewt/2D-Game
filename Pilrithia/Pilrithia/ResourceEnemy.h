#ifndef RESOURCEENEMY_H
#define RESOURCEENEMY_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <map>	
#include <string>

enum class ENEMY_TEXTURE_TYPE_
{
	SKELETON_WALK_TEXTURE,
	SKELETON_ATTACK_TEXTURE,
	SKELETON_DEATH_TEXTURE,
};

enum class ENEMY_SOUND_TYPE_
{
	ENEMY_ATTACK,

};


class ResourceEnemy
{
public:
	ResourceEnemy();
	~ResourceEnemy();

	void loadAllEnemyTextures();
	const sf::Texture* getEnemyTexture(ENEMY_TEXTURE_TYPE_ enemyTextureType) const;

	void loadAllEnemySounds();
	sf::Sound* getEnemySound(ENEMY_SOUND_TYPE_ enemySoundType);

private:
	void loadEnemyTexture(const std::string& enemyTextureFileName, ENEMY_TEXTURE_TYPE_ enemyTextureType);
	void AddToTextureMap(const sf::Texture* enemyTexture, ENEMY_TEXTURE_TYPE_ enemyTextureType);

	void loadEnemySound(const std::string& enemyTextureFileName, ENEMY_SOUND_TYPE_ enemySoundType);
	void AddToSoundMap(const sf::Sound* enemySound, ENEMY_SOUND_TYPE_ enemySoundType);

private:
	std::map<ENEMY_TEXTURE_TYPE_, sf::Texture> enemy_Textures_;
	std::map<ENEMY_SOUND_TYPE_, sf::Sound> enemy_Sounds_;

};

#endif // !RESOURCEENEMY_H
