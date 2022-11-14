#ifndef _ENV_CONF_HPP
#define _ENV_CONF_HPP

#include <unistd.h>

#include <iostream>
#include <cstddef>
#include <cstring>
#include <cstdlib>

template<typename T>
struct DefaultConf{
    enum Mode{
        TRAIN, EVAL, PLAY, TEST, NONE
    };

    /*** DEC ACTIONS HERE */
    enum Action{
        ZERO, ONE
    };

    const static size_t INPUTS;
    const static size_t OUTPUTS;

    const static size_t LIM_HIDDEN;

    const static float MUTATE_WEIGHT_RATE;
    const static float MUTATE_GENE_RATE;
    const static float MUTATE_LINK_RATE;
    const static float MUTATE_BIAS_RATE;
    const static float MUTATE_NEURON_RATE;
    const static float MUTATE_ENABLE_RATE;
    const static float MUTATE_DISABLE_RATE;
    const static float MUTATE_OFFSET_SIZE;

    const static float DELTA_WEIGHTS;
    const static float DELTA_DISJOINT;
    const static float DELTA_THRESHOLD;

    const static float CROSSOVER_PROB;
    const static size_t STALE_SPECIES;
    const static size_t POPULATION_SIZE;

    const static size_t ACT_REPEAT;
    const static size_t MAX_NOOP;
    const static size_t MVG_AVG;

    static size_t GENERATIONS_TRAIN;
    static size_t EPOCHS_EVAL;
    static size_t MAX_STEP;

    static std::string LOG_PLT;
    static std::string LOG_SAV;

    static Mode MODE;

    /*** DEC OPT PARAMS HERE */


    static inline bool argParse(int argc, char** argv)
    {
        // https://github.com/gnif/LookingGlass/blob/c0c63fd93bf999b6601a782fec8b56e9133388cc/client/main.c#L1391

        /*** DEF CMDS HERE */
        const char cmds[] = "h:m:g:e:n:p:s:";

        for(;;){
            switch(getopt(argc, argv, cmds)){

                /*** DEF HELP HERE */
                case '?': // help
                case 'h':
                default :
                    std::cerr << "usage: apps/exec [-h] [-m MOD] [-g GEN] [-e EPO] [-n NUM] [-p PLT] [-s SAV] \n";
                    std::cerr << "\n";
                    std::cerr << "NEAT XOR                                                                    \n";
                    std::cerr << "\n";
                    std::cerr << "optional args:                                                              \n";
                    std::cerr << "  -h      Print help and exit                                               \n";
                    std::cerr << "  -m MOD  Set mode < train | eval | play | test >                           \n";
                    std::cerr << "  params:                                                                   \n";
                    std::cerr << "  -g GEN  [train]       Set generation number (0=inf)                       \n";
                    std::cerr << "  -e EPO  [eval, play]  Set epoch number      (0=inf)                       \n";
                    std::cerr << "  -n NUM  [train, eval] Set max step number   (0=inf)                       \n";
                    std::cerr << "  utils:                                                                    \n";
                    std::cerr << "  -p PLT  [train]       Set plot log file name                              \n";
                    std::cerr << "  -s SAV  [train, eval] Set save sav file name                              \n";

                    return false;

                case -1:
                    break;

                case 'm': // mode < train | eval | play | test >
                    if(std::strcmp(optarg, "train") == 0){
                        DefaultConf<T>::MODE = DefaultConf<T>::Mode::TRAIN;
                    }else if(std::strcmp(optarg, "eval") == 0){
                        DefaultConf<T>::MODE = DefaultConf<T>::Mode::EVAL;
                    }else if(std::strcmp(optarg, "play") == 0){
                        DefaultConf<T>::MODE = DefaultConf<T>::Mode::PLAY;
                    }else if(std::strcmp(optarg, "test") == 0){
                        DefaultConf<T>::MODE = DefaultConf<T>::Mode::TEST;
                    }
                continue;

                case 'g': // generation number
                    DefaultConf<T>::GENERATIONS_TRAIN = static_cast<size_t>(std::atoi(optarg));
                    continue;

                case 'e': // epoch number
                    DefaultConf<T>::EPOCHS_EVAL = static_cast<size_t>(std::atoi(optarg));
                    continue;

                case 'n': // max step number
                    DefaultConf<T>::MAX_STEP = static_cast<size_t>(std::atoi(optarg));
                    continue;

                case 'p': // plot log file name
                    DefaultConf<T>::LOG_PLT = std::string(optarg);
                    continue;

                case 's': // save sav file name
                    DefaultConf<T>::LOG_SAV = std::string(optarg);
                    continue;

                /*** DEF OPT CMDS HERE */


            }
            break;
        }

        return true;
    }
};

template<typename T>
typename DefaultConf<T>::Mode DefaultConf<T>::MODE = DefaultConf<T>::Mode::NONE;
template<typename T>
std::string DefaultConf<T>::LOG_PLT = "";
template<typename T>
std::string DefaultConf<T>::LOG_SAV = "";

/*** DEF PARAMS HERE */
template<typename T>
const size_t DefaultConf<T>::INPUTS = 2;
template<typename T>
const size_t DefaultConf<T>::OUTPUTS = 1;
template<typename T>
const size_t DefaultConf<T>::LIM_HIDDEN = 1000000;
template<typename T>
const float DefaultConf<T>::MUTATE_WEIGHT_RATE = 0.1f;
template<typename T>
const float DefaultConf<T>::MUTATE_GENE_RATE = 0.25f;
template<typename T>
const float DefaultConf<T>::MUTATE_LINK_RATE = 2.f;
template<typename T>
const float DefaultConf<T>::MUTATE_BIAS_RATE = 0.4f;
template<typename T>
const float DefaultConf<T>::MUTATE_NEURON_RATE = 0.5f;
template<typename T>
const float DefaultConf<T>::MUTATE_ENABLE_RATE = 0.2f;
template<typename T>
const float DefaultConf<T>::MUTATE_DISABLE_RATE = 0.4f;
template<typename T>
const float DefaultConf<T>::MUTATE_OFFSET_SIZE = 0.1f;
template<typename T>
const float DefaultConf<T>::DELTA_DISJOINT = 2.f;
template<typename T>
const float DefaultConf<T>::DELTA_WEIGHTS = 0.4f;
template<typename T>
const float DefaultConf<T>::DELTA_THRESHOLD = 1.f;
template<typename T>
const float DefaultConf<T>::CROSSOVER_PROB = 0.75f;
template<typename T>
const size_t DefaultConf<T>::STALE_SPECIES = 15;
template<typename T>
const size_t DefaultConf<T>::POPULATION_SIZE = 150;
template<typename T>
const size_t DefaultConf<T>::ACT_REPEAT = 0;
template<typename T>
const size_t DefaultConf<T>::MAX_NOOP = 0; // 0=inf
template<typename T>
const size_t DefaultConf<T>::MVG_AVG = 20;

template<typename T>
size_t DefaultConf<T>::GENERATIONS_TRAIN = 300; // 0=inf
template<typename T>
size_t DefaultConf<T>::EPOCHS_EVAL = 10; // 0=inf
template<typename T>
size_t DefaultConf<T>::MAX_STEP = 0; // 0=inf

/*** DEF OPT PARAMS HERE */


using CONF = DefaultConf<int>;

#endif
