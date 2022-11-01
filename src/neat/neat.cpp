#include "neat/neat.hpp"

Neat::Neat()
{
    this->pool.init();
}

// initializeRun
void Neat::reset()
{
    this->_reset();

    this->step = 0;
    this->noop = 0;
    this->repeat = 0;

    this->obs.clear();
    for(size_t i = 0; i < this->inputs; i++){
        this->obs.push_back(-1.f);
    }
    this->act.clear();
    for(size_t i = 0; i < this->outputs; i++){
        this->obs.push_back(false);
    }

    this->pool.self_curr_genome().ctor_network();

    this->pool.eval_curr_genome(this->obs, this->act);
}

