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

    this->init();

    do{
    }while(this->play());
}

void Play::init()
{
    env.init_func();

    env.mvg_avg = MovingAverage(env.mvg_avg_max);

    env.mdp.act.clear();
    for(size_t i = 0; i < env.outputs; i++){
        this->env.mdp.act.push_back(0.f);
    }

    env.epoch = 0;

    this->reset();
}

void Play::reset()
{
    env.reset_func();

    env.reset_render_func();

    env.steps = 0;

    env.mdp.done = false;
    env.mdp.fitness = 0.f;

    env.epoch++;
}

void Play::step()
{
    env.step_func();

    env.step_render_func();

    this->ev_handler.get_action(env.mdp.act);

    env.act_func();

    env.steps++;

    env.done_func();

    env.fitness_func();

    if(env.mdp.done){
        env.mvg_avg.add(env.mdp.fitness);
    }
}



bool Play::play()
{
    this->step();

    if(env.mdp.done) {
        env.info_func();
        env.ss_info.str(std::string());

        this->reset();
    }

    if(env.max_epoch_eval && env.epoch > env.max_epoch_eval){

        return false;
    }

    return true;
}

/*

Play::Play()
{
    std::cout << "PLAY" << "\n";

    this->run();
}

Play::~Play()
{
}

void Play::setup()
{
    this->env.reset(nullptr);
}

void Play::loop()
{
    int action = this->getAction();

    this->env.step(action, nullptr, nullptr, this->done, nullptr);

    if(this->done){
        this->setup();
    }
}

void Play::drawInit()
{
    this->Super::m_renderer.drawInit(this->env.get_env());
}

void Play::drawLoop()
{
    this->Super::m_renderer.drawLoop(this->env.get_env());
}

void Play::eventAdd()
{
    this->m_ev_handler.eventAdd();
}

int Play::getAction() {
    return this->m_ev_handler.getAction();
}

void Play::mainInit()
{
    this->setup();
}

void Play::mainLoop()
{
    this->loop();
}

 *
 */