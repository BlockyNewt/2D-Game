#include "ResourceRace.h"

ResourceRace::ResourceRace()
{
}

ResourceRace::~ResourceRace()
{
}

void ResourceRace::loadAllRaceTextures()
{
	this->loadRaceTexture("orc_Icon_.png", RACE_TYPE_::ORC_ICON_);
	this->loadRaceTexture("test_Strip_.png", RACE_TYPE_::TEST_SPRITE_STRIP);
	this->loadRaceTexture("test_Strip_Idle_.png", RACE_TYPE_::TEST_SPRITE_STRIP_IDLE);
	this->loadRaceTexture("test_Strip_Attack_.png", RACE_TYPE_::TEST_SPRITE_STRIP_ATTACK);
	this->loadRaceTexture("test_Strip_Jump_.png", RACE_TYPE_::TEST_SPRITE_STRIP_JUMP);
}

const sf::Texture* ResourceRace::getRaceTexture(RACE_TYPE_ raceType) const
{
	auto findPos = this->race_Textures_.find(raceType);

	if (findPos != this->race_Textures_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceRace::loadRaceTexture(const std::string& raceTextureFileName, RACE_TYPE_ raceType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + raceTextureFileName))
	{
		this->AddToMap(texture, raceType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCERACE::LOADRACETEXTURE() -> Couldn't load texture from file " << raceTextureFileName << std::endl;
	}
}

void ResourceRace::AddToMap(const sf::Texture* raceTexture, RACE_TYPE_ raceType)
{
	this->race_Textures_.insert(std::make_pair(raceType, *raceTexture));
}
