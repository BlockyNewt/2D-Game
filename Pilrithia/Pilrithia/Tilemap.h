#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Camera.h"
#include "PlayerTest.h"

#include <iostream>
#include <fstream>

class Tilemap
{
public:
	Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY);
	~Tilemap();

	void update(const Camera& camera);

	void render(sf::RenderTarget& target);

	void addTile(float gridPosX, float gridPosY);
	void removeTile(float gridPosX, float gridPosY);
	void save(const std::string fileName);
	void load(const std::string fileName);

	void clearGrid(const bool& isGridEnabled = false);
	void enableGrid();
	void disableGrid();

	void resizeTilemap(const unsigned gridSizeX, const unsigned gridSizeY);
	void resizeTileSize(float tileSizeXY);

	//TESTING 
	void playerCollision(PlayerTest& playerTest);

	const float& getTileSizeXY() const;

private:

private:
	unsigned grid_Max_Size_X_;
	unsigned grid_Max_Size_Y_;

	float tile_Size_X_Y_;
	float camera_Left_Position;
	float camera_Right_Position;
	float camera_Top_Position;
	float camera_Bottom_Position;

	std::vector<std::vector<Tile*> > grid_;
	std::vector<std::vector<Tile*> > outline_;
};

#endif