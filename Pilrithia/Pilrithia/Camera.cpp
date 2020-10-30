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
	/*
		FOR NOW THIS FUNCTION WILL ONLY BE USED WITHIN THE STATEEDITOR.H
	*/

	/*
		MOVE CAMERA
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->camera_.move(sf::Vector2f(0.f, -15.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->camera_.move(sf::Vector2f(0.f, 15.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->camera_.move(sf::Vector2f(-15.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->camera_.move(sf::Vector2f(15.f, 0.f));
	}


	/*
		ZOOM IN AND OUT 
	*/
	if (ev.type == sf::Event::MouseWheelScrolled)
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

void Camera::setCenter(const sf::Vector2f& playerPosition)
{
	this->camera_.setCenter(playerPosition);
}

const sf::View& Camera::getView() const
{
	return this->camera_;
}
