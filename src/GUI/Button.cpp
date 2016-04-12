#include "Button.hpp"


namespace gui3ds {

    Button::Button()
            : m_needsUpdate(true), m_active(false) {

    }

    void Button::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        states.transform *= getTransform();
        ensureUpdate(target, states);

        if (!m_text.getString().isEmpty())
            target.draw(m_text, states);
    }

    void Button::setTextOffset(const cpp3ds::Vector2f &offset) {
        m_textOffset = offset;
        m_needsUpdate = true;
    }

    const cpp3ds::Vector2f &Button::getTextOffset() const {
        return m_textOffset;
    }

    void Button::setString(const cpp3ds::String &string) {
        m_text.setString(string);
        m_needsUpdate = true;
    }

    const cpp3ds::String &Button::getString() const {
        return m_text.getString();
    }

    const u_int Button::getTextSize() const {
        return m_text.getCharacterSize();
    }

    void Button::setTextSize(const u_int &size) {
        m_text.setCharacterSize(size);
    }

    void Button::setTextColor(const cpp3ds::Color &color) {
        m_textColor = color;
        m_needsUpdate = true;
    }

    const cpp3ds::Color &Button::getTextColor() const {
        return m_textColor;
    }

    void Button::setTextActiveColor(const cpp3ds::Color &color) {
        m_textActiveColor = color;
        m_needsUpdate = true;
    }

    const cpp3ds::Color &Button::getTextActiveColor() const {
        return m_textActiveColor;
    }

    void Button::setTexture(const cpp3ds::Texture &texture) {
        m_texture.setTexture(texture);
    }

    void Button::setActiveTexture(const cpp3ds::Texture &texture) {
        m_activeTexture.setTexture(texture);
    }


    const cpp3ds::FloatRect Button::getRect() const {
        return m_rect;
    }

    void Button::toggle() {
        m_active = !m_active;
        m_needsUpdate = true;
    }

    bool Button::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::TouchBegan) {
            if (m_rect.contains(event.touch.x, event.touch.y)) {
//                toggle();
                return false;
            }
        }

        if (event.type == cpp3ds::Event::TouchEnded) {
            if (m_active) {
                toggle();
                if (m_clickFunction)
                    m_clickFunction();
                return false;
            }
        }

        if (event.type == cpp3ds::Event::TouchMoved) {
            if (m_active) {
                if (!m_rect.contains(event.touch.x, event.touch.y)) {
                    m_active = false;
                    m_needsUpdate = true;
                }
                return false;
            }
        }

        return true;
    }

    void Button::ensureUpdate(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        if (m_needsUpdate) {
            if (m_active) {
                target.draw(m_activeTexture, states);
            } else {
                target.draw(m_texture, states);
            }
        }
    };

    void Button::onClick(const std::function<void()> &callback) {
        m_clickFunction = callback;
    }

    cpp3ds::Text &Button::getText() const {
        return m_text;
    }


} // namespace gui3ds
