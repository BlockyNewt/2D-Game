#include "Tilemap.h"

Tilemap::Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, const unsigned gridSizeZ, float tileSizeXY)
{
	this->grid_Max_Size_X_ = gridSizeX;
	this->grid_Max_Size_Y_ = gridSizeY;
	this->grid_Max_Size_Z_ = gridSizeZ;

	this->tile_Size_X_Y_ = tileSizeXY;

	this->is_Grid_Enabled_ = false;

	this->tile_Type_ = 0;
	this->tile_Layer_ = 0;
	this->tile_Type_Str_ = "";

	/*
		RESIZE GRID AND THE OUTLINE GRID 
	*/
	this->grid_.resize(grid_Max_Size_X_, std::vector<std::vector<Tile*>>());
	this->outline_.resize(grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(grid_Max_Size_Y_, std::vector<Tile*>());
			this->outline_[x].resize(grid_Max_Size_Y_, NULL);

			for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
			{
				this->grid_[x][y].resize(grid_Max_Size_Z_, NULL);
			}
		}
	}


	/*
		FILL THE OUTLINE GRID WITH BLANK TILES 
	*/
	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->outline_[x][y] = new Tile(static_cast<float>(x * this->tile_Size_X_Y_), static_cast<float>(y * this->tile_Size_X_Y_), static_cast<float>(this->tile_Size_X_Y_), 0);
		}
	}
}

Tilemap::~Tilemap()
{
	for (auto& x : this->grid_)
	{
		for (auto& y : x)
		{
			for (auto& z : y)
			{
				delete z;
			}
		}
	}
}

void Tilemap::updatePollEvent(sf::Event& ev)
{
	/*
		CHANGING THE TILE TYPE
	*/

	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Num1)
		{
			if (this->tile_Type_ > 0)
			{
				this->tile_Type_--;

			}
		}

		if (ev.key.code == sf::Keyboard::Num2)
		{
			if (this->tile_Type_ < 3)
			{
				this->tile_Type_++;

			}
		}
	}

	/*
		CHANGE TILE LAYER
	*/

	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Num4)
		{
			if (this->tile_Layer_ > 0)
			{
				this->tile_Layer_--;

			}
		}

		if (ev.key.code == sf::Keyboard::Num5)
		{
			if (this->tile_Layer_ < this->grid_Max_Size_Z_)
			{
				this->tile_Layer_++;
			}
		}
	}
}

void Tilemap::update(const Camera& camera)
{
	/*
		UPDATE TILE TYPE STRING FOR STATEEDITOR
	*/
	this->updateTileType();
	this->tile_Layer_Str_ = std::to_string(this->tile_Layer_);


	/*
		GET CAMERA / VIEW FROM STATEEDITOR FOR CULLING
		-RENDERING ONLY WHAT'S VISIBLE ON THE SCREEN
	*/
	this->camera_Left_Position = camera.getView().getCenter().x - camera.getView().getSize().x / 2.f;
	this->camera_Right_Position = camera.getView().getCenter().x + camera.getView().getSize().x / 2.f;
	this->camera_Top_Position = camera.getView().getCenter().y - camera.getView().getSize().y / 2.f;
	this->camera_Bottom_Position = camera.getView().getCenter().y + camera.getView().getSize().y / 2.f;
}

void Tilemap::updateTileType()
{
	/*
		GET A STRING BASED ON THE TILE TYPE SELECTED
	*/

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
	/*
		RENDER ONLY WHAT CAN BE SEEN ON THE SCREEN
	*/
	for (auto& x : this->grid_)
	{
		for (auto& y : x)
		{
			for (auto& z : y)
			{
				if (z != NULL)
				{
					if (z->getPosition().x > this->camera_Left_Position &&
						z->getPosition().x < this->camera_Right_Position &&
						z->getPosition().y > this->camera_Top_Position &&
						z->getPosition().y < this->camera_Bottom_Position)
					{
						z->render(target);
					}
				}
			}
		}
	}

	if (this->is_Grid_Enabled_)
	{
		for (auto& x : this->outline_)
		{
			for (auto& y : x)
			{
				if (y != NULL)
				{
					if (y->getPosition().x > this->camera_Left_Position &&
						y->getPosition().x < this->camera_Right_Position &&
						y->getPosition().y > this->camera_Top_Position &&
						y->getPosition().y < this->camera_Bottom_Position)
					{
						y->render(target);
					}
				}
			}
		}
	}
}

