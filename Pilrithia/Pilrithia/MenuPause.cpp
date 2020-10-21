#include "MenuPause.h"

MenuPause::MenuPause()
{
	this->is_Paused_ = false;

	this->x_A_.SetSettings(1280.f, 720.f, 0.f, 0.f, sf::Color(255, 255, 255, 50), 1.f, sf::Color::Red, true);

	this->t_A_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 50, "Pause Menu", sf::Vector2f(400.f, 10.f), true);

	this->b_B_.SetSettings(100.f, 50.f, 10.f, 50.f, sf::Color::Red, 1, sf::Color::Red, true);
	this->t_B_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "Continue", this->b_B_.setPositionOfText(this->t_B_.setText()), true);

	this->b_C_.SetSettings(100.f, 50.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_C_.SetSettings("C:/Users/thoma/source/repos/BlockyNewt/Pilrithia/Pilrithia/Pilrithia/Font/arial.ttf", 18, "Exit", this->b_C_.setPositionOfText(this->t_C_.setText()), true);

	this->buttons_.push_back(this->b_B_);
	this->buttons_.push_back(this->b_C_);
	
	this->texts_.push_back(this->t_B_);
	this->texts_.push_back(this->t_C_);
}

MenuPause::~MenuPause()
{
}

void MenuPause::UpdatePollEvent(sf::Event& ev, std::stack<State*>* states)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Escape &&
			!this->is_Paused_)
		{
			this->is_Paused_ = true;
		}
		else if (ev.key.code == sf::Keyboard::Escape &&
			this->is_Paused_)
		{
			this->is_Paused_ = false;
		}
	}

	if (this->is_Paused_)
	{
		if (this->buttons_[0].UpdatePollEvent(ev))
		{
			this->is_Paused_ = false;
		}
		else if (this->buttons_[1].UpdatePollEvent(ev))
		{
			this->is_Paused_ = false;

			states->pop();
		}
	}
}

void MenuPause::Update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_Paused_)
	{
		for (auto& b : this->buttons_)
		{
			b.UpdateBoundaries(mousePositionWindow);
		}
	}
}

void MenuPause::Render(sf::RenderTarget& target)
{
	if (this->is_Paused_)
	{
		this->x_A_.Render(target);

		this->t_A_.Render(target);

		for (auto& b : this->buttons_)
		{
			b.Render(target);
		}

		for (auto& t : this->texts_)
		{
			t.Render(target);
		}
	}
}

const bool& MenuPause::getIsPaused() const
{
	return this->is_Paused_;
}
