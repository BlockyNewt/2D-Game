#ifndef GATHER_H
#define GATHER_H

#include "ResourceFont.h"
#include "ResourceHud.h"

#include "ItemTest.h"

#include <vector>

enum class GATHERTYPE
{
	MINING, 
	FORESTING,
	HARVESTING
};

class Gather
{
public:
	Gather();
	Gather(GATHERTYPE gatherType, const sf::Vector2f& position, ResourceFont* resourceFont, ResourceHud* resourceHud, ResourceItem* resourceItem);
	virtual ~Gather();

	virtual void updatePollEvent(sf::Event& ev) = 0;
	virtual void update(const sf::Vector2i& mousePositionWindow, const sf::FloatRect playerbounds, std::vector<Item*>& playerGatheredItems) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual void setWidthOfGatherBar() = 0;

	virtual Item* getItem() = 0;
	virtual const bool& getIsGathered() const = 0;

private:

private:

};

#endif // !GATHER_H
