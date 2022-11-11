#ifndef _EVAL_HPP
#define _EVAL_HPP

#include "env/conf.hpp"
#include "env/env.hpp"

#include "utils/timer.hpp"

class Eval
{
    private:
        Env env;

    private:
        void run();

    public:
        Eval();
};

#endif