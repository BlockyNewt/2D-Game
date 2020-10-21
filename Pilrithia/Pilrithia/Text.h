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

	void SetSettings(std::string fontFilePath, unsigned int characterSize, std::string text, sf::Vector2f position, bool isVisible);

	void Render(sf::RenderTarget& target);

	sf::Text& setText();
	void setIsVisible(bool isVisible);

	const bool& getIsVisible() const;

private:

private:
	sf::Font font_;
	sf::Text text_;

	bool is_Visible_;

};

#endif // !TEXT_H
