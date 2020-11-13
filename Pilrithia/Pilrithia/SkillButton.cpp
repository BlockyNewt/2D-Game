#include "SkillButton.h"

SkillButton::SkillButton()
{
	this->max_Amount_ = 3;
	this->amount_ = 0;

	this->stat_Increase_ = 0;

	this->cost_ = 0;
}

SkillButton::~SkillButton()
{
}

void SkillButton::setSettings(float radius, float x, float y, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, STATNAME statName, int statIncrease)
{
	this->button_.setRadius(radius);
	this->button_.setPosition(sf::Vector2f(x, y));
	this->button_.setFillColor(fillColor);
	this->button_.setOutlineThickness(outlineThickness);
	this->button_.setOutlineColor(outlineColor);

	this->fill_Color_ = fillColor;

	this->stat_Name_ = statName;

	this->stat_Increase_ = statIncrease;

	std::string title = "";
	std::string description = "";

	switch (this->stat_Name_)
	{
	case STATNAME::HEALTH:
		title = "Health";
		break;
	case STATNAME::MANA:
		title = "Mana";
		break;
	case STATNAME::STRENGTH:
		title = "Strength";
		break;
	case STATNAME::DEXERITY:
		title = "Dexerity";
		break;
	case STATNAME::CONSTITUTION:
		title = "Constitution";
		break;
	case STATNAME::INTELLIGENCE:
		title = "Intelligence";
		break;
	case STATNAME::PERCEPTION:
		title = "Perception";
		break;
	case STATNAME::WISDOM:
		title = "Wisdom";
		break;
	default:
		title = "Something went terribly fucking wrong for this to display.";
		break;
	}
	
	description = "Increase stat by " + std::to_string(this->stat_Increase_) + ".";

	this->t_A_.setSettings("Font/arial.ttf", 18, std::to_string(this->amount_), sf::Vector2f(this->getRightPosition(true, 10.f), this->getBottomPosition(false, 20.f)), true);
	this->h_A_.setHoverBoundaries(HOVERPOSITION::TOP, this->button_.getGlobalBounds(), this->button_.getGlobalBounds());
	this->h_A_.setString(DESCRIPTIONTYPE::SKILL, title, description);
}

void SkillButton::manageStatAllocation(bool pOrM, std::map<std::string, int>& stats)
{
	if (pOrM)
	{
		if (this->stat_Name_ == STATNAME::HEALTH)
		{
			stats.at("health") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::MANA)
		{
			stats.at("mana") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::STRENGTH)
		{
			stats.at("strength") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::DEXERITY)
		{
			stats.at("dexerity") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::CONSTITUTION)
		{
			stats.at("constitution") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::INTELLIGENCE)
		{
			stats.at("intelligence") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::PERCEPTION)
		{
			stats.at("perception") += this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::WISDOM)
		{
			stats.at("wisdom") += this->stat_Increase_;
		}
	}
	else
	{
		if (this->stat_Name_ == STATNAME::HEALTH)
		{
			stats.at("health") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::MANA)
		{
			stats.at("mana") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::STRENGTH)
		{
			stats.at("strength") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::DEXERITY)
		{
			stats.at("dexerity") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::CONSTITUTION)
		{
			stats.at("constitution") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::INTELLIGENCE)
		{
			stats.at("intelligence") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::PERCEPTION)
		{
			stats.at("perception") -= this->stat_Increase_;
		}
		else if (this->stat_Name_ == STATNAME::WISDOM)
		{
			stats.at("wisdom") -= this->stat_Increase_;
		}
	}
}

void SkillButton::updatePollEvent(sf::Event& ev, std::map<std::string, int>& stats)
{
	/*
		IF YOU ARE HOVERING THEN YOU CANT CLICK THE BUTTON
	*/
	if (this->is_Hovering_)
	{
		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.key.code == sf::Mouse::Left)
			{
				//std::cout << "Left mouse button is being pressed" << std::endl;
				if (this->amount_ < this->max_Amount_)
				{
					this->amount_++;

					this->is_Hovering_ = false;

					this->manageStatAllocation(true, stats);
				}
			}

			else if (ev.key.code == sf::Mouse::Right)
			{
				if (this->amount_ > 0)
				{
					this->is_Hovering_ = false;

					this->manageStatAllocation(false, stats);

					this->amount_--;
				}
			}
		}
	}
}

void SkillButton::update(const sf::Vector2i& mousePositionWindow)
{
	/*
		IF THE MOUSE POSITION OF THE WINDOW IS WITHIN THE BOUNDARIES OF THIS BUTTON THEN CHANGE THE COLOR
	*/
	this->t_A_.setString(std::to_string(this->amount_));

	this->h_A_.update(mousePositionWindow);

	if (this->button_.getGlobalBounds().contains(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y)))
	{
		//std::cout << "Within bounds." << std::endl;
		this->button_.setFillColor(sf::Color::Green);

		this->is_Hovering_ = true;
	}
	else
	{
		this->button_.setFillColor(this->fill_Color_);

		this->is_Hovering_ = false;
	}
}

void SkillButton::render(sf::RenderTarget& target)
{
	target.draw(this->button_);

	this->t_A_.render(target);

	this->h_A_.render(target);
}

const float SkillButton::getLeftPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().left + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().left - offset;
	}
}

const float SkillButton::getRightPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().left + this->button_.getGlobalBounds().width + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().left + this->button_.getGlobalBounds().width - offset;
	}
}

const float SkillButton::getTopPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().top + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().top - offset;
	}
}

const float SkillButton::getBottomPosition(bool pOrM, float offset) const
{
	/*
		pOrM STAND FOR "PLUS OR MINUS". TRUE FOR ADDING THE OFFSET OR MINUS FOR SUBTRACTING THE OFFSET
	*/
	if (pOrM)
	{
		return this->button_.getGlobalBounds().top + this->button_.getGlobalBounds().height + offset;
	}
	else
	{
		return this->button_.getGlobalBounds().top + this->button_.getGlobalBounds().height - offset;
	}
}