#include "ResourceNpc.h"

ResourceNpc::ResourceNpc()
{
}

ResourceNpc::~ResourceNpc()
{
	//for (std::map<NPC_TEXTURE_TYPE_, sf::Texture>::iterator itr = this->npc_Textures_.begin(); itr != this->npc_Textures_.end(); itr++)
	//{
	//	delete& itr;
	//	this->npc_Textures_.erase(itr);
	//}

	//if (this->npc_Textures_.empty())
	//{
	//	std::cout << "DEBUG::RESOURCENPC::~RESOURCENPC() -> Deleted all textures." << std::endl;
	//}

	//for (std::map<NPC_SOUND_TYPE_, sf::Sound>::iterator itr = this->npc_Sounds_.begin(); itr != this->npc_Sounds_.end(); itr++)
	//{
	//	delete itr->second.getBuffer();
	//	this->npc_Sounds_.erase(itr);
	//}

	//if (this->npc_Sounds_.empty())
	//{
	//	std::cout << "DEBUG::RESOURCERACE::~RESOURCERACE() -> Deleted all sounds." << std::endl;
	//}
}

void ResourceNpc::loadAllNpcTextures()
{
	/*
		LOAD ALL TEXTURES FOR NPC
	*/
	this->loadNpcTexture("quest_Npc_.png", NPC_TEXTURE_TYPE_::TEST_QUEST_NPC_TEXTURE);
	this->loadNpcTexture("merchant_Npc_.png", NPC_TEXTURE_TYPE_::TEST_MERCHANT_NPC_TEXTURE);

	std::cout << "npc sound: " << this->npc_Sounds_.size() << std::endl;
}

void ResourceNpc::loadAllNpcSounds()
{
	this->loadNpcSound("purchase_.wav", NPC_SOUND_TYPE_::PURCHASE);
}

const sf::Texture* ResourceNpc::getNpcTexture(NPC_TEXTURE_TYPE_ npcTextureType) const
{
	auto findPos = this->npc_Textures_.find(npcTextureType);

	if (findPos != this->npc_Textures_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

sf::Sound* ResourceNpc::getNpcSound(NPC_SOUND_TYPE_ npcSoundType)
{
	auto findPos = this->npc_Sounds_.find(npcSoundType);

	if (findPos != this->npc_Sounds_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceNpc::loadNpcTexture(const std::string& npcTextureFileName, NPC_TEXTURE_TYPE_ npcTextureType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + npcTextureFileName))
	{
		this->AddToMap(texture, npcTextureType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCENPC::LOADNPCTEXTURE() -> Couldn't load texture from file " << npcTextureFileName << std::endl;
	}
}

void ResourceNpc::loadNpcSound(const std::string& npcTextureFileName, NPC_SOUND_TYPE_ npcSoundType)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

	if (soundBuffer->loadFromFile("Sound/" + npcTextureFileName))
	{
		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(*soundBuffer);

		this->AddToSoundMap(sound, npcSoundType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCENPC::LOADNPCSOUND() -> Couldn't load sound from file " << npcTextureFileName << std::endl;
	}
}

void ResourceNpc::AddToMap(const sf::Texture* npcTexture, NPC_TEXTURE_TYPE_ npcTextureType)
{
	this->npc_Textures_.insert(std::make_pair(npcTextureType, *npcTexture));
}

void ResourceNpc::AddToSoundMap(const sf::Sound* npcSound, NPC_SOUND_TYPE_ npcSoundType)
{
	this->npc_Sounds_.insert(std::make_pair(npcSoundType, *npcSound));
}
