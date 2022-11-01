#ifndef _NEAT_NEAT_HPP
#define _NEAT_NEAT_HPP

#include <vector>

#include "env/hyperparams.hpp"

#include "neat/population.hpp"

class Neat
{
    private:
        size_t step = 0;

        size_t noop = 0;
        size_t repeat = HyperParams::ACT_REPEAT;
        size_t max_noop = HyperParams::MAX_NOOP;
        size_t max_step = HyperParams::MAX_STEP;

        size_t inputs = HyperParams::INPUTS;
        size_t outputs = HyperParams::OUTPUTS;

        std::vector<float> obs;
        std::vector<bool> act;

        Population::Pool pool;

    protected:
        virtual void _reset() = 0;
        virtual void _step() = 0;

    public:
        Neat();

        void reset();
};

#endif