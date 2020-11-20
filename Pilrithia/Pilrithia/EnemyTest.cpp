#include "EnemyTest.h"

void EnemyTest::initializeStats()
{
	/*
		SET ALL STATS FOR THE ENEMY
	*/
	this->name_ = "Test Enemy";

	this->velocity_.x = 0.f;
	this->velocity_.y = 0.f;
	this->movement_Speed_ = 100.f;
	this->gravity_ = 6.f;

	this->health_Max_ = 15;
	this->health_ = this->health_Max_;
	this->mana_Max_ = 3;
	this->mana_ = this->mana_Max_;
	this->strength_ = 0;
	this->dexerity_ = 0;
	this->constitution_ = 0;
	this->intelligence_ = 0;
	this->perception_ = 0;
	this->wisdom_ = 0;

	this->cold_ = 0;
	this->fire_ = 0;
	this->lightning_ = 0;
	this->poison_ = 0;

}

void EnemyTest::initializeModel(const sf::Vector2f& position, const int& range)
{
	/*
		SET SIZE AND POSITION OF MODEL, NEXT POSITION, AND ATTACK RANGE 
	*/
	this->enemy_Model_.setSize(sf::Vector2f(25.f, 50.f));
	this->enemy_Model_.setPosition(position);
	this->enemy_Model_.setFillColor(sf::Color::Blue);
	this->enemy_Model_.setOutlineThickness(1.f);
	this->enemy_Model_.setOutlineColor(sf::Color::Transparent);

	this->next_Position_.setSize(sf::Vector2f(this->enemy_Model_.getSize().x, this->enemy_Model_.getSize().y));
	this->next_Position_.setPosition(sf::Vector2f(this->enemy_Model_.getPosition().x, this->enemy_Model_.getPosition().y));
	this->next_Position_.setFillColor(sf::Color::Transparent);
	this->next_Position_.setOutlineThickness(1.f);
	this->next_Position_.setOutlineColor(sf::Color::White);


	this->range_ = range;

	this->attack_Range_.setSize(sf::Vector2f(this->enemy_Model_.getSize().x * this->range_, this->enemy_Model_.getSize().y));
	this->attack_Range_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->attack_Range_.getSize().x / 2.f - this->enemy_Model_.getSize().x, this->enemy_Model_.getGlobalBounds().top));
	this->attack_Range_.setFillColor(sf::Color::Transparent);
	this->attack_Range_.setOutlineThickness(1.f);
	this->attack_Range_.setOutlineColor(sf::Color::Yellow);
}

void EnemyTest::initializeHealthBar()
{
	/*
		SET SIZE AND POSITION OF ENEMY HEALTH BAR
	*/
	this->health_Bar_Back_.setSize(sf::Vector2f(100.f, 10.f));
	this->health_Bar_Back_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->health_Bar_Back_.getSize().x / 2.f + 10.f, this->enemy_Model_.getGlobalBounds().top - this->health_Bar_Back_.getGlobalBounds().height - 5.f));
	this->health_Bar_Back_.setFillColor(sf::Color::White);
	this->health_Bar_Back_.setOutlineThickness(1.f);
	this->health_Bar_Back_.setOutlineColor(sf::Color::White);

	this->health_Bar_Front_.setPosition(sf::Vector2f(this->health_Bar_Back_.getPosition().x + 2.f, this->health_Bar_Back_.getPosition().y + 2.f));
	this->health_Bar_Front_.setSize(sf::Vector2f(this->health_Bar_Back_.getSize().x, this->health_Bar_Back_.getSize().y - 4.f));
	this->health_Bar_Front_.setFillColor(sf::Color::Green);
	this->health_Bar_Front_.setOutlineThickness(1.f);
	this->health_Bar_Front_.setOutlineColor(sf::Color::Green);
}

EnemyTest::EnemyTest()
{
	
}

