#ifndef _ENV_ENV_HPP
#define _ENV_ENV_HPP

#include <cmath>

#include "neat/neat.hpp"

#include "env/env/xor.hpp"

class Env: public Neat
{
    private:
        typedef Neat Super;

        Xor agent;

    private:
        void init_func() override;

        void obs_func() override;
        void act_func() override;
        void done_func() override;
        void fitness_func() override;
        void info_func() override;

        bool noop_func() override;

        void reset_func() override;
        void step_func() override;

        void reset_render_func() override;
        void step_render_func() override;

    public:
        Env();
};

#endif