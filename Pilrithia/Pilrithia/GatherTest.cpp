#include "GatherTest.h"

GatherTest::GatherTest()
{
}

GatherTest::GatherTest(GATHERTYPE gatherType, const sf::Vector2f& position, const ResourceFont& resourceFont, const ResourceHud& resourceHud, const ResourceItem& resourceItem)
{
	this->resource_Item_ = resourceItem;

	//std::cout << "x: " << position.x << " y: " << position.y << std::endl;

	this->gather_Time_ = 5.f;

	this->gather_Type_ = gatherType;

	this->item_ = NULL;

	this->t_B_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "", sf::Vector2f(0.f, 0.f), true);

	switch (gatherType)
	{
	case GATHERTYPE::MINING:
		//std::cout << "mining created" << std::endl;

		this->item_ = new ItemTest(position.x, position.y, ITEMTYPE::ORE, "Iron Vein", "This is used to craft various armors.", resourceFont, resourceItem);

		this->t_B_.setString("Mining");

		break;
	case GATHERTYPE::HARVESTING:
		//std::cout << "harvesting created" << std::endl;

		this->item_ = new ItemTest(position.x, position.y, ITEMTYPE::PLANT, "Herb", "This is used to craft various poitions.", resourceFont, resourceItem);
		
		this->t_B_.setString("Harvesting");

		break;
	case GATHERTYPE::FORESTING:
		//std::cout << "foresting created" << std::endl;

		this->item_ = new ItemTest(position.x, position.y, ITEMTYPE::WOOD, "Wood", "Empty for now.", resourceFont, resourceItem);
		
		this->t_B_.setString("Foresting");

		break;
	default:
		std::cout << "DEBUG::GATHERTEST::GATHERTEST() -> Something went wrong with the switch." << std::endl;
		break;
	}


	this->x_A_.setSettings(50.f, 50.f, this->item_->getPosition().x, this->item_->getPosition().y - 55.f, sf::Color::Red, 1.f, sf::Color::White, false);
	this->t_A_.setSettings(resourceFont.getFont(FONT_TYPE::ARIAL), 18, "E", sf::Vector2f(this->x_A_.getLeftPosition(true, 10.f), this->x_A_.getTopPosition(true, 10.f)), false);

	this->gather_Sprite_.setTexture(*resourceHud.getHudTexture(HUD_TEXTURE_TYPE_::GATHER));
	this->gather_Sprite_.setPosition(sf::Vector2f(this->item_->getItemGlobalBoundaries().left - 300.f / 2.f + this->item_->getItemGlobalBoundaries().width / 2.f, this->item_->getItemGlobalBoundaries().top - 120.f));

	this->gather_Bar_Back_.setSize(sf::Vector2f(300.f, 20.f));
	this->gather_Bar_Back_.setPosition(sf::Vector2f(this->gather_Sprite_.getGlobalBounds().left + 11.f, this->gather_Sprite_.getGlobalBounds().top + 47.f));
	this->gather_Bar_Back_.setFillColor(sf::Color::Black);
	this->gather_Bar_Back_.setOutlineThickness(1.f);
	this->gather_Bar_Back_.setOutlineColor(sf::Color::Black);

	this->gather_Bar_Front_.setSize(sf::Vector2f(0.f, 20.f));
	this->gather_Bar_Front_.setPosition(sf::Vector2f(this->gather_Sprite_.getGlobalBounds().left + 11.f, this->gather_Sprite_.getGlobalBounds().top + 47.f));
	this->gather_Bar_Front_.setFillColor(sf::Color::Yellow);
	this->gather_Bar_Front_.setOutlineThickness(1.f);
	this->gather_Bar_Front_.setOutlineColor(sf::Color::Yellow);

	this->t_B_.setPosition(this->gather_Sprite_.getGlobalBounds().left + this->gather_Sprite_.getGlobalBounds().width / 2.f - 30.f, this->gather_Sprite_.getGlobalBounds().top + 5.f);

	

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
		if (this->item_ != NULL)
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

							if (this->gather_Type_ == GATHERTYPE::MINING)
							{
								if (this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->getStatus() != sf::Sound::Playing)
								{
									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->setLoop(true);
									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->play();
								}
							}
							else if (this->gather_Type_ == GATHERTYPE::HARVESTING)
							{
								if (this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->getStatus() != sf::Sound::Playing)
								{
									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->setLoop(true);
									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->play();
								}
							}
							else if (this->gather_Type_ == GATHERTYPE::FORESTING)
							{
								if (this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->getStatus() != sf::Sound::Playing)
								{
									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->setLoop(true);
									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->play();
								}
							}
							else
							{
								std::cout << "DEBUG::GATHERTEST::UPDATEPOLLEVENT() -> Something went wrong with playing sound." << std::endl;
							}
						}
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
		if (this->item_ != NULL)
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
								//WILL ADD THE COLLECTED RESOURCE QUANTITY TO PLAYERS CURRENT QUANTITY BASED ON THE RESOURCE TYPE
								if (this->gather_Type_ == GATHERTYPE::MINING &&
									i->getItemType() == ITEMTYPE::ORE)
								{
									i->setQuantity() += this->item_->getQuantity();

									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->stop();

									this->is_Gathered_ = true;

									break;
								}
								else if (this->gather_Type_ == GATHERTYPE::FORESTING &&
									i->getItemType() == ITEMTYPE::WOOD)
								{
									i->setQuantity() += this->item_->getQuantity();

									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->stop();

									this->is_Gathered_ = true;

									break;
								}
								else if (this->gather_Type_ == GATHERTYPE::HARVESTING &&
									i->getItemType() == ITEMTYPE::PLANT)
								{
									i->setQuantity() += this->item_->getQuantity();

									this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->stop();

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

				if (this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->getStatus() == sf::Sound::Playing)
				{
					this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->setLoop(false);
					this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_MINE)->stop();

				}
				else if (this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->getStatus() == sf::Sound::Playing)
				{
					this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->setLoop(false);
					this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_PLANT)->stop();
				}
				else if (this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->getStatus() == sf::Sound::Playing)
				{
					this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->setLoop(false);
					this->resource_Item_.getItemSound(ITEM_SOUND_TYPE_::GATHER_CHOP)->stop();
				}
			}
		}
	}
}

void GatherTest::render(sf::RenderTarget& target)
{
	if (!this->is_Gathered_)
	{
		if (this->item_ != NULL)
		{
			this->item_->render(target);
		}
		
		if (this->is_Collecting_)
		{
			target.draw(this->gather_Bar_Back_);
			target.draw(this->gather_Bar_Front_);

			target.draw(this->gather_Sprite_);

			this->t_B_.render(target);
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
	this->gather_Bar_Front_.setSize(sf::Vector2f((this->gather_Timer_.getElapsedTime().asSeconds() / this->gather_Time_) * 300.f, this->gather_Bar_Front_.getSize().y));
}

Item* GatherTest::getItem()
{
	return this->item_;
}

const bool& GatherTest::getIsGathered() const
{
	return this->is_Gathered_;
}
