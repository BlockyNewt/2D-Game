#include "Text.h"

Text::Text()
{
}

Text::~Text()
{
}

void Text::SetSettings(std::string fontFilePath, std::string text)
{
	//WILL HAVE TO ALSO ADD POSITION SETTERS 

	if (!this->font_.loadFromFile(fontFilePath))
	{
		std::cout << "DEBUG::TEXT::SETSETTINGS() -> COULD NOT LOAD FONT FILE " << fontFilePath << " ." << std::endl;
	}

	this->text_.setFont(this->font_);
	this->text_.setString(text);
}

void Text::Render(sf::RenderTarget& target)
{
	target.draw(this->text_);
}
