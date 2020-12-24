#ifndef RESOURCENPC_H
#define RESOURCENPC_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


#include <iostream>
#include <map>

enum class NPC_TEXTURE_TYPE_
{
	TEST_QUEST_NPC_TEXTURE,
	TEST_MERCHANT_NPC_TEXTURE
};

enum class NPC_SOUND_TYPE_
{
	PURCHASE,
};

class ResourceNpc
{
public:
	ResourceNpc();
	~ResourceNpc();

	void loadAllNpcTextures();
	const  sf::Texture* getNpcTexture(NPC_TEXTURE_TYPE_ npcTextureType) const;

	void loadAllNpcSounds();
	sf::Sound* getNpcSound(NPC_SOUND_TYPE_ npcSoundType);

private:
	void loadNpcTexture(const std::string& npcTextureFileName, NPC_TEXTURE_TYPE_ npcTextureType);
	void AddToMap(sf::Texture* npcTexture, NPC_TEXTURE_TYPE_ npcTextureType);

	void loadNpcSound(const std::string& npcTextureFileName, NPC_SOUND_TYPE_ npcSoundType);
	void AddToSoundMap(sf::Sound* npcSound, NPC_SOUND_TYPE_ npcSoundType);

private:
	std::map<NPC_TEXTURE_TYPE_, sf::Texture*> npc_Textures_;
	std::map<NPC_SOUND_TYPE_, sf::Sound*> npc_Sounds_;

};

#endif // !RESOURCENPC_H
