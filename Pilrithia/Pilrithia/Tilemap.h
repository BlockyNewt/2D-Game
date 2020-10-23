#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

class Tilemap
{
public:
	Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY);
	~Tilemap();

	void Update();

	void Render(sf::RenderTarget& target);

private:

private:
	std::vector<std::vector<Tile*> > grid_;
};

#endif