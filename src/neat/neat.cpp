#include "neat/neat.hpp"

Neat::Neat()
{
}

void Neat::init()
{
    this->init_func();

    for(size_t i = 0; i < this->inputs; i++){
        this->mdp.obs.push_back(0.f);
    }

    for(size_t i = 0; i < this->outputs; i++){
        this->mdp.act.push_back(false);
    }

    this->epoch = 0;
    this->generation = 0;

    switch(this->mode){

        case Neat::MODE::TRAIN:
            this->pool.init();
            break;

        case Neat::MODE::EVAL:
            this->best.ctor_network();
            break;

        default:
            break;
    }
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

    this->reset_render();

    this->steps = 0;
    this->noops = 0;

    mdp.done = false;
    mdp.fitness = 0.f;

    this->epoch++;
    this->generation = this->pool.get_generation();

    switch(this->mode){

        case Neat::MODE::TRAIN:
            this->pool.self_curr_genome().ctor_network();
            break;

        case Neat::MODE::EVAL:
            break;

        default:
            break;
    }
}

void Neat::step()
{
    this->step_func();

    this->step_render();

    if(!this->repeat || this->steps % this->repeat == 0){
        this->obs();

        switch(this->mode){

            case Neat::MODE::TRAIN:
                this->pool.eval_curr_genome(this->mdp.obs, this->mdp.act);
                break;

            case Neat::MODE::EVAL:
                this->best.eval_network(this->mdp.obs, this->mdp.act);
                break;

            default:
                break;
        }

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
                this->pool.next_genome(this->best);
            }

            if(this->generation < this->pool.get_generation()){
                this->info();
            }

            this->reset();
        }

        if(this->max_generation && this->generation >= this->max_generation){
            break;
        }
    }
}

void Neat::eval()
{
    this->mode = Neat::MODE::EVAL;

    this->init();

    this->reset();

    while(true){
        this->step();

        if(this->mdp.done) {
            this->info();

            this->reset();
        }

        if(this->max_epoch && this->epoch > this->max_epoch){
            break;
        }
    }
}
