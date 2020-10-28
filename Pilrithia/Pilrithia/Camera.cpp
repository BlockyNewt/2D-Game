#include "Camera.h"

Camera::Camera(const unsigned sizeX, const unsigned sizeY)
{
	this->camera_.setSize(sf::Vector2f(sizeX, sizeY));

	this->camera_.setCenter(sf::Vector2f(this->camera_.getSize().x / 2.f, this->camera_.getSize().y / 2.f));
}

Camera::~Camera()
{
}

void Camera::updatePollEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::W)
		{
			this->camera_.move(sf::Vector2f(0.f, -15.f));
		}
		else if (ev.key.code == sf::Keyboard::S)
		{
			this->camera_.move(sf::Vector2f(0.f, 15.f));
		}
		
		if (ev.key.code == sf::Keyboard::A)
		{
			this->camera_.move(sf::Vector2f(-15.f, 0.f));
		}
		else if (ev.key.code == sf::Keyboard::D)
		{
			this->camera_.move(sf::Vector2f(15.f, 0.f));
		}
	}
	else if (ev.type == sf::Event::MouseWheelScrolled)
	{
		//WILL NEED TO CHANGE THE VALUES LATER IN CASE SOMEONE CHANGES RESOLUTION
		if (ev.mouseWheelScroll.delta == 1)
		{
			this->camera_.setSize(sf::Vector2f(this->camera_.getSize().x - 128.f, this->camera_.getSize().y - 72.f));
		}

		if (ev.mouseWheelScroll.delta == -1)
		{
			this->camera_.setSize(sf::Vector2f(this->camera_.getSize().x + 128.f, this->camera_.getSize().y + 72.f));
		}
	}
}

const sf::View& Camera::getView() const
{
	return this->camera_;
}
