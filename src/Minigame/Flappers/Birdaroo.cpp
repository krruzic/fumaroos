#include "Birdaroo.hpp"

namespace Minigame {
    Birdaroo::Birdaroo() {
    }

    void Birdaroo::setSprite(AnimatedSprite sprite) {
        m_sprite = sprite;
        m_bounding.setOutlineColor(cpp3ds::Color::Red);
        m_bounding.setOutlineThickness(1);
        m_bounding.setSize(cpp3ds::Vector2f(m_sprite.getSize().x - 32, m_sprite.getSize().y - 26));
//    cpp3ds::Vector2f m_temp = m_sprite.getSize();
//    m_bounding = cpp3ds::IntRect(m_sprite.getM_bounding.position().x + 4, m_sprite.getM_bounding.position().y + 12, m_temp.x - 4, m_temp.y - 12);
    }

    void Birdaroo::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
        states.transform *= getTransform();
//    target.draw(m_bounding, states);
        target.draw(m_sprite, states);
    }

    void Birdaroo::move(float x, float y) {
        m_sprite.move(x, y);
        m_bounding.move(x, y);
    }

    void Birdaroo::setPosition(float x, float y) {
        m_bounding.setPosition(x, y);
        m_sprite.setPosition(x - 17, y - 13);
    }

    cpp3ds::Vector2f Birdaroo::getSize() {
        cpp3ds::Vector2f m_temp = m_sprite.getSize();
        return cpp3ds::Vector2f(m_temp.x - 8, m_temp.y - 24);
    }

    void Birdaroo::update(float delta) {
        m_sprite.update(delta);
    }


    cpp3ds::FloatRect Birdaroo::getBounding() {
//    cpp3ds::Vector2f m_temp = m_sprite.getSize();
        return cpp3ds::FloatRect(m_bounding.getPosition().x, m_bounding.getPosition().y + m_bounding.getSize().y,
                                 m_bounding.getSize().x, m_bounding.getSize().y);
    }

}