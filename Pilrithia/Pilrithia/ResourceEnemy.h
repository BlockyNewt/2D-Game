#ifndef RESOURCEENEMY_H
#define RESOURCEENEMY_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <map>	
#include <string>

enum class ENEMY_TYPE_
{
	SKELETON_WALK_TEXTURE,
	SKELETON_ATTACK_TEXTURE,
	SKELETON_DEATH_TEXTURE,
};

class ResourceEnemy
{
public:
	ResourceEnemy();
	~ResourceEnemy();

	void loadAllEnemyTextures();

	const  sf::Texture* getEnemyTexture(ENEMY_TYPE_ enemyType) const;

private:
	void loadEnemyTexture(const std::string& enemyTextureFileName, ENEMY_TYPE_ enemyType);
	void AddToMap(const sf::Texture* enemyTexture, ENEMY_TYPE_ enemyType);

private:
	std::map<ENEMY_TYPE_, sf::Texture> enemy_Textures_;

};

#endif // !RESOURCEENEMY_H
