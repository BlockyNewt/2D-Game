#ifndef RESOURCERACE_H
#define RESOURCERACE_H

#include "SFML/Graphics.hpp"

#include <iostream>

enum class RACETYPE
{
	ORCICON,

	TESTSPRITESTRIP,
	TESTSPRITESTRIPIDLE,
	TESTSPRITESTRIPATTACK,
	TESTSPRITESTRIPJUMP
};

class ResourceRace
{
public:
	ResourceRace();
	~ResourceRace();

	void loadAllRaceTextures();

	const  sf::Texture* getRaceTexture(RACETYPE raceType) const;

private:
	void loadRaceTexture(const std::string& raceTextureFileName, RACETYPE raceType);
	void AddToMap(const sf::Texture* raceTexture, RACETYPE raceType);

private:
	std::map<RACETYPE, sf::Texture> race_Textures_;

};

#endif // !RESOURCERACE_H
