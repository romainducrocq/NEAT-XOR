#ifndef _NEAT_NEAT_HPP
#define _NEAT_NEAT_HPP

#include <vector>

#include "env/hyperparams.hpp"

#include "neat/population.hpp"

class Neat
{
    struct Mdp
    {
        std::vector<float> obs;
        std::vector<float> act;
        bool done = false;
        float fitness = 0.f;
    };

    protected:
        enum MODE { TEST, PLAY, EVAL, TRAIN };
        size_t mode = Neat::MODE::TEST;

        size_t inputs = HyperParams::INPUTS;
        size_t outputs = HyperParams::OUTPUTS;

        size_t repeat = HyperParams::ACT_REPEAT;
        size_t max_noop = HyperParams::MAX_NOOP;
        size_t max_step = HyperParams::MAX_STEP;
        size_t max_epoch = HyperParams::EPOCHS;
        size_t max_generation = HyperParams::GENERATIONS;

        size_t steps = 0;
        size_t noops = 0;
        size_t epoch = 0;
        size_t generation = 0;

        Neat::Mdp mdp;

        Population::Pool pool;

        Genotype::Genome best;

    protected:
        virtual void init_func() = 0;

        virtual void obs_func() = 0;
        virtual void act_func() = 0;
        virtual void done_func() = 0;
        virtual void fitness_func() = 0;
        virtual void info_func() = 0;

        virtual bool noop_func() = 0;

        virtual void reset_func() = 0;
        virtual void step_func() = 0;

        virtual void reset_render_func() = 0;
        virtual void step_render_func() = 0;

    private:
        void obs();
        void act();
        void done();
        void fitness();
        void info();

        void noop();

        void reset();
        void step();

        void reset_render();
        void step_render();

    public:
        Neat();

        void init();

        void train();
        void eval();
};

#endif