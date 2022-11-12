#ifndef _TRAIN_HPP
#define _TRAIN_HPP

#include "env/conf.hpp"
#include "env/env.hpp"

#include "utils/timer.hpp"

class Train
{
    private:
        Env env;

    private:
        void run();

        void setup();
        bool loop();

    public:
        Train();
};

#endif
