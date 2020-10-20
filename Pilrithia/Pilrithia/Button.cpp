#include "Button.h"

Button::Button()
{
	this->is_Hovering_ = false;
}

Button::~Button()
{
}

void Button::SetSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor)
{
	this->button_.setSize(sf::Vector2f(sizeX, sizeY));
	this->button_.setPosition(sf::Vector2f(posX, posY));
	this->button_.setFillColor(fillColor);
	this->button_.setOutlineThickness(outlineThickness);
	this->button_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;
}

void Button::UpdatePollEvent(sf::Event& ev)
{
	if (this->is_Hovering_)
	{
		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.key.code == sf::Mouse::Left)
			{
				std::cout << "Left mouse button is being pressed" << std::endl;
			}
		}
	}
}

void Button::UpdateBoundaries(const sf::Vector2i& mousePositionWindow)
{
	if (this->button_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->button_.setFillColor(sf::Color::Green);
		
		this->is_Hovering_ = true;
	}
	else
	{
		this->button_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;
	}
}

void Button::Render(sf::RenderTarget& target)
{
	target.draw(this->button_);
}

const sf::Vector2f& Button::setPositionOfText(sf::Text& text)
{
	text.setPosition(sf::Vector2f(this->button_.getGlobalBounds().left + 10.f, this->button_.getGlobalBounds().top + 10.f));

	return text.getPosition();
}

const sf::Vector2f& Button::getPosition() const
{
	return this->button_.getPosition();
}

const float& Button::getLeftPosition(int offset) const
{
	return this->button_.getGlobalBounds().left + offset;
}

const float& Button::getBottomPosition(int offset) const
{
	return this->button_.getGlobalBounds().top + this->button_.getGlobalBounds().height + offset;
}
