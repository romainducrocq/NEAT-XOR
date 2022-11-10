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
    this->Super::mdp.done = this->agent.is_end();
}

void Env::fitness_func()
{
    switch(this->Super::mode) {
        case Super::MODE::TRAIN:
            this->Super::mdp.fitness += 1.f - std::pow(((this->Super::mdp.act[0] + 1.f) / 2.f) - this->agent.get_y(), 2);

            break;

        case Super::MODE::EVAL:
            this->Super::ss_info << "#" << this->Super::steps << " | "
                                 << this->agent.get_x()[0] << " " << this->agent.get_x()[1] << " | "
                                 << this->agent.get_y()                                     << " | "
                                 << ((this->Super::mdp.act[0] + 1.f) / 2.f)                 << " | " << "\n";
            this->Super::mdp.fitness += 1.f - std::abs(((this->Super::mdp.act[0] + 1.f) / 2.f) - this->agent.get_y());

            break;

        default:
            break;
    }
}

void Env::info_func()
{
    switch(this->Super::mode){

        case Super::MODE::TRAIN:
            std::cout << "GENERATION  : " << this->Super::pool.get_generation() << " / " << this->Super::max_generation_train << "\n";
            std::cout << "MAX FITNESS : " << this->Super::pool.get_max_fitness() << "\n";
            std::cout << "MVG AVG     : " << this->Super::mvg_avg.get() << "\n";
            std::cout << "\n";
            break;

        case Super::MODE::EVAL:
            std::cout << "EPOCH   : " << this->Super::epoch << " / " << this->Super::max_epoch_eval << "\n";
            std::cout << "SUCCESS : " << this->Super::mdp.fitness << " / " << this->Super::steps << "\n";
            std::cout << "RATE    : " << (this->Super::mdp.fitness / this->Super::steps) << "\n";
            std::cout << "MVG AVG : " << this->Super::mvg_avg.get() << "\n";
            std::cout << "   |  X  | Y | H |" << "\n";
            std::cout << "---|-----|---|---|" << "\n";
            std::cout << this->Super::ss_info.str();
            std::cout << "------------------" << "\n";
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
    this->agent.shuffle_data();
    this->agent.reset_data();
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