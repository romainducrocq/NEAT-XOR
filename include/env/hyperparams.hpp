#ifndef _ENV_HYPERPARAMS_HPP
#define _ENV_HYPERPARAMS_HPP

#include <cstddef>

template<typename T>
struct DefaultHyperParams {
    enum ACTION{
        XOR
    };

    static size_t INPUTS;
    static size_t OUTPUTS;

    static size_t LIM_HIDDEN;

    static float MUTATE_WEIGHT_RATE;
    static float MUTATE_GENE_RATE;
    static float MUTATE_LINK_RATE;
    static float MUTATE_BIAS_RATE;
    static float MUTATE_NEURON_RATE;
    static float MUTATE_ENABLE_RATE;
    static float MUTATE_DISABLE_RATE;
    static float MUTATE_OFFSET_SIZE;

    static float DELTA_WEIGHTS;
    static float DELTA_DISJOINT;
    static float DELTA_THRESHOLD;

    static float CROSSOVER_PROB;

    static size_t STALE_SPECIES;
    static size_t POPULATION_SIZE;

    static size_t ACT_REPEAT;
    static size_t MAX_NOOP;
    static size_t MAX_STEP;
};

template<typename T>
size_t DefaultHyperParams<T>::INPUTS = 2;
template<typename T>
size_t DefaultHyperParams<T>::OUTPUTS = 1;
template<typename T>
size_t DefaultHyperParams<T>::LIM_HIDDEN = 1000000;
template<typename T>
float DefaultHyperParams<T>::MUTATE_WEIGHT_RATE = 0.1f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_GENE_RATE = 0.25f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_LINK_RATE = 2.f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_BIAS_RATE = 0.4f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_NEURON_RATE = 0.5f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_ENABLE_RATE = 0.2f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_DISABLE_RATE = 0.4f;
template<typename T>
float DefaultHyperParams<T>::MUTATE_OFFSET_SIZE = 0.1f;
template<typename T>
float DefaultHyperParams<T>::DELTA_DISJOINT = 2.f;
template<typename T>
float DefaultHyperParams<T>::DELTA_WEIGHTS = 0.4f;
template<typename T>
float DefaultHyperParams<T>::DELTA_THRESHOLD = 1.f;
template<typename T>
float DefaultHyperParams<T>::CROSSOVER_PROB = 0.75f;
template<typename T>
size_t DefaultHyperParams<T>::STALE_SPECIES = 15;
template<typename T>
size_t DefaultHyperParams<T>::POPULATION_SIZE = 300;
template<typename T>
size_t DefaultHyperParams<T>::ACT_REPEAT = 0;
template<typename T>
size_t DefaultHyperParams<T>::MAX_NOOP = 0;
template<typename T>
size_t DefaultHyperParams<T>::MAX_STEP = 0;

using HyperParams = DefaultHyperParams<int>;

#endif
