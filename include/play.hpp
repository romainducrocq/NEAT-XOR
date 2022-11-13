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

        View::Renderer renderer;

    private:
        void init();
        void reset();
        void step();
        bool play();

    private:
        void run();

        void ev_setup();
        void draw_setup();
        void draw_loop();

        void setup();
        bool loop();

        Play();

    public:
        Play(const Play& other) = delete;
        Play operator=(const Play& other) = delete;

        static inline Play& PLAY()
        {
            static Play singleton;
            return singleton;
        }
};

#endif