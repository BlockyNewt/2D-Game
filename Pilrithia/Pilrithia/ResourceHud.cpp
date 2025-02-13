#include "ResourceHud.h"

ResourceHud::ResourceHud()
{
}

ResourceHud::~ResourceHud()
{
	for (std::map<HUD_TEXTURE_TYPE_, sf::Texture*>::iterator itr = this->hud_Textures_.begin(); itr != this->hud_Textures_.end(); itr++)
	{
		delete itr->second;
		//this->hud_Textures_.erase(itr);
	}

	this->hud_Textures_.clear();

	if (this->hud_Textures_.empty())
	{
		std::cout << "DEBUG::RESOURCERACE::~RESOURCEHUD() -> Deleted all textures." << std::endl;
	}

	for (std::map<HUD_SOUND_TYPE_, sf::Sound*>::iterator itr = this->hud_Sound_.begin(); itr != this->hud_Sound_.end(); itr++)
	{
		delete itr->second->getBuffer();
		delete itr->second;
		//this->hud_Sound_.erase(itr);
	}

	this->hud_Sound_.clear();

	if (this->hud_Sound_.empty())
	{
		std::cout << "DEBUG::RESOURCERACE::~RESOURCEHUD() -> Deleted all sounds." << std::endl;
	}
}

void ResourceHud::loadAllHudTextures()
{
	/*
		LOAD ALL HUD TEXTURES
	*/
	this->loadHudTexture("main_Menu_Button_.png", HUD_TEXTURE_TYPE_::MAIN_MENU_BUTTON);

	this->loadHudTexture("Bars_2.png", HUD_TEXTURE_TYPE_::BAR);
	this->loadHudTexture("bag_.png", HUD_TEXTURE_TYPE_::BAG);
	this->loadHudTexture("x_Button_.png", HUD_TEXTURE_TYPE_::CLOSE);
	this->loadHudTexture("gathering_.png", HUD_TEXTURE_TYPE_::GATHER);
	this->loadHudTexture("hotbar_.png", HUD_TEXTURE_TYPE_::HOTBAR);
	this->loadHudTexture("window_One_.png", HUD_TEXTURE_TYPE_::WINDOW);
	this->loadHudTexture("inventory_Window_.png", HUD_TEXTURE_TYPE_::INVENTORY_WINDOW);

	this->loadHudTexture("race_Face_.png", HUD_TEXTURE_TYPE_::RACE_FACE);

	this->loadHudTexture("inventory_Icon_.png", HUD_TEXTURE_TYPE_::INVENTORY_ICON);
	this->loadHudTexture("bag_Icon_.png", HUD_TEXTURE_TYPE_::BAG_ICON);
	this->loadHudTexture("quest_Icon_.png", HUD_TEXTURE_TYPE_::QUEST_ICON);
	this->loadHudTexture("skill_Icon_.png", HUD_TEXTURE_TYPE_::SKILL_ICON);
}

void ResourceHud::loadAllHudSounds()
{
	/*
		LOAD ALL HUD SOUND TEXTURES
	*/
	this->loadHudSound("button_Click_.wav", HUD_SOUND_TYPE_::BUTTON_CLICK);
	this->loadHudSound("button_Click_2_.wav", HUD_SOUND_TYPE_::BUTTON_HUD_CLICK);
}

const sf::Texture* ResourceHud::getHudTexture(HUD_TEXTURE_TYPE_ hudTextureType) const
{
	auto findPos = this->hud_Textures_.find(hudTextureType);

	if (findPos != this->hud_Textures_.end())
	{
		return findPos->second;
	}
	else
	{
		return NULL;
	}
}

sf::Sound* ResourceHud::getHudSound(HUD_SOUND_TYPE_ hudSoundType) 
{
	auto findPos = this->hud_Sound_.find(hudSoundType);

	if (findPos != this->hud_Sound_.end())
	{
		return findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceHud::loadHudTexture(const std::string& hudTextureFileName, HUD_TEXTURE_TYPE_ hudTextureType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + hudTextureFileName))
	{
		this->AddToTextureMap(texture, hudTextureType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDTEXTURE() -> Couldn't load texture from file " << hudTextureFileName << std::endl;
	}
}

void ResourceHud::loadHudSound(const std::string& hudSoundFileName, HUD_SOUND_TYPE_ hudSoundType)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();
	
	if (soundBuffer->loadFromFile("Sound/" + hudSoundFileName))
	{
		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(*soundBuffer);

		this->AddToSoundMap(sound, hudSoundType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDSOUND() -> Couldn't load sound from file " << hudSoundFileName << std::endl;
	}
}

void ResourceHud::AddToTextureMap(sf::Texture* hudTexture, HUD_TEXTURE_TYPE_ hudTextureType)
{
	this->hud_Textures_.insert(std::make_pair(hudTextureType, hudTexture));
}


void ResourceHud::AddToSoundMap(sf::Sound* hudSound, HUD_SOUND_TYPE_ hudSoundType)
{
	this->hud_Sound_.insert(std::make_pair(hudSoundType, hudSound));
}
