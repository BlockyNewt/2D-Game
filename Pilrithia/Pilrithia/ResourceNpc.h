#ifndef RESOURCENPC_H
#define RESOURCENPC_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <map>

enum class NPC_TEXTURE_TYPE_
{
	TEST_QUEST_NPC_TEXTURE,
	TEST_MERCHANT_NPC_TEXTURE
};

class ResourceNpc
{
public:
	ResourceNpc();
	~ResourceNpc();

	void loadAllNpcTextures();

	const  sf::Texture* getNpcTexture(NPC_TEXTURE_TYPE_ npcTextureType) const;

private:
	void loadNpcTexture(const std::string& npcTextureFileName, NPC_TEXTURE_TYPE_ npcTextureType);
	void AddToMap(const sf::Texture* npcTexture, NPC_TEXTURE_TYPE_ npcTextureType);

private:
	std::map<NPC_TEXTURE_TYPE_, sf::Texture> npc_Textures_;

};

#endif // !RESOURCENPC_H
