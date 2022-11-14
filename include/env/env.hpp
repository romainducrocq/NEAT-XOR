#ifndef _ENV_ENV_HPP
#define _ENV_ENV_HPP

#include "neat/neat.hpp"

/*** ADD INCLUDE HERE */
#include <iostream>
#include <cmath>

#include "env/env/xor.hpp"

class Play;

class Env: public Neat
{
    private:
        typedef Neat Super;
        friend class Play;

    private:
        /*** DEC ENV HERE */
        Xor agent;

    private:
        void init_func() override;

        void obs_func() override;
        void act_func() override;
        void done_func() override;
        void fitness_func() override;
        void info_func() override;

        void noop_func() override;

        void reset_func() override;
        void step_func() override;

        void reset_render_func() override;
        void step_render_func() override;

    public:
        Env() = default;
};

#endif