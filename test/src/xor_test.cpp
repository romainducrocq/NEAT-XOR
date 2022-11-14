#include "xor_test.hpp"

TEST_P(XorTest, Xor_P)
{
    auto as = GetParam();

    Xor agent;

    agent.shuffle_data();
    agent.reset_data();

    for(size_t i = 0; i < 4; i++){
        ASSERT_FALSE(agent.is_end());

        agent.next_data();

        GTEST_UTILS::EXPECT_FEQ(as.xs[i][0], agent.get_x()[0], 5);
        GTEST_UTILS::EXPECT_FEQ(as.xs[i][1], agent.get_x()[1], 5);
        GTEST_UTILS::EXPECT_FEQ(as.ys[i], agent.get_y(), 5);
    }

    ASSERT_TRUE(agent.is_end());

    agent.reset_data();

    ASSERT_FALSE(agent.is_end());
}

INSTANTIATE_TEST_SUITE_P(ActivationInstanciation, XorTest,
                         testing::Values(
                                 XorState{{{0.f, 1.f}, {1.f, 1.f}, {1.f, 0.f}, {0.f, 0.f}}, {1.f, 0.f, 1.f, 0.f}},
                                 XorState{{{1.f, 1.f}, {0.f, 1.f}, {1.f, 0.f}, {0.f, 0.f}}, {0.f, 1.f, 1.f, 0.f}},
                                 XorState{{{1.f, 1.f}, {0.f, 0.f}, {1.f, 0.f}, {0.f, 1.f}}, {0.f, 0.f, 1.f, 1.f}},
                                 XorState{{{1.f, 0.f}, {0.f, 1.f}, {1.f, 1.f}, {0.f, 0.f}}, {1.f, 1.f, 0.f, 0.f}},
                                 XorState{{{0.f, 1.f}, {0.f, 0.f}, {1.f, 0.f}, {1.f, 1.f}}, {1.f, 0.f, 1.f, 0.f}}
                         )
);