#ifndef _ENV_VIEW_HPP
#define _ENV_VIEW_HPP

#include <iostream>
#include <vector>

#include "env/conf.hpp"

#include "env/env.hpp"

class EventHandler
{
    struct EventState
    {
        CONF::Action action = CONF::ZERO;
    };

    private:
        EventState ev_state;

    public:
        EventHandler();

        void add_event();
        void get_action(std::vector<float>& act);
};

class Renderer
{
    private:

    public:
        Renderer();

        void draw_init(const Env& /*env*/);
        void draw_loop(const Env& /*env*/);
};

#endif