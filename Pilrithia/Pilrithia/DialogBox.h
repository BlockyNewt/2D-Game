#ifndef DIALOGBOX_H	
#define DIALOGBOX_H

#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Button.h"
#include "Text.h"

#include <iostream>

class DialogBox
{
public:
	DialogBox();
	~DialogBox();

	void setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, const std::string& dialogText, bool isVisible);

	bool updatePollEvent(sf::Event& ev);

	void update(const sf::Vector2f& mousePositionView);

	void render(sf::RenderTarget& target);


	void setIsVisible(bool isVisible);
	void setString(const std::string& string);
	void setExpandButtonVisibility(bool isVisible);

	const bool& getIsVisible() const;

private:

private:
	Box dialog_Background_;
	Text dialog_Text_;

	Button expand_Button_;
	Text expand_Button_Text_;

	bool is_Visible_;
};

#endif