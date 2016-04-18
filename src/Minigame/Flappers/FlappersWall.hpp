#ifndef FUMAROOS_FLAPPERSWALL_HPP
#define FUMAROOS_FLAPPERSWALL_HPP

#include <cpp3ds/Graphics/RectangleShape.hpp>
#include <cpp3ds/Graphics/RenderTarget.hpp>
#include <cpp3ds/Graphics/Texture.hpp>

class FlappersWall : public cpp3ds::Drawable, public cpp3ds::Transformable {
public:
    FlappersWall();

    void draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const override;

    int getWidth();

//    void setPosition(float x, float y);

    cpp3ds::IntRect getLowerIntRect(const cpp3ds::Vector2f &position);

    cpp3ds::IntRect getUpperIntRect(const cpp3ds::Vector2f &position);

    cpp3ds::RectangleShape &getLowerWall();

    cpp3ds::RectangleShape &getUpperWall();

private:
    int gapHeight;
    int wallWidth;
    int minHeight;

    cpp3ds::RectangleShape wallLower;
    cpp3ds::RectangleShape wallUpper;
};

#endif //FUMAROOS_FLAPPERSWALL_HPP
