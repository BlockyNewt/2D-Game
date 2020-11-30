#ifndef MERCHANT_H
#define MERCHANT_H

#include "Camera.h"

#include "DialogBox.h"
#include "ShopBox.h"

#include <iostream>
#include <string>

class Merchant
{
public:
	Merchant();
	Merchant(const ResourceFont& resourceFont);
	virtual ~Merchant();

	virtual void updatePollEvent(sf::Event& ev, int& playerGold, int& playerSilver, int& playerCopper, std::vector<std::vector<Item*>>& playerBag, const int& playerBagMaxSizeX, const int& playerBagMaxSizeY) = 0;
	virtual void update(const sf::Vector2f& mousePositionView, const sf::Vector2i mousePositionWindow, sf::FloatRect playerBounds, const Camera& camera, const std::vector<Item*>& playerInventory, std::vector<std::vector<Item*>>& playerBag) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
	virtual const bool& getIsShopBoxVisible() const = 0;


private:

private:

};

#endif // !MERCHANT_H
