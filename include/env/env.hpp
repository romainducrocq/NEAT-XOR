#ifndef _ENV_ENV_HPP
#define _ENV_ENV_HPP

#include "neat/neat.hpp"

#include "env/env/xor.hpp"

class Env: public Neat
{
    private:
        typedef Neat Super;

        Xor agent;

    private:
        void _reset() override;
        void _step() override;

    public:
        Env();
};

#endif