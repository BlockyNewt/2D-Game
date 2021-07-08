#include "ZoneTest.h"

ZoneTest::ZoneTest()
{
	/*
		WILL NOT BE USING THIS CONSTRUCTOR
	*/
}

ZoneTest::ZoneTest(sf::RenderWindow* window, ResourceFont* resourceFont, ResourceEnemy* resourceEnemy, ResourceNpc* resourceNpc, ResourceItem* resourceItem, ResourceHud* resourceHud)
{
	std::cout << "DEBUG::ZONETEST::ZONETEST() -> ZoneTest created." << std::endl;

	this->window_ = window;
	this->resource_Font_ = resourceFont;
	this->resource_Enemy_ = resourceEnemy;
	this->resource_Item_ = resourceItem;
	this->resource_Hud_ = resourceHud;

	this->tilemap_ = new Tilemap(20, 20, 50, 2);
	this->tilemap_->load("s");

	this->npc_Test_ = new NpcTest(window, resourceFont, resourceNpc);
	this->npc_Test_->setSettings(window->getSize(), *resourceFont);

	this->max_Enemies_ = 1;
	this->enemy_Test_ = new EnemyTest(sf::Vector2f(600.f, 120.f), 3, window, resourceFont, resourceEnemy, resourceItem);

	this->enemies_.push_back(this->enemy_Test_);

	this->merchant_Test_ = new MerchantTest(window, resourceFont, resourceNpc, resourceItem);

	//WILL HAVE TO CHANGE LOCATION LATER
	this->teleporter_Rec_.setPosition(sf::Vector2f(1400.f, 650.f));
	this->teleporter_Rec_.setSize(sf::Vector2f(50.f, 50.f));
	this->teleporter_Rec_.setFillColor(sf::Color::Red);

	this->gather_Type_Increment_ = 0;
}

ZoneTest::~ZoneTest()
{
	delete this->tilemap_;
	delete this->npc_Test_;
	delete this->merchant_Test_;

	for (int i = 0; i < this->enemies_.size(); ++i)
	{
		if (this->enemies_[i] != NULL)
		{
			delete this->enemies_[i];
			this->enemies_[i] = NULL;
			this->enemies_.erase(this->enemies_.begin() + i);
		}
	}

	std::cout << "DEBUG::ZONETEST::~ZONETEST() -> ZoneTest deconstructed." << std::endl;
}

void ZoneTest::zoneUpdatePollEvent(sf::Event& ev, PlayerTest* playerTest)
{
	for (auto& e : this->enemies_)
	{
		e->updatePollEvent(ev, playerTest->setPlayerBag().setItem(), playerTest->getPlayerBag().getBagSizeX(), playerTest->getPlayerBag().getBagSizeY(), playerTest->getPlayerModel().getGlobalBounds());
	}
}

void ZoneTest::zoneUpdate(const sf::Vector2i& mousePositionWindow, Camera** camera, PlayerTest* playerTest, const float& dt)
{
	/*
		1. UPDATE ENEMIES
		2. UPDATE TILEMAP
		3. UPDATE BOUNDARIES FOR BOTH PLAYER AND ENEMIES
		4. OTHER NEEDED THINGS
	*/
	this->tilemap_->PlayerCollision(*playerTest);

	for (int i = 0; i < this->enemies_.size(); ++i)
	{
		if (this->enemies_[i] != NULL)
		{
			this->tilemap_->EnemyCollision(*this->enemies_[i]);
		}
	}

	this->updateEnemies(mousePositionWindow, camera, playerTest, dt);

	this->updateGather(mousePositionWindow, playerTest);
}

void ZoneTest::zoneRender(sf::RenderTarget& target)
{
	this->tilemap_->render(target);

	for (auto& e : this->enemies_)
	{
		if (e != NULL)
		{
			e->render(target);
		}
	}

	for (auto& g : this->gathers_)
	{
		if (g != NULL)
		{
			g->render(target);
		}
	}

	this->npc_Test_->render(target);

	this->merchant_Test_->render(target);
}

void ZoneTest::updateEnemies(const sf::Vector2i& mousePositionWindow, Camera** camera, PlayerTest* playerTest, const float& dt)
{
	//ENEMY HANDLING
	for (int i = 0; i < this->enemies_.size(); ++i)
	{
		this->tilemap_->EnemyCollision(*this->enemies_[i]);

		this->enemies_[i]->update(mousePositionWindow, camera, playerTest->getPlayerModel().getGlobalBounds(), dt, playerTest->getStatForChange("health"), playerTest->setExp(), playerTest->setIsCombat(), playerTest->setPlayerHud().setLeaveCombatTimer());


		//this->player_Test_->updateEnemyAutoSelector(this->enemies_[i]);

		if (this->enemies_[i]->getIsDead())
		{
			delete this->enemies_[i];
			this->enemies_.erase(this->enemies_.begin() + i);
		}
	}

	if (this->enemies_.size() < this->max_Enemies_)
	{
		this->enemies_.push_back(new EnemyTest(sf::Vector2f(600.f, 120.f), 3, this->window_, this->resource_Font_, this->resource_Enemy_, this->resource_Item_));
	}
}

void ZoneTest::updateGather(const sf::Vector2i& mousePositionWindow, PlayerTest* playerTest)
{
	for (int i = 0; i < this->gathers_.size(); ++i)
	{
		this->gathers_[i]->update(mousePositionWindow, playerTest->getPlayerModel().getGlobalBounds(), playerTest->setPlayerGather().setGatheredItems());

		if (this->gathers_[i]->getIsGathered())
		{
			delete this->gathers_[i];
			this->gathers_.erase(this->gathers_.begin() + i);
		}
	}

	if (this->gathers_.size() < 1)
	{
		switch (this->gather_Type_Increment_)
		{
		case 1:
			this->gathers_.push_back(new GatherTest(GATHERTYPE::MINING, sf::Vector2f(400.f, 400.f), this->resource_Font_, this->resource_Hud_, this->resource_Item_));
			break;
		case 2:
			this->gathers_.push_back(new GatherTest(GATHERTYPE::HARVESTING, sf::Vector2f(100.f, 600.f), this->resource_Font_, this->resource_Hud_, this->resource_Item_));
			break;
		case 3:
			this->gathers_.push_back(new GatherTest(GATHERTYPE::FORESTING, sf::Vector2f(850.f, 600.f), this->resource_Font_, this->resource_Hud_, this->resource_Item_));
			break;
		default:
			break;
		}

		if (this->gather_Type_Increment_ == 3)
		{
			this->gather_Type_Increment_ = 0;
		}
		else
		{
			this->gather_Type_Increment_++;
		}
	}
}
