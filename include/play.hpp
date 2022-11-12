#ifndef _PLAY_HPP
#define _PLAY_HPP

#include <iostream>
#include <cstring>
#include <sstream>

#include "env/conf.hpp"
#include "env/env.hpp"
#include "env/view.hpp"

#include "utils/timer.hpp"

class Play
{
    private:
        Env env;

        EventHandler ev_handler;
        Renderer renderer;

    private:
        void run();

        void init();
        void reset();
        void step();

        bool play();

    public:
        Play();
};

#endif