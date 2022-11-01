#include "env/env.hpp"

Env::Env()
{
}

void Env::init_func()
{
}

void Env::obs_func()
{
    this->Super::mdp.obs[0] = agent.get_x()[0];
    this->Super::mdp.obs[1] = agent.get_x()[1];
}

void Env::act_func()
{
}

void Env::done_func()
{
    this->Super::mdp.done = false;
}

void Env::fitness_func()
{
    if(this->Super::mdp.done){
        this->Super::mdp.fitness = pow((this->Super::mdp.fitness / this->Super::timestep), 2);
        if(this->Super::mdp.fitness == 0.f){
            this->Super::mdp.fitness = -1.f;
        }
    }else{
        this->Super::mdp.fitness += this->Super::mdp.act[0] == this->agent.get_y() ? 1.f : 0.f;
    }
}

void Env::info_func()
{
    switch(this->Super::mode){
        case 0: // test
            break;
        case 1: // play
            break;
        case 2: // eval
            break;
        case 3: // train
            break;
        default:
            break;
    }
}

void Env::noop_func()
{
}

void Env::reset_func()
{
}

void Env::step_func()
{
    this->agent.next_data();
}

void Env::reset_render_func()
{
}

void Env::step_render_func()
{
}