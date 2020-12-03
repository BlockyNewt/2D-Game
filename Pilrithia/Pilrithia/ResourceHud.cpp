#include "ResourceHud.h"

ResourceHud::ResourceHud()
{
}

ResourceHud::~ResourceHud()
{
}

void ResourceHud::loadAllHudTextures()
{
	this->loadHudTexture("Bars_2.png", HUDTYPE::BAR);
	this->loadHudTexture("bag_.png", HUDTYPE::BAG);
	this->loadHudTexture("x_Button_.png", HUDTYPE::CLOSE);
	this->loadHudTexture("gathering_.png", HUDTYPE::GATHER);
	this->loadHudTexture("hotbar_.png", HUDTYPE::HOTBAR);
	this->loadHudTexture("window_One_.png", HUDTYPE::WINDOW);

	this->loadHudTexture("race_Face_.png", HUDTYPE::RACEFACE);

	this->loadHudTexture("inventory_Icon_.png", HUDTYPE::INVENTORYICON);
	this->loadHudTexture("bag_Icon_.png", HUDTYPE::BAGICON);
	this->loadHudTexture("quest_Icon_.png", HUDTYPE::QUESTICON);
	this->loadHudTexture("skill_Icon_.png", HUDTYPE::SKILLICON);
}

const sf::Texture* ResourceHud::getHudTexture(HUDTYPE hudType) const
{
	auto findPos = this->hud_Textures_.find(hudType);

	if (findPos != this->hud_Textures_.end())
	{
		return &findPos->second;
	}
	else
	{
		return NULL;
	}
}

void ResourceHud::loadHudTexture(const std::string& hudTextureFileName, HUDTYPE hudType)
{
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("Texture/" + hudTextureFileName))
	{
		this->AddToMap(texture, hudType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEHUD::LOADHUDTEXTURE() -> Couldn't load texture from file " << hudTextureFileName << std::endl;
	}
}

void ResourceHud::AddToMap(const sf::Texture* hudTexture, HUDTYPE hudType)
{
	this->hud_Textures_.insert(std::make_pair(hudType, *hudTexture));
}
