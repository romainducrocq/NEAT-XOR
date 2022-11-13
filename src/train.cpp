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

    this->setup();

    while(this->loop()){}
}

void Train::setup()
{
    this->env.init(CONF::Mode::TRAIN, nullptr);
}

bool Train::loop()
{
    return this->env.train();
}
