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

	void setSettings(std::string fontFilePath, unsigned int characterSize, std::string text, sf::Vector2f position, bool isVisible);

	void render(sf::RenderTarget& target);

	sf::Text& setText();
	void setIsVisible(bool isVisible);

	const sf::Vector2f& getPosition() const;
	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;
	const bool& getIsVisible() const;

private:

private:
	sf::Font font_;
	sf::Text text_;

	bool is_Visible_;

};

#endif // !TEXT_H
