#include "NpcTest.h"

NpcTest::NpcTest()
{
	this->npc_Model_.setSize(sf::Vector2f(30.f, 30.f));
	this->npc_Model_.setPosition(sf::Vector2f(30.f, 120.f));
	this->npc_Model_.setFillColor(sf::Color::Magenta);

	this->npc_Range_.setSize(sf::Vector2f(90.f, 30.f));
	this->npc_Range_.setPosition(sf::Vector2f(this->npc_Model_.getPosition().x - 30, this->npc_Model_.getPosition().y));
	this->npc_Range_.setFillColor(sf::Color::Transparent);
	this->npc_Range_.setOutlineThickness(1.f);
	this->npc_Range_.setOutlineColor(sf::Color::Red);

	this->dialog_Box_.setSettings(300.f, 200.f, this->npc_Model_.getPosition().x - 300.f / 2.f, this->npc_Model_.getPosition().y - 205, sf::Color::Blue, 1.f, sf::Color::Magenta, false);

	this->is_Within_Range_ = false;

	this->camera_ = new Camera(0.f, 0.f);

}

NpcTest::~NpcTest()
{
	delete this->camera_;
}

void NpcTest::setSettings(const sf::Vector2u& windowSize)
{
	//this->quest_Box_.setSettings(windowSize.x / 2.f, windowSize.y / 2.f, sf::Color::Red, 1.f, sf::Color::Green, false);
	this->quest_Box_.setSettings(windowSize.x / 2.f, windowSize.y / 2.f, sf::Color::Red, 1.f, sf::Color::Green);

}

void NpcTest::updatePollEvent(sf::Event& ev)
{
	if (this->is_Within_Range_)
	{
		if (this->dialog_Box_.updatePollEvent(ev))
		{
			if (!this->quest_Box_.getIsVisible())
			{
				std::cout << "enabling" << std::endl;
				this->quest_Box_.setIsVisible(true);
			}
		}

		//WHEN QUESTS ARE ADDED LATER, MAKE THIS INTO AN IF STATEMENT AND IF RETURN TRUE
		//THEN ADD TO QUEST VECTOR
		if (this->quest_Box_.updatePollEvent(ev))
		{
			this->dialog_Box_.setIsVisible(true);
			this->quest_Box_.setIsVisible(false);
		}
	}
}

void NpcTest::update(const sf::Vector2f& mousePositionView, const sf::Vector2i& mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera)
{
	if (this->npc_Range_.getGlobalBounds().intersects(playerBounds))
	{
		*this->camera_ = camera;

		//std::cout << "WITHIN RANGE OF NPC" << std::endl;
		this->is_Within_Range_ = true;

		if (!this->quest_Box_.getIsVisible())
		{
			this->dialog_Box_.setIsVisible(true);
			this->dialog_Box_.update(mousePositionView);

		}
		else
		{
			this->dialog_Box_.setIsVisible(false);

			this->quest_Box_.update(mousePositionWindow);
		}

	}
	else
	{
		this->is_Within_Range_ = false;
		this->dialog_Box_.setIsVisible(false);

	}
}

void NpcTest::render(sf::RenderTarget& target)
{
	target.draw(this->npc_Range_);
	target.draw(this->npc_Model_);

	if (this->is_Within_Range_)
	{
		this->dialog_Box_.render(target);

		target.setView(target.getDefaultView());

		this->quest_Box_.render(target);

		target.setView(this->camera_->getView());
	}
	
}
