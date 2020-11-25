#include "MenuPause.h"

MenuPause::MenuPause(sf::RenderWindow* window, const ResourceFont& resourceFont)
{
	this->is_Paused_ = false;

	this->x_A_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(255, 255, 255, 70), 1.f, sf::Color::Red, true);

	this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 50, "Pause Menu", sf::Vector2f(400.f, 10.f), true);

	this->b_B_.setSettings(100.f, 50.f, 10.f, 50.f, sf::Color::Red, 1, sf::Color::Red, true);
	this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Continue", this->b_B_.setPositionOfText(this->t_B_.setText()), true);

	this->b_C_.setSettings(100.f, 50.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Exit", this->b_C_.setPositionOfText(this->t_C_.setText()), true);

	this->buttons_.push_back(this->b_B_);
	this->buttons_.push_back(this->b_C_);
	
	this->texts_.push_back(this->t_B_);
	this->texts_.push_back(this->t_C_);
}

MenuPause::~MenuPause()
{
}

bool MenuPause::updatePollEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		/*
			ENABLE PAUSE MENU BY PRESSING ESCAPE AND IF YOU PUSH IT AGAIN THEN
			YOU WILL DISABLE IT
		*/
		if (ev.key.code == sf::Keyboard::Escape &&
			!this->is_Paused_)
		{
			this->is_Paused_ = true;

			return false;
		}
		else if (ev.key.code == sf::Keyboard::Escape &&
			this->is_Paused_)
		{
			this->is_Paused_ = false;

			return false;
		}
	}

	/*
		UPDATE POLL EVENTS OF THE BUTTONS
	*/
	if (this->is_Paused_)
	{
		if (this->buttons_[0].updatePollEvent(ev))
		{
			this->is_Paused_ = false;

			return false;
		}
		else if (this->buttons_[1].updatePollEvent(ev))
		{
			this->is_Paused_ = false;

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void MenuPause::update(const sf::Vector2i& mousePositionWindow)
{
	/*
		UPDATE BOUNADRIES OF BUTTONS
	*/
	if (this->is_Paused_)
	{
		for (auto& b : this->buttons_)
		{
			b.updateBoundaries(mousePositionWindow);
		}
	}
}

void MenuPause::render(sf::RenderTarget& target)
{
	/*
		IF PAUSED RENDER OBJECTS
	*/
	if (this->is_Paused_)
	{
		this->x_A_.render(target);

		this->t_A_.render(target);

		for (auto& b : this->buttons_)
		{
			b.render(target);
		}

		for (auto& t : this->texts_)
		{
			t.render(target);
		}
	}
}

const bool& MenuPause::getIsPaused() const
{
	return this->is_Paused_;
}
