#ifndef _UTILS_UTILS_HPP
#define _UTILS_UTILS_HPP

#include <iostream>
#include <chrono>

#include <vector>

struct Timer
{
    std::chrono::_V2::system_clock::time_point m_start, m_end;
    std::chrono::duration<float> m_duration;

    Timer()
    {
        this->m_start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        this->m_end = std::chrono::high_resolution_clock::now();
        this->m_duration = this->m_end - this->m_start;

        float ms = this->m_duration.count() * 1000.0f;
        std::cout << "Time: " << ms << "ms" << std::endl;
    }
};

struct MovingAverage
{
private:
    size_t n = 0;
    size_t i = 0;
    float t = 0.f;

    float avg = 0.f;

    std::vector<float> xs;

public:
    MovingAverage() {}

    MovingAverage(size_t n)
            : n(n) {}

    void add(float x)
    {
        this->t += x;
        this->i = (this->i + 1) % this->n;
        if(this->xs.size() < n){
            this->xs.push_back(x);
        }else{
            this->t -= this->xs[this->i];
            this->xs[this->i] = x;
        }

        this->avg = this->t / this->xs.size();
    }

    float get() const
    {
        return this->avg;
    }

    size_t max() const
    {
        return this->n;
    }
};

#endif