#ifndef RESOURCEHUD_H
#define RESOURCEHUD_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <map>

enum class HUD_TEXTURE_TYPE_
{
	BAR,
	BAG,
	CLOSE,
	GATHER,
	HOTBAR,
	WINDOW,

	INVENTORY_WINDOW,

	RACE_FACE,

	INVENTORY_ICON,
	BAG_ICON,
	QUEST_ICON,
	SKILL_ICON,

};

enum class HUD_SOUND_TYPE_
{

};

class ResourceHud
{
public:
	ResourceHud();
	~ResourceHud();

	void loadAllHudTextures();

	const  sf::Texture* getHudTexture(HUD_TEXTURE_TYPE_ hudTextureType) const;

private:
	void loadHudTexture(const std::string& hudTextureFileName, HUD_TEXTURE_TYPE_ hudTextureType);
	void AddToMap(const sf::Texture* hudTexture, HUD_TEXTURE_TYPE_ hudTextureType);

private:
	std::map<HUD_TEXTURE_TYPE_, sf::Texture> hud_Textures_;

};

#endif // !RESOURCEHUD_H
