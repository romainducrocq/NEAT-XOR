#ifndef _ENV_ENV_HPP
#define _ENV_ENV_HPP

#include <iostream>
#include <cmath>
#include <limits>

#include "neat/neat.hpp"

#include "env/env/xor.hpp"
#include "env/env/utils.hpp"

class Env: public Neat
{
    private:
        typedef Neat Super;

    private:
        Xor agent;
        MovingAverage mvg_avg;

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