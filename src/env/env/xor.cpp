#include "env/env/xor.hpp"

Xor::Xor()
{
    this->data[0] = {{0.f, 0.f}, false};
    this->data[1] = {{0.f, 1.f}, true};
    this->data[2] = {{1.f, 0.f}, true};
    this->data[3] = {{1.f, 1.f}, false};
}

void Xor::next_data()
{
    this->curr = std::rand() % 4;
}

const std::vector<float>& Xor::get_x() const
{
    return this->data[this->curr].first;
}

bool Xor::get_y() const
{
    return this->data[this->curr].second;
}