#ifndef RESOURCEFONT_H
#define RESOURCEFONT_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <map>

enum class FONT_TYPE
{
	ARIAL = 0,
};

class ResourceFont
{
public:
	ResourceFont();
	~ResourceFont();

	void loadAllFonts();

	const sf::Font& getFont(FONT_TYPE fontType) const;

private:
	void loadFont(const std::string& fontFileName, FONT_TYPE fontType);
	void AddToMap(sf::Font* font, FONT_TYPE fontType);

private:
	std::map<FONT_TYPE, sf::Font*> fonts_;
};

#endif // !RESOURCEFONT_H
