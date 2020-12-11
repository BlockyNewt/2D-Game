#include "MenuSetting.h"

MenuSetting::MenuSetting(sf::RenderWindow* window, const ResourceFont& resourceFont)
{
	this->is_In_Settings_ = false;

	this->x_A_.setSettings(window->getSize().x, window->getSize().y, 0.f, 0.f, sf::Color::Black, 1.f, sf::Color::Red, false);

	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 50, "Settings", sf::Vector2f(window->getSize().x / 2.f, 10.f), false);

	this->res_1920x1080_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 25, "1920 x 1080", sf::Vector2f(10.f, 200.f), false);
	this->res_1920x1080_C_A_.setSettings(40.f, 40.f, this->res_1920x1080_T_A_.getRightPosition(true, 15.f), this->res_1920x1080_T_A_.getTopPosition(false, 10.f), sf::Color::White, 1.f, sf::Color::White, false, false);

	this->res_1600x900_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 25, "1600 x 900", sf::Vector2f(10.f, 300.f), false);
	this->res_1600x900_C_A_.setSettings(40.f, 40.f, this->res_1600x900_T_A_.getRightPosition(true, 15.f), this->res_1600x900_T_A_.getTopPosition(false, 10.f), sf::Color::White, 1.f, sf::Color::White, false, false);

	this->res_1280x720_T_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 25, "1280 x 720", sf::Vector2f(10.f, 400.f), false);
	this->res_1280x720_C_A_.setSettings(40.f, 40.f, this->res_1280x720_T_A_.getRightPosition(true, 15.f), this->res_1280x720_T_A_.getTopPosition(false, 10.f), sf::Color::White, 1.f, sf::Color::White, false, false);


	this->b_B_.setSettings(150.f, 50.f, window->getSize().x / 2.f - 150.f, window->getSize().y - 60.f, sf::Color::Red, 1.f, sf::Color::Red, false);
	this->t_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Accept", sf::Vector2f(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f)), false);

	this->b_C_.setSettings(150.f, 50.f, window->getSize().x / 2.f + 150.f, window->getSize().y - 60.f, sf::Color::Red, 1.f, sf::Color::Red, false);
	this->t_C_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "Close", sf::Vector2f(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f)), false);

	if (window->getSize() == sf::Vector2u(1920, 1080))
	{
		this->res_1920x1080_C_A_.setIsEnabled(true);
		this->res_1600x900_C_A_.setIsEnabled(false);
		this->res_1280x720_C_A_.setIsEnabled(false);
	}
	else if (window->getSize() == sf::Vector2u(1600, 900))
	{
		this->res_1920x1080_C_A_.setIsEnabled(false);
		this->res_1600x900_C_A_.setIsEnabled(true);
		this->res_1280x720_C_A_.setIsEnabled(false);
	}
	else if (window->getSize() == sf::Vector2u(1280, 720))
	{
		this->res_1920x1080_C_A_.setIsEnabled(false);
		this->res_1600x900_C_A_.setIsEnabled(false);
		this->res_1280x720_C_A_.setIsEnabled(true);
	}
	else
	{
		this->res_1920x1080_C_A_.setIsEnabled(false);
		this->res_1600x900_C_A_.setIsEnabled(false);
		this->res_1280x720_C_A_.setIsEnabled(false);
	}
}

MenuSetting::~MenuSetting()
{
}

