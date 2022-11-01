#include <iostream>

#include <cstdlib>
#include <ctime>

#include "env/env.hpp"

int main(int argc, char** argv)
{
    std::srand(time(nullptr));

    std::cout << "Hello world!" << "\n";

    Env env;

    return 0;
}
