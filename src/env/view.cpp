#include "env/view.hpp"

/*** DEF EVENT SETUP HERE */
void View::EventHandler::ev_setup()
{
}

/*** DEF ACTION HANDLER HERE */
void View::EventHandler::get_action(std::array<float, CONF::OUTPUTS>& act)
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

/*** DEF DRAW SETUP HERE */
void View::Renderer::draw_setup(const MyEnv::Model& /*m*/)
{
}

/*** DEF DRAW LOOP HERE */
void View::Renderer::draw_loop(const MyEnv::Model& /*m*/)
{
}

/*** DEF DRAW FUNCS HERE */

