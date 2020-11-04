#include "HoverDescription.h"

HoverDescription::HoverDescription()
{
	this->description_Box_.setSettings(200.f, 200.f, 0.f, 0.f, sf::Color::Blue, 1.f, sf::Color::White, true);

	this->text_.setSettings("Font/arial.ttf", 18, "", sf::Vector2f(this->description_Box_.getLeftPosition(), this->description_Box_.getTopPosition()), true);

	this->is_Visible_ = false;
}

HoverDescription::~HoverDescription()
{
}

void HoverDescription::setHoverBoundaries(const sf::FloatRect itemBoundaries)
{
	this->boundaries_ = itemBoundaries;

	this->description_Box_.setPosition(this->boundaries_.left + this->boundaries_.width, this->boundaries_.top);
	this->text_.setText().setPosition(sf::Vector2f(this->boundaries_.left + this->boundaries_.width, this->boundaries_.top));
}

void HoverDescription::setString(const std::string& text)
{
	this->text_.setString(text);
}

void HoverDescription::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->boundaries_.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		this->is_Visible_ = true;
	}
	else
	{
		this->is_Visible_ = false;
	}
}

void HoverDescription::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->description_Box_.render(target);

		this->text_.render(target);
	}
}
