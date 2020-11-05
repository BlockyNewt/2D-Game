#include "PlayerTest.h"

PlayerTest::PlayerTest()
{
	this->race_ = new RaceOrc();
	this->race_->initializeRace(0.f, 0.f);
	this->race_->setPlayerClasses(this->race_->getClassesOne());


	this->name_ = "";

	this->player_Model_.setSize(sf::Vector2f(25.f, 50.f));
	this->player_Model_.setPosition(sf::Vector2f(60.f, 60.f));
	this->player_Model_.setFillColor(sf::Color::Cyan);

	this->next_Position_.setSize(sf::Vector2f(this->player_Model_.getSize().x, this->player_Model_.getSize().y));
	this->next_Position_.setPosition(sf::Vector2f(this->player_Model_.getPosition().x, this->player_Model_.getPosition().y));
	this->next_Position_.setFillColor(sf::Color::Transparent);
	this->next_Position_.setOutlineThickness(1.f);
	this->next_Position_.setOutlineColor(sf::Color::Red);
	
	this->velocity_.x = 0.f;
	this->velocity_.y = 0.f;
	this->movement_Speed_ = 200.f;
	this->gravity_ = 2.f;
	this->position_Before_Jump_ = 0.f;
	this->jump_Speed_ = 200.f;
	this->max_Jump_Height_ = 60.f;

	this->is_Falling_ = false;
	this->is_Jumping_ = false;
}

PlayerTest::~PlayerTest()
{
	//delete this->race_;
}

void PlayerTest::initializeCharacter(Race* race, const std::string& name)
{
	this->race_ = race;
	this->player_Model_.setFillColor(this->race_->getModel().getFillColor());
	this->player_Model_.setOutlineColor(this->race_->getModel().getOutlineColor());

	this->name_ = name;
	this->player_Hud_.intializeHud(this->name_, &this->race_->getPlayerClass());

	//WILL NEED TO INSERT CLASS STATS ONCE WE HAVE THOSE READY
	this->stats_.insert(std::make_pair("strength", 0));
	this->stats_.insert(std::make_pair("dexerity", 0));
	this->stats_.insert(std::make_pair("constitution", 0));
	this->stats_.insert(std::make_pair("intelligence", 0));
	this->stats_.insert(std::make_pair("perception", 0));
	this->stats_.insert(std::make_pair("wisdom", 0));

	this->resistances_.insert(std::make_pair("cold", 0));
	this->resistances_.insert(std::make_pair("fire", 0));
	this->resistances_.insert(std::make_pair("lightning", 0));
	this->resistances_.insert(std::make_pair("poison", 0));
}

void PlayerTest::initializeHud()
{
}

void PlayerTest::updatePollEvent(sf::Event& ev, const float& dt)
{
	/*
		PLAYER HUD POLL UPDATES
	*/
	
	this->player_Hud_.updateInventoryPollEvent(ev, this->name_, this->race_->getPlayerClass().getName(), this->stats_, this->resistances_);
	this->player_Hud_.updatePollEvent(ev);

	if (!this->is_Falling_ && !this->is_Jumping_)
	{
		this->velocity_.y = 0.f;
	}
	
	this->velocity_.x = 0.f;


	/*
		MOVEMENT POLL UPDATES
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->is_Jumping_)
	{
		this->velocity_.y += -this->movement_Speed_ * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->velocity_.y += this->movement_Speed_ * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->velocity_.x += -this->movement_Speed_ * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->velocity_.x += this->movement_Speed_ * dt;
	}

	/*
		JUMP POLL UPDATE
	*/
	if (ev.type == sf::Event::KeyPressed && !this->is_Falling_)
	{
		if (ev.key.code == sf::Keyboard::Space)
		{
			this->is_Jumping_ = true;
			this->velocity_.y += -this->jump_Speed_ * dt;
		}
	}
}

void PlayerTest::update(const sf::Vector2i& mousePositionWindow, const Camera& camera)
{
	player_Model_.move(this->velocity_);

	this->next_Position_Bounds_ = this->player_Model_.getGlobalBounds();
	this->next_Position_Bounds_.left += this->velocity_.x;
	this->next_Position_Bounds_.top += this->velocity_.y;



	if (!this->is_Jumping_)
	{
		this->position_Before_Jump_ = this->player_Model_.getGlobalBounds().top;
	}

	if (this->is_Jumping_ && this->player_Model_.getGlobalBounds().top - this->position_Before_Jump_ <= -this->max_Jump_Height_)
	{
		//std::cout << "jumping" << std::endl;

		this->is_Jumping_ = false;
		this->is_Falling_ = true;
		this->velocity_.y = 0.f;
	}

	if (this->is_Falling_)
	{
		this->velocity_.y += this->gravity_;
	}
	
	this->next_Position_.setPosition(this->next_Position_Bounds_.left, this->next_Position_Bounds_.top);

	this->player_Hud_.update(mousePositionWindow, camera, this->player_Model_.getPosition());
}

void PlayerTest::render(sf::RenderTarget& target)
{
	target.draw(this->next_Position_);
	target.draw(this->player_Model_);

	this->player_Hud_.render(target);
}

void PlayerTest::setPosition(float x, float y)
{
	this->player_Model_.setPosition(sf::Vector2f(x, y));
}

void PlayerTest::setVelocityX(float x)
{
	this->velocity_.x = x;
}

void PlayerTest::setVelocityY(float y)
{
	this->velocity_.y = y;
}

void PlayerTest::setIsFalling(bool isFalling)
{
	this->is_Falling_ = isFalling;
}

void PlayerTest::setIsJumping(bool isJumping)
{
	this->is_Jumping_ = isJumping;
}

sf::RectangleShape& PlayerTest::getPlayerModel()
{
	return this->player_Model_;
}

const sf::Vector2f& PlayerTest::getVelocity() const
{
	return this->velocity_;
}

const sf::FloatRect PlayerTest::getPlayerGlobalBounds() const
{
	return this->player_Model_.getGlobalBounds();
}

const sf::FloatRect PlayerTest::getNextPositionGlobalBounds() const
{
	return this->next_Position_Bounds_;
}

const bool& PlayerTest::getIsFalling() const
{
	return this->is_Falling_;
}

const bool& PlayerTest::getIsJumping() const
{
	return this->is_Jumping_;
}
