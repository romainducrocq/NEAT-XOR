#include "env/view.hpp"

View::EventHandler::EventHandler()
{
}

void View::EventHandler::ev_setup()
{
}

void View::EventHandler::get_action(std::vector<float>& act)
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

View::Renderer::Renderer()
{
}

void View::Renderer::draw_setup(const Env& /*env*/)
{
}

void View::Renderer::draw_loop(const Env& /*env*/)
{
}
