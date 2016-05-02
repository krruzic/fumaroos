#include "Button.hpp"

namespace gui3ds {

    Button::Button() : m_needsUpdate(true), m_active(false) {
    }

    void Button::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        ensureUpdate(target, states);
    }


    void Button::setTexture(const cpp3ds::Texture &texture) {
        m_sprite.setTexture(texture);
        m_needsUpdate = true;
    }


    void Button::setActiveTexture(const cpp3ds::Texture &texture) {
        m_activeSprite.setTexture(texture);
        m_needsUpdate = true;
    }


    void Button::setPosition(float x, float y) {
        m_sprite.setPosition(x, y);
        m_activeSprite.setPosition(x, y);
        cpp3ds::Transformable::setPosition(x, y);
    }

    void Button::move(float x, float y) {
        m_sprite.move(x, y);
        m_activeSprite.move(x, y);
        cpp3ds::Transformable::move(x, y);
    }

    bool Button::getActive() {
        return m_active;
    }

    cpp3ds::IntRect Button::getRect() {
        m_activeSprite.getTextureRect();
    }


    void Button::toggle() {
        m_active = !m_active;
        m_needsUpdate = true;
    }

    bool Button::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::TouchBegan) {
            if (m_sprite.getGlobalBounds().contains(event.touch.x, event.touch.y)) {
                m_touched = true;
                toggle();
                return false;
            }
        }

        if (event.type == cpp3ds::Event::TouchEnded) {
            if (m_touched) {
                m_touched = false;
                if (!m_sprite.getGlobalBounds().contains(event.touch.x, event.touch.y)) {
                    toggle();
                    return false;
                } else {
                    if (m_clickFunction)
                        m_clickFunction();
                    return false;
                }
            }
        }
//
//        if (event.type == cpp3ds::Event::TouchMoved) {
//            if (m_active) {
//                if (!m_rect.contains(event.touch.x, event.touch.y)) {
//                    m_active = false;
//                    m_needsUpdate = true;
//                }
//                return false;
//            }
//        }

        return true;
    }

    void Button::ensureUpdate(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        if (m_needsUpdate) {
//            target.draw(m_sprite, states);
            if (m_active) {
                target.draw(m_activeSprite, states);
            } else {
                target.draw(m_sprite, states);
            }
        }
    };

    void Button::onClick(const std::function<void()> &callback) {
        m_clickFunction = callback;
    }
} // namespace gui3ds
