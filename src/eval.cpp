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

    this->renderer.self_ev_handler().add_event();
    this->setup();
    this->renderer.draw_init(this->env);

    while(this->loop()){
        this->renderer.draw_loop(this->env);
    }
}

void Eval::setup()
{
    this->env.init(CONF::Mode::EVAL, true, nullptr);
}

bool Eval::loop()
{
    return this->env.eval();
}