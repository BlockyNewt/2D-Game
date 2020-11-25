#include "MenuSetting.h"

MenuSetting::MenuSetting(sf::RenderWindow* window, const ResourceFont& resourceFont)
{
	this->is_In_Settings_ = false;

	this->x_A_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color::Black, 1.f, sf::Color::Red, false);

	this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 50, "Settings", sf::Vector2f(window->getSize().x / 2.f, 10.f), false);

	this->resolution_1280x720_T_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 25, "1280 x 720", sf::Vector2f(10.f, 200.f), false);
	this->resolution_1280x720_C_A_.setSettings(40.f, 40.f, this->resolution_1280x720_T_A_.getRightPosition(true, 15.f), this->resolution_1280x720_T_A_.getTopPosition(false, 10.f), sf::Color::White, 1.f, sf::Color::White, false, false);

	this->resolution_600x600_T_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 25, "600 x 600", sf::Vector2f(10.f, this->resolution_1280x720_T_A_.getBottomPosition(true, 20.f)), false);
	this->resolution_600x600_C_A_.setSettings(40.f, 40.f, this->resolution_1280x720_C_A_.getLeftPosition(), this->resolution_600x600_T_A_.getTopPosition(false, 10.f), sf::Color::White, 1.f, sf::Color::White, false, false);

	this->b_B_.setSettings(150.f, 50.f, window->getSize().x / 2.f - 150.f, window->getSize().y - 60.f, sf::Color::Red, 1.f, sf::Color::Red, false);
	this->t_B_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Accept", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), false);

	this->b_C_.setSettings(150.f, 50.f, window->getSize().x / 2.f + 150.f, window->getSize().y - 60.f, sf::Color::Red, 1.f, sf::Color::Red, false);
	this->t_C_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f)), false);

	if (window->getSize() == sf::Vector2u(1280, 720))
	{
		this->resolution_600x600_C_A_.setIsEnabled(false);
		this->resolution_1280x720_C_A_.setIsEnabled(true);
	}
	else if (window->getSize() == sf::Vector2u(600, 600))
	{
		this->resolution_1280x720_C_A_.setIsEnabled(false);
		this->resolution_600x600_C_A_.setIsEnabled(true);
	}
}

MenuSetting::~MenuSetting()
{
}

void MenuSetting::updatePollEvent(sf::Event& ev, sf::RenderWindow* window)
{
	if (this->is_In_Settings_)
	{
		if (this->resolution_1280x720_C_A_.updatePollEvent(ev) && 
			!this->resolution_1280x720_C_A_.getIsEnabled())
		{
			this->resolution_600x600_C_A_.setIsEnabled(false);
			this->resolution_1280x720_C_A_.setIsEnabled(true);
		}

		if (this->resolution_600x600_C_A_.updatePollEvent(ev) &&
			!this->resolution_600x600_C_A_.getIsEnabled())
		{
			this->resolution_1280x720_C_A_.setIsEnabled(false);
			this->resolution_600x600_C_A_.setIsEnabled(true);
		}

		if (this->b_B_.updatePollEvent(ev))
		{
			if (this->resolution_1280x720_C_A_.getIsEnabled())
			{
				window->setSize(sf::Vector2u(1280, 720));
			}
			else if (this->resolution_600x600_C_A_.getIsEnabled())
			{
				window->setSize(sf::Vector2u(600, 600));
			}
		}

		if (this->b_C_.updatePollEvent(ev))
		{
			this->makeAllVisible(false);
		}
	}
}

void MenuSetting::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->is_In_Settings_)
	{
		this->resolution_1280x720_C_A_.updateBoundaries(mousePositionWindow);
		this->resolution_600x600_C_A_.updateBoundaries(mousePositionWindow);

		this->b_B_.updateBoundaries(mousePositionWindow);
		this->b_C_.updateBoundaries(mousePositionWindow);
	}
}

void MenuSetting::render(sf::RenderTarget& target)
{
	if (this->is_In_Settings_)
	{
		this->x_A_.render(target);

		this->t_A_.render(target);

		this->resolution_1280x720_T_A_.render(target);
		this->resolution_1280x720_C_A_.render(target);

		this->resolution_600x600_T_A_.render(target);
		this->resolution_600x600_C_A_.render(target);

		this->b_B_.render(target);
		this->t_B_.render(target);

		this->b_C_.render(target);
		this->t_C_.render(target);
	}
}

void MenuSetting::makeAllVisible(bool isInSettings)
{
	this->is_In_Settings_ = isInSettings;

	if (this->is_In_Settings_)
	{
		std::cout << "Is true" << std::endl;

		this->x_A_.setIsVisible(true);

		this->t_A_.setIsVisible(true);

		this->resolution_1280x720_T_A_.setIsVisible(true);
		this->resolution_1280x720_C_A_.setIsVisible(true);

		this->resolution_600x600_T_A_.setIsVisible(true);
		this->resolution_600x600_C_A_.setIsVisible(true);

		this->b_B_.setIsVisible(true);
		this->t_B_.setIsVisible(true);

		this->b_C_.setIsVisible(true);
		this->t_C_.setIsVisible(true);

		this->is_In_Settings_ = isInSettings;
	}
	else
	{
		std::cout << "IS false" << std::endl;
		this->x_A_.setIsVisible(false);

		this->t_A_.setIsVisible(false);

		this->resolution_1280x720_T_A_.setIsVisible(false);
		this->resolution_1280x720_C_A_.setIsVisible(false);

		this->resolution_600x600_T_A_.setIsVisible(false);
		this->resolution_600x600_C_A_.setIsVisible(false);

		this->b_B_.setIsVisible(false);
		this->t_B_.setIsVisible(false);
		
		this->b_C_.setIsVisible(false);
		this->t_C_.setIsVisible(false);

		this->is_In_Settings_ = false;
	}
}

const bool& MenuSetting::getIsInSettings() const
{
	return this->is_In_Settings_;
}
