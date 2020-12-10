#include "ResourceNpc.h"

ResourceNpc::ResourceNpc()
{
}

ResourceNpc::~ResourceNpc()
{
}

void ResourceNpc::loadAllNpcTextures()
{
	/*
		LOAD ALL TEXTURES FOR NPC
	*/
	this->loadNpcTexture("quest_Npc_.png", NPC_TEXTURE_TYPE_::TEST_QUEST_NPC_TEXTURE);
	this->loadNpcTexture("merchant_Npc_.png", NPC_TEXTURE_TYPE_::TEST_MERCHANT_NPC_TEXTURE);
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

void ResourceNpc::AddToMap(const sf::Texture* npcTexture, NPC_TEXTURE_TYPE_ npcTextureType)
{
	this->npc_Textures_.insert(std::make_pair(npcTextureType, *npcTexture));
}
