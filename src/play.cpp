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

    this->ev_setup();
    this->setup();
    this->draw_setup();

    while(this->loop()){
        this->draw_loop();
    }
}

void Play::setup()
{
    this->init();
}

bool Play::loop()
{
    return this->play();
}

void Play::ev_setup()
{
    View::EventHandler::EVENTHANDLER().ev_setup();
}

void Play::draw_setup()
{
    View::Renderer::RENDERER().draw_setup(this->env);
}

void Play::draw_loop()
{
    View::Renderer::RENDERER().draw_loop(this->env);
}

void Play::init()
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

    View::EventHandler::EVENTHANDLER().get_action(this->env.mdp.act);

    this->env.act_func();

    this->env.steps++;

    this->env.done_func();

    this->env.fitness_func();

    if(this->env.mdp.done){
        this->env.mvg_avg.add(this->env.mdp.fitness);
    }
}

bool Play::play()
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