void Tilemap::addTile(float gridPosX, float gridPosY)
{
	/*
		ADD A TILE
	*/
	if (gridPosX >= 0 &&
		gridPosX < this->grid_Max_Size_X_&&
		gridPosY >= 0 &&
		gridPosY < this->grid_Max_Size_Y_ &&
		this->tile_Layer_ >= 0 &&
		this->tile_Layer_ < this->grid_Max_Size_Z_)
	{
		if (this->grid_[gridPosX][gridPosY][this->tile_Layer_] == NULL)
		{
			this->grid_[gridPosX][gridPosY][this->tile_Layer_] = new Tile(gridPosX * this->tile_Size_X_Y_, gridPosY * this->tile_Size_X_Y_, this->tile_Size_X_Y_, this->tile_Type_);
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
	/*
		REMOVE A TILE
	*/
	if (gridPosX >= 0 &&
		gridPosX < this->grid_Max_Size_X_ &&
		gridPosY >= 0 &&
		gridPosY < this->grid_Max_Size_Y_ &&
		this->tile_Layer_ >= 0 &&
		this->tile_Layer_ < this->grid_Max_Size_Z_)
	{
		if (this->grid_[gridPosX][gridPosY][this->tile_Layer_] != NULL)
		{
			delete this->grid_[gridPosX][gridPosY][this->tile_Layer_];

			this->grid_[gridPosX][gridPosY][this->tile_Layer_] = NULL;

			std::cout << "DEBUG::TILEMAP::REMOVETILE() -> TILE REMOVED." << std::endl;
		}
	}
}

void Tilemap::save(const std::string fileName)
{
	/*
		***DO NOT DELETE***
		
		FILE SAVE FORMAT:

			GRID MAX SIZE X
			GRID MAX SIZE Y
			GRID MAX SIZE Z

			TILE SIZE XY

			POSITION X, POSITION Y, TILESIZE XY, TYPE CONVERSION
	
	*/

	/*
		OPEN FILE 
	*/
	std::ofstream outToFile;
	outToFile.open("Tilemap/" + fileName);

	if (outToFile.is_open())
	{
		/*
			WRITE THINGS TO FILE
		*/
		outToFile << this->grid_Max_Size_X_ << "\n" << this->grid_Max_Size_Y_ << "\n" << this->tile_Size_X_Y_ << "\n";

		/*
			WRITE EACH TILE INSIDE OF GRID AND IT'S SETTINGS TO FILE 
		*/
		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
				{
					if (this->grid_[x][y][z])
					{
						outToFile << x << " " << y << " " << z << " " << this->grid_[x][y][z]->getTypeConversion() << " ";
					}
				}
			}
		}

		std::cout << "DEBUG::TILEMAP::SAVE() -> SAVE TO FILE SUCCESSFUL." << std::endl;
	}
	else
	{
		std::cout << "DEBUG::TILEMAP::SAVE() -> COULD NOT OPEN FILE FOR SAVE." << std::endl;
	}

	/*
		CLOSE FILE
	*/
	outToFile.close();
}

void Tilemap::load(const std::string fileName)
{
	/*
		CLEAR THE GRID INCASE IF ANYTHING IS ALREADY ON IT
	*/
	this->clearGrid();

	/*
		OPEN LOAD FILE
	*/
	std::ifstream inFromFile;
	inFromFile.open("Tilemap/" + fileName);

	if (inFromFile.is_open())
	{
		/*
			LOAD SOME THINGS FROM THE FILE 
		*/
		inFromFile >> this->grid_Max_Size_X_ >> this->grid_Max_Size_Y_ >> this->tile_Size_X_Y_;

		/*
			RESIZE GRID AND OUTLINE GRID
		*/
		this->grid_.resize(this->grid_Max_Size_X_, std::vector<std::vector<Tile*>>());
		this->outline_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
		for (int x = 0; x < this->grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
			{
				this->grid_[x].resize(this->grid_Max_Size_Y_, std::vector<Tile*>());
				this->outline_[x].resize(this->grid_Max_Size_Y_, NULL);

				for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
				{
					this->grid_[x][y].resize(this->grid_Max_Size_Z_, NULL);
				}
			}
		}

		/*
			FILL OUTLINE GRID WITH BLANK TILES
		*/
		for (int x = 0; x < grid_Max_Size_X_; ++x)
		{
			for (int y = 0; y < grid_Max_Size_Y_; ++y)
			{
				this->outline_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, 0);
			}
		}

		/*
			MAKE LOCAL VARIABELS FOR TAKING TILE DATA FROM FILE
		*/
		unsigned x = 0;
		unsigned y = 0;
		unsigned z = 0;

		int typeConversion = 0;

		while (inFromFile >> x >> y >> z >> typeConversion)
		{
			/*
				READ TILE DATA FROM FILE AND ADD IT TO THE GID
			*/
			this->grid_[x][y][z] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_,  this->tile_Size_X_Y_, typeConversion);
		}


		std::cout << "DEBUG::TILEMAP::SAVE() -> LOAD WAS SUCCESSFUL." << std::endl;
	}
	else
	{
		std::cout << "DEBUG::TILEMAP::SAVE() -> COULD NOT OPEN FILE FOR LOAD." << std::endl;
	}

	/*
		CLOSE FILE
	*/
	inFromFile.close();
}

