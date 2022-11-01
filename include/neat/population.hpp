#ifndef _NEAT_POPULATION_HPP
#define _NEAT_POPULATION_HPP

#include <cstdlib>
#include <cmath>

#include <vector>

#include <functional>
#include <utility>

#include "env/hyperparams.hpp"

#include "neat/genotype.hpp"

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
            size_t curr_specie = 0;
            size_t curr_genome = 0;

            size_t generation = 0;
            // size_t innovation = HyperParams::OUTPUTS;
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

        public:
            Pool();

            void init();

            void eval_curr_genome(const std::vector<float>& obs, std::vector<bool>& act);

            bool fitness_pass();
            void next_genome();

            size_t get_generation() const;
            float get_max_fitness() const;

            void set_max_fitness(size_t max_fitness);
            void set_curr_specie(size_t curr_specie);
            void set_curr_genome(size_t curr_genome);

            Population::Specie& self_curr_specie();
            Genotype::Genome& self_curr_genome();
    };
}

#endif
