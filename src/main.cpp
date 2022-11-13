#include <cstdlib>
#include <ctime>

#include <mutex>

#include <gtest/gtest.h>

#include "env/conf.hpp"

#include "train.hpp"
#include "eval.hpp"
#include "play.hpp"

std::mutex rw;

int main(int argc, char** argv)
{
    if(CONF::argParse(argc, argv)) {

        switch(CONF::MODE){

            case CONF::Mode::TRAIN:{
                std::srand(time(nullptr));
                Train::TRAIN();
                return 0;
            }

            case CONF::Mode::EVAL:{
                if(CONF::LOG_SAV.empty()) { return 1; }
                std::srand(time(nullptr));
                Eval::EVAL();
                return 0;
            }

            case CONF::Mode::PLAY:{
                std::srand(time(nullptr));
                Play::PLAY();
                return 0;
            }

            case CONF::Mode::TEST:{
                std::srand(42);
                testing::InitGoogleTest(&argc, argv);
                return RUN_ALL_TESTS();
            }

            default:
                return 1;
        }

    }

    return 1;
}
