#ifndef _ENV_XOR_HPP
#define _ENV_XOR_HPP

#include <cstdlib>

#include <array>
#include <vector>
#include <utility>

class Xor
{
    private:
        size_t inputs = 2;
        size_t self = 0;

        std::array<std::pair<std::vector<float>, bool>, 4> data; /* {{
                {{0.f, 0.f}, false},
                {{0.f, 1.f}, true},
                {{1.f, 0.f}, true},
                {{1.f, 1.f}, false}
            }}; */

    public:
        Xor();

        const std::vector<float>& obs() const;

        void reset();
        void step();
};

#endif