#ifndef QUESTBOX_H
#define QUESTBOX_H

#include "SFML/Graphics.hpp"

#include "ResourceFont.h"

#include "Box.h"	
#include "Button.h"
#include "Text.h"

#include <iostream>

class QuestBox
{
public:
	QuestBox();
	~QuestBox();

	void setSettings(float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, const std::string& questText, const ResourceFont& resourceFont);

	bool updateAcceptPollEvent(sf::Event& ev);
	bool updateDeclinePollEvent(sf::Event& ev);
	bool updateCompletePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);
	void setString(const std::string& string);
	void setIsAccepted(bool isAccepted);

	const bool& getIsVisible() const;

private:

private:
	Box quest_Box_;
	Text quest_Text_;
	Button accept_Button_;
	Button decline_Button_;
	Button complete_Button_;
	Text accept_Text_;
	Text decline_Text_;
	Text complete_Text_;

	bool is_Visible_;
	bool is_Accepted_;
	bool is_Completed_;
};

#endif