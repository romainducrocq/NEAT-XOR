#ifndef _ENV_VIEW_HPP
#define _ENV_VIEW_HPP

#include <iostream>
#include <vector>

#include "env/conf.hpp"

#include "env/env.hpp"

namespace View
{
    class EventHandler
    {
        struct EventState
        {
            CONF::Action action = CONF::ZERO;
        };

        private:
            EventState ev_state;

        private:
            EventHandler();

        public:
            void ev_setup();
            void get_action(std::vector<float>& act);

        public:
            EventHandler(const EventHandler& other) = delete;
            EventHandler operator=(const EventHandler& other) = delete;

            static EventHandler& EVENTHANDLER()
            {
                static EventHandler singleton;
                return singleton;
            }
    };

    class Renderer
    {
        private:
            Renderer();

        public:
            void draw_setup(const Env& /*env*/);
            void draw_loop(const Env& /*env*/);

        public:
            Renderer(const Renderer& other) = delete;
            Renderer operator=(const Renderer& other) = delete;

            static Renderer& RENDERER()
            {
                static Renderer singleton;
                return singleton;
            }
    };
}

#endif