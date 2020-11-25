#ifndef RESOURCEFONT_H
#define RESOURCEFONT_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <map>

enum class FONTTYPE
{
	ARIAL = 0,

};

class ResourceFont
{
public:
	ResourceFont();
	~ResourceFont();

	void loadAllFonts();

	const sf::Font& getFont(FONTTYPE fontType) const;

private:
	void loadFont(const std::string& fontFileName, FONTTYPE fontType);
	void AddToMap(const sf::Font* font, FONTTYPE fontType);

private:
	std::map<FONTTYPE, sf::Font> fonts_;
};

#endif // !RESOURCEFONT_H
