#ifndef ITEMTEST_H
#define ITEMTEST_H

#include "Item.h"

class ItemTest
	: public Item
{
public:
	ItemTest();
	ItemTest(float posX, float posY, ITEMTYPE itemType, const std::string& name, const std::string& description, ResourceFont* resourceFont, ResourceItem* resourceItem);
	virtual ~ItemTest();

	void setItemHoverDescriptionSettings(HOVERPOSITION hoverPosition, const sf::FloatRect boundaries, const sf::FloatRect boundariesOffset, DESCRIPTIONTYPE descriptionType, const std::string& title, const std::string& description) override;
	void increaseStatsOnEquip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances);
	void descreaseStatsOnUnequip(std::map<std::string, int>& stats, std::map<std::string, int>& resistances);


	bool updatePollEvent(sf::Event& ev) override;
	bool update(const sf::Vector2i& mousePositionWindow) override;
	void render(sf::RenderTarget& target) override;

	void setPosition(const sf::Vector2f& position);
	int& setGoldPrice() override;
	int& setSilverPrice() override;
	int& setCopperPrice() override;
	int& setQuantity() override;
	void setShowGatherBox(bool showGatherBox) override;

	const sf::FloatRect getItemGlobalBoundaries() const override;
	const ITEMTYPE& getItemType() const override;
	const Button& getButton() const override;
	const std::string& getName()const override;
	const std::string& getDescription()const override;
	const sf::FloatRect getHoverDescriptionGlobalBounds() const override;
	Item* getNewItem() override;
	const int& getGoldPrice() const override;
	const int& getSilverPrice() const override;
	const int& getCopperPrice() const override;
	const sf::Vector2f& getPosition() const override;
	const sf::FloatRect getItemRange() const override;
	const int& getQuantity() const override;
	

private:
	
private:
	Button b_A_;
	Text t_A_;
	Text t_B_;

	sf::RectangleShape item_Range_;

	HoverDescription d_A_;

	ITEMTYPE item_Type_;

	std::string name_;
	std::string description_;

	int health_Max_;
	int mana_Max_;
	int strength_;
	int dexerity_;
	int constitution_;
	int intelligence_;
	int perception_;
	int wisdom_;

	int cold_;
	int fire_;
	int lightning_;
	int poison_;

	int gold_Price_;
	int silver_Price_;
	int copper_Price_;

	int quantity_;
	bool is_Gather_Box_;
	
	ResourceFont* resource_Font_;
	ResourceItem* resource_Item_;
};

#endif // !ITEMTEST_H
