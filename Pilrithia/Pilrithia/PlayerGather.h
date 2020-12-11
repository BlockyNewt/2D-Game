#ifndef PLAYERGATHER_H
#define PLAYERGATHER_H

#include "GatherTest.h"

#include "Camera.h"

#include "ResourceFont.h"
#include "ResourceHud.h"

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "HoverDescription.h"

#include <vector>
#include <string>

class PlayerGather
{
public:
	PlayerGather(const sf::RenderWindow* window, const ResourceFont& resourceFont);
	~PlayerGather();

	void updatePollEvent(sf::Event& ev);
	void update(const sf::Vector2i& mousePositionWindow);
	void render(sf::RenderTarget& target);

	void setIsVisible(bool isVisible);
	std::vector<Item*>& setGatheredItems();
	void setPositionOnResize(const sf::RenderWindow* window);

	const bool& getIsVisible() const;


private:	

private:
	Box x_A_;
	Box x_B_;
	Text t_A_;

	Button b_B_;
	Text t_B_;

	bool is_Visible_;

	Item* ore_;
	Item* wood_;
	Item* plant_;

	std::vector<Item*> gathered_Items_;


};

#endif // !PLAYERGATHER_H
