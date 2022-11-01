#include "env/env/xor.hpp"

Xor::Xor()
{
    this->data[0] = {{0.f, 0.f}, false};
    this->data[1] = {{0.f, 1.f}, true};
    this->data[2] = {{1.f, 0.f}, true};
    this->data[3] = {{1.f, 1.f}, false};
}

/*
const std::vector<float>& Xor::obs() const
{
    return this->data[this->self].first;
}
*/

void Xor::rand_data()
{
    this->curr = std::rand() % 4;
}