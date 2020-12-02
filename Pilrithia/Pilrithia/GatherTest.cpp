#include "GatherTest.h"

GatherTest::GatherTest()
{
}

GatherTest::GatherTest(GATHERTYPE gatherType, const ResourceFont& resourceFont)
{
	this->item_ = new ItemTest(400.f, 400.f, ITEMTYPE::ORE, "Iron Vein", "This is used to craft various armors.", resourceFont);

	this->x_A_.setSettings(50.f, 50.f, this->item_->getPosition().x, this->item_->getPosition().y - 55.f, sf::Color::Red, 1.f, sf::Color::White, false);
	this->t_A_.setSettings(resourceFont.getFont(FONTTYPE::ARIAL), 18, "E", sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 10.f)), false);

	this->gather_Bar_Back_.setSize(sf::Vector2f(200.f, 20.f));
	this->gather_Bar_Back_.setPosition(sf::Vector2f(this->x_A_.getLeftPosition(), this->x_A_.getTopPosition(false, 10.f)));
	this->gather_Bar_Back_.setFillColor(sf::Color::White);
	this->gather_Bar_Back_.setOutlineThickness(1.f);
	this->gather_Bar_Back_.setOutlineColor(sf::Color::White);

	this->gather_Bar_Front_.setSize(sf::Vector2f(0.f, 10.f));
	this->gather_Bar_Front_.setPosition(sf::Vector2f(this->gather_Bar_Back_.getGlobalBounds().left, this->gather_Bar_Back_.getGlobalBounds().top + 5.f));
	this->gather_Bar_Front_.setFillColor(sf::Color::Yellow);
	this->gather_Bar_Front_.setOutlineThickness(1.f);
	this->gather_Bar_Front_.setOutlineColor(sf::Color::Yellow);

	this->gather_Time_ = 5.f;

	this->gather_Type_ = gatherType;

	switch (gatherType)
	{
	case GATHERTYPE::MINING:
		//DO SOMETHING
		break;
	case GATHERTYPE::FORESTING:
		//DO SOMETHING
		break;
	case GATHERTYPE::HARVESTING:
		//DO SOMETHING
		break;
	default:
		std::cout << "DEBUG::GATHERTEST::GATHERTEST() -> Something went wrong with the switch." << std::endl;
		break;
	}

	this->is_Within_Range_ = false;

	this->is_Collecting_ = false;
	this->is_Gathered_ = false;
}

GatherTest::~GatherTest()
{
	delete this->item_;
}

void GatherTest::updatePollEvent(sf::Event& ev)
{
	
	if (!this->is_Gathered_)
	{
		if (!this->is_Collecting_)
		{
			if (this->is_Within_Range_)
			{
				if (ev.type == sf::Event::KeyPressed)
				{
					if (ev.key.code == sf::Keyboard::E)
					{
						this->is_Collecting_ = true;
						this->gather_Timer_.restart();
					}
				}
			}
		}
	}
}

void GatherTest::update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect playerbounds, std::vector<Item*>& playerGatheredItems)
{
	if (!this->is_Gathered_)
	{
		if (this->item_->getItemRange().intersects(playerbounds))
		{
			this->x_A_.setIsVisible(true);
			this->t_A_.setIsVisible(true);

			this->is_Within_Range_ = true;

			if (this->is_Collecting_)
			{
				this->setWidthOfGatherBar();

				if (this->gather_Timer_.getElapsedTime().asSeconds() >= this->gather_Time_)
				{
					//TAKE RESOURCES
					for (auto& i : playerGatheredItems)
					{
						if (i != NULL)
						{
							if (this->item_->getItemType() == ITEMTYPE::ORE)
							{
								i->setOreQuantity() += this->item_->getOreQuantity();

								this->is_Gathered_ = true;

								break;
							}
							else if (this->item_->getItemType() == ITEMTYPE::WOOD)
							{
								i->setOreQuantity() += this->item_->getWoodQuantity();

								this->is_Gathered_ = true;

								break;
							}
							else if (this->item_->getItemType() == ITEMTYPE::PLANT)
							{
								i->setOreQuantity() += this->item_->getPlantQuantity();

								this->is_Gathered_ = true;

								break;
							}
							else
							{
								std::cout << "DEBUG::GATHERTEST::UPDATEPOLLEVENT() -> Item type is invalid." << std::endl;
							}
						}
					}

					this->is_Collecting_ = false;
					this->is_Gathered_ = true;
				}
			}

			//std::cout << "DEBUG::GATHERTEST::UPDATE() -> Player is within bounds." << std::endl;
		}
		else
		{
			this->x_A_.setIsVisible(false);
			this->t_A_.setIsVisible(false);

			this->is_Within_Range_ = false;

			this->is_Collecting_ = false;
		}
	}
	
}

void GatherTest::render(sf::RenderTarget& target)
{
	if (!this->is_Gathered_)
	{
		this->item_->render(target);

		
		
		if (this->is_Collecting_)
		{
			target.draw(this->gather_Bar_Back_);
			target.draw(this->gather_Bar_Front_);
		}
		else
		{
			this->x_A_.render(target);
			this->t_A_.render(target);
		}
	}
}

void GatherTest::setWidthOfGatherBar()
{
	this->gather_Bar_Front_.setSize(sf::Vector2f((this->gather_Timer_.getElapsedTime().asSeconds() / this->gather_Time_) * 200.f, this->gather_Bar_Front_.getSize().y));
}

Item* GatherTest::getItem()
{
	return this->item_;
}

const bool& GatherTest::getIsGathered() const
{
	return this->is_Gathered_;
}
