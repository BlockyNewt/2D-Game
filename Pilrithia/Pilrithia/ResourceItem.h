#ifndef RESOURCEITEM_H
#define RESOURCEITEM_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <string>

enum class ITEM_TEXTURE_TYPE_
{
	ITEM_TEST,
};

enum class ITEM_SOUND_TYPE_
{
	GATHER_PLANT,
	GATHER_MINE,
	GATHER_CHOP,
};

class ResourceItem
{
public:
	ResourceItem();
	~ResourceItem();

	void loadAllItemTextures();
	const sf::Texture* getItemTexture(ITEM_TEXTURE_TYPE_ itemTextureType) const;

	void loadAllItemSounds();
	sf::Sound* getItemSound(ITEM_SOUND_TYPE_ itemSoundType);

private:
	void loadItemTexture(const std::string& itemTextureFileName, ITEM_TEXTURE_TYPE_ itemTextureType);
	void AddToTextureMap(const sf::Texture* itemTexture, ITEM_TEXTURE_TYPE_ itemTextureType);

	void loadItemSound(const std::string& itemTextureFileName, ITEM_SOUND_TYPE_ itemSoundType);
	void AddToSoundMap(const sf::Sound* itemSound, ITEM_SOUND_TYPE_ itemSoundType);

private:
	std::map<ITEM_TEXTURE_TYPE_, sf::Texture> item_Textures_;
	std::map<ITEM_SOUND_TYPE_, sf::Sound> item_Sounds_;

};

#endif // !RESOURCEITEM_H
