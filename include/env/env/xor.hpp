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

        std::array<std::pair<std::vector<float>, float>, 4> data; /* {{
                {{0.f, 0.f}, false},
                {{0.f, 1.f}, true},
                {{1.f, 0.f}, true},
                {{1.f, 1.f}, false}
            }}; */

    public:
        Xor();

        void shuffle_data();
        void next_data();

        const std::vector<float>& get_x() const;
        float get_y() const;
        bool is_end() const;
};

#endif