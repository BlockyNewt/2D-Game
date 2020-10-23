#include "Tilemap.h"

Tilemap::Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY)
{

	this->grid_.resize(gridSizeX, std::vector<Tile*>());
	for (int i = 0; i < gridSizeX; ++i)
	{
		for (int k = 0; k < gridSizeY; ++k)
		{
			this->grid_[k].resize(gridSizeY, NULL);
		}
	}

	for (int i = 0; i < gridSizeX; ++i)
	{
		this->grid_[i].push_back(new Tile(i * tileSizeXY, i * tileSizeXY, tileSizeXY));

		for (int k = 0; k < gridSizeY; ++k)
		{
			this->grid_[i][k] = new Tile(i * tileSizeXY, k * tileSizeXY, tileSizeXY);
		}
	}
}

Tilemap::~Tilemap()
{
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
