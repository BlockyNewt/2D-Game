#include "Tilemap.h"

Tilemap::Tilemap(const unsigned gridSizeX, const unsigned gridSizeY, float tileSizeXY)
{
	this->grid_Max_Size_X_ = gridSizeX;
	this->grid_Max_Size_Y_ = gridSizeY;

	this->tile_Size_X_Y_ = tileSizeXY;

	this->is_Grid_Enabled_ = false;

	this->tile_Type_ = 0;
	this->tile_Type_Str_ = "";

	/*
		RESIZE GRID AND THE OUTLINE GRID 
	*/
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
			delete y;
		}
	}
}

void Tilemap::updatePollEvent(sf::Event& ev)
{
	/*
		FOR NOW THIS IS ONLY FOR CHANGING THE TILE TYPE
	*/

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
	/*
		UPDATE TILE TYPE STRING FOR STATEEDITOR
	*/
	this->updateTileType();


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
	/*
		ADD A TILE
	*/
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
	/*
		REMOVE A TILE
	*/
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
		***DO NOT DELETE***
		
		FILE SAVE FORMAT:

			GRID MAX SIZE X
			GRID MAX SIZE Y

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

		int typeConversion = 0;

		while (inFromFile >> x >> y >> typeConversion)
		{
			/*
				READ TILE DATA FROM FILE AND ADD IT TO THE GID
			*/
			this->grid_[x][y] = new Tile(x * this->tile_Size_X_Y_, y * this->tile_Size_X_Y_, this->tile_Size_X_Y_, typeConversion);
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
			delete this->grid_[x][y];
			delete this->outline_[x][y];

			this->grid_[x][y] = NULL;
			this->outline_[x][y] = NULL;
		}
	}

	/*
		RESIZE BOTH GRIDS
	*/
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
			/*
				IF A GRID POSITION DOES NOT EQUAL NULL
			*/
			if (this->grid_[x][y] != NULL)
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
				if (this->grid_[x][y]->getType() == TYPE::BOUNDARY)
				{
					if (this->grid_[x][y]->getGlobalBounds().intersects(NextPosition))
					{
						//RIGHT COLLISION
						if (playerBounds.left < this->grid_[x][y]->getLeftPosition() &&
							playerBounds.left + playerBounds.width < this->grid_[x][y]->getRightPosition() &&
							playerBounds.top < this->grid_[x][y]->getBottomPosition() &&
							playerBounds.top + playerBounds.height > this->grid_[x][y]->getTopPosition())
						{
							//std::cout << "Right ";
							playerTest.setVelocityX(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(this->grid_[x][y]->getLeftPosition() - playerTest.getPlayerGlobalBounds().width, playerTest.getPlayerGlobalBounds().top));
						}

						//LEFT COLLISION
						else if (playerBounds.left > this->grid_[x][y]->getLeftPosition() &&
							playerBounds.left + playerBounds.width > this->grid_[x][y]->getRightPosition() &&
							playerBounds.top < this->grid_[x][y]->getBottomPosition() &&
							playerBounds.top + playerBounds.height > this->grid_[x][y]->getTopPosition())
						{
							//std::cout << "Left ";

							playerTest.setVelocityX(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(this->grid_[x][y]->getRightPosition(), playerTest.getPlayerGlobalBounds().top));
						}

						//BOTTOM COLLISION	
						if (playerBounds.top < this->grid_[x][y]->getTopPosition() &&
							playerBounds.top + playerBounds.height < this->grid_[x][y]->getBottomPosition() &&
							playerBounds.left < this->grid_[x][y]->getRightPosition() &&
							playerBounds.left + playerBounds.width > this->grid_[x][y]->getLeftPosition())
						{
							//std::cout << "Bottom ";

							playerTest.setIsFalling(false);
							playerTest.setVelocityY(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(playerTest.getPlayerGlobalBounds().left, this->grid_[x][y]->getTopPosition() - playerTest.getPlayerGlobalBounds().height));
						}

						//TOP COLLISION
						else if (playerBounds.top > this->grid_[x][y]->getTopPosition() &&
							playerBounds.top + playerBounds.height > this->grid_[x][y]->getBottomPosition() &&
							playerBounds.left < this->grid_[x][y]->getRightPosition() &&
							playerBounds.left + playerBounds.width > this->grid_[x][y]->getLeftPosition())
						{
							//std::cout << "Top ";
							playerTest.setIsFalling(true);
							playerTest.setVelocityY(0.f);
							playerTest.getPlayerModel().setPosition(sf::Vector2f(playerTest.getPlayerGlobalBounds().left, this->grid_[x][y]->getBottomPosition()));
						}
					}
				}
				


				
				/*
					IF THE TILE TYPE IS FALL AND THE PLAYER IS NOT JUMPING THEN UPDATE COLLISION 
					AND MAKE THE PLAYER FALL
				*/
				if (this->grid_[x][y]->getType() == TYPE::FALL && !playerTest.getIsJumping())
				{
					if (this->grid_[x][y]->getGlobalBounds().intersects(NextPosition))
					{
						//RIGHT COLLISION
						if (playerBounds.left < this->grid_[x][y]->getLeftPosition() &&
							playerBounds.left + playerBounds.width < this->grid_[x][y]->getRightPosition() &&
							playerBounds.top < this->grid_[x][y]->getBottomPosition() &&
							playerBounds.top + playerBounds.height > this->grid_[x][y]->getTopPosition())
						{
							playerTest.setIsFalling(true);
						}

						//LEFT COLLISION
						else if (playerBounds.left > this->grid_[x][y]->getLeftPosition() &&
							playerBounds.left + playerBounds.width > this->grid_[x][y]->getRightPosition() &&
							playerBounds.top < this->grid_[x][y]->getBottomPosition() &&
							playerBounds.top + playerBounds.height > this->grid_[x][y]->getTopPosition())
						{
							playerTest.setIsFalling(true);
						}

						//BOTTOM COLLISION	
						if (playerBounds.top < this->grid_[x][y]->getTopPosition() &&
							playerBounds.top + playerBounds.height < this->grid_[x][y]->getBottomPosition() &&
							playerBounds.left < this->grid_[x][y]->getRightPosition() &&
							playerBounds.left + playerBounds.width > this->grid_[x][y]->getLeftPosition())
						{
							playerTest.setIsFalling(true);
						}

						//TOP COLLISION
						else if (playerBounds.top > this->grid_[x][y]->getTopPosition() &&
							playerBounds.top + playerBounds.height > this->grid_[x][y]->getBottomPosition() &&
							playerBounds.left < this->grid_[x][y]->getRightPosition() &&
							playerBounds.left + playerBounds.width > this->grid_[x][y]->getLeftPosition())
						{
							playerTest.setIsFalling(true);
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
