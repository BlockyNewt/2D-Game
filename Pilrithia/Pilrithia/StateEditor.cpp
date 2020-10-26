#include "StateEditor.h"

StateEditor::StateEditor(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEEDITOR::STATEEDITOR() -> HAS STARTED." << std::endl;

	this->camera_ = new Camera(this->window_->getSize().x, this->window_->getSize().y);
	this->tilemap_ = new Tilemap(100, 100, 30);
	this->window_Position_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->grid_Position_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->tile_Box_.SetSettings(30.f, 30.f, 0.f, 0.f, sf::Color::Transparent, 1.f, sf::Color::Red, true);


	this->x_A_.SetSettings(400.f, 700.f, 10.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);
	this->x_B_.SetSettings(50.f, 700.f, this->window_->getSize().x - 60.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	std::string instructionsStr = "1.) Press 'Tab' to hide this window. \n\n2.) Press 'Esc' to open pause window \n\n3.) Left click to add tile \n\n4.) Right click to remove tile \n\n5.) nothing for now";

	this->t_A_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Editor Instructions", sf::Vector2f(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, instructionsStr, sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->t_A_.getBottomPosition(true, 50.f)), true);


	this->b_A_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->x_B_.getTopPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->b_B_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->b_A_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->b_C_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->b_B_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->b_D_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->b_C_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);

	this->t_C_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 12, "Clear", sf::Vector2f(this->b_A_.getLeftPosition(true, 5.f), this->b_A_.getTopPosition(true, 10.f)), true);
	this->t_E_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 12, "Setting", sf::Vector2f(this->b_B_.getLeftPosition(true, 2.f), this->b_B_.getTopPosition(true, 10.f)), true);

	this->x_C_.SetSettings(800.f, 600.f, this->window_->getSize().x / 2.f - 800.f / 2.f, this->window_->getSize().y / 2.f - 600.f / 2.f, sf::Color::Green, 1.f, sf::Color::Red, false);
	this->t_D_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 35, "Tilemap Settings", sf::Vector2f(this->x_C_.getLeftPosition(true, 300.f), this->x_C_.getTopPosition(true, 20.f)), false);

	this->t_F_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Max Grid Size X", sf::Vector2f(this->x_C_.getLeftPosition(true, 10.f), this->x_C_.getTopPosition(true, 100.f)), false);
	this->t_G_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Max Grid Size Y", sf::Vector2f(this->x_C_.getLeftPosition(true, 10.f), this->t_F_.getTopPosition(true, 50.f)), false);
	this->t_H_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Tile Size X & Y", sf::Vector2f(this->x_C_.getLeftPosition(true, 10.f), this->t_G_.getTopPosition(true, 50.f)), false);

	this->i_A_.SetSettings(75.f, 40.f, this->t_F_.getRightPosition(true, 10.f), this->t_F_.getTopPosition(false, 10), sf::Color::White, 1.f, sf::Color::Red, false);
	this->i_B_.SetSettings(75.f, 40.f, this->t_G_.getRightPosition(true, 10.f), this->t_G_.getTopPosition(false, 10), sf::Color::White, 1.f, sf::Color::Red, false);
	this->i_C_.SetSettings(75.f, 40.f, this->t_H_.getRightPosition(true, 10.f), this->t_H_.getTopPosition(false, 10), sf::Color::White, 1.f, sf::Color::Red, false);


	this->panel_Buttons_.push_back(b_A_);
	this->panel_Buttons_.push_back(b_B_);
	this->panel_Buttons_.push_back(b_C_);
	this->panel_Buttons_.push_back(b_D_);

	this->panel_Texts_.push_back(t_C_);
	this->panel_Texts_.push_back(t_E_);
}

StateEditor::~StateEditor()
{
}

