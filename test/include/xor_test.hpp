#ifndef _TEST_NN_HPP
#define _TEST_NN_HPP

#include <gtest/gtest.h>

#include <vector>

#include "env/env/xor.hpp"

#include "gtutils.hpp"

struct XorState
{
    const std::vector<std::vector<float>> xs;
    const std::vector<float> ys;
};

struct XorTest : testing::Test, testing::WithParamInterface<XorState>
{
    XorTest() {}
};

#endif