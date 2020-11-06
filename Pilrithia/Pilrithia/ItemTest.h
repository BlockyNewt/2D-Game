#ifndef ITEMTEST_H
#define ITEMTEST_H

#include "Item.h"

class ItemTest
	: public Item
{
public:
	ItemTest();
	ItemTest(float posX, float posY);
	virtual ~ItemTest();

	bool updatePollEvent(sf::Event& ev) override;
	bool update(const sf::Vector2i& mousePositionWindow) override;
	void render(sf::RenderTarget& target) override;

	const sf::FloatRect getItemGlobalBoundaries() const override;

private:
	
private:
	Button b_A_;

	Text t_A_;

	ITEMTYPE item_Type_;

};

#endif // !ITEMTEST_H
