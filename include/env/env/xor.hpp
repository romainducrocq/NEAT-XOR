#ifndef _ENV_XOR_HPP
#define _ENV_XOR_HPP

#include <cstdlib>

#include <array>
#include <vector>
#include <utility>

class Xor
{
    private:
        size_t curr = -1;

        std::array<std::pair<std::vector<float>, float>, 4> data;

    public:
        Xor();

        void shuffle_data();
        void reset_data();
        void next_data();

        const std::vector<float>& get_x() const;
        float get_y() const;
        bool is_end() const;
};

#endif