#include <string>
#include "Flappers.hpp"

namespace Fumaroos {

    Flappers::Flappers(StateStack &stack, Context &context)
            : State(stack, context) {
        TextureManager *texmgr = &context.texmgr;
        texmgr->loadTexture(States::Flappers, "spritesheet", "sprites/ss.png");
        texmgr->loadTexture(States::Flappers, "pipeT", "imgs/pipeT.png");
        texmgr->loadTexture(States::Flappers, "pipeB", "imgs/pipeB.png");
        m_animSpriteSheet.setSpriteSheet(texmgr->getRef(States::Flappers, "spritesheet"));

        m_animSpriteSheet.addFrames("mold", cpp3ds::IntRect(0, 0, 320, 64), 5, 64);
        AnimatedSprite m_temp = AnimatedSprite(0.4f, false, true, "mold");
        m_temp.setSpriteManager(m_animSpriteSheet);

        m_birdaroo.setSprite(m_temp);

        m_pointsText.setString(_("0"));
        m_pointsText.setCharacterSize(20);
        m_pointsText.setPosition(380.f - m_pointsText.getLocalBounds().width, 0.f);

        wallDistance = 120;
        jumpVelocity = -40;
        gravity = 90;
        birdarooVelocity = 0.f;
        wallSpeed = -340;
        paused = true;
        restart();
    }

    bool Flappers::update(float delta) {
        m_birdaroo.update(delta);
//        std::string m_pointsString = std::to_string(m_points);
        m_pointsText.setPosition(380.f - m_pointsText.getLocalBounds().width, 0.f);

//        m_pointsText.setString(_(m_pointsString));
        if (!paused) {
            move_delta += delta;
            if (move_delta >= 0.1f) {
                moveBird(delta);
                moveWalls(delta);
                move_delta = 0;
            }
            checkBirdBounds();
            handleCollisions();
        }
        return true;
    }

    bool Flappers::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::KeyPressed) {
            if (event.key.code == cpp3ds::Keyboard::A) {
                birdarooVelocity = jumpVelocity;
                paused = false;
            }
        }
        return false;
    }

    void Flappers::renderTopScreen(cpp3ds::Window &window) {
        window.clear(cpp3ds::Color(0, 150, 255));
        for (std::deque<FlappersWall>::iterator it = m_walls.begin(); it != m_walls.end(); ++it) {
            window.draw(*it);
        }
        window.draw(m_pointsText);

        window.draw(m_birdaroo);
    }

    void Flappers::renderBottomScreen(cpp3ds::Window &window) {
    }

    void Flappers::restart() {
        m_points = 0;
//        std::string m_pointsString = std::to_string(m_points);
        m_birdaroo.setPosition(0.2 * 400, (240 - m_birdaroo.getSize().y) / 2);
        paused = true;
        m_walls.clear();
        FlappersWall newWall;
        loadWallTextures(newWall);
        newWall.setPosition(0.7 * 400, 0);
        m_walls.push_back(newWall);
    }

    void Flappers::loadWallTextures(FlappersWall &wall) {
        wall.getLowerWall().setTexture(&this->getContext().texmgr.getRef(States::Flappers, "pipeB"));
        wall.getUpperWall().setTexture(&this->getContext().texmgr.getRef(States::Flappers, "pipeT"));
    }

    void Flappers::moveBird(float delta) {
        birdarooVelocity += move_delta * gravity;
        float offset = move_delta * (birdarooVelocity + move_delta * gravity / 2);

        m_birdaroo.move(0, offset);
    }

    void Flappers::handleCollisions() {
        for (std::deque<FlappersWall>::iterator it = m_walls.begin(); it != m_walls.end(); ++it) {
            cpp3ds::IntRect lowerIntRect = (*it).getLowerIntRect((*it).getPosition());
            cpp3ds::IntRect upperIntRect = (*it).getUpperIntRect((*it).getPosition());
            cpp3ds::IntRect birdIntRect = m_birdaroo.getIntRect(m_birdaroo.getPosition());
            cpp3ds::IntRect inbetweenRect = cpp3ds::IntRect(lowerIntRect.left, lowerIntRect.height, lowerIntRect.width,
                                                            240 - upperIntRect.height - lowerIntRect.height);
            if (lowerIntRect.intersects(birdIntRect) || upperIntRect.intersects(birdIntRect)) {
                restart();
            }
            else if (m_birdaroo.getPosition().y + m_birdaroo.getSize().y <= 0 &&
                     m_birdaroo.getPosition().x + m_birdaroo.getSize().x > (*it).getPosition().x &&
                     m_birdaroo.getPosition().x < (*it).getPosition().x
                                                  + (*it).getWidth()) {
                restart();
            }
        }
    }

    void Flappers::checkBirdBounds() {
        if (m_birdaroo.getPosition().y + m_birdaroo.getSize().y >= 240) {
            restart();
        }
    }

    void Flappers::moveWalls(float delta) {
        for (std::deque<FlappersWall>::iterator it = m_walls.begin(); it != m_walls.end(); ++it) {
            (*it).move(cpp3ds::Vector2f(delta * wallSpeed, 0));

            int distance = 400 - (*it).getPosition().x - (*it).getWidth();

            if (it == --m_walls.end()) {
                if (distance >= wallDistance) {
                    FlappersWall wall;
                    wall.setPosition(400, 0);
                    loadWallTextures(wall);
                    m_walls.push_back(wall);
                    break;
                }
            }

            if (distance >= 400) {
                m_walls.pop_front();
            }
        }
    }
}