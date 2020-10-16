#include "Engine.h"

Engine::Engine()
{
	this->vm_.width = 1280;
	this->vm_.height = 720;

	this->window_ = new sf::RenderWindow(this->vm_, "Pilrithia", sf::Style::Default);
	this->window_->setFramerateLimit(60);
	this->window_->setKeyRepeatEnabled(false);

	//PUSH NEW STATE HERE
}

Engine::~Engine()
{
	delete this->window_;
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
		else if (!this->states_.empty())
		{
			this->states_.top()->UpdatePollEvent(this->ev_);
		}
	}
}

void Engine::Update()
{
	if (!this->states_.empty())
	{
		this->states_.top()->Update();
	}
}

void Engine::Render()
{
	if (!this->states_.empty())
	{
		this->states_.top()->Render(*this->window_);
	}
}