EnemyTest::EnemyTest(const sf::Vector2f& position, const int& range)
{
	this->initializeStats();
	this->initializeModel(position, range);
	this->initializeHealthBar();

	this->t_A_.setSettings("Font/arial.ttf", 18, this->name_, sf::Vector2f(this->enemy_Model_.getPosition().x, this->enemy_Model_.getPosition().y), true);

	this->direction_ = DIRECTION::RIGHT;

	this->is_Bottom_Colliding_ = false;

	this->is_attack_Cooldown_ = false;
	this->is_Dead_ = false;
	
	this->loot_Timer_Max_ = 10.f;
	this->has_Loot_Timer_Started_ = false;

	this->camera_ = NULL;

	this->item_One_ = new ItemTest(0.f, 0.f, ITEMTYPE::HELM, "Helm", "Made from strong steel");
	this->item_Two_ = new ItemTest(0.f, 0.f, ITEMTYPE::LEG, "Leg", "Weaved pants");
	this->items_.push_back(this->item_One_);
	this->items_.push_back(this->item_Two_);

	this->loot_Window_.addEnemyItems(this->items_);
}

EnemyTest::~EnemyTest()
{
	
}

void EnemyTest::updatePollEvent(sf::Event& ev, std::vector<std::vector<Item*>>& playerBag, const int& maxBagSizeX, const int& maxBagSizeY)
{
	if (this->has_Loot_Timer_Started_)
	{
		//LOOT SHIT GOES HERE
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::E)
			{
				std::cout << "fucking pressing e bitch" << std::endl;
				this->loot_Window_.setIsVisible(true);
			}
		}

		this->loot_Window_.updatePollEvent(ev, playerBag, maxBagSizeX, maxBagSizeY);
	}
}

void EnemyTest::updateAutoMovement(const float& dt)
{
	/*
		AUTO MOVEMENT FOR ENEMY
	*/
	this->velocity_.x = 0.f;

	/*
		IF THE ENEMY IS TOUCHING THE TOP OF A TILE THEN ALLOW IT TO MOVE LEFT AND RIGHT
	*/
	if (this->is_Bottom_Colliding_)
	{
		this->velocity_.y = 0.f;

		if (this->direction_ == DIRECTION::RIGHT)
		{
			this->velocity_.x += this->movement_Speed_ * dt;
		}

		if (this->direction_ == DIRECTION::LEFT)
		{
			this->velocity_.x -= this->movement_Speed_ * dt;
		}
	}
	
	this->enemy_Model_.move(this->velocity_);

	this->next_Position_Bounds_ = this->enemy_Model_.getGlobalBounds();
	this->next_Position_Bounds_.left += this->velocity_.x;
	this->next_Position_Bounds_.top += this->velocity_.y;

	this->next_Position_.setPosition(sf::Vector2f(this->next_Position_Bounds_.left, this->next_Position_Bounds_.top));
}

void EnemyTest::updateHealth()
{
	/*
		IF HEALTH GOES BELOW 0 THEN SET IT TO 0
	*/
	if (this->health_ <= 0 && !this->has_Loot_Timer_Started_)
	{
		this->health_ = 0;
		//std::cout << "enemy has died." << std::endl;
		/*this->is_Dead_ = true;*/
		this->has_Loot_Timer_Started_ = true;
		this->loot_Timer_.restart();
	}
	

	if (this->has_Loot_Timer_Started_)
	{
		//std::cout << "Loot timer: " << this->loot_Timer_.getElapsedTime().asSeconds() << std::endl;
	}

	if (this->has_Loot_Timer_Started_ && 
		this->loot_Timer_.getElapsedTime().asSeconds() >= this->loot_Timer_Max_)
	{
		std::cout << "enemy is now dead" << std::endl;
		this->is_Dead_ = true;
	}

	

	/*
		MUST USE THIS FOR THE HEALTH BAR VALUES TO WORK
	*/
	float healthMaxToFloat = static_cast<float>(this->health_Max_);
	float healthToFloat = static_cast<float>(this->health_);

	this->health_Bar_Front_.setSize(sf::Vector2f((healthToFloat / healthMaxToFloat) * 95.f, this->health_Bar_Back_.getSize().y - 4.f));

	this->health_Bar_Back_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->health_Bar_Back_.getSize().x / 2.f + 10.f, this->enemy_Model_.getGlobalBounds().top - this->health_Bar_Back_.getGlobalBounds().height - 5.f));
	this->health_Bar_Front_.setPosition(sf::Vector2f(this->health_Bar_Back_.getPosition().x + 2.f, this->health_Bar_Back_.getPosition().y + 2.f));
}

