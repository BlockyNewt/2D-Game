#ifndef QUESTBOX_H
#define QUESTBOX_H

#include "SFML/Graphics.hpp"

#include "Box.h"	
#include "Button.h"
#include "Text.h"

#include <iostream>

class QuestBox
{
public:
	QuestBox();
	~QuestBox();

	void setSettings(float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor);

	bool updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);

	const bool& getIsVisible() const;

private:

private:
	Box quest_Box_;
	Text quest_Text_;
	Button accept_Button_;
	Button decline_Button_;

	bool is_Visible_;
};

#endif