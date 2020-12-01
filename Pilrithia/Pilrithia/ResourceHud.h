#ifndef RESOURCEHUD_H
#define RESOURCEHUD_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <map>

enum class HUDTYPE
{
	BAR,
	BAG,
	CLOSE

};

class ResourceHud
{
public:
	ResourceHud();
	~ResourceHud();

	void loadAllHudTextures();

	const  sf::Texture* getHudTexture(HUDTYPE hudType) const;

private:
	void loadHudTexture(const std::string& hudTextureFileName, HUDTYPE hudType);
	void AddToMap(const sf::Texture* hudTexture, HUDTYPE hudType);

private:
	std::map<HUDTYPE, sf::Texture> hud_Textures_;

};

#endif // !RESOURCEHUD_H
