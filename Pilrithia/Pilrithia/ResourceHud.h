#ifndef RESOURCEHUD_H
#define RESOURCEHUD_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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
	BUTTON_CLICK,
};

class ResourceHud
{
public:
	ResourceHud();
	~ResourceHud();

	void loadAllHudTextures();
	const  sf::Texture* getHudTexture(HUD_TEXTURE_TYPE_ hudTextureType) const;

	void loadAllHudSounds();
	sf::Sound* getHudSound(HUD_SOUND_TYPE_ hudSoundType);



private:
	void loadHudTexture(const std::string& hudTextureFileName, HUD_TEXTURE_TYPE_ hudTextureType);
	void AddToTextureMap(const sf::Texture* hudTexture, HUD_TEXTURE_TYPE_ hudTextureType);

	void loadHudSound(const std::string& hudSoundFileName, HUD_SOUND_TYPE_ hudSoundType);
	void AddToSoundMap(const sf::Sound* hudSound, HUD_SOUND_TYPE_ hudSoundType);

private:
	std::map<HUD_TEXTURE_TYPE_, sf::Texture> hud_Textures_;
	std::map<HUD_SOUND_TYPE_, sf::Sound> hud_Sound_;

};

#endif // !RESOURCEHUD_H
