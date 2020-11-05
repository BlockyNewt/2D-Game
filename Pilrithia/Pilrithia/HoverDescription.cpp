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

	this->description_Box_.setPosition(this->boundaries_.left, this->boundaries_.top - this->description_Box_.getGlobalBounds().height);
	this->text_.setPosition(this->description_Box_.getLeftPosition(), this->description_Box_.getTopPosition());
}

void HoverDescription::setString(const std::string& text)
{
	this->text_.setString(text);
	
	for (int x = 0; x < this->text_.setText().getString().getSize(); ++x)
	{
		if (this->text_.setText().findCharacterPos(x).x >= this->description_Box_.getRightPosition())
		{
			std::string reformat = this->text_.setText().getString();

			reformat.insert(x, "\n");

			this->text_.setString(reformat);
		}
	}

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
