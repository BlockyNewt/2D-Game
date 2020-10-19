#include "Engine.h"

Engine::Engine()
{
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

	while (!this->states_.empty())
	{
		delete this->states_.top();
	}
}

void Engine::Run()
{
	while (this->window_->isOpen())
	{
		this->UpdatePollEvent();
		this->Update();
		this->Render();
	}
}

void Engine::UpdatePollEvent()
{
	while (this->window_->pollEvent(this->ev_))
	{
		if (this->ev_.type == sf::Event::Closed)
		{
			this->window_->close();
		}
		
		if (!this->states_.empty())
		{
			this->states_.top()->UpdatePollEvent(this->ev_);
		}
		else
		{
			this->window_->close();
		}
	}
}

void Engine::Update()
{
	if (!this->states_.empty())
	{
		this->states_.top()->Update();
	}
	else
	{
		this->window_->close();
	}
}

void Engine::Render()
{
	this->window_->clear();

	if (!this->states_.empty())
	{
		this->states_.top()->Render(*this->window_);
	}
	else
	{
		this->window_->close();
	}

	this->window_->display();
}
