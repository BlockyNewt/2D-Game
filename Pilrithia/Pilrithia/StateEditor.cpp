#include "StateEditor.h"

StateEditor::StateEditor(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEEDITOR::STATEEDITOR() -> HAS STARTED." << std::endl;

	this->cam = new Camera(this->window_->getSize().x, this->window_->getSize().y);
	this->aaa = new Tilemap(10, 10, 30);
	this->window_Position_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->grid_Position_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "", sf::Vector2f(0.f, 0.f), true);
	this->tile_Box_.SetSettings(30.f, 30.f, 0.f, 0.f, sf::Color::Cyan, 1.f, sf::Color::Red, true);


	this->x_A_.SetSettings(400.f, 700.f, 10.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);
	this->x_B_.SetSettings(50.f, 700.f, this->window_->getSize().x - 60.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	std::string instructionsStr = "1.) Press tab to hide this window. \n\n2.) nothing for now \n\n3.) nothing for now \n\n4.) nothing for now";

	this->t_A_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Editor Instructions", sf::Vector2f(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f)), true);
	this->t_B_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, instructionsStr, sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->t_A_.getBottomPosition(true, 50.f)), true);


	this->b_A_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->x_B_.getTopPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->b_B_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->b_A_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->b_C_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->b_B_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);
	this->b_D_.SetSettings(40.f, 40.f, this->x_B_.getLeftPosition(true, 5), this->b_C_.getBottomPosition(true, 5), sf::Color::Blue, 1, sf::Color::Red, true);

	this->buttons_.push_back(b_A_);
	this->buttons_.push_back(b_B_);
	this->buttons_.push_back(b_C_);
	this->buttons_.push_back(b_D_);
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

			this->cam->UpdatePollEvent(ev);
			
		}

		for (auto& b : this->buttons_)
		{
			b.UpdatePollEvent(ev);
		}
	}
}

void StateEditor::Update()
{
	this->UpdateMousePosition(&this->cam->GetView());

	this->menu_Pause_->Update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		for (auto& b : this->buttons_)
		{
			b.UpdateBoundaries(this->mouse_Position_Window_);
		}

		this->aaa->Update();

		this->tile_Box_.SetPosition(static_cast<float>(this->mouse_Position_Grid_.x * 30), static_cast<float>(this->mouse_Position_Grid_.y * 30));


		this->window_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Window_.x) + " Y:" + std::to_string(this->mouse_Position_Window_.y));
		this->window_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y - 15.f));

		this->grid_Position_.setText().setString("X: " + std::to_string(this->mouse_Position_Grid_.x * 30) + " Y:" + std::to_string(this->mouse_Position_Grid_.y * 30));
		this->grid_Position_.setText().setPosition(sf::Vector2f(this->mouse_Position_Window_.x + 20.f, this->mouse_Position_Window_.y + 15.f));
	}
}

void StateEditor::Render(sf::RenderTarget& target)
{
	target.setView(this->cam->GetView());

	this->aaa->Render(target);
	this->tile_Box_.Render(target);

	target.setView(target.getDefaultView());

	this->x_A_.Render(target);
	this->x_B_.Render(target);

	this->t_A_.Render(target);
	this->t_B_.Render(target);

	for (auto& b : this->buttons_)
	{
		b.Render(target);
	}


	this->window_Position_.Render(target);
	this->grid_Position_.Render(target);
	
	this->menu_Pause_->Render(target);
}
