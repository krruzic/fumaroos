#ifndef FUMAROOS_BIRDAROO_HPP
#define FUMAROOS_BIRDAROO_HPP

#include <cpp3ds/Graphics/RenderTarget.hpp>
#include <cpp3ds/Graphics/RectangleShape.hpp>
#include <cpp3ds/Graphics/Texture.hpp>
#include "../../AnimatedSprite.hpp"


class Birdaroo : public cpp3ds::Drawable, public cpp3ds::Transformable {

public:
    Birdaroo();

    void draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const override;

    cpp3ds::Vector2f getSize();

    cpp3ds::IntRect getIntRect(const cpp3ds::Vector2f &position);

    void update(float delta);

    void setSprite(AnimatedSprite sprite);

private:
    AnimatedSprite m_sprite;
//    cpp3ds::IntRect m_bounding;
};


#endif //FUMAROOS_BIRDAROO_HPP
