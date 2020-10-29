#include "Tilemap.h"

Tilemap::Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY)
{
	this->grid_Max_Size_X_ = gridSizeX;
	this->grid_Max_Size_Y_ = gridSizeY;

	this->tile_Size_X_Y_ = tileSizeXY;

	this->is_Grid_Enabled_ = false;

	this->tile_Type_ = 0;
	this->tile_Type_Str_ = "";

	this->grid_.resize(grid_Max_Size_X_, std::vector<Tile*>());
	this->outline_.resize(grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(grid_Max_Size_Y_, NULL);
			this->outline_[x].resize(grid_Max_Size_Y_, NULL);
		}
	}

	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->outline_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, 0);
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

void Tilemap::updatePollEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Q)
		{
			if (this->tile_Type_ > 0)
			{
				this->tile_Type_--;
			}
		}

		if (ev.key.code == sf::Keyboard::E)
		{
			this->tile_Type_++;
		}
	}
}

void Tilemap::update(const Camera& camera)
{
	this->updateTileType();


	this->camera_Left_Position = camera.getView().getCenter().x - camera.getView().getSize().x / 2.f;
	this->camera_Right_Position = camera.getView().getCenter().x + camera.getView().getSize().x / 2.f;
	this->camera_Top_Position = camera.getView().getCenter().y - camera.getView().getSize().y / 2.f;
	this->camera_Bottom_Position = camera.getView().getCenter().y + camera.getView().getSize().y / 2.f;
}

void Tilemap::updateTileType()
{
	switch (this->tile_Type_)
	{
	case 0:
		this->tile_Type_Str_ = "Default";
		break;
	case 1:
		this->tile_Type_Str_ = "Boundary";
		break;
	case 2:
		this->tile_Type_Str_ = "Fall";
		break;
	default:
		break;
	}
}

void Tilemap::render(sf::RenderTarget& target)
{
	for (auto& g : this->grid_)
	{
		for (auto& a : g)
		{
			if (a != NULL)
			{
				if (a->getPosition().x > this->camera_Left_Position &&
					a->getPosition().x < this->camera_Right_Position &&
					a->getPosition().y > this->camera_Top_Position &&
					a->getPosition().y < this->camera_Bottom_Position)
				{
					a->render(target);
				}
			}
		}
	}

	if (this->is_Grid_Enabled_)
	{
		for (auto& g : this->outline_)
		{
			for (auto& a : g)
			{
				if (a != NULL)
				{
					if (a->getPosition().x > this->camera_Left_Position &&
						a->getPosition().x < this->camera_Right_Position &&
						a->getPosition().y > this->camera_Top_Position &&
						a->getPosition().y < this->camera_Bottom_Position)
					{
						a->render(target);
					}
				}
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
			this->grid_[gridPosX][gridPosY] = new Tile(gridPosX * this->tile_Size_X_Y_, gridPosY * this->tile_Size_X_Y_, this->tile_Size_X_Y_, this->tile_Type_);
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

		POSITION X, POSITION Y, TILESIZE XY, TYPE CONVERSION
	
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
					outToFile << x << " " << y << " " << this->grid_[x][y]->getTypeConversion() << " ";
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
		this->outline_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				this->grid_[x].resize(this->grid_Max_Size_Y_, NULL);
				this->outline_[x].resize(this->grid_Max_Size_Y_, NULL);
			}
		}

		for (int x = 0; x < grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < grid_Max_Size_Y_; ++y)
			{
				this->outline_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, 0);
			}
		}

		unsigned x = 0;
		unsigned y = 0;

		int typeConversion = 0;

		while (inFromFile >> x >> y >> typeConversion)
		{
			this->grid_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, typeConversion);
		}


		std::cout << "DEBUG::TILEMAP::SAVE() -> LOAD WAS SUCCESSFUL." << std::endl;
	}
	else
	{
		std::cout << "DEBUG::TILEMAP::SAVE() -> COULD NOT OPEN FILE FOR LOAD." << std::endl;
	}

	inFromFile.close();
}

void Tilemap::clearGrid(const bool& isGridEnabled)
{
	this->is_Grid_Enabled_ = isGridEnabled;

	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			delete this->grid_[x][y];
			delete this->outline_[x][y];

			this->grid_[x][y] = NULL;
			this->outline_[x][y] = NULL;
		}
	}

	this->grid_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	this->outline_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(this->grid_Max_Size_Y_, NULL);
			this->outline_[x].resize(grid_Max_Size_Y_, NULL);
		}
	}

	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->outline_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, 0);
		}
	}

	this->enableGrid(this->is_Grid_Enabled_);

	std::cout << "DEBUG::TILEMAP::CLEARGRID() -> TILE GRID HAS BEEN CLEARED." << std::endl;
}

void Tilemap::enableGrid(const bool& isGridEnabled)
{
	this->is_Grid_Enabled_ = isGridEnabled;

	if (this->is_Grid_Enabled_)
	{
		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				this->outline_[x][y]->setOutlineColor(sf::Color::White);
			}
		}
	}
}

void Tilemap::disableGrid(const bool& isGridEnabled)
{
	this->is_Grid_Enabled_ = isGridEnabled;

	if (this->is_Grid_Enabled_)
	{
		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				this->outline_[x][y]->setOutlineColor(sf::Color::Transparent);
			}
		}
	}
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
	std::cout << "AA" << std::endl;

	this->grid_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	this->outline_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(this->grid_Max_Size_Y_, NULL);
			this->outline_[x].resize(grid_Max_Size_Y_, NULL);
		}
	}
	std::cout << "BB" << std::endl;

	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->outline_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, 0);
		}
	}

}

