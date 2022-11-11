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

    this->env.init(CONF::Mode::EVAL, true, nullptr);

    do{
    }while(this->env.eval());
}