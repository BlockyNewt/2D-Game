#ifndef CAMERA_H
#define CAMERA_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>

class Camera
{
public:
	Camera(const unsigned sizeX, const unsigned sizeY);
	~Camera();

	void UpdatePollEvent(sf::Event& ev);

	const sf::View& GetView() const;

private:

private:
	sf::View camera_;
};

#endif // !CAMERA_H
