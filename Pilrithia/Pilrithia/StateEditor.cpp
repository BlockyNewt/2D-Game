#include "StateEditor.h"

StateEditor::StateEditor(std::stack<State*>* states, sf::RenderWindow* window, MenuSetting* menuSetting, MenuPause* menuPause)
	: State(states, window, menuSetting, menuPause)
{
	std::cout << "DEBUG::STATEEDITOR::STATEEDITOR() -> HAS STARTED." << std::endl;

	this->x_A_.SetSettings(400.f, 600.f, 10.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);
	this->x_B_.SetSettings(50.f, 700.f, this->window_->getSize().x - 60.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	this->t_A_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Editor Instructions", sf::Vector2f(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f)), true);

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
				}
				else
				{
					this->x_A_.setIsVisible(true);

					this->t_A_.setIsVisible(true);
				}
			}
		}

		for (auto& b : this->buttons_)
		{
			b.UpdatePollEvent(ev);
		}
	}
}

void StateEditor::Update()
{
	this->UpdateMousePosition();

	this->menu_Pause_->Update(this->mouse_Position_Window_);
	
	if (!this->menu_Pause_->getIsPaused())
	{
		for (auto& b : this->buttons_)
		{
			b.UpdateBoundaries(this->mouse_Position_Window_);
		}
	}
}

void StateEditor::Render(sf::RenderTarget& target)
{
	this->x_A_.Render(target);
	this->x_B_.Render(target);

	this->t_A_.Render(target);

	for (auto& b : this->buttons_)
	{
		b.Render(target);
	}
	
	this->menu_Pause_->Render(target);
}
