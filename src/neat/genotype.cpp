#include "neat/genotype.hpp"

Genotype::Genome::Genome()
{
}

/*
Genotype::Genome::Genome(Genotype::Genome&& other)
    : inputs(other.inputs)
    , max_neuron(other.max_neuron)
    , mutation_rates(std::move(other.mutation_rates))
    , genes(std::move(other.genes))
    , innovation_set(std::move(other.innovation_set))
    , innovation_gene_map(std::move(other.innovation_gene_map))
{
}
*/
/*
Genotype::Genome& Genotype::Genome::operator=(const Genotype::Genome& other)
{
    this->inputs = other.inputs;
    this->max_neuron = other.max_neuron;

    for(const auto& mutation_rate : other.mutation_rates){
        this->mutation_rates[mutation_rate.first] = mutation_rate.second;
    }

    for(const auto& gene : other.genes){
        this->genes.push_back(gene);

        this->innovation_set.insert(gene.innovation);
        this->innovation_gene_map.insert({gene.innovation, std::ref(this->genes.back())});
    }

    return *this;
}
*/

// copyGenome
void Genotype::Genome::copy_genome(const Genotype::Genome& other)
{
    this->inputs = other.inputs;
    this->max_neuron = other.max_neuron;

    for(const auto& mutation_rate : other.mutation_rates){
        this->mutation_rates[mutation_rate.first] = mutation_rate.second;
    }

    for(const auto& gene : other.genes){
        this->genes.push_back(gene);

        this->innovation_set.insert(gene.innovation);
        this->innovation_gene_map.insert({gene.innovation, std::ref(this->genes.back())});
    }
}

// generateNetwork
void Genotype::Genome::ctor_network()
{
    this->neurons.clear();

    for(size_t i = 0; i < this->inputs; i++){
        this->neurons.emplace(std::piecewise_construct, std::forward_as_tuple(i), std::forward_as_tuple());
    }

    for(size_t i = 0; i < this->outputs; i++){
        this->neurons.emplace(std::piecewise_construct, std::forward_as_tuple(this->lim_hidden + i),
                              std::forward_as_tuple());
    }

    std::sort(this->genes.begin(), this->genes.end());

    for(auto& gene : this->genes){
        if(gene.enabled){
            if(!this->neurons.count(gene.out)){
                this->neurons.emplace(std::piecewise_construct, std::forward_as_tuple(gene.out),
                                      std::forward_as_tuple());
            }

            this->neurons.at(gene.out).incoming.push_back(std::ref(gene));

            if(!this->neurons.count(gene.into)){
                this->neurons.emplace(std::piecewise_construct, std::forward_as_tuple(gene.into),
                                      std::forward_as_tuple());
            }
        }
    }
}

// evaluateNetwork
void Genotype::Genome::eval_network(const std::vector<float>& obs, std::vector<bool>& act)
{
    // assert(obs.size() + 1 == this->inputs);

    for(size_t i = 0; i < obs.size(); i++){
        this->neurons.at(i).value = obs[i];
    }
    this->neurons.at(obs.size()).value = 1.f; // bias

    for(auto& neuron : this->neurons){
        if(neuron.second.incoming.size() > 0) {
            float dot = 0.f;
            for(const auto &gene : neuron.second.incoming) {
                dot += gene.get().weight * this->neurons.at(gene.get().into).value;
            }

            neuron.second.value = this->activation_func(dot);
        }
    }

    // classification
    for(size_t i = 0; i < this->outputs; i++){
        act[i] = this->neurons.at(i + this->lim_hidden).value > 0;
    }
}

// randomNeuron
void Genotype::Genome::rand_neurons(size_t& into, size_t& out) const
{
    std::set<size_t> neurons;

    for(size_t i = 0; i < this->inputs; i++){
        neurons.insert(i);
    }

    for(size_t i = 0; i < this->outputs; i++){
        neurons.insert(i + this->lim_hidden);
    }

    for(const auto& gene : this->genes){
        neurons.insert(gene.into);
        neurons.insert(gene.out);
    }

    into = *std::next(neurons.begin(), rand() % neurons.size());

    do{
        out = *std::next(neurons.begin(), rand() % neurons.size());
    }while(out < this->inputs);

    /*
    std::set<size_t> neurons;

    for(size_t i = 0; i < this->outputs; i++){
        neurons.insert(i + this->lim_hidden);
    }

    for(const auto& gene : this->genes){
        if(gene.into >= this->inputs){
            neurons.insert(gene.into);
        }
        if(gene.out >= this->inputs){
            neurons.insert(gene.out);
        }
    }

    out = *std::next(neurons.begin(), rand() % neurons.size());

    for(size_t i = 0; i < this->inputs; i++){
        neurons.insert(i);
    }

    into = *std::next(neurons.begin(), rand() % neurons.size());
     */
}

