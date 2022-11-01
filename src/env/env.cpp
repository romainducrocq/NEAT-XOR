#include "env/env.hpp"

Env::Env()
{
}

void Env::_reset()
{
}

void Env::_step()
{
    this->agent.rand_data();
}