void EnemyTest::update(const sf::Vector2i& mousePositionWindow, Camera** camera, const sf::FloatRect playerBounds, const float& dt, int& playerHealth)
{
	if (!this->has_Loot_Timer_Started_)
	{
		if (!this->attack_Range_.getGlobalBounds().intersects(playerBounds))
		{
			this->updateAutoMovement(dt);
		}
		else
		{
			/*
				IF ATTACK COOLDOWN IS FALSE THEN INFLICT DAMAGE TO PLAYER
			*/
			if (!this->is_attack_Cooldown_)
			{
				playerHealth -= 4;

				this->is_attack_Cooldown_ = true;
			}
		}
	}
	
	/*
		AFTER 4 SECONDS ATTACK COMES OFF OF COOLDOWN
	*/
	if (this->attack_Cooldown_Clock_.getElapsedTime().asSeconds() >= 4.f)
	{
		this->is_attack_Cooldown_ = false;

		this->attack_Cooldown_Clock_.restart();
	}


	this->attack_Range_.setPosition(sf::Vector2f(this->enemy_Model_.getGlobalBounds().left - this->attack_Range_.getSize().x / 2.f + this->enemy_Model_.getSize().x / 2.f, this->enemy_Model_.getGlobalBounds().top));

	this->updateHealth();

	this->t_A_.setPosition(this->health_Bar_Back_.getGlobalBounds().left, this->enemy_Model_.getGlobalBounds().top - 45.f);

	if (this->has_Loot_Timer_Started_)
	{
		this->camera_ = *camera;

		this->loot_Window_.update(mousePositionWindow);
	}
}

void EnemyTest::render(sf::RenderTarget& target)
{
	target.draw(this->next_Position_);

	target.draw(this->attack_Range_);

	target.draw(this->health_Bar_Back_);
	target.draw(this->health_Bar_Front_);

	target.draw(this->enemy_Model_);

	this->t_A_.render(target);

	if (this->has_Loot_Timer_Started_)
	{
		target.setView(target.getDefaultView());

		this->loot_Window_.render(target);
		
		target.setView(this->camera_->getView());
	}
}

void EnemyTest::setVelocityX(float x)
{
	this->velocity_.x = x;
}

void EnemyTest::setVelocityY(float y)
{
	this->velocity_.y = y;
}

void EnemyTest::setDirection(DIRECTION direction)
{
	this->direction_ = direction;
}

void EnemyTest::setIsBottomColliding(bool isBottomColliding)
{
	this->is_Bottom_Colliding_ = isBottomColliding;
}

void EnemyTest::setHealth(const int& damage)
{
	if (this->health_ > 0)
	{
		this->health_ -= damage;
	}
}

sf::RectangleShape& EnemyTest::getEnemyModel()
{
	return this->enemy_Model_;
}

const sf::FloatRect EnemyTest::getEnemyGlobalBounds() const
{
	return this->enemy_Model_.getGlobalBounds();
}

const sf::FloatRect EnemyTest::getNextPositionGlobalBounds()
{
	return this->next_Position_Bounds_;
}

const sf::Vector2f& EnemyTest::getVelocity() const
{
	return this->velocity_;
}

const float& EnemyTest::getGravity() const
{
	return this->gravity_;
}

const DIRECTION& EnemyTest::getDirection()
{
	return this->direction_;
}

const bool& EnemyTest::getIsBottomColliding() const
{
	return this->is_Bottom_Colliding_;
}

const bool& EnemyTest::getIsDead() const
{
	return this->is_Dead_;
}
