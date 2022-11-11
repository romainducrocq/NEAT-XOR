#include "neat/neat.hpp"

Neat::Neat()
{
}

void Neat::init()
{
    this->init_func();

    this->mvg_avg = MovingAverage(this->mvg_avg_max);

    this->mdp.obs.clear();
    for(size_t i = 0; i < this->inputs; i++){
        this->mdp.obs.push_back(0.f);
    }

    this->mdp.act.clear();
    for(size_t i = 0; i < this->outputs; i++){
        this->mdp.act.push_back(0.f);
    }

    this->epoch = 0;
    this->generation = 0;

    switch(this->mode){

        case Neat::MODE::TRAIN:
            this->pool.init();
            break;

        case Neat::MODE::EVAL:
            this->best.ctor_network();
            break;

        default:
            break;
    }
}

void Neat::obs()
{
    this->obs_func();
}

void Neat::act()
{
    this->act_func();
}

void Neat::done()
{
    this->done_func();

    this->mdp.done = this->mdp.done ||
                     (this->max_step && this->steps >= this->max_step) ||
                     (this->max_noop && this->noops >= this->max_noop);
}

void Neat::fitness()
{
    this->fitness_func();

    if (this->mdp.done) {
        if (this->mdp.fitness == 0.f) {
            this->mdp.fitness = std::numeric_limits<float>::min();
        }

        this->mvg_avg.add(this->mdp.fitness);
    }
}

void Neat::info()
{
    this->info_func();

    this->ss_info.str(std::string());
}

void Neat::noop()
{
    if(this->noop_func()){
        this->noops++;
    }else{
        this->noops = 0;
    }
}

// initializeRun
void Neat::reset()
{
    this->reset_func();

    this->reset_render();

    this->steps = 0;
    this->noops = 0;

    mdp.done = false;
    mdp.fitness = 0.f;

    this->epoch++;
    this->generation = this->pool.get_generation();

    switch(this->mode){

        case Neat::MODE::TRAIN:
            this->pool.self_curr_genome().ctor_network();
            break;

        case Neat::MODE::EVAL:
            break;

        default:
            break;
    }
}

void Neat::step()
{
    this->step_func();

    this->step_render();

    if(!this->repeat || this->steps % this->repeat == 0){
        this->obs();

        switch(this->mode){

            case Neat::MODE::TRAIN:
                this->pool.eval_curr_genome(this->mdp.obs, this->mdp.act);
                break;

            case Neat::MODE::EVAL:
                this->best.eval_network(this->mdp.obs, this->mdp.act);
                break;

            default:
                break;
        }

        this->noop();
    }

    this->act();

    this->steps++;

    this->done();

    this->fitness();
}

void Neat::reset_render()
{
    this->reset_render_func();
}

void Neat::step_render()
{
    this->step_render_func();
}

void Neat::train()
{
    this->mode = Neat::MODE::TRAIN;

    this->init();

    this->reset();

    while(true){
        this->step();

        if(this->mdp.done){

            this->pool.self_curr_genome().set_fitness(this->mdp.fitness);

            if(this->mdp.fitness > this->pool.get_max_fitness()){
                this->pool.set_max_fitness(this->mdp.fitness);
            }

            while(this->pool.fitness_pass()){
                this->pool.next_genome(this->best);
            }

            if(this->generation < this->pool.get_generation()){
                this->info();

                if(! this->log_plt.empty()) { this->to_plt(); }
            }

            this->reset();
        }

        if(this->max_generation_train && this->generation >= this->max_generation_train){
            break;
        }
    }

    if(! this->log_plt.empty()) { this->plot(); }
    if(! this->log_sav.empty()) { this->best.save(this->log_sav); }
}

void Neat::eval()
{
    this->mode = Neat::MODE::EVAL;

    this->init();

    this->reset();

    while(true){
        this->step();

        if(this->mdp.done) {
            this->info();

            this->reset();
        }

        if(this->max_epoch_eval && this->epoch > this->max_epoch_eval){
            break;
        }
    }
}

void Neat::to_plt()
{
    this->plt_data.first.push_back(static_cast<double>(this->generation));
    this->plt_data.second.push_back(static_cast<double>(this->mvg_avg.get()));
}

void Neat::plot()
{
    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    ScatterPlotSeries* series = GetDefaultScatterPlotSeriesSettings();
    series->xs = &this->plt_data.first;
    series->ys = &this->plt_data.second;
    series->linearInterpolation = true;
    series->lineType = toVector(L"solid");
    series->color = CreateRGBColor(0, 0, 1);

    std::string str;
    ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
    settings->width = 1200;
    settings->height = 800;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    str = "Learning Curve : " + this->log_plt;
    settings->title = toVector(std::wstring(str.begin(), str.end()).c_str());
    str = "Generations (" + std::to_string(this->max_generation_train) + ")";
    settings->xLabel = toVector(std::wstring(str.begin(), str.end()).c_str());
    str = "Fitness (Mvg Avg " + std::to_string(this->mvg_avg.max()) + ")";
    settings->yLabel = toVector(std::wstring(str.begin(), str.end()).c_str());
    settings->scatterPlotSeries->push_back(series);

    DrawScatterPlotFromSettings(imageReference, settings, nullptr);

    std::vector<double>* pngData = ConvertToPNG(imageReference->image);
    WriteToFile(pngData, "../../log/plots/" + this->log_plt + ".png");
    DeleteImage(imageReference->image);
}
