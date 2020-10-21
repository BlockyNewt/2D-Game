#include "StateEditor.h"

StateEditor::StateEditor(std::stack<State*>* states, sf::RenderWindow* window) 
	: State(states, window)
{
	std::cout << "DEBUG::STATEEDITOR::STATEEDITOR() -> HAS STARTED." << std::endl;

	this->x_A_.SetSettings(400.f, 600.f, 10.f, 10.f, sf::Color::Green, 1.f, sf::Color::Red, true);

	this->t_A_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 25, "Editor Instructions", sf::Vector2f(this->x_A_.getLeftPosition(true, 100.f), this->x_A_.getTopPosition(true, 10.f)), true);
}

StateEditor::~StateEditor()
{
}

void StateEditor::UpdatePollEvent(sf::Event& ev)
{
	this->menu_Pause_.UpdatePollEvent(ev, this->states_);

	if (!this->menu_Pause_.getIsPaused())
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
	}
}

void StateEditor::Update()
{
	this->UpdateMousePosition();

	this->menu_Pause_.Update(this->mouse_Position_Window_);
}

void StateEditor::Render(sf::RenderTarget& target)
{
	this->x_A_.Render(target);

	this->t_A_.Render(target);
	
	this->menu_Pause_.Render(target);
}
