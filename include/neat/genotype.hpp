#ifndef _NEAT_GENOTYPE_HPP
#define _NEAT_GENOTYPE_HPP

// #include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <unordered_map>

#include <iterator>
#include <algorithm>
#include <functional>
#include <utility>

#include "env/hyperparams.hpp"

namespace Genotype
{
    struct Activation
    {
        static inline float sigmoid(float z)
        {
            return 2.f / (1.f + exp(-4.9f * z)) - 1.f;
        }
    };

    struct Gene
    {
        size_t into = 0;
        size_t out = 0;
        size_t innovation = 0;

        float weight = 0.f;
        bool enabled = true;

        bool operator<(const Genotype::Gene& other) const {
            return out < other.out;
        }

        Gene() {}
        Gene(size_t into, size_t out, size_t innovation, float weight, bool enabled)
            : into(into), out(out), innovation(innovation), weight(weight), enabled(enabled) {}
    };

    struct Neuron
    {
        std::vector<std::reference_wrapper<Genotype::Gene>> incoming;
        float value = 0.f;
    };

    class Genome
    {
        private:
            size_t inputs = HyperParams::INPUTS + 1;
            size_t outputs = HyperParams::OUTPUTS;

            size_t lim_hidden = HyperParams::LIM_HIDDEN;

            size_t max_neuron = 0;

            float fitness = 0.f;
            size_t global_rank = 0;

            float mutation_rate_weight = HyperParams::MUTATE_WEIGHT_RATE;
            std::unordered_map<std::string, float> mutation_rates = {
                {"gene", HyperParams::MUTATE_GENE_RATE},
                {"link", HyperParams::MUTATE_LINK_RATE},
                {"bias", HyperParams::MUTATE_BIAS_RATE},
                {"neuron", HyperParams::MUTATE_NEURON_RATE},
                {"enable", HyperParams::MUTATE_ENABLE_RATE},
                {"disable", HyperParams::MUTATE_DISABLE_RATE},
                {"offset", HyperParams::MUTATE_OFFSET_SIZE}
            };

            float d_disjoint = HyperParams::DELTA_DISJOINT;
            float d_weight = HyperParams::DELTA_WEIGHTS;
            float d_threshold = HyperParams::DELTA_THRESHOLD;

            std::vector<Genotype::Gene> genes;
            std::map<size_t, Genotype::Neuron> neurons;

            std::set<size_t> innovation_set;
            std::unordered_map<size_t, std::reference_wrapper<Genotype::Gene>> innovation_gene_map;

            float(*activation_func)(float) = Genotype::Activation::sigmoid;

        private:
            size_t inc_innovation(size_t& innovation) const;
            bool contains_link(size_t into, size_t out) const;

            void rand_neurons(size_t& into, size_t& out) const;

            void mutate_point();
            void mutate_link(bool bias, size_t& innovation);
            void mutate_node(size_t& innovation);
            void mutate_enable(bool enable);

            float delta_disjoints(const Genotype::Genome& other) const;
            float delta_weights(const Genotype::Genome& other) const;

        public:
            Genome();
            Genome(size_t inputs);
            Genome(const Genotype::Genome& other) = delete;
            Genome(Genotype::Genome&& other) noexcept = default;
            Genotype::Genome& operator=(const Genotype::Genome& other) = delete;
            Genotype::Genome& operator=(Genotype::Genome&& other) noexcept = default;

            void copy_genome(const Genotype::Genome& other);

            void ctor_network();
            void eval_network(const std::vector<float>& obs, std::vector<bool>& act);

            void mutate(size_t& innovation);

            bool same_specie(const Genotype::Genome& other) const;

            void crossover(const Genotype::Genome& other, Genotype::Genome& child) const;

            void simple_genome(size_t& innovation);

            float get_fitness() const;
            size_t get_global_rank() const;

            void set_fitness(float fitness);
            void set_global_rank(size_t global_rank);
    };
}

#endif
