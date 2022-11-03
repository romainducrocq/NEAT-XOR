#include "env/env/xor.hpp"

Xor::Xor()
{
    this->data[0] = {{0.f, 0.f}, 0.f};
    this->data[1] = {{0.f, 1.f}, 1.f};
    this->data[2] = {{1.f, 0.f}, 1.f};
    this->data[3] = {{1.f, 1.f}, 0.f};
}

void Xor::shuffle_data()
{
    for(size_t i = 0; i < data.size(); i++){
        std::swap(data[i], data[std::rand() % data.size()]);
    }

    this->curr = -1;
}

void Xor::next_data()
{
    this->curr++;
}

const std::vector<float>& Xor::get_x() const
{
    return this->data[this->curr].first;
}

float Xor::get_y() const
{
    return this->data[this->curr].second;
}

bool Xor::is_end() const
{
    return this->curr == this->data.size() - 1;
}