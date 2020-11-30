#ifndef MERCHANTTEST_H
#define MERCHANTTEST_H

#include "Merchant.h"

class MerchantTest 
	: public Merchant
{
public:
	MerchantTest();
	MerchantTest(const ResourceFont& resourceFont);
	virtual ~MerchantTest();

	void updatePollEvent(sf::Event& ev, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag, const int& playerBagMaxSizeX, const int& playerBagMaxSizeY) override;
	void update(const sf::Vector2f& mousePositionView, const sf::Vector2i mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, const std::vector<Item*>& playerInventory, std::vector<std::vector<Item*>>& playerBag) override;
	void render(sf::RenderTarget& target) override;
	const bool& getIsShopBoxVisible() const override;

private:

private:
	sf::RectangleShape merchant_Model_;
	sf::RectangleShape merchant_Range_;

	std::string merchant_Name_;
	Text t_A_;
	bool is_Within_Range_;

	DialogBox dialog_Box_;
	std::string dialog_Box_Str_;

	ShopBox* shop_Box_;

	Camera* camera_;
};

#endif // !MERCHANTTEST_H
