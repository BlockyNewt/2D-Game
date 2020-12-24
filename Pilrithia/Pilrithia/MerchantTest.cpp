#include "MerchantTest.h"

MerchantTest::MerchantTest()
{
}

MerchantTest::MerchantTest(const sf::RenderWindow* window, ResourceFont* resourceFont, ResourceNpc* resourceNpc, ResourceItem* resourceItem)
{
	this->idle_Rect_ = sf::IntRect(0, 0, 64, 64);
	this->idle_Sheet_Width_ = 640;

	this->merchant_Model_.setSize(sf::Vector2f(64.f, 64.f));
	this->merchant_Model_.setPosition(sf::Vector2f(1300.f, 636.f));
	this->merchant_Model_.setFillColor(sf::Color::White);
	this->merchant_Model_.setTexture(resourceNpc->getNpcTexture(NPC_TEXTURE_TYPE_::TEST_MERCHANT_NPC_TEXTURE));
	this->merchant_Model_.setTextureRect(this->idle_Rect_);
	this->merchant_Model_.setScale(sf::Vector2f(-1.f, 1.f));
	this->merchant_Model_.setOrigin(sf::Vector2f(this->merchant_Model_.getGlobalBounds().width, 0.f));

	this->merchant_Range_.setSize(sf::Vector2f(100.f, 64.f));
	this->merchant_Range_.setPosition(sf::Vector2f(this->merchant_Model_.getPosition().x - 30, this->merchant_Model_.getPosition().y));
	this->merchant_Range_.setFillColor(sf::Color::Transparent);
	this->merchant_Range_.setOutlineThickness(1.f);
	this->merchant_Range_.setOutlineColor(sf::Color::Red);

	this->merchant_Name_ = "Test Merchant";
	this->t_A_.setSettings(resourceFont->getFont(FONT_TYPE::ARIAL), 18, this->merchant_Name_, sf::Vector2f(this->merchant_Model_.getGlobalBounds().left - 25.f, this->merchant_Model_.getGlobalBounds().top - 25.f), true);

	this->is_Within_Range_ = false;

	this->dialog_Box_Str_ = "I am a merchant. Click Expand to open up the shop.";
	this->dialog_Box_.setSettings(300.f, 200.f, this->merchant_Model_.getPosition().x - 300.f / 2.f, this->merchant_Model_.getPosition().y - 205, sf::Color(27, 133, 184), 1.f, sf::Color::Magenta, this->dialog_Box_Str_, resourceFont, true);
	this->dialog_Box_.setString(this->dialog_Box_Str_);

	this->shop_Box_ = new ShopBox(resourceFont, resourceItem, resourceNpc);

	this->camera_ = new Camera(0, 0);
}

MerchantTest::~MerchantTest()
{
	delete this->camera_;

	delete this->shop_Box_;
}

void MerchantTest::updatePollEvent(sf::Event& ev, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag, const int& playerBagMaxSizeX, const int& playerBagMaxSizeY)
{
	if (this->is_Within_Range_)
	{
		if (this->dialog_Box_.updatePollEvent(ev))
		{
			//OPEN UP BOX
			this->shop_Box_->setIsVisible(true);
			this->shop_Box_->alignPlayerBagItems(playerBag, playerBagMaxSizeX, playerBagMaxSizeY);
		}

		this->shop_Box_->updatePollEvent(ev, playerGold, playerSilver, playerCopper, playerBag);
	}
}

void MerchantTest::update(const sf::Vector2f& mousePositionView, const sf::Vector2i mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, const std::vector<Item*>& playerInventory, std::vector<std::vector<Item*>>& playerBag)
{
	this->animation_.update(this->merchant_Model_, this->idle_Rect_, this->idle_Sheet_Width_, 100.f);

	if (this->merchant_Range_.getGlobalBounds().intersects(playerBounds))
	{
		*this->camera_ = camera;

		this->is_Within_Range_ = true;

		if (!this->shop_Box_->getIsVisible())
		{
			this->dialog_Box_.setIsVisible(true);
			this->dialog_Box_.update(mousePositionView);
		}
		else
		{
			this->dialog_Box_.setIsVisible(false);
			this->shop_Box_->update(mousePositionWindow, playerInventory, playerBag);
		}
	}
	else
	{
		this->is_Within_Range_ = false;

		this->dialog_Box_.setIsVisible(false);
	}
}

void MerchantTest::render(sf::RenderTarget& target)
{
	this->t_A_.render(target);

	target.draw(this->merchant_Model_);
	target.draw(this->merchant_Range_);

	if (this->is_Within_Range_)
	{
		this->dialog_Box_.render(target);

		target.setView(sf::View(sf::FloatRect(0,0,target.getSize().x, target.getSize().y)));

		//SHOP BOX GOES HERE
		this->shop_Box_->render(target);

		target.setView(this->camera_->getView());
	}
}

const bool& MerchantTest::getIsShopBoxVisible() const
{
	return this->shop_Box_->getIsVisible();
}
