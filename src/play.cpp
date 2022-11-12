#include "play.hpp"

Play::Play()
{
    this->run();
}

void Play::run()
{
    Timer timer;

    std::cout << "\n";
    std::cout << "-------------------------------PLAY--------------------------------" << "\n";
    std::cout << "\n";

    this->ev_handler.add_event();
    this->setup();
    this->renderer.draw_init(this->env);

    while(this->loop()){
        this->renderer.draw_loop(this->env);
    }
}

void Play::setup()
{
    this->env.init_func();

    this->env.mvg_avg = MovingAverage(this->env.mvg_avg_max);

    this->env.mdp.act.clear();
    for(size_t i = 0; i < this->env.outputs; i++){
        this->env.mdp.act.push_back(0.f);
    }

    this->env.epoch = 0;

    this->reset();
}

bool Play::loop()
{
    this->step();

    if(this->env.mdp.done) {
        this->env.info_func();
        this->env.ss_info.str(std::string());

        this->reset();
    }

    if(this->env.max_epoch_eval && this->env.epoch > this->env.max_epoch_eval){

        return false;
    }

    return true;
}

void Play::reset()
{
    this->env.reset_func();

    this->env.reset_render_func();

    this->env.steps = 0;

    this->env.mdp.done = false;
    this->env.mdp.fitness = 0.f;

    this->env.epoch++;
}

void Play::step()
{
    this->env.step_func();

    this->env.step_render_func();

    this->ev_handler.get_action(this->env.mdp.act);

    this->env.act_func();

    this->env.steps++;

    this->env.done_func();

    this->env.fitness_func();

    if(this->env.mdp.done){
        this->env.mvg_avg.add(this->env.mdp.fitness);
    }
}
