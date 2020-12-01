#include "ResourceFont.h"

ResourceFont::ResourceFont()
{
}

ResourceFont::~ResourceFont()
{
}

void ResourceFont::loadAllFonts()
{
	this->loadFont("arial.ttf", FONTTYPE::ARIAL);
}

const sf::Font& ResourceFont::getFont(FONTTYPE fontType) const
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

void ResourceFont::loadFont(const std::string& fontFileName, FONTTYPE fontType)
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

void ResourceFont::AddToMap(const sf::Font* font, FONTTYPE fontType)
{
	this->fonts_.insert(std::make_pair(fontType, *font));
}
