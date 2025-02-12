#include "Text.h"

Text::Text()
{
	this->is_Visible_ = true;
}

Text::~Text()
{
}

void Text::setSettings(const sf::Font& font, unsigned int characterSize, std::string text, sf::Vector2f position, bool isVisible)
{
	/*
		CHECK IF THE FONT FILE IS LOADS
	*/
	this->font_ = font;

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

void Text::wrapText(const sf::FloatRect boundaries)
{
	/*
		FIND EVERY CHARACTERS POSITION IN THE STRING WITHIN THE WINDOW. IF IT'S OUTSIDE OF THE
		BOUNDS OF THE HOVER BOX THEN IT WILL INSERT A NEWLINE BEFORE THAT CHARACTER
	*/
	for (int x = 0; x < this->text_.getString().getSize(); ++x)
	{
		if (this->text_.findCharacterPos(x).x >= boundaries.left + boundaries.width)
		{
			std::string reformat = this->text_.getString();

			reformat.insert(x, "\n");

			this->text_.setString(reformat);
		}
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

void Text::setCharacterSize(unsigned int characterSize)
{
	this->text_.setCharacterSize(characterSize);	
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

const unsigned int& Text::getCharacterSize() const
{
	return this->text_.getCharacterSize();
}
