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

	void AddTile(float gridPosX, float gridPosY);
	void RemoveTile(float gridPosX, float gridPosY);

	void ClearGrid();

private:

private:
	unsigned grid_Max_Size_X_;
	unsigned grid_Max_Size_Y_;

	float tile_Size_X_Y_;

	std::vector<std::vector<Tile*> > grid_;
};

#endif