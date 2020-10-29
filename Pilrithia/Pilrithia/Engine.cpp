#include "Engine.h"

Engine::Engine()
{
	std::cout << "DEBUG::ENGINE::ENGINE() -> HAS STARTED." << std::endl;

	this->vm_.width = 1280;
	this->vm_.height = 720;

	this->window_ = new sf::RenderWindow(this->vm_, "Pilrithia", sf::Style::Default);
	this->window_->setFramerateLimit(60);
	this->window_->setKeyRepeatEnabled(false);

	//PUSH NEW STATE HERE
	this->states_.push(new StateMainMenu(&this->states_, this->window_));

}

Engine::~Engine()
{
	delete this->window_;

	if (!this->states_.empty())
	{
		delete this->states_.top();
	}
}

void Engine::run()
{
	while (this->window_->isOpen())
	{
		this->updatePollEvent();
		this->update();
		this->render();
	}
}

void Engine::updatePollEvent()
{
	while (this->window_->pollEvent(this->ev_))
	{
		if (this->ev_.type == sf::Event::Closed)
		{
			this->window_->close();
		}
		
		if (!this->states_.empty())
		{
			this->states_.top()->updatePollEvent(this->ev_);
		}
		else
		{
			this->window_->close();
		}
	}
}

void Engine::update()
{
	if (!this->states_.empty())
	{
		this->states_.top()->update();
	}
	else
	{
		this->window_->close();
	}
}

void Engine::render()
{
	this->window_->clear();

	if (!this->states_.empty())
	{
		this->states_.top()->render(*this->window_);
	}
	else
	{
		this->window_->close();
	}

	this->window_->display();
}
