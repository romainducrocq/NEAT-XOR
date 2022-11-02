#include <iostream>

#include <cstdlib>
#include <ctime>

#include "env/env.hpp"
#include "env/env/utils.hpp"

int main(int argc, char** argv)
{
    std::srand(time(nullptr));

    Env env;

    {
        Timer timer;

        std::cout << "\n";
        std::cout << "-------------------------------TRAIN-------------------------------" << "\n";
        std::cout << "\n";

        env.train();

        std::cout << "\n";
        std::cout << "\n";
    }

    return 0;

    {
        Timer timer;

        std::cout << "\n";
        std::cout << "-------------------------------EVAL--------------------------------" << "\n";
        std::cout << "\n";

        env.eval();

        std::cout << "\n";
        std::cout << "\n";
    }

    return 0;
}
