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

    std::thread th([&]() {
        this->setup();

        while(this->loop()){}
    });

    if(th.joinable()){
        th.join();
    }
}

void Train::setup()
{
    this->env.init(CONF::Mode::TRAIN);
}

bool Train::loop()
{
    return this->env.train();
}
