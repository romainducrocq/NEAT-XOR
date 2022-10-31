#ifndef _NEAT_POPULATION_HPP
#define _NEAT_POPULATION_HPP

#include <cstdlib>
#include <cmath>

#include <vector>

#include <functional>
#include <utility>

#include "hyperparams.hpp"

#include "genotype.hpp"

namespace Population
{
    class Specie
    {
        private:
            size_t staleness = 0;

            float max_fitness = 0.f;
            float avg_fitness = 0.f;

            float crossover_prob = HyperParams::CROSSOVER_PROB;

            std::vector<Genotype::Genome> genomes;

        public:
            Specie();

            void calc_avg_fitness();

            void breed_child(Genotype::Genome& child, size_t& innovation) const;

            size_t get_avg_fitness() const;
            size_t get_staleness() const;
            float get_max_fitness() const;

            void set_staleness(size_t staleness);
            void set_max_fitness(float max_fitness);

            std::vector<Genotype::Genome>& self_genomes();
    };

    class Pool
    {
        private:
            size_t step = 0;
            size_t repeat = HyperParams::ACT_REPEAT;
            size_t noop = HyperParams::MAX_NOOP;

            size_t self_specie = 0;
            size_t self_genome = 0;

            size_t generation = 0;
            // size_t innovation = HyperParams::ACTION::N;
            size_t innovation = 0;

            float max_fitness = 0.f;
            float tot_avg_fitness = 0.f;

            size_t stale_species = HyperParams::STALE_SPECIES;
            size_t population_size = HyperParams::POPULATION_SIZE;

            std::vector<Population::Specie> species;

        private:
            void calc_tot_avg_fitness();
            void calc_glob_rank();

            void cull_species(bool half);
            void pop_stale_species();
            void pop_weak_species();

            void add_to_species(Genotype::Genome& child);

            void new_generation();
            void init(size_t inputs);

            bool fitness_pass();
            void next_genome();

        public:
            Pool();

            size_t get_self_specie() const;
            size_t get_self_genome() const;

            void set_self_specie(size_t self_specie);
            void set_self_genome(size_t self_genome);
    };
}

#endif
