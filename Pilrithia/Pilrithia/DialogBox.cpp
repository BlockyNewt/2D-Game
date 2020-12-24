#include "DialogBox.h"

DialogBox::DialogBox()
{
}

DialogBox::~DialogBox()
{
}

void DialogBox::setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, const std::string& dialogText, ResourceFont* resourceFont, bool isVisible)
{
	/*
		SET SETTINGS FOR DIALOG BOX HERE
	*/
	this->dialog_Background_.setSettings(300.f, 200.f, posX, posY, fillColor, outlineThickness, outlineColor, true);

	this->dialog_Text_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, dialogText, sf::Vector2f(this->dialog_Background_.getLeftPosition(), this->dialog_Background_.getTopPosition(true, 10.f)), true);

	this->expand_Button_.setSettings(150.f, 40.f, this->dialog_Background_.getLeftPosition(true, 300.f / 2.f - 75.f), this->dialog_Background_.getBottomPosition(false, 45.f), sf::Color(174, 90, 65), outlineThickness, outlineColor, true);

	this->expand_Button_Text_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, "Expand", sf::Vector2f(this->expand_Button_.getLeftPosition(true, 10.f), this->expand_Button_.getTopPosition(true, 10.f)), true);
}

bool DialogBox::updatePollEvent(sf::Event& ev)
{
	if (this->is_Visible_)
	{
		if (this->expand_Button_.getIsVisible())
		{
			if (this->expand_Button_.updatePollEvent(ev))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void DialogBox::update(const sf::Vector2f& mousePositionView)
{
	if (this->is_Visible_)
	{
		if (this->expand_Button_.getIsVisible())
		{
			//std::cout << "updating mouse position for dialog box" << std::endl;
			this->expand_Button_.updateBoundaries(sf::Vector2i(mousePositionView.x, mousePositionView.y));
		}
	}
}

void DialogBox::render(sf::RenderTarget& target)
{
	if (this->is_Visible_)
	{
		this->dialog_Background_.render(target);
		this->dialog_Text_.render(target);

		if (this->expand_Button_.getIsVisible())
		{
			this->expand_Button_.render(target);
			this->expand_Button_Text_.render(target);
		}
	}
}

void DialogBox::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void DialogBox::setString(const std::string& string)
{
	this->dialog_Text_.setString(string);

	this->dialog_Text_.wrapText(this->dialog_Background_.getGlobalBounds());
}

void DialogBox::setExpandButtonVisibility(bool isVisible)
{
	this->expand_Button_.setIsVisible(isVisible);
}

const bool& DialogBox::getIsVisible() const
{
	return this->is_Visible_;
}
