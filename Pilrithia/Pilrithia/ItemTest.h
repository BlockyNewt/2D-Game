#ifndef ITEMTEST_H
#define ITEMTEST_H

#include "Item.h"

class ItemTest
	: public Item
{
public:
	ItemTest();
	ItemTest(float posX, float posY, ITEMTYPE itemType);
	virtual ~ItemTest();

	void setItemHoverDescriptionSettings(HOVERPOSITION hoverPosition, const sf::FloatRect boundaries, const sf::FloatRect boundariesOffset, DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description) override;

	bool updatePollEvent(sf::Event& ev) override;
	bool update(const sf::Vector2i& mousePositionWindow) override;
	void render(sf::RenderTarget& target) override;

	const sf::FloatRect getItemGlobalBoundaries() const override;
	const ITEMTYPE& getItemType() const override;
	const Button& getButton() const override;

private:
	
private:
	Button b_A_;

	Text t_A_;

	HoverDescription d_A_;

	ITEMTYPE item_Type_;

};

#endif // !ITEMTEST_H
