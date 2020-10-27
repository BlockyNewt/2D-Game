#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

#include <iostream>
#include <fstream>

class Tilemap
{
public:
	Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY);
	~Tilemap();

	void update();

	void render(sf::RenderTarget& target);

	void addTile(float gridPosX, float gridPosY);
	void removeTile(float gridPosX, float gridPosY);
	void save(const std::string fileName);
	void load(const std::string fileName);

	void clearGrid();

	void resizeTilemap(const unsigned gridSizeX, const unsigned gridSizeY);
	void resizeTileSize(float tileSizeXY);

private:

private:
	unsigned grid_Max_Size_X_;
	unsigned grid_Max_Size_Y_;

	float tile_Size_X_Y_;

	std::vector<std::vector<Tile*> > grid_;
};

#endif