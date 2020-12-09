#ifndef RESOURCERACE_H
#define RESOURCERACE_H

#include "SFML/Graphics.hpp"

#include <iostream>

enum class RACE_TYPE_
{
	ORC_ICON_,

	TEST_SPRITE_STRIP,
	TEST_SPRITE_STRIP_IDLE,
	TEST_SPRITE_STRIP_ATTACK,
	TEST_SPRITE_STRIP_JUMP
};

class ResourceRace
{
public:
	ResourceRace();
	~ResourceRace();

	void loadAllRaceTextures();

	const  sf::Texture* getRaceTexture(RACE_TYPE_ raceType) const;

private:
	void loadRaceTexture(const std::string& raceTextureFileName, RACE_TYPE_ raceType);
	void AddToMap(const sf::Texture* raceTexture, RACE_TYPE_ raceType);

private:
	std::map<RACE_TYPE_, sf::Texture> race_Textures_;

};

#endif // !RESOURCERACE_H
