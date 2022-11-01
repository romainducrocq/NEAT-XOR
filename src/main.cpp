#include <iostream>

#include <cstdlib>
#include <ctime>

#include "neat/population.hpp"
#include "env/xor.hpp"

int main(int argc, char** argv)
{
    std::srand(time(nullptr));

    std::cout << "Hello world!" << "\n";

    Xor agent;

    Population::Pool neat;
    neat.init(2);

    while(true){
        // STEP

        //

    }

    return 0;
}
