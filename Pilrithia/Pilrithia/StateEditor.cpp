#include "StateEditor.h"

void StateEditor::initializeInstructionsPanel()
{
	this->instruction_Panel_X_A_.setSettings(400.f, 700.f, 10.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	std::string instructionsStr = "1.) Press 'Tab' to hide this window. \n\n2.) Press 'Esc' to open pause window \n\n3.) Left click to add tile \n\n4.) Right click to remove tile \n\n5.) WSAD to move camera \n\n6.) Mouse wheel to scroll in and out \n\n7.) nothing for now";

	this->t_A_.setSettings("Font/arial.ttf", 25, "Editor Instructions", sf::Vector2f(this->instruction_Panel_X_A_.getLeftPosition(true, 100.f), this->instruction_Panel_X_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.setSettings("Font/arial.ttf", 18, instructionsStr, sf::Vector2f(this->instruction_Panel_X_A_.getLeftPosition(true, 10.f), this->t_A_.getBottomPosition(true, 50.f)), true);
}

void StateEditor::initializeRightSidePanel()
{
	this->right_Side_Panel_X_A_.setSettings(50.f, 700.f, this->window_->getSize().x - 60.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	this->right_Side_Panel_B_A_.setSettings(40.f, 40.f, this->right_Side_Panel_X_A_.getLeftPosition(true, 5), this->right_Side_Panel_X_A_.getTopPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->right_Side_Panel_B_B_.setSettings(40.f, 40.f, this->right_Side_Panel_X_A_.getLeftPosition(true, 5), this->right_Side_Panel_B_A_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->right_Side_Panel_B_C_.setSettings(40.f, 40.f, this->right_Side_Panel_X_A_.getLeftPosition(true, 5), this->right_Side_Panel_B_B_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->right_Side_Panel_B_D_.setSettings(40.f, 40.f, this->right_Side_Panel_X_A_.getLeftPosition(true, 5), this->right_Side_Panel_B_C_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);

	this->right_Side_Panel_T_A_.setSettings("Font/arial.ttf", 12, "Clear", sf::Vector2f(this->right_Side_Panel_B_A_.getLeftPosition(true, 5.f), this->right_Side_Panel_B_A_.getTopPosition(true, 10.f)), true);
	this->right_Side_Panel_T_B_.setSettings("Font/arial.ttf", 12, "Setting", sf::Vector2f(this->right_Side_Panel_B_B_.getLeftPosition(true, 2.f), this->right_Side_Panel_B_B_.getTopPosition(true, 10.f)), true);
	this->right_Side_Panel_T_C_.setSettings("Font/arial.ttf", 12, "Save", sf::Vector2f(this->right_Side_Panel_B_C_.getLeftPosition(true, 2.f), this->right_Side_Panel_B_C_.getTopPosition(true, 10.f)), true);
	this->right_Side_Panel_T_D_.setSettings("Font/arial.ttf", 12, "Load", sf::Vector2f(this->right_Side_Panel_B_D_.getLeftPosition(true, 2.f), this->right_Side_Panel_B_D_.getTopPosition(true, 10.f)), true);

	this->right_Side_Panel_Buttons_.push_back(right_Side_Panel_B_A_);
	this->right_Side_Panel_Buttons_.push_back(right_Side_Panel_B_B_);
	this->right_Side_Panel_Buttons_.push_back(right_Side_Panel_B_C_);
	this->right_Side_Panel_Buttons_.push_back(right_Side_Panel_B_D_);

	this->right_Side_Panel_Texts_.push_back(right_Side_Panel_T_A_);
	this->right_Side_Panel_Texts_.push_back(right_Side_Panel_T_B_);
	this->right_Side_Panel_Texts_.push_back(right_Side_Panel_T_C_);
	this->right_Side_Panel_Texts_.push_back(right_Side_Panel_T_D_);
}

void StateEditor::initializeTilemapSettings()
{
	this->tilemap_Settings_X_A_.setSettings(800.f, 600.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, false);
	this->tilemap_Settings_T_D_.setSettings("Font/arial.ttf", 35, "Tilemap Settings", sf::Vector2f(this->tilemap_Settings_X_A_.getLeftPosition(true, 300.f), this->tilemap_Settings_X_A_.getTopPosition(true, 20.f)), false);

	this->tilemap_Settings_B_A_.setSettings(150.f, 50.f, this->tilemap_Settings_X_A_.getLeftPosition(true, 250), this->tilemap_Settings_X_A_.getBottomPosition(false, 55), sf::Color::Blue, 1, sf::Color::Red, false);
	this->tilemap_Settings_B_B_.setSettings(150.f, 50.f, this->tilemap_Settings_B_A_.getRightPosition(true, 20), this->tilemap_Settings_B_A_.getTopPosition(), sf::Color::Blue, 1, sf::Color::Red, false);

	this->tilemap_Settings_T_A_.setSettings("Font/arial.ttf", 25, "Max Grid Size X", sf::Vector2f(this->tilemap_Settings_X_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_X_A_.getTopPosition(true, 100.f)), false);
	this->tilemap_Settings_T_B_.setSettings("Font/arial.ttf", 25, "Max Grid Size Y", sf::Vector2f(this->tilemap_Settings_X_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_T_A_.getTopPosition(true, 50.f)), false);
	this->tilemap_Settings_T_C_.setSettings("Font/arial.ttf", 25, "Tile Size X & Y", sf::Vector2f(this->tilemap_Settings_X_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_T_B_.getTopPosition(true, 50.f)), false);
	this->tilemap_Settings_T_E_.setSettings("Font/arial.ttf", 25, "Accept", sf::Vector2f(this->tilemap_Settings_B_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_B_A_.getTopPosition(true, 10.f)), false);
	this->tilemap_Settings_T_F_.setSettings("Font/arial.ttf", 25, "Close", sf::Vector2f(this->tilemap_Settings_B_B_.getLeftPosition(true, 10.f), this->tilemap_Settings_B_B_.getTopPosition(true, 10.f)), false);
	this->tilemap_Settings_T_G_.setSettings("Font/arial.ttf", 25, "Enable grid", sf::Vector2f(this->tilemap_Settings_X_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_T_C_.getTopPosition(true, 50.f)), false);

	this->tilemap_Settings_I_A_.setSettings(75.f, 40.f, this->tilemap_Settings_T_A_.getRightPosition(true, 10.f), this->tilemap_Settings_T_A_.getTopPosition(false, 10), sf::Color::Black, 1.f, sf::Color::Red, false, false, 4);
	this->tilemap_Settings_I_B_.setSettings(75.f, 40.f, this->tilemap_Settings_T_B_.getRightPosition(true, 10.f), this->tilemap_Settings_T_B_.getTopPosition(false, 10), sf::Color::Black, 1.f, sf::Color::Red, false, false, 4);
	this->tilemap_Settings_I_C_.setSettings(75.f, 40.f, this->tilemap_Settings_I_B_.getLeftPosition(), this->tilemap_Settings_T_C_.getTopPosition(false, 10), sf::Color::Black, 1.f, sf::Color::Red, false, false, 4);

	this->tilemap_Settings_C_A_.setSettings(40.f, 40.f, this->tilemap_Settings_I_C_.getLeftPosition(), this->tilemap_Settings_T_G_.getTopPosition(false, 10), sf::Color::Black, 1, sf::Color::Red, false, false);
}

void StateEditor::initializeSave()
{
	this->save_X_A_.setSettings(800.f, 400.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, false);

	this->save_B_A_.setSettings(150.f, 50.f, this->save_X_A_.getLeftPosition(true, 250), this->save_X_A_.getBottomPosition(false, 55), sf::Color::Blue, 1, sf::Color::Red, false);
	this->save_B_B_.setSettings(150.f, 50.f, this->save_B_A_.getRightPosition(true, 20), this->save_B_A_.getTopPosition(), sf::Color::Blue, 1, sf::Color::Red, false);

	this->save_T_A_.setSettings("Font/arial.ttf", 35, "Save current tilemap", sf::Vector2f(this->save_X_A_.getLeftPosition(true, 250.f), this->save_X_A_.getTopPosition(true, 10.f)), false);
	this->save_T_B_.setSettings("Font/arial.ttf", 25, "Filename: ", sf::Vector2f(this->save_X_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_X_A_.getTopPosition(true, 200.f)), false);
	this->save_T_C_.setSettings("Font/arial.ttf", 25, "Save", sf::Vector2f(this->save_B_A_.getLeftPosition(true, 10.f), this->save_B_A_.getTopPosition(true, 10.f)), false);
	this->save_T_D_.setSettings("Font/arial.ttf", 25, "Close", sf::Vector2f(this->save_B_B_.getLeftPosition(true, 10.f), this->save_B_B_.getTopPosition(true, 10.f)), false);

	this->save_I_A_.setSettings(500.f, 40.f, this->save_T_B_.getRightPosition(true, 10.f), this->save_T_B_.getTopPosition(), sf::Color::Black, 1.f, sf::Color::Red, false, false, 30);
}

void StateEditor::initializeLoad()
{
	this->load_X_A_.setSettings(800.f, 400.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, false);

	this->load_B_A_.setSettings(150.f, 50.f, this->load_X_A_.getLeftPosition(true, 250), this->load_X_A_.getBottomPosition(false, 55), sf::Color::Blue, 1, sf::Color::Red, false);
	this->load_B_B_.setSettings(150.f, 50.f, this->load_B_A_.getRightPosition(true, 20), this->load_B_A_.getTopPosition(), sf::Color::Blue, 1, sf::Color::Red, false);

	this->load_T_A_.setSettings("Font/arial.ttf", 35, "Load a tilemap", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 250.f), this->load_X_A_.getTopPosition(true, 10.f)), false);
	this->load_T_B_.setSettings("Font/arial.ttf", 25, "Filename: ", sf::Vector2f(this->load_X_A_.getLeftPosition(true, 10.f), this->tilemap_Settings_X_A_.getTopPosition(true, 200.f)), false);
	this->load_T_C_.setSettings("Font/arial.ttf", 25, "Load", sf::Vector2f(this->load_B_A_.getLeftPosition(true, 10.f), this->load_B_A_.getTopPosition(true, 10.f)), false);
	this->load_T_D_.setSettings("Font/arial.ttf", 25, "Close", sf::Vector2f(this->load_B_B_.getLeftPosition(true, 10.f), this->load_B_B_.getTopPosition(true, 10.f)), false);

	this->load_I_A_.setSettings(500.f, 40.f, this->load_T_B_.getRightPosition(true, 10.f), this->load_T_B_.getTopPosition(), sf::Color::Black, 1.f, sf::Color::Red, false, false, 30);
}

StateEditor::StateEditor(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEEDITOR::STATEEDITOR() -> HAS STARTED." << std::endl;

	this->camera_ = new Camera(this->window_->getSize().x, this->window_->getSize().y);
	this->tilemap_ = new Tilemap(5, 5, 30);
	this->window_Position_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->grid_Position_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->tile_Type_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->tile_Box_.setSettings(30.f, 30.f, 0.f, 0.f, sf::Color::Transparent, 1.f, sf::Color::Red, true);

	this->initializeInstructionsPanel();
	this->initializeRightSidePanel();
	this->initializeTilemapSettings();
	this->initializeSave();
	this->initializeLoad();
}

StateEditor::~StateEditor()
{
}

void StateEditor::instructionsPollEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Tab)
		{
			//SHOW LEFT PANE INSTRUCTION BOX
			if (this->instruction_Panel_X_A_.getIsVisible())
			{
				this->instruction_Panel_X_A_.setIsVisible(false);

				this->t_A_.setIsVisible(false);
				this->t_B_.setIsVisible(false);
			}
			else
			{
				this->instruction_Panel_X_A_.setIsVisible(true);

				this->t_A_.setIsVisible(true);
				this->t_B_.setIsVisible(true);
			}
		}
	}
}

void StateEditor::rightPanelPollEvent(sf::Event& ev)
{
	//RIGHT SIDE PANEL BUTTONS
	if (this->right_Side_Panel_Buttons_[0].updatePollEvent(ev))
	{
		this->tilemap_->clearGrid(this->tilemap_Settings_C_A_.getIsEnabled());
	}

	if (this->right_Side_Panel_Buttons_[1].updatePollEvent(ev))
	{
		if (!this->tilemap_Settings_X_A_.getIsVisible())
		{
			this->tilemap_Settings_X_A_.setIsVisible(true);

			this->tilemap_Settings_B_A_.setIsVisible(true);
			this->tilemap_Settings_B_B_.setIsVisible(true);

			this->tilemap_Settings_T_D_.setIsVisible(true);
			this->tilemap_Settings_T_A_.setIsVisible(true);
			this->tilemap_Settings_T_B_.setIsVisible(true);
			this->tilemap_Settings_T_C_.setIsVisible(true);
			this->tilemap_Settings_T_D_.setIsVisible(true);
			this->tilemap_Settings_T_E_.setIsVisible(true);
			this->tilemap_Settings_T_F_.setIsVisible(true);
			this->tilemap_Settings_T_G_.setIsVisible(true);

			this->tilemap_Settings_I_A_.setIsVisible(true);
			this->tilemap_Settings_I_B_.setIsVisible(true);
			this->tilemap_Settings_I_C_.setIsVisible(true);

			this->tilemap_Settings_C_A_.setIsVisible(true);
		}
		else
		{
			this->tilemap_Settings_X_A_.setIsVisible(false);

			this->tilemap_Settings_B_A_.setIsVisible(false);
			this->tilemap_Settings_B_B_.setIsVisible(false);

			this->tilemap_Settings_T_D_.setIsVisible(false);
			this->tilemap_Settings_T_A_.setIsVisible(false);
			this->tilemap_Settings_T_B_.setIsVisible(false);
			this->tilemap_Settings_T_C_.setIsVisible(false);
			this->tilemap_Settings_T_D_.setIsVisible(false);
			this->tilemap_Settings_T_E_.setIsVisible(false);
			this->tilemap_Settings_T_F_.setIsVisible(false);
			this->tilemap_Settings_T_G_.setIsVisible(false);

			this->tilemap_Settings_I_A_.setIsVisible(false);
			this->tilemap_Settings_I_B_.setIsVisible(false);
			this->tilemap_Settings_I_C_.setIsVisible(false);

			this->tilemap_Settings_C_A_.setIsVisible(false);
		}
	}

	if (this->right_Side_Panel_Buttons_[2].updatePollEvent(ev))
	{
		if (!this->save_X_A_.getIsVisible())
		{
			this->save_X_A_.setIsVisible(true);
			this->save_B_A_.setIsVisible(true);
			this->save_B_B_.setIsVisible(true);
			this->save_T_A_.setIsVisible(true);
			this->save_T_B_.setIsVisible(true);
			this->save_T_C_.setIsVisible(true);
			this->save_T_D_.setIsVisible(true);
			this->save_I_A_.setIsVisible(true);
		}
		else
		{
			this->save_X_A_.setIsVisible(false);
			this->save_B_A_.setIsVisible(false);
			this->save_B_B_.setIsVisible(false);
			this->save_T_A_.setIsVisible(false);
			this->save_T_B_.setIsVisible(false);
			this->save_T_C_.setIsVisible(false);
			this->save_T_D_.setIsVisible(false);
			this->save_I_A_.setIsVisible(false);
		}
		
	}

	if (this->right_Side_Panel_Buttons_[3].updatePollEvent(ev))
	{
		if (!this->load_X_A_.getIsVisible())
		{
			this->load_X_A_.setIsVisible(true);
			this->load_B_A_.setIsVisible(true);
			this->load_B_B_.setIsVisible(true);
			this->load_T_A_.setIsVisible(true);
			this->load_T_B_.setIsVisible(true);
			this->load_T_C_.setIsVisible(true);
			this->load_T_D_.setIsVisible(true);
			this->load_I_A_.setIsVisible(true);
		}
		else
		{
			this->load_X_A_.setIsVisible(false);
			this->load_B_A_.setIsVisible(false);
			this->load_B_B_.setIsVisible(false);
			this->load_T_A_.setIsVisible(false);
			this->load_T_B_.setIsVisible(false);
			this->load_T_C_.setIsVisible(false);
			this->load_T_D_.setIsVisible(false);
			this->load_I_A_.setIsVisible(false);
		}
	}
}

void StateEditor::tilemapSettingsPollEvent(sf::Event& ev)
{
	if (this->tilemap_Settings_X_A_.getIsVisible())
	{
		this->tilemap_Settings_I_A_.updatePollEvent(ev);
		this->tilemap_Settings_I_B_.updatePollEvent(ev);
		this->tilemap_Settings_I_C_.updatePollEvent(ev);

		if (this->tilemap_Settings_B_A_.updatePollEvent(ev))
		{
			if (this->tilemap_Settings_I_A_.getString().length() > 0 || this->tilemap_Settings_I_B_.getString().length() > 0)
			{
				int newGridSizeX = std::atoi(this->tilemap_Settings_I_A_.getString().c_str());
				int newGridSizeY = std::atoi(this->tilemap_Settings_I_B_.getString().c_str());

				this->tilemap_->resizeTilemap(newGridSizeX, newGridSizeY);

				this->tilemap_Settings_I_A_.clearString();
				this->tilemap_Settings_I_B_.clearString();
			}

			if (this->tilemap_Settings_I_C_.getString().length() > 0)
			{
				int newTileSizeXY = std::atoi(this->tilemap_Settings_I_C_.getString().c_str());

				//CHANGE SIZE OF TILE_BOX HERE
				this->tile_Box_.setSize(static_cast<float>(newTileSizeXY), static_cast<float>(newTileSizeXY));

				this->tilemap_->resizeTileSize(static_cast<float>(newTileSizeXY));

				this->tilemap_Settings_I_C_.clearString();
			}

			if (this->tilemap_Settings_C_A_.getIsEnabled())
			{
				this->tilemap_->enableGrid(this->tilemap_Settings_C_A_.getIsEnabled());
			}
			else
			{
				this->tilemap_->disableGrid(this->tilemap_Settings_C_A_.getIsEnabled());
			}
		}

		if (this->tilemap_Settings_C_A_.updatePollEvent(ev))
		{
			std::cout << "Hey" << std::endl;
			if (!this->tilemap_Settings_C_A_.getIsEnabled())
			{
				std::cout << "True" << std::endl;
				this->tilemap_Settings_C_A_.setIsEnabled(true);
			}
			else
			{
				std::cout << "False" << std::endl;
				this->tilemap_Settings_C_A_.setIsEnabled(false);
			}
		}


		if (this->tilemap_Settings_B_B_.updatePollEvent(ev))
		{
			this->tilemap_Settings_X_A_.setIsVisible(false);

			this->tilemap_Settings_B_A_.setIsVisible(false);
			this->tilemap_Settings_B_B_.setIsVisible(false);

			this->tilemap_Settings_T_D_.setIsVisible(false);
			this->tilemap_Settings_T_A_.setIsVisible(false);
			this->tilemap_Settings_T_B_.setIsVisible(false);
			this->tilemap_Settings_T_C_.setIsVisible(false);
			this->tilemap_Settings_T_D_.setIsVisible(false);
			this->tilemap_Settings_T_E_.setIsVisible(false);
			this->tilemap_Settings_T_F_.setIsVisible(false);
			this->tilemap_Settings_T_G_.setIsVisible(false);

			this->tilemap_Settings_I_A_.setIsVisible(false);
			this->tilemap_Settings_I_B_.setIsVisible(false);
			this->tilemap_Settings_I_C_.setIsVisible(false);

			this->tilemap_Settings_C_A_.setIsVisible(false);

			this->tilemap_Settings_I_A_.clearString();
			this->tilemap_Settings_I_B_.clearString();
		}
	}
}

void StateEditor::savePollEvent(sf::Event& ev)
{
	if (this->save_X_A_.getIsVisible())
	{
		this->save_I_A_.updatePollEvent(ev);

		if (this->save_B_A_.updatePollEvent(ev))
		{
			if (this->save_I_A_.getString().length() > 0)
			{
				this->tilemap_->save(this->save_I_A_.getString());

				this->save_I_A_.clearString();
			}
		}

		if (this->save_B_B_.updatePollEvent(ev))
		{
			this->save_X_A_.setIsVisible(false);
			this->save_B_A_.setIsVisible(false);
			this->save_B_B_.setIsVisible(false);
			this->save_T_A_.setIsVisible(false);
			this->save_T_B_.setIsVisible(false);
			this->save_T_C_.setIsVisible(false);
			this->save_T_D_.setIsVisible(false);
			this->save_I_A_.setIsVisible(false);
		}
	}
}

void StateEditor::loadPollEvent(sf::Event& ev)
{
	if (this->load_X_A_.getIsVisible())
	{
		this->load_I_A_.updatePollEvent(ev);

		if (this->load_B_A_.updatePollEvent(ev))
		{
			if (this->load_I_A_.getString().length() > 0)
			{
				this->tilemap_->load(this->load_I_A_.getString());

				this->load_I_A_.clearString();
			}
		}

		if (this->load_B_B_.updatePollEvent(ev))
		{
			this->load_X_A_.setIsVisible(false);
			this->load_B_A_.setIsVisible(false);
			this->load_B_B_.setIsVisible(false);
			this->load_T_A_.setIsVisible(false);
			this->load_T_B_.setIsVisible(false);
			this->load_T_C_.setIsVisible(false);
			this->load_T_D_.setIsVisible(false);
			this->load_I_A_.setIsVisible(false);
		}
	}
}

void StateEditor::updatePollEvent(sf::Event& ev)
{
	if (this->menu_Pause_->updatePollEvent(ev))
	{
		this->states_->pop();
	}

	if (!this->menu_Pause_->getIsPaused())
	{
		this->window_->setKeyRepeatEnabled(true);

		this->camera_->updatePollEvent(ev);

		this->instructionsPollEvent(ev);
		this->rightPanelPollEvent(ev);
		this->tilemapSettingsPollEvent(ev);
		this->savePollEvent(ev);
		this->loadPollEvent(ev);

		if (!this->tilemap_Settings_X_A_.getIsVisible() && !this->save_X_A_.getIsVisible() && !this->load_X_A_.getIsVisible())
		{
			this->tilemap_->updatePollEvent(ev);

			if (ev.type == sf::Event::MouseButtonPressed)
			{
				if (ev.key.code == sf::Mouse::Left)
				{
					this->tilemap_->addTile(this->mouse_Position_Grid_.x, this->mouse_Position_Grid_.y);
				}

				if (ev.key.code == sf::Mouse::Right)
				{
					this->tilemap_->removeTile(this->mouse_Position_Grid_.x, this->mouse_Position_Grid_.y);
				}
			}
		}
	}
}

void StateEditor::update()
{
	this->updateMousePosition(&this->camera_->getView(), this->tilemap_->getTileSizeXY());

	this->menu_Pause_->update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		this->tilemap_->update(*this->camera_);

		this->tile_Box_.setPosition(static_cast<float>(this->mouse_Position_Grid_.x * this->tilemap_->getTileSizeXY()), static_cast<float>(this->mouse_Position_Grid_.y * this->tilemap_->getTileSizeXY()));


		this->window_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Window_.x) + " Y:" + std::to_string(this->mouse_Position_Window_.y));
		this->window_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y - 15.f));

		this->grid_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Grid_.x * static_cast<int>(this->tilemap_->getTileSizeXY())) + " Y:" + std::to_string(this->mouse_Position_Grid_.y * static_cast<int>(this->tilemap_->getTileSizeXY())));
		this->grid_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y + 15.f));

		this->tile_Type_.setText().setString("Tile Type: " + this->tilemap_->getTileTypeStr());
		this->tile_Type_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y + 40.f));


		for (auto& b : this->right_Side_Panel_Buttons_)
		{
			b.updateBoundaries(this->mouse_Position_Window_);
		}

		//SETTINGS BUTTONS	
		if (this->tilemap_Settings_X_A_.getIsVisible())
		{
			this->tilemap_Settings_B_A_.updateBoundaries(this->mouse_Position_Window_);
			this->tilemap_Settings_B_B_.updateBoundaries(this->mouse_Position_Window_);

			this->tilemap_Settings_I_A_.update(this->mouse_Position_Window_);
			this->tilemap_Settings_I_B_.update(this->mouse_Position_Window_);
			this->tilemap_Settings_I_C_.update(this->mouse_Position_Window_);

			this->tilemap_Settings_C_A_.updateBoundaries(this->mouse_Position_Window_);
		}

		if (this->save_X_A_.getIsVisible())
		{
			this->save_B_A_.updateBoundaries(this->mouse_Position_Window_);
			this->save_B_B_.updateBoundaries(this->mouse_Position_Window_);

			this->save_I_A_.update(this->mouse_Position_Window_);
		}

		if (this->load_X_A_.getIsVisible())
		{
			this->load_B_A_.updateBoundaries(this->mouse_Position_Window_);
			this->load_B_B_.updateBoundaries(this->mouse_Position_Window_);

			this->load_I_A_.update(this->mouse_Position_Window_);
		}
	}
}

