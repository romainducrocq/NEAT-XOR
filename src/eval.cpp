#include "eval.hpp"

Eval::Eval()
{
    this->run();
}

void Eval::run()
{
    Timer timer;

    std::cout << "\n";
    std::cout << "-------------------------------EVAL--------------------------------" << "\n";
    std::cout << "\n";

    this->ev_setup();
    this->setup();
    this->draw_setup();

    while(this->loop()){
        this->draw_loop();
    }
}

void Eval::setup()
{
    this->env.init(CONF::Mode::EVAL);
}

bool Eval::loop()
{
    return this->env.eval();
}


void Eval::ev_setup()
{
    this->renderer.self_ev_handler().ev_setup();
}

void Eval::draw_setup()
{
    this->renderer.draw_setup(this->env);
}

void Eval::draw_loop()
{
    this->renderer.draw_loop(this->env);
}