void MenuSetting::updatePollEvent(sf::Event& ev, sf::RenderWindow* window)
{
	if (this->is_In_Settings_)
	{
		if (this->res_1920x1080_C_A_.updatePollEvent(ev) &&
			!this->res_1920x1080_C_A_.getIsEnabled())
		{
			this->res_1920x1080_C_A_.setIsEnabled(true);
			this->res_1600x900_C_A_.setIsEnabled(false);
			this->res_1280x720_C_A_.setIsEnabled(false);
		}

		if (this->res_1600x900_C_A_.updatePollEvent(ev) &&
			!this->res_1600x900_C_A_.getIsEnabled())
		{
			this->res_1920x1080_C_A_.setIsEnabled(false);
			this->res_1600x900_C_A_.setIsEnabled(true);
			this->res_1280x720_C_A_.setIsEnabled(false);
		}

		if (this->res_1280x720_C_A_.updatePollEvent(ev) && 
			!this->res_1280x720_C_A_.getIsEnabled())
		{
			this->res_1920x1080_C_A_.setIsEnabled(false);
			this->res_1600x900_C_A_.setIsEnabled(false);
			this->res_1280x720_C_A_.setIsEnabled(true);
		}

		

		if (this->b_B_.updatePollEvent(ev))
		{
			if (this->res_1920x1080_C_A_.getIsEnabled())
			{
				window->setSize(sf::Vector2u(1920, 1080));
			}
			else if (this->res_1600x900_C_A_.getIsEnabled())
			{
				window->setSize(sf::Vector2u(1600, 900));
			}
			else if (this->res_1280x720_C_A_.getIsEnabled())
			{
				window->setSize(sf::Vector2u(1280, 720));
			}
			

			this->repositionGui(window);
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
		this->res_1920x1080_C_A_.updateBoundaries(mousePositionWindow);
		this->res_1600x900_C_A_.updateBoundaries(mousePositionWindow);
		this->res_1280x720_C_A_.updateBoundaries(mousePositionWindow);

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

		this->res_1920x1080_T_A_.render(target);
		this->res_1920x1080_C_A_.render(target);

		this->res_1600x900_T_A_.render(target);
		this->res_1600x900_C_A_.render(target);

		this->res_1280x720_T_A_.render(target);
		this->res_1280x720_C_A_.render(target);


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
		this->x_A_.setIsVisible(true);

		this->t_A_.setIsVisible(true);

		this->res_1920x1080_T_A_.setIsVisible(true);
		this->res_1920x1080_C_A_.setIsVisible(true);

		this->res_1600x900_T_A_.setIsVisible(true);
		this->res_1600x900_C_A_.setIsVisible(true);

		this->res_1280x720_T_A_.setIsVisible(true);
		this->res_1280x720_C_A_.setIsVisible(true);


		this->b_B_.setIsVisible(true);
		this->t_B_.setIsVisible(true);

		this->b_C_.setIsVisible(true);
		this->t_C_.setIsVisible(true);

		this->is_In_Settings_ = isInSettings;
	}
	else
	{
		this->x_A_.setIsVisible(false);

		this->t_A_.setIsVisible(false);

		this->res_1920x1080_T_A_.setIsVisible(false);
		this->res_1920x1080_C_A_.setIsVisible(false);

		this->res_1600x900_T_A_.setIsVisible(false);
		this->res_1600x900_C_A_.setIsVisible(false);

		this->res_1280x720_T_A_.setIsVisible(false);
		this->res_1280x720_C_A_.setIsVisible(false);

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

void MenuSetting::repositionGui(sf::RenderWindow* window)
{
	this->x_A_.setPosition(0.f, 0.f);
	this->x_A_.setSize(window->getSize().x, window->getSize().y);

	this->t_A_.setPosition(window->getSize().x / 2.f, 10.f);

	this->res_1920x1080_T_A_.setPosition(10.f, 200.f);
	this->res_1920x1080_C_A_.setPosition(sf::Vector2f(this->res_1920x1080_T_A_.getRightPosition(true, 15.f), this->res_1920x1080_T_A_.getTopPosition(false, 10.f)));

	this->res_1600x900_T_A_.setPosition(10.f, 300.f);
	this->res_1600x900_C_A_.setPosition(sf::Vector2f(this->res_1600x900_T_A_.getRightPosition(true, 15.f), this->res_1600x900_T_A_.getTopPosition(false, 10.f)));

	this->res_1280x720_T_A_.setPosition(10.f, 400.f);
	this->res_1280x720_C_A_.setPosition(sf::Vector2f(this->res_1280x720_T_A_.getRightPosition(true, 15.f), this->res_1280x720_T_A_.getTopPosition(false, 10.f)));


	this->b_B_.setPosition(sf::Vector2f(window->getSize().x / 2.f - 150.f, window->getSize().y - 60.f));
	this->t_B_.setPosition(this->b_B_.getLeftPosition(true, 10.f), this->b_B_.getTopPosition(true, 10.f));

	this->b_C_.setPosition(sf::Vector2f(window->getSize().x / 2.f + 150.f, window->getSize().y - 60.f));
	this->t_C_.setPosition(this->b_C_.getLeftPosition(true, 10.f), this->b_C_.getTopPosition(true, 10.f));
}