void StateEditor::render(sf::RenderTarget& target)
{
	target.setView(this->camera_->getView());

	this->tilemap_->render(target);
	this->tile_Box_.render(target);

	target.setView(target.getDefaultView());

	this->instruction_Panel_X_A_.render(target);
	this->right_Side_Panel_X_A_.render(target);

	this->t_A_.render(target);
	this->t_B_.render(target);


	this->tilemap_Settings_X_A_.render(target);
	this->tilemap_Settings_B_A_.render(target);
	this->tilemap_Settings_B_B_.render(target);
	this->tilemap_Settings_T_D_.render(target);
	this->tilemap_Settings_T_A_.render(target);
	this->tilemap_Settings_T_B_.render(target);
	this->tilemap_Settings_T_C_.render(target);
	this->tilemap_Settings_T_D_.render(target);
	this->tilemap_Settings_T_E_.render(target);
	this->tilemap_Settings_T_F_.render(target);
	this->tilemap_Settings_T_G_.render(target);
	this->tilemap_Settings_I_A_.render(target);
	this->tilemap_Settings_I_B_.render(target);
	this->tilemap_Settings_I_C_.render(target);
	this->tilemap_Settings_C_A_.render(target);
	

	this->save_X_A_.render(target);
	this->save_B_A_.render(target);
	this->save_B_B_.render(target);
	this->save_T_A_.render(target);
	this->save_T_B_.render(target);
	this->save_T_C_.render(target);
	this->save_T_D_.render(target);
	this->save_I_A_.render(target);


	this->load_X_A_.render(target);
	this->load_B_A_.render(target);
	this->load_B_B_.render(target);
	this->load_T_A_.render(target);
	this->load_T_B_.render(target);
	this->load_T_C_.render(target);
	this->load_T_D_.render(target);
	this->load_I_A_.render(target);

	for (auto& b : this->right_Side_Panel_Buttons_)
	{
		b.render(target);
	}

	for (auto& t : this->right_Side_Panel_Texts_)
	{
		t.render(target);
	}


	this->window_Position_.render(target);
	this->grid_Position_.render(target);
	this->tile_Type_.render(target);
	
	this->menu_Pause_->render(target);
}
