#ifndef RESOURCEENEMY_H
#define RESOURCEENEMY_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <map>	
#include <string>

enum class ENEMYTYPE
{
	SKELETONTEXTURE
};

class ResourceEnemy
{
public:
	ResourceEnemy();
	~ResourceEnemy();

	void loadAllEnemyTextures();

	const  sf::Texture* getEnemyTexture(ENEMYTYPE enemyType) const;

private:
	void loadEnemyTexture(const std::string& enemyTextureFileName, ENEMYTYPE enemyType);
	void AddToMap(const sf::Texture* enemyTexture, ENEMYTYPE enemyType);

private:
	std::map<ENEMYTYPE, sf::Texture> enemy_Textures_;

};

#endif // !RESOURCEENEMY_H
