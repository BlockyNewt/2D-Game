#include "StateEditor.h"

void StateEditor::initializeInstructionsPanel()
{
	this->instruction_Panel_X_A_.setSettings(400.f, 700.f, 10.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	std::string instructionsStr = "1.) Press 'Tab' to hide this window. \n\n2.) Press 'Esc' to open pause window \n\n3.) Left click to add tile \n\n4.) Right click to remove tile \n\n5.) nothing for now";

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

	this->tilemap_Settings_I_A_.setSettings(75.f, 40.f, this->tilemap_Settings_T_A_.getRightPosition(true, 10.f), this->tilemap_Settings_T_A_.getTopPosition(false, 10), sf::Color::Black, 1.f, sf::Color::Red, false, false);
	this->tilemap_Settings_I_B_.setSettings(75.f, 40.f, this->tilemap_Settings_T_B_.getRightPosition(true, 10.f), this->tilemap_Settings_T_B_.getTopPosition(false, 10), sf::Color::Black, 1.f, sf::Color::Red, false, false);
	this->tilemap_Settings_I_C_.setSettings(75.f, 40.f, this->tilemap_Settings_I_B_.getLeftPosition(), this->tilemap_Settings_T_C_.getTopPosition(false, 10), sf::Color::Black, 1.f, sf::Color::Red, false, false);
}

StateEditor::StateEditor(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEEDITOR::STATEEDITOR() -> HAS STARTED." << std::endl;

	this->camera_ = new Camera(this->window_->getSize().x, this->window_->getSize().y);
	this->tilemap_ = new Tilemap(5, 5, 30);
	this->window_Position_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->grid_Position_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->tile_Box_.setSettings(30.f, 30.f, 0.f, 0.f, sf::Color::Transparent, 1.f, sf::Color::Red, true);

	this->initializeInstructionsPanel();
	this->initializeRightSidePanel();
	this->initializeTilemapSettings();
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
		this->tilemap_->clearGrid();
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

			this->tilemap_Settings_I_A_.setIsVisible(true);
			this->tilemap_Settings_I_B_.setIsVisible(true);
			this->tilemap_Settings_I_C_.setIsVisible(true);
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

			this->tilemap_Settings_I_A_.setIsVisible(false);
			this->tilemap_Settings_I_B_.setIsVisible(false);
			this->tilemap_Settings_I_C_.setIsVisible(false);
		}
	}

	if (this->right_Side_Panel_Buttons_[2].updatePollEvent(ev))
	{
		this->tilemap_->save("testing.txt");
	}

	if (this->right_Side_Panel_Buttons_[3].updatePollEvent(ev))
	{
		this->tilemap_->load("testing.txt");
	}
}

void StateEditor::tilemapSettingsPollEvent(sf::Event& ev)
{
	if (this->tilemap_Settings_X_A_.getIsVisible())
	{
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

				this->tilemap_->resizeTileSize(static_cast<float>(newTileSizeXY));

				this->tilemap_Settings_I_C_.clearString();
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

			this->tilemap_Settings_I_A_.setIsVisible(false);
			this->tilemap_Settings_I_B_.setIsVisible(false);
			this->tilemap_Settings_I_C_.setIsVisible(false);

			this->tilemap_Settings_I_A_.clearString();
			this->tilemap_Settings_I_B_.clearString();
		}

		this->tilemap_Settings_I_A_.updatePollEvent(ev);
		this->tilemap_Settings_I_B_.updatePollEvent(ev);
		this->tilemap_Settings_I_C_.updatePollEvent(ev);
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

void StateEditor::update()
{
	this->updateMousePosition(&this->camera_->getView());

	this->menu_Pause_->update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
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
		}

		this->tilemap_->update();

		this->tile_Box_.SetPosition(static_cast<float>(this->mouse_Position_Grid_.x * 30), static_cast<float>(this->mouse_Position_Grid_.y * 30));


		this->window_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Window_.x) + " Y:" + std::to_string(this->mouse_Position_Window_.y));
		this->window_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y - 15.f));

		this->grid_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Grid_.x * 30) + " Y:" + std::to_string(this->mouse_Position_Grid_.y * 30));
		this->grid_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y + 15.f));
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
								
	this->tilemap_Settings_I_A_.render(target);
	this->tilemap_Settings_I_B_.render(target);
	this->tilemap_Settings_I_C_.render(target);
	


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
	
	this->menu_Pause_->render(target);
}
