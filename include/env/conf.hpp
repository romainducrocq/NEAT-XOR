#ifndef _ENV_CONF_HPP
#define _ENV_CONF_HPP

#include <unistd.h>

#include <iostream>
#include <cstddef>
#include <cstring>
#include <cstdlib>

template<typename T>
struct DefaultConf {
    enum ACTION{
        XOR
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

    const static size_t ACT_REPEAT;
    const static size_t MAX_NOOP;
    const static size_t MAX_STEP;
    const static size_t MVG_AVG;
    const static size_t EPOCHS_EVAL;

    static size_t POPULATION_SIZE;
    static size_t GENERATIONS_TRAIN;

    static std::string LOG_PLT;

    static bool argParse(int argc, char** argv)
    {
        // https://github.com/gnif/LookingGlass/blob/c0c63fd93bf999b6601a782fec8b56e9133388cc/client/main.c#L1391

        for(;;){
            switch(getopt(argc, argv, "h:g:l:p:")){
                case '?': // help
                case 'h':
                default :
                    std::cerr << "usage: apps/exec [-h] [-g NUM] [-p SIZ] [-l PLT] \n";
                    std::cerr << "\n";
                    std::cerr << "NEAT XOR                                         \n";
                    std::cerr << "\n";
                    std::cerr << "optional args:                                   \n";
                    std::cerr << "  -h      Print help and exit                    \n";
                    std::cerr << "  params:                                        \n";
                    std::cerr << "  -g NUM  Set generation number                  \n";
                    std::cerr << "  -p SIZ  Set population size                    \n";
                    std::cerr << "  utils:                                         \n";
                    std::cerr << "  -l PLT  Set plot log file name                 \n";

                    return false;

                case -1:
                    break;

                case 'g': // generation number
                    DefaultConf<T>::GENERATIONS_TRAIN = static_cast<size_t>(std::atoi(optarg));
                    continue;

                case 'p': // population size
                    DefaultConf<T>::POPULATION_SIZE = static_cast<size_t>(std::atoi(optarg));
                    continue;

                case 'l': // plot log file name
                    DefaultConf<T>::LOG_PLT = std::string(optarg);
                    continue;
            }
            break;
        }

        return true;
    }
};

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
const size_t DefaultConf<T>::ACT_REPEAT = 0;
template<typename T>
const size_t DefaultConf<T>::MAX_NOOP = 0;
template<typename T>
const size_t DefaultConf<T>::MAX_STEP = 0;
template<typename T>
const size_t DefaultConf<T>::MVG_AVG = 20;
template<typename T>
const size_t DefaultConf<T>::EPOCHS_EVAL = 10;

template<typename T>
size_t DefaultConf<T>::POPULATION_SIZE = 150;
template<typename T>
size_t DefaultConf<T>::GENERATIONS_TRAIN = 300;
template<typename T>
std::string DefaultConf<T>::LOG_PLT = "";

using CONF = DefaultConf<int>;

#endif
