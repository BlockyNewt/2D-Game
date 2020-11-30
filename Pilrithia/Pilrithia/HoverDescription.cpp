#include "HoverDescription.h"

HoverDescription::HoverDescription()
{
	this->description_Box_.setSettings(200.f, 200.f, 0.f, 0.f, sf::Color(90, 82, 85), 1.f, sf::Color::White, true);

	

	this->is_Visible_ = false;
}

HoverDescription::~HoverDescription()
{
}

void HoverDescription::setTextFont(const ResourceFont& resourceFont)
{
	/*
		SET FONT FOR TEXT HERE (MUST CALL THIS OR ELSE IT WONT SHOW AND WONT GIVE AN ERROR) 
	*/
	this->title_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 24, "", sf::Vector2f(this->description_Box_.getLeftPosition(), this->description_Box_.getTopPosition()), true);
	this->description_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "", sf::Vector2f(this->description_Box_.getLeftPosition(), this->description_Box_.getTopPosition()), true);
}

void HoverDescription::setHoverBoundaries(HOVERPOSITION hoverPosition, const sf::FloatRect itemBoundaries, const sf::FloatRect itemBoundariesOffset)
{
	/*
		SET POSITION OF HOVER BOX TO THE OBJECT BEING SENT IN
	*/

	this->boundaries_ = itemBoundaries;
	this->boundaries_Offset_ = itemBoundariesOffset;

	if (hoverPosition == HOVERPOSITION::TOP)
	{
		this->description_Box_.setPosition(this->boundaries_Offset_.left, this->boundaries_Offset_.top - this->description_Box_.getGlobalBounds().height);

	}
	else if (hoverPosition == HOVERPOSITION::BOTTOM)
	{
		this->description_Box_.setPosition(this->boundaries_Offset_.left, this->boundaries_Offset_.top + this->boundaries_Offset_.height);

	}
	else if (hoverPosition == HOVERPOSITION::LEFT)
	{
		this->description_Box_.setPosition(this->boundaries_Offset_.left - this->description_Box_.getGlobalBounds().width, this->boundaries_Offset_.top);

	}
	else if (hoverPosition == HOVERPOSITION::RIGHT)
	{
		this->description_Box_.setPosition(this->boundaries_Offset_.left + this->boundaries_Offset_.width, this->boundaries_Offset_.top);
	}


	if (this->description_Box_.getTopPosition() < 0.f)
	{
		this->description_Box_.setPosition(this->boundaries_Offset_.left + this->boundaries_Offset_.width, 0.f);
	}
}

void HoverDescription::setString(DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description)
{
	/*
		SET THE STRING AND WORD WRAP IT IF IT GOES OUTSIDE OF THE BOUNDARIES OF THE HOVER BOX
	*/

	if (descriptionType == DESCRIPTIONTYPE::SKILL || 
		descriptionType == DESCRIPTIONTYPE::ITEM)
	{
		this->title_.setString(title);
		this->title_.setPosition(this->description_Box_.getLeftPosition(true, 10.f), this->description_Box_.getTopPosition());
		this->title_.wrapText(this->description_Box_.getGlobalBounds());

		this->description_.setString(description);
		this->description_.setPosition(this->description_Box_.getLeftPosition(), this->title_.getGlobalBounds().top + 50.f);
		this->description_.wrapText(this->description_Box_.getGlobalBounds());
	}

	else if (descriptionType == DESCRIPTIONTYPE::STAT)
	{
		this->description_.setString(description);
		this->description_.setPosition(this->description_Box_.getLeftPosition(), this->description_Box_.getTopPosition());
		this->description_.wrapText(this->description_Box_.getGlobalBounds());
	}
}

void HoverDescription::update(const sf::Vector2i& mousePositionWindow)
{
	if (this->boundaries_.contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		this->is_Visible_ = true;
	}
	else
	{
		this->is_Visible_ = false;
	}
}

void HoverDescription::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->description_Box_.render(target);

		this->title_.render(target);
		this->description_.render(target);
	}
}

void HoverDescription::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

const sf::FloatRect HoverDescription::getGlobalBounds() const
{
	return this->description_Box_.getGlobalBounds();
}
