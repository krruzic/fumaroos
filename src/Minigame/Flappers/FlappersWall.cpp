#include "FlappersWall.hpp"

#include <iostream>
#include <cpp3ds/Graphics/Drawable.hpp>

FlappersWall::FlappersWall()
{
    gapHeight = 70;
    minHeight = 20;
    wallWidth = 52;
    wallLower.setSize(cpp3ds::Vector2f(wallWidth, minHeight + rand() % (240
                                                                    - 2 * minHeight - gapHeight)));
    wallUpper.setSize(cpp3ds::Vector2f(wallWidth, 240 - gapHeight - wallLower.getSize().y));
    wallLower.setPosition(0, 240 - wallLower.getSize().y);
    wallUpper.setPosition(0, 0);
}

//void FlappersWall::setPosition(float x, float y) {
//    wallLower.setPosition(x, 240 - wallLower.getSize().y);
//    wallUpper.setPosition(x, y);
//}

void FlappersWall::draw(cpp3ds::RenderTarget& target, cpp3ds::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(wallLower, states);
    target.draw(wallUpper, states);
}

int FlappersWall::getWidth()
{
    return wallWidth;
}

cpp3ds::IntRect FlappersWall::getLowerIntRect(const cpp3ds::Vector2f& position)
{
    return cpp3ds::IntRect(position.x, position.y + wallUpper.getSize().y + gapHeight,
                       wallLower.getSize().x, wallLower.getSize().y);
}

cpp3ds::IntRect FlappersWall::getUpperIntRect(const cpp3ds::Vector2f& position)
{
    return cpp3ds::IntRect(position.x, position.y, wallUpper.getSize().x, wallUpper.getSize().y);
}

cpp3ds::RectangleShape& FlappersWall::getLowerWall()
{
    return wallLower;
}

cpp3ds::RectangleShape& FlappersWall::getUpperWall()
{
    return wallUpper;
}
