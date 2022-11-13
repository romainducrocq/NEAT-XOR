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
    View::EventHandler::EVENTHANDLER().ev_setup();
}

void Eval::draw_setup()
{
    View::Renderer::RENDERER().draw_setup(this->env);
}

void Eval::draw_loop()
{
    View::Renderer::RENDERER().draw_loop(this->env);
}