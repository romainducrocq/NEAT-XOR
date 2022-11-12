#include <cstdlib>
#include <ctime>

#include "env/conf.hpp"

#include "train.hpp"
#include "eval.hpp"
#include "play.hpp"

int main(int argc, char** argv)
{
    std::srand(time(nullptr));

    if(CONF::argParse(argc, argv)) {

        switch(CONF::MODE){

            case CONF::Mode::TRAIN:{
                Train train;
                return 0;
            }

            case CONF::Mode::EVAL:{
                if(CONF::LOG_SAV.empty()) { return 1; }
                Eval eval;
                return 0;
            }

            case CONF::Mode::PLAY:{
                Play play;
                return 0;
            }

            case CONF::Mode::TEST:{
                // TODO
                return 0;
            }

            default:
                return 1;
        }

    }

    return 1;
}
