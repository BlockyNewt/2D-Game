#include "InputBox.h"

InputBox::InputBox()
{
	this->input_String_ = "";

	this->input_String_Max_Size_ = 0;

	this->is_Hovering_ = false;
}

InputBox::~InputBox()
{
}

void InputBox::setSettings(float sizeX, float sizeY, float posX, float posY, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, bool isVisible, bool isInputting, int inputStringMaxSize, ResourceFont* resourceFont)
{
	/*
		SET SETTINGS FOR INPUTBOX
	*/
	this->input_Box_.setSize(sf::Vector2f(sizeX, sizeY));
	this->input_Box_.setPosition(sf::Vector2f(posX, posY));
	this->input_Box_.setFillColor(fillColor);
	this->input_Box_.setOutlineThickness(outlineThickness);
	this->input_Box_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;

	this->input_String_Max_Size_ = inputStringMaxSize;

	this->is_Visible_ = isVisible;
	this->is_Inputting_ = isInputting;

	this->input_Text_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 25, "Editor Instructions", sf::Vector2f(this->getLeftPosition(true, 5.f), this->getTopPosition(true, 5.f)), true);
}

void InputBox::updateEnablePollEvent(sf::Event& ev)
{
	/*
		IF YOU ARE HOVERING THEN YOU CAN CLICK THE INPUTBOX AND ENABLE IT FOR TYPING
	*/
	if (this->is_Hovering_)
	{
		if (!this->is_Inputting_)
		{
			if (ev.type == sf::Event::MouseButtonPressed)
			{
				if (ev.key.code == sf::Mouse::Left)
				{
					std::cout << "DEBUG::INPUTBOX::UPDATEPOLLEVENT() -> Typing is enabled." << std::endl;

					this->is_Inputting_ = true;
				}
			}
		}
	}
	else
	{
		/*
			IF CLICKED AGAIN WHILE NOT HOVERING WITHIN THE BOUNDARIES OF THE BOX THEN YOU WILL DISABLE TYPING
		*/
		if (this->is_Inputting_)
		{
			if (ev.type == sf::Event::MouseButtonPressed)
			{
				if (ev.key.code == sf::Mouse::Left)
				{
					std::cout << "DEBUG::INPUTBOX::UPDATEPOLLEVENT() -> Typing is disabled." << std::endl;

					this->is_Inputting_ = false;
				}
			}
		}
	}

}

void InputBox::updateInputPollEvent(sf::Event& ev)
{
	if (this->is_Inputting_)
	{
		/*
			GET TEXT TYPED FROM THE KEYBOARD AS LONG AS IT'S NOT A 'BACKSPACE'
		*/
		if (ev.type == sf::Event::TextEntered)
		{
			if (ev.text.unicode != '\b')
			{
				if (this->input_String_.size() < this->input_String_Max_Size_)
				{
					this->input_String_ += ev.text.unicode;
				}
			}
		}

		/*
			IF 'BACKSPACE' IS PRESSED THEN DELETE THE LAST CHARACTER ADDED FROM THE STRING
		*/
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::BackSpace)
			{
				if (this->input_String_.size() > 0)
				{
					this->input_String_.pop_back();
				}
			}
		}
	}
}

void InputBox::updatePollEvent(sf::Event& ev)
{
	this->updateEnablePollEvent(ev);
	this->updateInputPollEvent(ev);
}

void InputBox::updateBoundaries(const sf::Vector2i& mousePositionWindow)
{
	/*
		IF THE MOUSE POSITION OF THE WINDOW IS WITHIN THE BOUNDARIES OF THIS INPUTBOX THEN CHANGE THE COLOR
	*/
	if (this->input_Box_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->input_Box_.setFillColor(sf::Color::Green);

		this->is_Hovering_ = true;
	}
	else
	{
		this->input_Box_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;
	}
}

void InputBox::updateInputString()
{
	this->input_Text_.setString(this->input_String_);
}

void InputBox::update(const sf::Vector2i& mousePositionWindow)
{
	this->updateBoundaries(mousePositionWindow);
	this->updateInputString();
}

void InputBox::render(sf::RenderTarget& target)
{
	/*
		DRAW THE INPUTBOX ONLY IF IT IS VISIBLE
	*/
	if (this->is_Visible_)
	{
		target.draw(this->input_Box_);

		this->input_Text_.render(target);
	}
}

void InputBox::setIsVisible(bool isVisible)
{
	this->is_Visible_ = isVisible;
}

void InputBox::setPosition(const sf::Vector2f& position)
{
	this->input_Box_.setPosition(position);
	this->input_Text_.setPosition(this->getLeftPosition(true, 5.f), this->getTopPosition(true, 5.f));
}

void InputBox::clearString()
{
	this->input_String_ = "";
}

const sf::Vector2f& InputBox::getPosition() const
{
	return this->input_Box_.getPosition();
}

const float InputBox::getLeftPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->input_Box_.getGlobalBounds().left + offset;
	}
	else
	{
		return this->input_Box_.getGlobalBounds().left - offset;
	}
}

const float InputBox::getRightPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->input_Box_.getGlobalBounds().left + this->input_Box_.getGlobalBounds().width + offset;
	}
	else
	{
		return this->input_Box_.getGlobalBounds().left + this->input_Box_.getGlobalBounds().width - offset;
	}
}

const float InputBox::getTopPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->input_Box_.getGlobalBounds().top + offset;
	}
	else
	{
		return this->input_Box_.getGlobalBounds().top - offset;
	}
}

const float InputBox::getBottomPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->input_Box_.getGlobalBounds().top + this->input_Box_.getGlobalBounds().height + offset;
	}
	else
	{
		return this->input_Box_.getGlobalBounds().top + this->input_Box_.getGlobalBounds().height - offset;
	}
}

const std::string& InputBox::getString() const
{
	return this->input_String_;
}

const bool& InputBox::getIsVisible() const
{
	return this->is_Visible_;
}