void Tilemap::clearGrid(const bool& isGridEnabled)
{
	/*
		IF THIS IS ENABLED WE CAN DECIDE TO ENABLE OUTLINE GRID OR NOT
	*/
	this->is_Grid_Enabled_ = isGridEnabled;

	/*
		CLEAR BOTH GRIDS
	*/
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			delete this->outline_[x][y];
			this->outline_[x][y] = NULL;

			for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
			{
				delete this->grid_[x][y][z];
				this->grid_[x][y][z] = NULL;
			}
		}
	}

	/*
		RESIZE BOTH GRIDS
	*/
	this->grid_.resize(this->grid_Max_Size_X_, std::vector<std::vector<Tile*>>());
	this->outline_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(this->grid_Max_Size_Y_, std::vector<Tile*>());
			this->outline_[x].resize(grid_Max_Size_Y_, NULL);

			for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
			{
				this->grid_[x][y].resize(this->grid_Max_Size_Z_, NULL);
			}
		}
	}

	/*
		FILL OUTLINE GRID WITH BLANK TILES
	*/
	for (int x = 0; x < grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < grid_Max_Size_Y_; ++y)
		{
			this->outline_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, 0);
		}
	}

	/*
		ENABLE OR DISABLE GRID BASED ON VALUE
	*/
	this->enableGrid(this->is_Grid_Enabled_);

	std::cout << "DEBUG::TILEMAP::CLEARGRID() -> TILE GRID HAS BEEN CLEARED." << std::endl;
}

void Tilemap::enableGrid(const bool& isGridEnabled)
{
	/*
		IF VALUE IS TRUE THEN CHANGE OUTLINE COLOR OF TILES IN OUTLINE GRID
	*/
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
	/*
		IF VALUE IS FALSE THEN CHANGE OUTLINE COLOR OF TILES IN OUTLINE GRID
	*/
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
	/*
		IF VALUES ARE GREATER THAN ZERO THEN WE CAN RESIZE GRID
	*/
	if (gridSizeX > 0)
	{
		this->grid_Max_Size_X_ = gridSizeX;
	}

	if (gridSizeY > 0)
	{
		this->grid_Max_Size_Y_ = gridSizeY;
	}

	/*
		RESIZE BOTH GRIDS HERE
	*/
	this->grid_.resize(this->grid_Max_Size_X_, std::vector<std::vector<Tile*>>());
	this->outline_.resize(this->grid_Max_Size_X_, std::vector<Tile*>());
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			this->grid_[x].resize(this->grid_Max_Size_Y_, std::vector<Tile*>());
			this->outline_[x].resize(grid_Max_Size_Y_, NULL);
			
			for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
			{
				this->grid_[x][y].resize(this->grid_Max_Size_Z_, NULL);
			}
		}
	}

	/*
		FILE OUTLINE GRID WITH BLANK TILES
	*/
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
	/*
		CHANGE THE SIZE OF TILES
	*/
	this->tile_Size_X_Y_ = tileSizeXY;
}

