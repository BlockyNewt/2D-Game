#include "Engine.h"

Engine::Engine()
{
	std::cout << "DEBUG::ENGINE::ENGINE() -> HAS STARTED." << std::endl;

	/*
		SET WINDOW SETTINGS
	*/
	this->vm_.width = 1280;
	this->vm_.height = 720;

	this->context_Settings_.antialiasingLevel = 8;

	this->window_ = new sf::RenderWindow(this->vm_, "Dunilidor", sf::Style::Close | sf::Style::Titlebar, this->context_Settings_);
	this->window_->setFramerateLimit(60);
	this->window_->setKeyRepeatEnabled(false);
	this->window_->setVerticalSyncEnabled(false);
	
	/*
		PUSH FIRST STATE HERE
	*/
	this->states_.push(new StateMainMenu(&this->states_, this->window_));
}

Engine::~Engine()
{
	delete this->window_;

	if (!this->states_.empty())
	{
		for (int i = 0; i < this->states_.size(); ++i)
		{
			delete this->states_.top();
		}
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
		/*
			IF 'X' BUTTON IS CLICKED ON THE WINDOW THEN EXIT THE PROGRAM
		*/
		if (this->ev_.type == sf::Event::Closed)
		{
			this->window_->close();
		}

		/*
			IF THE STATES CONTAINER IS NOT EMPTY THEN CONTINUE TO UPDATE POLL EVENTS
		*/
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
	/*
		IF THE STATES CONTAINER IS NOT EMPTY THEN CONTINUE TO UPDATE 
	*/
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
	/*
		CLEAR WINDOW FOR DRAWING NEW ITEMS
	*/
	this->window_->clear();


	/*
		IF THE STATES CONTAINER IS NOT EMPTY THEN CONTINUE TO RENDER
	*/
	if (!this->states_.empty())
	{
		this->states_.top()->render(*this->window_);
	}
	else
	{
		this->window_->close();
	}

	/*
		DISPLAY DRAWN ITEMS
	*/
	this->window_->display();
}
