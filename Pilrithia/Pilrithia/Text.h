#ifndef TEXT_H
#define TEXT_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>

class Text
{
public:
	Text();
	~Text();

	void SetSettings(std::string fontFilePath, std::string text);

	void Render(sf::RenderTarget& target);

private:

private:
	sf::Font font_;
	sf::Text text_;

};

#endif // !TEXT_H
