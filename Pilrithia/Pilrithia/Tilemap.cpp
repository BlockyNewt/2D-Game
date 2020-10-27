#include "Tilemap.h"

Tilemap::Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY)
{
	this->grid_Max_Size_X_ = gridSizeX;
	this->grid_Max_Size_Y_ = gridSizeY;

	this->tile_Size_X_Y_ = tileSizeXY;

	std::cout << "BIcasdfasdfth" << std::endl;
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

void Tilemap::update()
{

}

void Tilemap::render(sf::RenderTarget& target)
{
	for (auto& g : this->grid_)
	{
		for (auto& a : g)
		{
			if (a != NULL)
			{
				a->render(target);
			}
		}
	}
}

void Tilemap::addTile(float gridPosX, float gridPosY)
{
	if (gridPosX >= 0 &&
		gridPosX < this->grid_Max_Size_X_&&
		gridPosY >= 0 &&
		gridPosY < this->grid_Max_Size_Y_)
	{
		if (this->grid_[gridPosX][gridPosY] == NULL)
		{
			this->grid_[gridPosX][gridPosY] = new Tile(gridPosX * this->tile_Size_X_Y_, gridPosY * this->tile_Size_X_Y_, this->tile_Size_X_Y_, true);
		}
		else
		{
			std::cout << "DEBUG::TILEMAP::DRAWTILE() -> TILE IS NOT NULL." << std::endl;
		}
	}
	else
	{
		std::cout << "DEBUG::TILEMPA::DRAWTILE() -> OUT OF GRID BOUNDS." << std::endl;
	}
	
}

void Tilemap::removeTile(float gridPosX, float gridPosY)
{
	if (gridPosX >= 0 &&
		gridPosX < this->grid_Max_Size_X_ &&
		gridPosY >= 0 &&
		gridPosY < this->grid_Max_Size_Y_)
	{
		if (this->grid_[gridPosX][gridPosY] != NULL)
		{
			delete this->grid_[gridPosX][gridPosY];

			this->grid_[gridPosX][gridPosY] = NULL;

			std::cout << "DEBUG::TILEMAP::REMOVETILE() -> TILE REMOVED." << std::endl;
		}
	}
}

void Tilemap::save(const std::string fileName)
{
	/*
	
	FORMAT:

		GRID MAX SIZE X
		GRID MAX SIZE Y

		TILE SIZE XY

		POSITION X, POSITION Y, TILESIZE XY, HAS COLOR 
	
	*/

	std::ofstream outToFile;
	outToFile.open("Tilemap/" + fileName);

	if (outToFile.is_open())
	{
		outToFile << this->grid_Max_Size_X_ << "\n" << this->grid_Max_Size_Y_ << "\n" << this->tile_Size_X_Y_ << "\n";

		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				if (this->grid_[x][y])
				{
					outToFile << x << " " << y << " " << this->grid_[x][y]->getHasColor() << " ";
				}
			}
		}

		std::cout << "DEBUG::TILEMAP::SAVE() -> SAVE TO FILE SUCCESSFUL." << std::endl;
	}
	else
	{
		std::cout << "DEBUG::TILEMAP::SAVE() -> COULD NOT OPEN FILE FOR SAVE." << std::endl;
	}

	outToFile.close();
}

void Tilemap::load(const std::string fileName)
{
	this->clearGrid();

	std::ifstream inFromFile;
	inFromFile.open("Tilemap/" + fileName);

	if (inFromFile.is_open())
	{
		inFromFile >> this->grid_Max_Size_X_ >> this->grid_Max_Size_Y_ >> this->tile_Size_X_Y_;

		this->grid_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				this->grid_[y].resize(this->grid_Max_Size_Y_, NULL);
			}
		}

		unsigned x = 0;
		unsigned y = 0;

		int hasColor = 0;


		while (inFromFile >> x >> y >> hasColor)
		{
			this->grid_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, hasColor);
		}


		std::cout << "DEBUG::TILEMAP::SAVE() -> LOAD WAS SUCCESSFUL." << std::endl;
	}
	else
	{
		std::cout << "DEBUG::TILEMAP::SAVE() -> COULD NOT OPEN FILE FOR LOAD." << std::endl;
	}

	inFromFile.close();
}

void Tilemap::clearGrid()
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

void Tilemap::resizeTilemap(const unsigned gridSizeX, const unsigned gridSizeY)
{
	if (gridSizeX > 0)
	{
		this->grid_Max_Size_X_ = gridSizeX;
	}

	if (gridSizeY > 0)
	{
		this->grid_Max_Size_Y_ = gridSizeY;
	}


	this->grid_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			this->grid_[y].resize(this->grid_Max_Size_Y_, NULL);
		}
	}
}

void Tilemap::resizeTileSize(float tileSizeXY)
{
	this->tile_Size_X_Y_ = tileSizeXY;
}