void StateEditor::UpdatePollEvent(sf::Event& ev)
{
	if (this->menu_Pause_->UpdatePollEvent(ev))
	{
		this->states_->pop();
	}

	if (!this->menu_Pause_->getIsPaused())
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Tab)
			{
				//SHOW LEFT PANE INSTRUCTION BOX
				if (this->x_A_.getIsVisible())
				{
					this->x_A_.setIsVisible(false);

					this->t_A_.setIsVisible(false);
					this->t_B_.setIsVisible(false);
				}
				else
				{
					this->x_A_.setIsVisible(true);

					this->t_A_.setIsVisible(true);
					this->t_B_.setIsVisible(true);
				}
			}
			
			this->window_->setKeyRepeatEnabled(true);

			this->camera_->UpdatePollEvent(ev);
			
		}


		if (ev.type == sf::Event::MouseButtonPressed)
		{
			this->window_->setKeyRepeatEnabled(true);

			if (ev.key.code == sf::Mouse::Left)
			{
				this->tilemap_->AddTile(this->mouse_Position_Grid_.x, this->mouse_Position_Grid_.y);
			}

			if (ev.key.code == sf::Mouse::Right)
			{
				this->tilemap_->RemoveTile(this->mouse_Position_Grid_.x, this->mouse_Position_Grid_.y);
			}
		}

		if (this->x_C_.getIsVisible())
		{
			this->i_A_.UpdatePollEvent(ev);
			this->i_B_.UpdatePollEvent(ev);
		}

		//RIGHT SIDE PANEL BUTTONS
		if (this->panel_Buttons_[0].UpdatePollEvent(ev))
		{
			this->tilemap_->ClearGrid();
		}
		if (this->panel_Buttons_[1].UpdatePollEvent(ev))
		{
			if (!this->x_C_.getIsVisible())
			{
				this->x_C_.setIsVisible(true);

				this->t_D_.setIsVisible(true);
				this->t_F_.setIsVisible(true);
				this->t_G_.setIsVisible(true);
				this->t_H_.setIsVisible(true);

				this->i_A_.setIsVisible(true);
				this->i_B_.setIsVisible(true);
				this->i_C_.setIsVisible(true);
			}
			else
			{
				this->x_C_.setIsVisible(false);
				
				this->t_D_.setIsVisible(false);
				this->t_F_.setIsVisible(false);
				this->t_G_.setIsVisible(false);
				this->t_H_.setIsVisible(false);

				this->i_A_.setIsVisible(false);
				this->i_B_.setIsVisible(false);
				this->i_C_.setIsVisible(false);
			}
		}

		
	}
}

void StateEditor::Update()
{
	this->UpdateMousePosition(&this->camera_->GetView());

	this->menu_Pause_->Update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		for (auto& b : this->panel_Buttons_)
		{
			b.UpdateBoundaries(this->mouse_Position_Window_);
		}

		//SETTINGS BUTTONS	
		if (this->x_C_.getIsVisible())
		{
			this->i_A_.UpdateBoundaries(this->mouse_Position_Window_);
			this->i_B_.UpdateBoundaries(this->mouse_Position_Window_);
			this->i_C_.UpdateBoundaries(this->mouse_Position_Window_);
		}

		this->tilemap_->Update();

		this->tile_Box_.SetPosition(static_cast<float>(this->mouse_Position_Grid_.x * 30), static_cast<float>(this->mouse_Position_Grid_.y * 30));


		this->window_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Window_.x) + " Y:" + std::to_string(this->mouse_Position_Window_.y));
		this->window_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y - 15.f));

		this->grid_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Grid_.x * 30) + " Y:" + std::to_string(this->mouse_Position_Grid_.y * 30));
		this->grid_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y + 15.f));
	}
}

void StateEditor::Render(sf::RenderTarget& target)
{
	target.setView(this->camera_->GetView());

	this->tilemap_->Render(target);
	this->tile_Box_.Render(target);

	target.setView(target.getDefaultView());

	this->x_A_.Render(target);
	this->x_B_.Render(target);

	this->t_A_.Render(target);
	this->t_B_.Render(target);

	this->x_C_.Render(target);
	this->t_D_.Render(target);
	this->t_F_.Render(target);
	this->t_G_.Render(target);
	this->t_H_.Render(target);

	this->i_A_.Render(target);
	this->i_B_.Render(target);
	this->i_C_.Render(target);


	for (auto& b : this->panel_Buttons_)
	{
		b.Render(target);
	}

	for (auto& t : this->panel_Texts_)
	{
		t.Render(target);
	}


	this->window_Position_.Render(target);
	this->grid_Position_.Render(target);
	
	this->menu_Pause_->Render(target);
}
