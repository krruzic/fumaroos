#ifndef FUMAROOS_FUMAROOS_HPP
#define FUMAROOS_FUMAROOS_HPP

#include <cpp3ds/Graphics.hpp>
#include <cpp3ds/Network.hpp>
#include "States/StateStack.hpp"

namespace Fumaroos {

    class Fumaroos : public cpp3ds::Game {
    public:
        Fumaroos();

        ~Fumaroos();

        void update(float delta);

        void processEvent(cpp3ds::Event &event);

        void renderTopScreen(cpp3ds::Window &window);

        void renderBottomScreen(cpp3ds::Window &window);


    private:
        StateStack m_topStateStack;
        StateStack m_bottomStateStack;

        // Shared State context variables
//        cpp3ds::String m_name;
//        cpp3ds::String m_data;
//        cpp3ds::Color m_color;

        // Shared State context variables
        cpp3ds::String m_topName;
        cpp3ds::String m_topData;
        cpp3ds::Color m_topColor;

        // Shared State context variables
        cpp3ds::String m_bottomName;
        cpp3ds::String m_bottomData;
        cpp3ds::Color m_bottomColor;
    };

}

#endif //FUMAROOS_FUMAROOS_HPP