// newInnovation
size_t Genotype::Genome::inc_innovation(size_t& innovation) const
{
    innovation++;
    return innovation;
}

// containsLink
bool Genotype::Genome::contains_link(size_t into, size_t out) const
{
    return std::find_if(this->genes.begin(), this->genes.end(), [&](const auto& gene){
        return gene.into == into && gene.out == out;
    }) != this->genes.end();
}

// pointMutate
void Genotype::Genome::mutate_point()
{
    for(auto& gene : this->genes){
        if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < this->mutation_rate_weight){
            gene.weight = ((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * 4.f) - 2.f;
        } else {
            gene.weight += ((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX))
                            * (this->mutation_rates["offset"] * 2.f)) - this->mutation_rates["offset"];
        }
    }
}

// linkMutate
void Genotype::Genome::mutate_link(bool bias, size_t& innovation)
{
    size_t into, out;
    this->rand_neurons(into, out);

    if(into < this->inputs && out < this->inputs){
        return;
    }
    if(out < this->inputs){
        std::swap(into, out);
    }

    if(bias){
        into = this->inputs - 1;
    }

    if(this->contains_link(into, out)){
        return;
    }

    this->genes.emplace_back(
        into,
        out,
        this->inc_innovation(innovation),
        ((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * 4.f) - 2.f,
        true
    );
    this->innovation_set.insert(this->genes.back().innovation); //
    this->innovation_gene_map.insert({this->genes.back().innovation, std::ref(this->genes.back())}); //

    /*
    size_t neuron1 = this->rand_neuron(true);
    size_t neuron2 = this->rand_neuron(false);

    if(neuron1 < this->inputs && neuron2 < this->inputs){
        return;
    }
    if(neuron2 < this->inputs){
        std::swap(neuron1, neuron2);
    }

    Genotype::Gene link;
    link.into = neuron1;
    link.out = neuron2;

    if(bias){
        link.into = this->inputs - 1;
    }

    if(this->contains_link(link)){
        return;
    }

    link.innovation = inc_innovation(innovation);
    link.weight = ((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * 4.f) - 2.f;

    this->genes.push_back(link);
     */
}

// nodeMutate
void Genotype::Genome::mutate_node(size_t& innovation)
{
    if(this->genes.empty()){
        return;
    }

    this->max_neuron++;

    auto& gene = this->genes[std::rand() % this->genes.size()];
    if(! gene.enabled){
        return;
    }
    gene.enabled = false;

    this->genes.emplace_back(
        gene.into,
        this->max_neuron,
        this->inc_innovation(innovation),
        1.f,
        true
    );
    this->innovation_set.insert(this->genes.back().innovation); //
    this->innovation_gene_map.insert({this->genes.back().innovation, std::ref(this->genes.back())}); //

    this->genes.emplace_back(
        this->max_neuron,
        gene.out,
        this->inc_innovation(innovation),
        gene.weight,
        true
    );
    this->innovation_set.insert(this->genes.back().innovation); //
    this->innovation_gene_map.insert({this->genes.back().innovation, std::ref(this->genes.back())}); //
}

// enableDisableMutate
void Genotype::Genome::mutate_enable(bool enable)
{
    std::vector<size_t> candidates;

    for(size_t i = 0; i < this->genes.size(); i++){
        if(this->genes[i].enabled != enable){
            candidates.push_back(i);
        }
    }

    if(candidates.empty()){
        return;
    }

    size_t gene = candidates[std::rand() % candidates.size()];
    this->genes[gene].enabled = ! this->genes[gene].enabled;
}

// mutate
void Genotype::Genome::mutate(size_t& innovation)
{
    for(auto& mutation_rate : this->mutation_rates){
        if(std::rand() % 2){
            mutation_rate.second *= 0.95f;
        } else {
            mutation_rate.second *= 1.05263f;
        }
    }

    if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < this->mutation_rates["gene"]){
        this->mutate_point();
    }

    for(float p = this->mutation_rates["link"]; p > 0.f; p -= 1.f){
        if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < p){
            this->mutate_link(false, innovation);
        }
    }

    for(float p = this->mutation_rates["bias"]; p > 0.f; p -= 1.f){
        if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < p){
            this->mutate_link(true, innovation);
        }
    }

    for(float p = this->mutation_rates["neuron"]; p > 0.f; p -= 1.f){
        if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < p){
            this->mutate_node(innovation);
        }
    }

    for(float p = this->mutation_rates["enable"]; p > 0.f; p -= 1.f){
        if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < p){
            this->mutate_enable(true);
        }
    }

    for(float p = this->mutation_rates["disable"]; p > 0.f; p -= 1.f){
        if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < p){
            this->mutate_enable(false);
        }
    }
}

