#include "ResourceRace.h"

ResourceRace::ResourceRace()
{
}

ResourceRace::~ResourceRace()
{
}

void ResourceRace::loadAllRaceTextures()
{
	this->loadRaceTexture("Orc_Icon_.png", RACETYPE::ORCICON);
	this->loadRaceTexture("test_Strip_.png", RACETYPE::TESTSPRITESTRIP);
	this->loadRaceTexture("test_Strip_Idle_.png", RACETYPE::TESTSPRITESTRIPIDLE);
	this->loadRaceTexture("test_Strip_Attack_.png", RACETYPE::TESTSPRITESTRIPATTACK);
	this->loadRaceTexture("test_Strip_Jump_.png", RACETYPE::TESTSPRITESTRIPJUMP);
}

const sf::Texture* ResourceRace::getRaceTexture(RACETYPE raceType) const
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

void ResourceRace::loadRaceTexture(const std::string& raceTextureFileName, RACETYPE raceType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + raceTextureFileName))
	{
		this->AddToMap(texture, raceType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDTEXTURE() -> Couldn't load texture from file " << raceTextureFileName << std::endl;
	}
}

void ResourceRace::AddToMap(const sf::Texture* raceTexture, RACETYPE raceType)
{
	this->race_Textures_.insert(std::make_pair(raceType, *raceTexture));
}
