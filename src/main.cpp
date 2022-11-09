#include <iostream>

#include <cstdlib>
#include <ctime>

#include "env/conf.hpp"
#include "env/env.hpp"
#include "env/env/utils.hpp"

int main(int argc, char** argv)
{
    std::srand(time(nullptr));

    if(CONF::argParse(argc, argv)) {
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

    return 1;
}
