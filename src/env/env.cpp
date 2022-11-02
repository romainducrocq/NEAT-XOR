#include "env/env.hpp"

Env::Env()
{
}

void Env::init_func()
{
    this->mvg_avg = MovingAverage(100);
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
    switch(this->Super::mode) {

        case Super::MODE::TRAIN:
            this->Super::mdp.fitness += this->Super::mdp.act[0] == this->agent.get_y() ? 1.f : 0.f;

            if (this->Super::mdp.done) {
                this->Super::mdp.fitness = pow((this->Super::mdp.fitness / this->Super::steps), 2);
                if (this->Super::mdp.fitness == 0.f) {
                    this->Super::mdp.fitness = -1.f;
                }

                this->mvg_avg.add(this->Super::mdp.fitness);
            }
            break;

        case Super::MODE::EVAL:
            this->Super::mdp.fitness += this->Super::mdp.act[0] == this->agent.get_y() ? 1.f : 0.f;

            if (this->Super::mdp.done) {
                this->mvg_avg.add(this->Super::mdp.fitness);
            }
            break;

        default:
            break;
    }
}

void Env::info_func()
{
    switch(this->Super::mode){

        case Super::MODE::TRAIN:
            std::cout << "GENERATION  : " << this->Super::pool.get_generation() << " / " << this->Super::max_generation << "\n";
            std::cout << "SPECIE      : " << this->Super::pool.get_curr_specie() << " / " << this->Super::pool.get_species_size() << "\n";
            std::cout << "GENOME      : " << this->Super::pool.get_curr_genome() << " / " << this->Super::pool.get_genomes_size(this->Super::pool.get_curr_genome()) << "\n";
            std::cout << "FITNESS     : " << this->Super::mdp.fitness << "\n";
            std::cout << "MAX FITNESS : " << this->Super::pool.get_max_fitness() << "\n";
            std::cout << "MVG AVG     : " << this->mvg_avg.get() << "\n";
            std::cout << "\n";
            break;

        case Super::MODE::EVAL:
            std::cout << "EPOCH   : " << this->Super::epoch << " / " << this->Super::max_epoch << "\n";
            std::cout << "SUCCESS : " << this->Super::mdp.fitness << " / " << this->Super::max_step << "\n";
            std::cout << "RATE    : " << (this->Super::mdp.fitness / this->Super::max_step)  << "\n";
            std::cout << "MVG AVG : " << this->mvg_avg.get() << "\n";
            std::cout << "\n";
            break;

        default:
            break;
    }
}

bool Env::noop_func()
{
    return false;
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