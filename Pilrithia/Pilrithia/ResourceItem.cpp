#include "ResourceItem.h"

ResourceItem::ResourceItem()
{
}

ResourceItem::~ResourceItem()
{
	for (std::map<ITEM_TEXTURE_TYPE_, sf::Texture*>::iterator itr = this->item_Textures_.begin(); itr != this->item_Textures_.end(); itr++)
	{
		delete itr->second;
		//this->item_Textures_.erase(itr);
	}

	this->item_Textures_.clear();

	if (this->item_Textures_.empty())
	{
		std::cout << "DEBUG::RESOURCEITEM::~RESOURCEITEM() -> Deleted all textures." << std::endl;
	}

	for (std::map<ITEM_SOUND_TYPE_, sf::Sound*>::iterator itr = this->item_Sounds_.begin(); itr != this->item_Sounds_.end(); itr++)
	{
		delete itr->second->getBuffer();
		delete itr->second;
		//this->item_Sounds_.erase(itr);
	}
	
	this->item_Sounds_.clear();

	if (this->item_Sounds_.empty())
	{
		std::cout << "DEBUG::RESOURCEITEM::~RESOURCEITEM() -> Deleted all sounds." << std::endl;
	}
}

void ResourceItem::loadAllItemTextures()
{
	this->loadItemTexture("item_Textures_.png", ITEM_TEXTURE_TYPE_::ITEM_TEST);
}

void ResourceItem::loadAllItemSounds()
{
	this->loadItemSound("mining_.wav", ITEM_SOUND_TYPE_::GATHER_MINE);
	this->loadItemSound("plant_Rustle_.wav", ITEM_SOUND_TYPE_::GATHER_PLANT);
	this->loadItemSound("chopping_Wood_.wav", ITEM_SOUND_TYPE_::GATHER_CHOP);

	std::cout << "DEBUG::RESOURCEITEM::LOADALLITEMSOUNDS() -> Size: " << this->item_Sounds_.size() << std::endl;
}

const sf::Texture* ResourceItem::getItemTexture(ITEM_TEXTURE_TYPE_ itemTextureType) const
{
	auto findPos = this->item_Textures_.find(itemTextureType);

	if (findPos != this->item_Textures_.end())
	{
		return findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceItem::loadItemTexture(const std::string& itemTextureFileName, ITEM_TEXTURE_TYPE_ itemTextureType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + itemTextureFileName))
	{
		this->AddToTextureMap(texture, itemTextureType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEITEM::LOADITEMTEXTURE() -> Couldn't load texture from file " << itemTextureFileName << std::endl;
	}
}

void ResourceItem::loadItemSound(const std::string& itemTextureFileName, ITEM_SOUND_TYPE_ itemSoundType)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

	if (soundBuffer->loadFromFile("Sound/" + itemTextureFileName))
	{
		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(*soundBuffer);

		this->AddToSoundMap(sound, itemSoundType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEITEM::LOADITEMSOUND() -> Couldn't load sound from file " << itemTextureFileName << std::endl;
	}
}

sf::Sound* ResourceItem::getItemSound(ITEM_SOUND_TYPE_ itemSoundType)
{
	auto findPos = this->item_Sounds_.find(itemSoundType);

	if (findPos != this->item_Sounds_.end())
	{
		return findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceItem::AddToTextureMap(sf::Texture* itemTexture, ITEM_TEXTURE_TYPE_ itemTextureType)
{
	this->item_Textures_.insert(std::make_pair(itemTextureType, itemTexture));
}

void ResourceItem::AddToSoundMap(sf::Sound* itemSound, ITEM_SOUND_TYPE_ itemSoundType)
{
	this->item_Sounds_.insert(std::make_pair(itemSoundType, itemSound));
}