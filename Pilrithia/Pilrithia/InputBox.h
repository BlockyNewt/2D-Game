#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Text.h"

#include <iostream>
#include <string>

class InputBox
{
public:
	InputBox();
	~InputBox();

	void setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible, bool isInputting, int inputStringMaxSize, const ResourceFont& resourceFont);

	void updatePollEvent(sf::Event& ev);

	void update(const sf::Vector2i& mousePositionWindow);

	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);

	void clearString();

	const sf::Vector2f& getPosition() const;
	const float getLeftPosition(bool pOrM = true, float offset = 0) const;
	const float getRightPosition(bool pOrM = true, float offset = 0) const;
	const float getTopPosition(bool pOrM = true, float offset = 0) const;
	const float getBottomPosition(bool pOrM = true, float offset = 0) const;
	const std::string& getString() const;
	const bool& getIsVisible() const;

private:
	void updateEnablePollEvent(sf::Event& ev);
	void updateInputPollEvent(sf::Event& ev);

	void updateBoundaries(const sf::Vector2i& mousePositionWindow);
	void updateInputString();

private:
	sf::RectangleShape input_Box_;
	sf::Color fill_Color_;

	Text input_Text_;

	std::string input_String_;
	int input_String_Max_Size_;


	bool is_Inputting_;
	bool is_Hovering_;
	bool is_Visible_;

};

#endif // !INPUTBOX_H
