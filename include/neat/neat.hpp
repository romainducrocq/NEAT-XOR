#ifndef _NEAT_NEAT_HPP
#define _NEAT_NEAT_HPP

#include <limits>
#include <cstring>
#include <sstream>

#include <vector>
#include <utility>

#include <algorithm>

#include <pbplots/pbPlots.hpp>
#include <pbplots/supportLib.hpp>

#include "env/conf.hpp"

#include "neat/population.hpp"

#include "utils/mvgavg.hpp"

class Neat
{
    struct Mdp
    {
        std::vector<float> obs;
        std::vector<float> act;
        bool done = false;
        float fitness = 0.f;
    };

    private:
        size_t inputs = CONF::INPUTS;

        size_t repeat = CONF::ACT_REPEAT;
        size_t max_noop = CONF::MAX_NOOP;

        size_t noops = 0;

        Population::Pool pool;

        Genotype::Genome best;

        std::string log_sav = CONF::LOG_SAV;
        std::string log_plt = CONF::LOG_PLT;
        std::pair<std::vector<double>, std::vector<double>> plt_data;

    protected:
        size_t mode = CONF::MODE;

        size_t outputs = CONF::OUTPUTS;

        size_t max_epoch_eval = CONF::EPOCHS_EVAL;
        size_t max_generation_train = CONF::GENERATIONS_TRAIN;

        size_t max_step = CONF::MAX_STEP;
        size_t mvg_avg_max = CONF::MVG_AVG;

        size_t steps = 0;
        size_t epoch = 0;
        size_t generation = 0;
        float max_fitness = 0.f;

        Neat::Mdp mdp;

        MovingAverage mvg_avg;
        std::stringstream ss_info;

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

        void to_plt();
        void plot();

    public:
        Neat();

        void init(size_t mode);

        bool train();
        bool eval();
};

#endif
