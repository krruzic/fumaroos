#include "DanceButton.hpp"
namespace Minigame {

    DanceButton::DanceButton(cpp3ds::Keyboard::Key button) {
        m_buttonKey = button;
        setPosition(50, 390);
    }

    bool DanceButton::processEvent(const cpp3ds::Event &event) {
        return false;
    }

    void DanceButton::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        target.draw(m_sprite, states);
    }

    cpp3ds::Keyboard::Key DanceButton::getKey() {
        return m_buttonKey;
    }

    void DanceButton::setSprite(cpp3ds::Sprite sprite) {
        m_sprite = sprite;
    }
};
