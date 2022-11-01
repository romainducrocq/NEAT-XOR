#include "neat/neat.hpp"

Neat::Neat()
{
}

void Neat::init()
{
    this->init_func();

    if(this->mode == Neat::MODE::TRAIN){
        this->pool.init();
    }

    for(size_t i = 0; i < this->inputs; i++){
        this->mdp.obs.push_back(0.f);
    }

    for(size_t i = 0; i < this->outputs; i++){
        this->mdp.act.push_back(false);
    }

    this->epoch = 0;
}

void Neat::obs()
{
    this->obs_func();
}

void Neat::act()
{
    this->act_func();
}

void Neat::done()
{
    this->done_func();

    this->mdp.done = this->mdp.done ||
                     (this->max_step && this->steps >= this->max_step) ||
                     (this->max_noop && this->noops >= this->max_noop);
}

void Neat::fitness()
{
    this->fitness_func();
}

void Neat::info()
{
    this->info_func();
}

void Neat::noop()
{
    if(this->noop_func()){
        this->noops++;
    }else{
        this->noops = 0;
    }
}

// initializeRun
void Neat::reset()
{
    this->reset_func();

    this->steps = 0;
    this->noops = 0;

    mdp.done = false;
    mdp.fitness = 0.f;

    this->epoch++;

    this->pool.self_curr_genome().ctor_network();
}

void Neat::step()
{
    this->step_func();

    if(!this->repeat || this->steps % this->repeat == 0){
        this->obs();

        this->pool.eval_curr_genome(this->mdp.obs, this->mdp.act);

        this->noop();
    }

    this->act();

    this->steps++;

    this->done();

    this->fitness();
}

void Neat::reset_render()
{
    this->reset_render_func();
}

void Neat::step_render()
{
    this->step_render_func();
}

void Neat::train()
{
    this->mode = Neat::MODE::TRAIN;

    this->init();

    this->reset();

    while(true){
        this->step();

        if(this->mdp.done){

            this->pool.self_curr_genome().set_fitness(this->mdp.fitness);

            if(this->mdp.fitness > this->pool.get_max_fitness()){
                this->pool.set_max_fitness(this->mdp.fitness);
            }

            while(this->pool.fitness_pass()){
                this->pool.next_genome();
            }

            this->info();

            this->reset();
        }

        if((this->max_generation && this->pool.get_generation() >= this->max_generation) ||
           (this->max_epoch && this->epoch >= this->max_epoch)){
            break;
        }
    }
}

void Neat::eval() // TODO
{
    this->mode = Neat::MODE::EVAL;
}