void Tilemap::playerCollision(PlayerTest& playerTest)
{
	for (int x = 0; x < this->grid_Max_Size_X_; ++x)
	{
		for (int y = 0; y < this->grid_Max_Size_Y_; ++y)
		{
			for (int z = 0; z < this->grid_Max_Size_Z_; ++z)
			{
				/*
					IF A GRID POSITION DOES NOT EQUAL NULL
				*/
				if (this->grid_[x][y][z] != NULL)
				{
					/*
						GET GLOBAL BOUNDS OF PLAYER AND PLAYERS NEXT POSITION
					*/
					sf::FloatRect playerBounds = playerTest.getPlayerGlobalBounds();
					sf::FloatRect NextPosition = playerTest.getNextPositionGlobalBounds();

					NextPosition = playerBounds;
					NextPosition.left += playerTest.getVelocity().x;
					NextPosition.top += playerTest.getVelocity().y;

					/*
						IF THE TILE IS BOUNDARY THEN UPDATE ITS COLLISION
					*/
					if (this->grid_[x][y][z]->getType() == TYPE::BOUNDARY)
					{
						if (this->grid_[x][y][z]->getGlobalBounds().intersects(NextPosition))
						{
							//RIGHT COLLISION
							if (playerBounds.left < this->grid_[x][y][z]->getLeftPosition() &&
								playerBounds.left + playerBounds.width < this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.top < this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.top + playerBounds.height > this->grid_[x][y][z]->getTopPosition())
							{
								//std::cout << "Right ";
								playerTest.setVelocityX(0.f);
								playerTest.getPlayerModel().setPosition(sf::Vector2f(this->grid_[x][y][z]->getLeftPosition() - playerTest.getPlayerGlobalBounds().width, playerTest.getPlayerGlobalBounds().top));
							}

							//LEFT COLLISION
							else if (playerBounds.left > this->grid_[x][y][z]->getLeftPosition() &&
								playerBounds.left + playerBounds.width > this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.top < this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.top + playerBounds.height > this->grid_[x][y][z]->getTopPosition())
							{
								//std::cout << "Left ";

								playerTest.setVelocityX(0.f);
								playerTest.getPlayerModel().setPosition(sf::Vector2f(this->grid_[x][y][z]->getRightPosition(), playerTest.getPlayerGlobalBounds().top));
							}

							//TOP COLLISION
							if (playerBounds.top > this->grid_[x][y][z]->getTopPosition() &&
								playerBounds.top + playerBounds.height > this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.left < this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.left + playerBounds.width > this->grid_[x][y][z]->getLeftPosition())
							{
								std::cout << "Top " << std::endl;

								playerTest.setIsJumping(false);
								playerTest.setIsFalling(true);

								playerTest.setVelocityY(0.f);
								playerTest.getPlayerModel().setPosition(sf::Vector2f(playerTest.getPlayerGlobalBounds().left, this->grid_[x][y][z]->getBottomPosition()));
							}

							//BOTTOM COLLISION	
							else if (playerBounds.top < this->grid_[x][y][z]->getTopPosition() &&
								playerBounds.top + playerBounds.height < this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.left < this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.left + playerBounds.width > this->grid_[x][y][z]->getLeftPosition())
							{
								//std::cout << "Bottom " << std::endl;

								playerTest.setIsFalling(false);
								playerTest.setVelocityY(0.f);
								playerTest.getPlayerModel().setPosition(sf::Vector2f(playerTest.getPlayerGlobalBounds().left, this->grid_[x][y][z]->getTopPosition() - playerTest.getPlayerGlobalBounds().height));
							}
						}
					}



					/*
						IF THE TILE TYPE IS FALL AND THE PLAYER IS NOT JUMPING THEN UPDATE COLLISION
						AND MAKE THE PLAYER FALL

						THIS IS STILL IFFY WITH FALLING
					*/
					if (this->grid_[x][y][z]->getType() == TYPE::FALL && !playerTest.getIsJumping())
					{
						if (this->grid_[x][y][z]->getGlobalBounds().intersects(NextPosition))
						{
							//RIGHT COLLISION
							if (playerBounds.left < this->grid_[x][y][z]->getLeftPosition() &&
								playerBounds.left + playerBounds.width < this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.top < this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.top + playerBounds.height > this->grid_[x][y][z]->getTopPosition())
							{
								playerTest.setIsFalling(true);
							}

							//LEFT COLLISION
							else if (playerBounds.left > this->grid_[x][y][z]->getLeftPosition() &&
								playerBounds.left + playerBounds.width > this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.top < this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.top + playerBounds.height > this->grid_[x][y][z]->getTopPosition())
							{
								playerTest.setIsFalling(true);
							}

							//BOTTOM COLLISION	
							if (playerBounds.top < this->grid_[x][y][z]->getTopPosition() &&
								playerBounds.top + playerBounds.height < this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.left < this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.left + playerBounds.width > this->grid_[x][y][z]->getLeftPosition())
							{
								playerTest.setIsFalling(true);
							}

							//TOP COLLISION
							else if (playerBounds.top > this->grid_[x][y][z]->getTopPosition() &&
								playerBounds.top + playerBounds.height > this->grid_[x][y][z]->getBottomPosition() &&
								playerBounds.left < this->grid_[x][y][z]->getRightPosition() &&
								playerBounds.left + playerBounds.width > this->grid_[x][y][z]->getLeftPosition())
							{
								playerTest.setIsFalling(true);
							}
						}
					}



				}
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

const std::string& Tilemap::getTileLayerStr() const
{
	return this->tile_Layer_Str_;
}
