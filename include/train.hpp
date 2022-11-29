#ifndef _TRAIN_HPP
#define _TRAIN_HPP

#include <thread>

#include "env/conf.hpp"
#include "env/env.hpp"

#include "utils/timer.hpp"

namespace App
{
    class Train
    {
        private:
            MyEnv::Env env;

        private:
            void setup();
            bool loop();

            Train() = default;

        public:
            void run();

        public:
            Train(const Train& other) = delete;
            Train operator=(const Train& other) = delete;

            static Train& TRAIN()
            {
                static Train singleton;
                return singleton;
            }
    };
}

#endif
