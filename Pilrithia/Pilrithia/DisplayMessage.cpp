#include "DisplayMessage.h"

DisplayMessage::DisplayMessage(const sf::Window* window, ResourceFont* resourceFont)
{
	this->level_Up_Text_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 50, "", sf::Vector2f(window->getSize().x / 2.f - 300.f, window->getSize().y / 2.f - 200.f), true);
	this->adding_Item_To_Bag_Text_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 50, "Bag is full", sf::Vector2f(window->getSize().x / 2.f - 300.f, window->getSize().y / 2.f - 200.f), true);
	this->left_Combat_Text_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 50, "You have left combat", sf::Vector2f(window->getSize().x / 2.f - 300.f, window->getSize().y / 2.f - 200.f), true);

	this->is_Leveling_Up_ = false;
	this->is_Adding_Item_To_Bag_ = false;
	this->has_Left_Combat_ = false;

	this->time_ = 5.f;
}

DisplayMessage::~DisplayMessage()
{
	std::cout << "DEBUG::DISPLAYMESSAGE::~DISPLAYMESSAGE() -> Deconstructed. " << std::endl;
}

void DisplayMessage::updateLevelUp(const std::string& playerLevel)
{
	if (!this->is_Leveling_Up_)
	{
		this->level_Up_display_Timer_.restart();

		this->level_Up_Text_.setString("You have reached level " + playerLevel);

		this->is_Leveling_Up_ = true;
	}
}

void DisplayMessage::updateBagFull()
{
	if (!this->is_Adding_Item_To_Bag_)
	{
		this->adding_Item_To_Bag_display_Timer_.restart();

		this->is_Adding_Item_To_Bag_ = true;
	}
}

void DisplayMessage::updateLeftCombat()
{
	if (!this->has_Left_Combat_)
	{
		this->left_Combat_Display_Timer_.restart();

		this->has_Left_Combat_ = true;
	}
}

void DisplayMessage::render(sf::RenderTarget& target)
{
	if (this->is_Leveling_Up_)
	{
		this->level_Up_Text_.render(target);

		if (this->level_Up_display_Timer_.getElapsedTime().asSeconds() >= this->time_)
		{
			this->level_Up_Text_.setString("");

			this->is_Leveling_Up_ = false;
		}
	}

	if (this->is_Adding_Item_To_Bag_)
	{
		this->adding_Item_To_Bag_Text_.render(target);

		if (this->adding_Item_To_Bag_display_Timer_.getElapsedTime().asSeconds() >= this->time_)
		{
			this->is_Adding_Item_To_Bag_ = false;
		}
	}

	if (this->has_Left_Combat_)
	{
		this->left_Combat_Text_.render(target);

		if (this->left_Combat_Display_Timer_.getElapsedTime().asSeconds() >= this->time_)
		{
			this->has_Left_Combat_ = false;
		}
	}
}

void DisplayMessage::setIsLevelingUp(bool isLevelingUp)
{
	this->is_Leveling_Up_ = isLevelingUp;
}

const bool& DisplayMessage::getIsLevelingUp() const
{
	return this->is_Leveling_Up_;
}
