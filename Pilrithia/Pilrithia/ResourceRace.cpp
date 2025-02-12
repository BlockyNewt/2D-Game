#include "ResourceRace.h"

ResourceRace::ResourceRace()
{
}

ResourceRace::~ResourceRace()
{
	for (std::map<RACE_TEXTURE_TYPE_, sf::Texture*>::iterator itr = this->race_Textures_.begin(); itr != this->race_Textures_.end(); itr++)
	{
		delete itr->second;
		//this->race_Textures_.erase(itr);
	}

	this->race_Textures_.clear();

	if (this->race_Textures_.empty())
	{
		std::cout << "DEBUG::RESOURCERACE::~RESOURCERACE() -> Deleted all textures." << std::endl;
	}

	for (std::map<RACE_SOUND_TYPE_, sf::Sound*>::iterator itr = this->race_Sounds_.begin(); itr != this->race_Sounds_.end(); itr++)
	{
		delete itr->second->getBuffer();
		delete itr->second;
		//this->race_Sounds_.erase(itr);
	}

	this->race_Sounds_.clear();

	if (this->race_Sounds_.empty())
	{
		std::cout << "DEBUG::RESOURCERACE::~RESOURCERACE() -> Deleted all sounds." << std::endl;
	}
}

void ResourceRace::loadAllRaceTextures()
{
	/*
		LOAD ALL TEXTURES FOR RACE
	*/
	this->loadRaceTexture("orc_Icon_.png", RACE_TEXTURE_TYPE_::ORC_ICON_);
	this->loadRaceTexture("test_Strip_.png", RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP);
	this->loadRaceTexture("test_Strip_Idle_.png", RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_IDLE);
	this->loadRaceTexture("test_Strip_Attack_.png", RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_ATTACK);
	this->loadRaceTexture("test_Strip_Jump_.png", RACE_TEXTURE_TYPE_::TEST_SPRITE_STRIP_JUMP);
}

void ResourceRace::loadAllRaceSounds()
{
	/*
		LOAD ALL SOUNDS FOR RACE
	*/
	this->loadRaceSound("footstep_.wav", RACE_SOUND_TYPE_::FOOTSTEP);
	this->loadRaceSound("auto_Attack_.wav", RACE_SOUND_TYPE_::AUTO_ATTACK);
	this->loadRaceSound("level_Up_.wav", RACE_SOUND_TYPE_::LEVEL_UP);
}

const sf::Texture* ResourceRace::getRaceTexture(RACE_TEXTURE_TYPE_ raceTextureType) const
{
	auto findPos = this->race_Textures_.find(raceTextureType);

	if (findPos != this->race_Textures_.end())
	{
		return findPos->second;
	}
	else
	{
		return NULL;
	}
}

sf::Sound* ResourceRace::getRaceSound(RACE_SOUND_TYPE_ raceSoundType) 
{
	auto findPos = this->race_Sounds_.find(raceSoundType);

	if (findPos != this->race_Sounds_.end())
	{
		return findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceRace::loadRaceTexture(const std::string& raceTextureFileName, RACE_TEXTURE_TYPE_ raceTextureType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + raceTextureFileName))
	{
		this->AddToTextureMap(texture, raceTextureType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCERACE::LOADRACETEXTURE() -> Couldn't load texture from file " << raceTextureFileName << std::endl;
	}
}

void ResourceRace::loadRaceSound(const std::string& raceSoundFileName, RACE_SOUND_TYPE_ raceSoundType)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

	if (soundBuffer->loadFromFile("Sound/" + raceSoundFileName))
	{
		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(*soundBuffer);

		this->AddToSoundMap(sound, raceSoundType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDSOUND() -> Couldn't load sound from file " << raceSoundFileName << std::endl;
	}
}

void ResourceRace::AddToTextureMap(sf::Texture* raceTexture, RACE_TEXTURE_TYPE_ raceTextureType)
{
	this->race_Textures_.insert(std::make_pair(raceTextureType, raceTexture));
}

void ResourceRace::AddToSoundMap(sf::Sound* raceSound, RACE_SOUND_TYPE_ raceSoundType)
{
	this->race_Sounds_.insert(std::make_pair(raceSoundType, raceSound));
}
