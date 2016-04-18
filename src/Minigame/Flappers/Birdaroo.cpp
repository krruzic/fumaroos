#include "Birdaroo.hpp"

Birdaroo::Birdaroo() {
}

void Birdaroo::setSprite(AnimatedSprite sprite) {
    m_sprite = sprite;
//    cpp3ds::Vector2f m_temp = m_sprite.getSize();
//    m_bounding = cpp3ds::IntRect(m_sprite.getPosition().x + 4, m_sprite.getPosition().y + 12, m_temp.x - 4, m_temp.y - 12);
}

void Birdaroo::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_sprite, states);
}

cpp3ds::Vector2f Birdaroo::getSize() {
    cpp3ds::Vector2f m_temp = m_sprite.getSize();
    return cpp3ds::Vector2f(m_temp.x - 8, m_temp.y - 24);
}

void Birdaroo::update(float delta) {
    m_sprite.update(delta);
}


cpp3ds::IntRect Birdaroo::getIntRect(const cpp3ds::Vector2f &position) {
    cpp3ds::Vector2f m_temp = m_sprite.getSize();
//    m_bounding.Rect(position.x + 4, position.y + 12, m_temp.x - 4, m_temp.y - 12);
    return cpp3ds::IntRect(position.x + 4, position.y + 12, m_temp.x - 4, m_temp.y - 12);
}

