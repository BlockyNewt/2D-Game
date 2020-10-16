#include "State.h"

State::State(std::stack<State*>* states)
	: states_(states)
{
}

State::~State()
{
}
