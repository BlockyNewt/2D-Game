#include "Text.h"

Text::Text()
{
	this->is_Visible_ = true;
}

Text::~Text()
{
}

void Text::SetSettings(std::string fontFilePath, unsigned int characterSize, std::string text, sf::Vector2f position, bool isVisible)
{
	if (!this->font_.loadFromFile(fontFilePath))
	{
		std::cout << "DEBUG::TEXT::SETSETTINGS() -> COULD NOT LOAD FONT FILE " << fontFilePath << " ." << std::endl;
	}

	this->text_.setFont(this->font_);
	this->text_.setCharacterSize(characterSize);
	this->text_.setString(text);
	this->text_.setPosition(position);

	this->is_Visible_ = isVisible;
}

void Text::Render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		target.draw(this->text_);
	}
}

sf::Text& Text::setText()
{
	return this->text_;
}

void Text::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const bool& Text::getIsVisible() const
{
	return this->is_Visible_;
}
