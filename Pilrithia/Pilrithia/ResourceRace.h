#ifndef RESOURCERACE_H
#define RESOURCERACE_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <map>

enum class RACE_TEXTURE_TYPE_
{
	ORC_ICON_,

	TEST_SPRITE_STRIP,
	TEST_SPRITE_STRIP_IDLE,
	TEST_SPRITE_STRIP_ATTACK,
	TEST_SPRITE_STRIP_JUMP
};

enum class RACE_SOUND_TYPE_
{
	FOOTSTEP,
	AUTO_ATTACK,
	LEVEL_UP,
};

class ResourceRace
{
public:
	ResourceRace();
	~ResourceRace();

	void loadAllRaceTextures();
	const sf::Texture* getRaceTexture(RACE_TEXTURE_TYPE_ raceTextureType) const;

	void loadAllRaceSounds();
	sf::Sound* getRaceSound(RACE_SOUND_TYPE_ raceSoundType);

private:
	void loadRaceTexture(const std::string& raceTextureFileName, RACE_TEXTURE_TYPE_ raceTextureType);
	void AddToTextureMap(sf::Texture* raceTexture, RACE_TEXTURE_TYPE_ raceTextureType);

	void loadRaceSound(const std::string& raceSoundFileName, RACE_SOUND_TYPE_ raceSoundType);
	void AddToSoundMap(sf::Sound* raceSound, RACE_SOUND_TYPE_ raceSoundType);

private:
	std::map<RACE_TEXTURE_TYPE_, sf::Texture*> race_Textures_;
	std::map<RACE_SOUND_TYPE_, sf::Sound*> race_Sounds_;

};

#endif // !RESOURCERACE_H
