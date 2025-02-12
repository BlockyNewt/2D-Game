#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Camera.h"
#include "PlayerTest.h"

#include "Enemy.h"

#include <iostream>
#include <fstream>

class Tilemap
{
public:
	Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, const unsigned gridSizeZ, float tileSizeXY);
	~Tilemap();

	void updatePollEvent(sf::Event& ev);

	void update(const Camera& camera);
	void updateTileType();

	void render(sf::RenderTarget& target);

	void addTile(float gridPosX, float gridPosY);
	void removeTile(float gridPosX, float gridPosY);
	void save(const std::string fileName);
	void load(const std::string fileName);
	void loadTexture(const std::string& fileName);

	void clearGrid(const bool& isGridEnabled = false);
	void enableGrid(const bool& isGridEnabled = false);
	void disableGrid(const bool& isGridEnabled = false);

	void resizeTilemap(const unsigned gridSizeX, const unsigned gridSizeY);
	void resizeTileSize(float tileSizeXY);


	sf::Sprite& setTextureSprite();
	void setTextureBounds(const sf::IntRect& bounds);

	const float& getTileSizeXY() const;
	const std::string& getTileTypeStr() const;
	const std::string& getTileLayerStr() const;
	const bool& getIsTilemapLoaded() const;
	const sf::Sprite& getTextureSprite() const;
	const sf::IntRect& getTextureBounds() const;

	//TESTING 
	void PlayerCollision(PlayerTest& playerTest);
	void EnemyCollision(Enemy& enemy);


private:

private:
	/*
		GRID
	*/
	unsigned grid_Max_Size_X_;
	unsigned grid_Max_Size_Y_;
	unsigned grid_Max_Size_Z_;
	float tile_Size_X_Y_;
	
	std::vector<std::vector<std::vector< Tile*> > > grid_;
	std::vector<std::vector<Tile*> > outline_;

	bool is_Grid_Enabled_;

	int tile_Type_;
	int tile_Layer_;
	std::string tile_Type_Str_;
	std::string tile_Layer_Str_;

	bool is_Bottom_Colliding_;


	bool is_Tilemap_Loaded_;

	/*
		CAMERA 
	*/
	float camera_Left_Position;
	float camera_Right_Position;
	float camera_Top_Position;
	float camera_Bottom_Position;

	sf::Texture texture_;
	std::string texture_File_Name_;
	sf::Sprite texture_Sprite_;

	sf::IntRect texture_Bounds_;
	
};

#endif