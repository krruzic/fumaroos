#ifndef FUMAROOS_TITLESTATE_HPP
#define FUMAROOS_TITLESTATE_HPP

#include "State.hpp"
#include "../GUI/Button.hpp"
#include <cpp3ds/Graphics/Sprite.hpp>
#include <cpp3ds/Graphics/Text.hpp>

namespace Fumaroos {

    class TitleState : public State {
    public:
        TitleState(StateStack &stack, Context &context);

        virtual void renderTopScreen(cpp3ds::Window &window);

        virtual void renderBottomScreen(cpp3ds::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const cpp3ds::Event &event);

        bool checkSave();

    private:
        cpp3ds::Text m_textTitle;
        cpp3ds::Sprite m_titleBackground;
        gui3ds::Button m_startButton;
    };

} // namespace Fumaroos

#endif // FUMAROOS_TITLESTATE_HPP
