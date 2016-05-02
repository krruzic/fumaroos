#ifndef FUMAROOS_DANCEBUTTON_HPP
#define FUMAROOS_DANCEBUTTON_HPP

#include <cpp3ds/Window/Event.hpp>
#include <cpp3ds/Graphics/Sprite.hpp>
#include "../../GUI/Button.hpp"

namespace Minigame {
    class DanceButton : public gui3ds::Button {
    public:
        virtual bool processEvent(const cpp3ds::Event &event) override;

        virtual void draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const override;

        DanceButton(cpp3ds::Keyboard::Key button = cpp3ds::Keyboard::Select);

        cpp3ds::Keyboard::Key getKey();

        void setSprite(cpp3ds::Sprite sprite);

    private:
        cpp3ds::Keyboard::Key m_buttonKey;
    };
}

#endif //FUMAROOS_DANCEBUTTON_HPP
