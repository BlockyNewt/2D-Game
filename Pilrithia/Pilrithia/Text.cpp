#include "Text.h"

Text::Text()
{
}

Text::~Text()
{
}

void Text::SetSettings(std::string fontFilePath, unsigned int characterSize, std::string text, sf::Vector2f position)
{
	if (!this->font_.loadFromFile(fontFilePath))
	{
		std::cout << "DEBUG::TEXT::SETSETTINGS() -> COULD NOT LOAD FONT FILE " << fontFilePath << " ." << std::endl;
	}

	this->text_.setFont(this->font_);
	this->text_.setCharacterSize(characterSize);
	this->text_.setString(text);
	this->text_.setPosition(position);
}

void Text::Render(sf::RenderTarget& target)
{
	target.draw(this->text_);
}

sf::Text& Text::setText()
{
	return this->text_;
}
