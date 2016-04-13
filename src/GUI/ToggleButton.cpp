#include "ToggleButton.hpp"


namespace gui3ds {

    ToggleButton::ToggleButton()
            : m_needsUpdate(true), m_active(false) {

    }

    void ToggleButton::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        ensureUpdate(target, states);
        if (!m_text.getString().isEmpty())
            target.draw(m_text, states);
    }

    void ToggleButton::setTextOffset(const cpp3ds::Vector2f &offset) {
        m_textOffset = offset;
        m_needsUpdate = true;
    }

    const cpp3ds::Vector2f &ToggleButton::getTextOffset() const {
        return m_textOffset;
    }

    void ToggleButton::setString(const cpp3ds::String &string) {
        m_text.setString(string);
        m_needsUpdate = true;
    }

    const cpp3ds::String &ToggleButton::getString() const {
        return m_text.getString();
    }

    const u_int ToggleButton::getTextSize() const {
        return m_text.getCharacterSize();
    }

    void ToggleButton::setTextSize(const u_int &size) {
        m_text.setCharacterSize(size);
    }

    void ToggleButton::setTextColor(const cpp3ds::Color &color) {
        m_textColor = color;
        m_needsUpdate = true;
    }

    const cpp3ds::Color &ToggleButton::getTextColor() const {
        return m_textColor;
    }

    void ToggleButton::setTextActiveColor(const cpp3ds::Color &color) {
        m_textActiveColor = color;
        m_needsUpdate = true;
    }

    const cpp3ds::Color &ToggleButton::getTextActiveColor() const {
        return m_textActiveColor;
    }

    void ToggleButton::setTexture(const cpp3ds::Texture &texture) {
        m_texture.setTexture(texture);
        m_needsUpdate = true;
    }

    void ToggleButton::setActiveTexture(const cpp3ds::Texture &texture) {
        m_activeTexture.setTexture(texture);
        m_needsUpdate = true;
    }

    void ToggleButton::setPosition(float x, float y) {
        m_texture.setPosition(x, y);
        m_activeTexture.setPosition(x, y);
        util3ds::TweenTransformable::setPosition(x,y);
    }

    const cpp3ds::FloatRect ToggleButton::getRect() const {
        return m_rect;
    }

    void ToggleButton::toggle() {
        m_active = !m_active;
        m_needsUpdate = true;
    }

    bool ToggleButton::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::TouchBegan) {
            if (m_texture.getGlobalBounds().contains(event.touch.x, event.touch.y)) {
                toggle();
                return false;
            }
        }

        if (event.type == cpp3ds::Event::TouchEnded) {
            if (m_active) {
                if (m_clickFunction)
                    m_clickFunction();
                return false;
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

    void ToggleButton::ensureUpdate(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        if (m_needsUpdate) {
            if (m_active) {
                target.draw(m_activeTexture, states);
            } else {
                target.draw(m_texture, states);
            }
        }
    };

    void ToggleButton::onClick(const std::function<void()> &callback) {
        m_clickFunction = callback;
    }

    cpp3ds::Text &ToggleButton::getText() const {
        return m_text;
    }


} // namespace gui3ds
