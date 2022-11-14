#include "env/env.hpp"

/*** DEF INIT FUNC HERE */
void Env::init_func()
{
}

/*** DEF OBS FUNC HERE */
void Env::obs_func()
{
    this->Super::mdp.obs[0] = agent.get_x()[0];
    this->Super::mdp.obs[1] = agent.get_x()[1];
}

/*** DEF ACT FUNC HERE */
void Env::act_func()
{
}

/*** DEF DONE FUNC HERE */
void Env::done_func()
{
    this->Super::mdp.done = this->agent.is_end();
}

/*** DEF FITNESS FUNC HERE */
void Env::fitness_func()
{
    switch(this->Super::mode) {
        case CONF::Mode::TRAIN:
            this->Super::mdp.fitness += 1.f - std::pow(Super::Scale::to01(this->Super::mdp.act[0]) - this->agent.get_y(), 2);

            break;

        case CONF::Mode::EVAL:
            this->Super::ss_info << "#" << this->Super::steps << " | "
                                 << this->agent.get_x()[0] << " " << this->agent.get_x()[1] << " | "
                                 << this->agent.get_y()                                     << " | "
                                 << Super::Scale::to01(this->Super::mdp.act[0])             << " | " << "\n";
            this->Super::mdp.fitness += 1.f - std::abs(Super::Scale::to01(this->Super::mdp.act[0]) - this->agent.get_y());

            break;

        case CONF::Mode::PLAY:
            this->Super::ss_info << "#" << this->Super::steps << " | "
                                 << this->agent.get_x()[0] << " " << this->agent.get_x()[1] << " | "
                                 << this->agent.get_y()                                     << " | "
                                 << this->Super::mdp.act[0]                                 << " | " << "\n";
            this->Super::mdp.fitness += 1.f - std::abs(this->Super::mdp.act[0] - this->agent.get_y());

            break;

        default:
            break;
    }
}

/*** DEF INFO FUNC HERE */
void Env::info_func()
{
    switch(this->Super::mode){

        case CONF::Mode::TRAIN:
            std::cout << "GENERATION  : " << this->Super::generation << " / " << this->Super::max_generation_train << "\n";
            std::cout << "MAX FITNESS : " << this->Super::max_fitness << "\n";
            std::cout << "MVG AVG     : " << this->Super::mvg_avg.get() << "\n";
            std::cout << "\n";
            break;

        case CONF::Mode::EVAL:
        case CONF::Mode::PLAY:
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

/*** DEF NOOP FUNC HERE */
bool Env::noop_func()
{
    return false;
}

/*** DEF RESET FUNC HERE */
void Env::reset_func()
{
    this->agent.shuffle_data();
    this->agent.reset_data();
}

/*** DEF STEP FUNC HERE */
void Env::step_func()
{
    this->agent.next_data();
}

/*** DEF RESET RENDER FUNC HERE */
void Env::reset_render_func()
{
}

/*** DEF STEP RENDER FUNC HERE */
void Env::step_render_func()
{
    switch(this->Super::mode) {

        case CONF::Mode::PLAY:
            std::cout << "#" << (this->Super::steps + 1) << ": " << "\n"
                      << this->agent.get_x()[0] << " ^ " << this->agent.get_x()[1] << " =" <<"\n";
            break;

        default:
            break;
    }
}