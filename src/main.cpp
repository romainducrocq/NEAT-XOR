#include <iostream>

#include <cstdlib>
#include <ctime>

#include "env/env.hpp"
#include "env/env/utils.hpp"

int main()
{
    std::srand(time(nullptr));

    Env env;

    {
        Timer timer;

        std::cout << "\n";
        std::cout << "-------------------------------TRAIN-------------------------------" << "\n";
        std::cout << "\n";

        env.train();
    }

    {
        Timer timer;

        std::cout << "\n";
        std::cout << "-------------------------------EVAL--------------------------------" << "\n";
        std::cout << "\n";

        env.eval();
    }

    return 0;
}