void Tilemap::resizeTileSize(float tileSizeXY)
{
	this->tile_Size_X_Y_ = tileSizeXY;
}

void Tilemap::playerCollision(PlayerTest& playerTest)
{
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			if (this->grid_[x][y] != NULL)
			{
				if (this->grid_[x][y]->getType() == TYPE::BOUNDARY)
				{
					if (this->grid_[x][y]->getGlobalBounds().intersects(playerTest.getNextPositionGlobalBounds()))
					{
						//BOTTOM COLLISION	
						if (playerTest.getPlayerGlobalBounds().top < this->grid_[x][y]->getTopPosition() &&
							playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height < this->grid_[x][y]->getBottomPosition() &&
							playerTest.getPlayerGlobalBounds().left < this->grid_[x][y]->getRightPosition() &&
							playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width > this->grid_[x][y]->getLeftPosition())
						{
							playerTest.setIsFalling(false);
							playerTest.setVelocityY(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(playerTest.getPlayerGlobalBounds().left, this->grid_[x][y]->getTopPosition() - playerTest.getPlayerGlobalBounds().height));
							std::cout << "BOTTOM" << std::endl;
						}

						//TOP COLLISION
						else if (playerTest.getPlayerGlobalBounds().top > this->grid_[x][y]->getTopPosition() &&
							playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height > this->grid_[x][y]->getBottomPosition() &&
							playerTest.getPlayerGlobalBounds().left < this->grid_[x][y]->getRightPosition() &&
							playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width > this->grid_[x][y]->getLeftPosition())
						{	
							playerTest.setVelocityY(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(playerTest.getPlayerGlobalBounds().left, this->grid_[x][y]->getBottomPosition()));
							std::cout << "TOP" << std::endl;

						}


						//RIGHT COLLISION
						if (playerTest.getPlayerGlobalBounds().left < this->grid_[x][y]->getLeftPosition() &&
							playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width < this->grid_[x][y]->getRightPosition() &&
							playerTest.getPlayerGlobalBounds().top < this->grid_[x][y]->getBottomPosition() &&
							playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height > this->grid_[x][y]->getTopPosition())
						{
							std::cout << "RIGHT" << std::endl;

							playerTest.setVelocityX(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(this->grid_[x][y]->getLeftPosition() - playerTest.getPlayerGlobalBounds().width, playerTest.getPlayerGlobalBounds().top));
						}

						//LEFT COLLISION
						else if (playerTest.getPlayerGlobalBounds().left > this->grid_[x][y]->getLeftPosition() &&
							playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width > this->grid_[x][y]->getRightPosition() &&
							playerTest.getPlayerGlobalBounds().top < this->grid_[x][y]->getBottomPosition() &&
							playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height > this->grid_[x][y]->getTopPosition())
						{
							playerTest.setVelocityX(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(this->grid_[x][y]->getRightPosition(), playerTest.getPlayerGlobalBounds().top));
							std::cout << "LEFT" << std::endl;

						}
					}
				}


				

				//if (this->grid_[x][y]->getType() == TYPE::FALL)
				//{
				//	//MAY WANT TO CHANGE THIS LATER 
				//	if (this->grid_[x][y]->getGlobalBounds().intersects(playerTest.getNextPositionGlobalBounds()))
				//	{
				//		//BOTTOM COLLISION	
				//		if (playerTest.getPlayerGlobalBounds().top < this->grid_[x][y]->getTopPosition() &&
				//			playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height < this->grid_[x][y]->getBottomPosition() &&
				//			playerTest.getPlayerGlobalBounds().left < this->grid_[x][y]->getRightPosition() &&
				//			playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width > this->grid_[x][y]->getLeftPosition())
				//		{
				//			playerTest.setIsFalling(true);
				//		}

				//		//TOP COLLISION
				//		else if (playerTest.getPlayerGlobalBounds().top > this->grid_[x][y]->getTopPosition() &&
				//			playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height > this->grid_[x][y]->getBottomPosition() &&
				//			playerTest.getPlayerGlobalBounds().left < this->grid_[x][y]->getRightPosition() &&
				//			playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width > this->grid_[x][y]->getLeftPosition())
				//		{
				//			playerTest.setIsFalling(true);
				//		}

				//		//RIGHT COLLISION
				//		if (playerTest.getPlayerGlobalBounds().left < this->grid_[x][y]->getLeftPosition() &&
				//			playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width < this->grid_[x][y]->getRightPosition() &&
				//			playerTest.getPlayerGlobalBounds().top < this->grid_[x][y]->getBottomPosition() &&
				//			playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height > this->grid_[x][y]->getTopPosition())
				//		{
				//			playerTest.setIsFalling(true);
				//		}

				//		//LEFT COLLISION
				//		else if (playerTest.getPlayerGlobalBounds().left > this->grid_[x][y]->getLeftPosition() &&
				//			playerTest.getPlayerGlobalBounds().left + playerTest.getPlayerGlobalBounds().width > this->grid_[x][y]->getRightPosition() &&
				//			playerTest.getPlayerGlobalBounds().top < this->grid_[x][y]->getBottomPosition() &&
				//			playerTest.getPlayerGlobalBounds().top + playerTest.getPlayerGlobalBounds().height > this->grid_[x][y]->getTopPosition())
				//		{
				//			playerTest.setIsFalling(true);
				//		}


				//	}
				//}
				
				
			}
		}
	}
}

const float& Tilemap::getTileSizeXY() const
{
	return this->tile_Size_X_Y_;
}

const std::string& Tilemap::getTileTypeStr() const
{
	return this->tile_Type_Str_;
}
