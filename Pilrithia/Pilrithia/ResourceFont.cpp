#include "ResourceFont.h"

ResourceFont::ResourceFont()
{
}

ResourceFont::~ResourceFont()
{
}

void ResourceFont::loadAllFonts()
{
	this->loadFont("arial.ttf", FONT_TYPE::ARIAL);
}

const sf::Font& ResourceFont::getFont(FONT_TYPE fontType) const
{
	auto findPos = this->fonts_.find(fontType);

	if (findPos != this->fonts_.end())
	{
		return findPos->second;
	}
	else
	{
		return sf::Font();
	}
}

void ResourceFont::loadFont(const std::string& fontFileName, FONT_TYPE fontType)
{
	sf::Font* font = new sf::Font();

	if (font->loadFromFile("Font/" + fontFileName))
	{
		this->AddToMap(font, fontType);
	}
	else
	{
		std::cout << "DEBUG::RESOURCEFONT::LOADFONT() -> Couldn't load font from file " << fontFileName << std::endl;
	}
}

void ResourceFont::AddToMap(const sf::Font* font, FONT_TYPE fontType)
{
	this->fonts_.insert(std::make_pair(fontType, *font));
}
