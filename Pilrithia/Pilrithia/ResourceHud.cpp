#include "ResourceHud.h"

ResourceHud::ResourceHud()
{
}

ResourceHud::~ResourceHud()
{
}

void ResourceHud::loadAllHudTextures()
{
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

const sf::Texture* ResourceHud::getHudTexture(HUD_TEXTURE_TYPE_ hudTextureType) const
{
	auto findPos = this->hud_Textures_.find(hudTextureType);

	if (findPos != this->hud_Textures_.end())
	{
		return &findPos->second;
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
		this->AddToMap(texture, hudTextureType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDTEXTURE() -> Couldn't load texture from file " << hudTextureFileName << std::endl;
	}
}

void ResourceHud::AddToMap(const sf::Texture* hudTexture, HUD_TEXTURE_TYPE_ hudTextureType)
{
	this->hud_Textures_.insert(std::make_pair(hudTextureType, *hudTexture));
}
