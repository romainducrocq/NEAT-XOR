#include "train.hpp"

Train::Train()
{
    this->run();
}

void Train::run()
{
    Timer timer;

    std::cout << "\n";
    std::cout << "-------------------------------TRAIN-------------------------------" << "\n";
    std::cout << "\n";

    this->env.init(CONF::Mode::TRAIN, false, nullptr);

    do{
    }while(this->env.train());
}