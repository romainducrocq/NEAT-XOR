#include "env/view.hpp"

EventHandler::EventHandler()
{
}

void EventHandler::add_event()
{
}

void EventHandler::get_action(std::vector<float>& act)
{
    size_t x;

    [&] {
        while(true){
            std::cin >> x;
            switch(x){
                case 0:
                    this->ev_state.action = CONF::Action::ZERO;
                    return;
                case 1:
                    this->ev_state.action = CONF::Action::ONE;
                    return;
                default:
                    break;
            }
        }
    }();

    std::cout << "\n";

    act[0] = x;
}

Renderer::Renderer()
{
}

void Renderer::draw_init(const Env& /*env*/)
{
}

void Renderer::draw_loop(const Env& /*env*/)
{
}
