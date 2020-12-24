#include "ResourceFont.h"

ResourceFont::ResourceFont()
{
}

ResourceFont::~ResourceFont()
{
	for (std::map<FONT_TYPE, sf::Font*>::iterator itr = this->fonts_.begin(); itr != this->fonts_.end(); itr++)
	{
		delete itr->second;
		//this->fonts_.erase(itr);
	}

	this->fonts_.clear();

	if (this->fonts_.empty())
	{
		std::cout << "DEBUG::RESOURCEFONT::~RESOURCEFONT() -> Deleted all fonts" << std::endl;
	}
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
		return *findPos->second;
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

void ResourceFont::AddToMap(sf::Font* font, FONT_TYPE fontType)
{
	this->fonts_.insert(std::make_pair(fontType, font));
}