// disjoint
float Genotype::Genome::delta_disjoints(const Genotype::Genome& other) const
{
    std::vector<size_t> disjoints;

    /*
    std::set<int> innovation_these, innovation_others;

    for(const auto& gene : this->genes){
        innovation_these.insert(gene.innovation);
    }

    for(const auto& gene : others){
        innovation_others.insert(gene.innovation);
    }
     */

    std::set_symmetric_difference(this->innovation_set.begin(), this->innovation_set.end(),
                                  other.innovation_set.begin(), other.innovation_set.end(),
                                  std::back_inserter(disjoints));

    return disjoints.size() / std::fmax(this->innovation_set.size(), other.innovation_set.size());
}

// weights
float Genotype::Genome::delta_weights(const Genotype::Genome& other) const
{
    float sum = 0.f;
    size_t coincident = 0;

    for(const auto& gene : this->genes){
        if(other.innovation_gene_map.count(gene.innovation)){
            sum += std::abs(gene.weight - other.innovation_gene_map.at(gene.innovation).get().weight);
            coincident += 1;
        }
    }

    return sum / coincident;
}

// sameSpecies
bool Genotype::Genome::same_specie(const Genotype::Genome& other) const
{
    return (this->d_disjoint * this->delta_disjoints(other)) + (this->d_weight * this->delta_weights(other))
           < this->d_threshold;
}

void Genotype::Genome::crossover(const Genotype::Genome& other, Genotype::Genome& child) const
{
    const Genotype::Genome* p1_genome = this;
    const Genotype::Genome* p2_genome = &other;

    if(p2_genome->fitness < p1_genome->fitness){
        std::swap(p1_genome, p2_genome);
    }

    child.inputs = p1_genome->inputs;
    child.outputs = p1_genome->outputs;
    child.max_neuron = std::max(p1_genome->max_neuron, p2_genome->max_neuron);
    for(const auto& mutation_rate : p1_genome->mutation_rates){
        child.mutation_rates[mutation_rate.first] = mutation_rate.second;
    }

    for(const auto& gene : p1_genome->genes){
        if(p2_genome->innovation_gene_map.count(gene.innovation) &&
           p2_genome->innovation_gene_map.at(gene.innovation).get().enabled &&
           std::rand() % 2){
            child.genes.push_back(p2_genome->innovation_gene_map.at(gene.innovation).get());
        }else{
            child.genes.push_back(gene);
        }

        child.innovation_set.insert(gene.innovation);
        child.innovation_gene_map.insert({gene.innovation, std::ref(child.genes.back())});
    }
}

// basicGenome
void Genotype::Genome::simple_genome(size_t& innovation)
{
    this->max_neuron = this->inputs - 1;
    this->mutate(innovation);
}

float Genotype::Genome::get_fitness() const { return this->fitness; }
size_t Genotype::Genome::get_global_rank() const { return this->global_rank; }

void Genotype::Genome::set_fitness(float fitness) { this->fitness = fitness; }
void Genotype::Genome::set_global_rank(size_t global_rank) { this->global_rank = global_rank; }
