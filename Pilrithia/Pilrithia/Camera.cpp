#include "Camera.h"

Camera::Camera(const unsigned sizeX, const unsigned sizeY)
{
	this->camera_.setSize(sf::Vector2f(sizeX, sizeY));

	this->camera_.setCenter(sf::Vector2f(this->camera_.getSize().x / 2.f, this->camera_.getSize().y / 2.f));
}

Camera::~Camera()
{
}

void Camera::UpdatePollEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::W)
		{
			this->camera_.move(sf::Vector2f(0.f, -5.f));
		}

		if (ev.key.code == sf::Keyboard::S)
		{
			this->camera_.move(sf::Vector2f(0.f, 5.f));
		}

		if (ev.key.code == sf::Keyboard::A)
		{
			this->camera_.move(sf::Vector2f(-5.f, 0.f));
		}

		if (ev.key.code == sf::Keyboard::D)
		{
			this->camera_.move(sf::Vector2f(5.f, 0.f));
		}
	}
}

const sf::View& Camera::GetView() const
{
	return this->camera_;
}
