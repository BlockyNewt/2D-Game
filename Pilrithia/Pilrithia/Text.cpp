#include "Text.h"

Text::Text()
{
	this->is_Visible_ = true;
}

Text::~Text()
{
}

void Text::setSettings(std::string fontFilePath, unsigned int characterSize, std::string text, sf::Vector2f position, bool isVisible)
{
	/*
		CHECK IF THE FONT FILE IS LOADS 
	*/
	if (!this->font_.loadFromFile(fontFilePath))
	{
		std::cout << "DEBUG::TEXT::SETSETTINGS() -> COULD NOT LOAD FONT FILE " << fontFilePath << " ." << std::endl;
	}

	/*
		SET SETTINGS FOR TEXT
	*/
	this->text_.setFont(this->font_);
	this->text_.setCharacterSize(characterSize);
	this->text_.setString(text);
	this->text_.setPosition(position);
	this->text_.setOutlineThickness(1.f);
	this->text_.setOutlineColor(sf::Color::Black);

	this->is_Visible_ = isVisible;
}

void Text::render(sf::RenderTarget& target)
{
	/*
		DRAW THE TEXT ONLY IF IT IS VISIBLE
	*/
	if (this->is_Visible_)
	{
		target.draw(this->text_);
	}
}

void Text::setString(const std::string& string)
{
	this->text_.setString(string);
}

void Text::setPosition(float x, float y)
{
	this->text_.setPosition(sf::Vector2f(x, y));
}

void Text::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

sf::Text& Text::setText()
{
	return this->text_;
}

const sf::Vector2f& Text::getPosition() const
{
	return this->text_.getPosition();
}

const sf::FloatRect Text::getGlobalBounds() const
{
	return this->text_.getGlobalBounds();
}

const std::string& Text::getString() const
{
	return this->text_.getString();
}

const sf::Text& Text::getText() const
{
	return this->text_;
}

const float Text::getLeftPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->text_.getGlobalBounds().left + offset;

	}
	else
	{
		return this->text_.getGlobalBounds().left - offset;

	}
}

const float Text::getRightPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->text_.getGlobalBounds().left + this->text_.getGlobalBounds().width + offset;

	}
	else
	{
		return this->text_.getGlobalBounds().left + this->text_.getGlobalBounds().width - offset;

	}
}

const float Text::getTopPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->text_.getGlobalBounds().top + offset;
	}
	else
	{

		return this->text_.getGlobalBounds().top - offset;

	}
}

const float Text::getBottomPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->text_.getGlobalBounds().top + this->text_.getGlobalBounds().height + offset;

	}
	else
	{
		return this->text_.getGlobalBounds().top + this->text_.getGlobalBounds().height - offset;

	}
}

const bool& Text::getIsVisible() const
{
	return this->is_Visible_;
}
