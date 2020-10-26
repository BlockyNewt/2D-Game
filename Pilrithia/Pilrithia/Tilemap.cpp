#include "Tilemap.h"

Tilemap::Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY)
{
	this->grid_Max_Size_X_ = gridSizeX;
	this->grid_Max_Size_Y_ = gridSizeY;

	this->tile_Size_X_Y_ = tileSizeXY;

	this->grid_.resize(grid_Max_Size_X_, std::vector<Tile*>());
	for (int i = 0; i < grid_Max_Size_X_; ++i)
	{
		for (int k = 0; k < grid_Max_Size_Y_; ++k)
		{
			this->grid_[k].resize(grid_Max_Size_Y_, NULL);
		}
	}

	/*for (int i = 0; i < gridSizeX; ++i)
	{
		this->grid_[i].push_back(new Tile(i * tileSizeXY, i * tileSizeXY, tileSizeXY));

		for (int k = 0; k < gridSizeY; ++k)
		{
			this->grid_[i][k] = new Tile(i * tileSizeXY, k * tileSizeXY, tileSizeXY);
		}
	}*/
}

Tilemap::~Tilemap()
{
	for (auto& x : this->grid_)
	{
		for (auto& y : x)
		{
			delete y;
		}
	}
}

void Tilemap::Update()
{

}

void Tilemap::Render(sf::RenderTarget& target)
{
	for (auto& g : this->grid_)
	{
		for (auto& a : g)
		{
			if (a != NULL)
			{
				a->Render(target);
			}
		}
	}
}

void Tilemap::AddTile(float gridPosX, float gridPosY)
{
	if (this->grid_[gridPosX][gridPosY] == NULL)
	{
		if (gridPosX >= 0 &&
			gridPosX < this->grid_Max_Size_X_ * this->tile_Size_X_Y_ &&
			gridPosY >= 0 &&
			gridPosY < this->grid_Max_Size_Y_ * this->tile_Size_X_Y_)
		{
			this->grid_[gridPosX][gridPosY] = new Tile(gridPosX * this->tile_Size_X_Y_, gridPosY * this->tile_Size_X_Y_, this->tile_Size_X_Y_);
			this->grid_[gridPosX][gridPosY]->SetColor(sf::Color::Yellow);
		}
		else
		{
			std::cout << "DEBUG::TILEMPA::DRAWTILE() -> OUT OF GRID BOUNDS." << std::endl;
		}
	}
	else
	{
		std::cout << "DEBUG::TILEMAP::DRAWTILE() -> TILE IS NOT NULL." << std::endl;
	}
}

void Tilemap::RemoveTile(float gridPosX, float gridPosY)
{
	if (this->grid_[gridPosX][gridPosY] != NULL)
	{
		delete this->grid_[gridPosX][gridPosY];

		this->grid_[gridPosX][gridPosY] = NULL;

		std::cout << "DEBUG::TILEMAP::REMOVETILE() -> TILE REMOVED." << std::endl;
	}
}

void Tilemap::ClearGrid()
{
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			delete this->grid_[x][y];

			this->grid_[x][y] = NULL;
		}
	}

	this->grid_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(this->grid_Max_Size_Y_, NULL);
		}
	}

	std::cout << "DEBUG::TILEMAP::CLEARGRID() -> TILE GRID HAS BEEN CLEARED." << std::endl;
}
