#ifndef GATHERTEST_H
#define GATHERTEST_H

#include "Gather.h"

class GatherTest
	: public Gather
{
public:
	GatherTest();
	GatherTest(GATHERTYPE gatherType, const ResourceFont& resourceFont, const ResourceHud& resourceHud);
	virtual ~GatherTest();

	void updatePollEvent(sf::Event& ev) override;
	void update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect playerbounds, std::vector<Item*>& playerGatheredItems) override;
	void render(sf::RenderTarget& target) override;

	void setWidthOfGatherBar() override;

	Item* getItem() override;
	const bool& getIsGathered() const override;


private:

private:
	Item* item_;

	Box x_A_;
	Text t_A_;

	sf::RectangleShape gather_Bar_Front_;
	sf::RectangleShape gather_Bar_Back_;
	sf::Sprite gather_Sprite_;

	GATHERTYPE gather_Type_;

	float gather_Time_;
	sf::Clock gather_Timer_;

	bool is_Within_Range_;

	bool is_Collecting_;
	bool is_Gathered_;
};

#endif // !GATHERTEST_H
