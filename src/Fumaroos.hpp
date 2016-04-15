#ifndef FUMAROOS_FUMAROOS_HPP
#define FUMAROOS_FUMAROOS_HPP

#include <cpp3ds/Graphics.hpp>
#include <cpp3ds/Network.hpp>
#include "States/StateStack.hpp"
#include "TextureManager.hpp"

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
        StateStack m_stateStack;

        // Shared State context variables
        cpp3ds::String m_name;
        cpp3ds::String m_data;
        cpp3ds::Color m_color;
        TextureManager m_texmgr;
    };

}

#endif //FUMAROOS_FUMAROOS_HPP
