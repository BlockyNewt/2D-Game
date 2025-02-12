#include "MenuPause.h"

MenuPause::MenuPause(sf::RenderWindow* window, const ResourceFont& resourceFont)
{
	this->is_Paused_ = false;

	this->x_A_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color(0, 0, 0, 200), 1.f, sf::Color::Red, true);

	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 50, "Pause Menu", sf::Vector2f(400.f, 10.f), true);

	this->b_B_.setSettings(100.f, 50.f, 10.f, 50.f, sf::Color::Red, 1, sf::Color::Red, true);
	this->t_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Continue", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), true);

	this->b_C_.setSettings(100.f, 50.f, this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f), sf::Color::Red, 1, sf::Color::Red, true);
	this->t_C_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Exit", sf::Vector2f(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f)), true);

	this->buttons_.push_back(this->b_B_);
	this->buttons_.push_back(this->b_C_);
	
	this->texts_.push_back(this->t_B_);
	this->texts_.push_back(this->t_C_);
}

MenuPause::~MenuPause()
{
	std::cout << "DEBUG::MENUPAUSE::~MENUPAUSE() -> Deconstructed." << std::endl;
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

void MenuPause::setPositionOnResize(const sf::RenderWindow* window)
{
	this->x_A_.setSize(window->getSize().x, window->getSize().y);

	this->t_A_.setPosition(400.f, 10.f);

	this->b_B_.setPosition(sf::Vector2f(10.f, 50.f));
	this->t_B_.setPosition(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f));

	this->b_C_.setPosition(sf::Vector2f(this->b_B_.getLeftPosition(), this->b_B_.getBottomPosition(true, 10.f)));
	this->t_C_.setPosition(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f));
}

const bool& MenuPause::getIsPaused() const
{
	return this->is_Paused_;
}
