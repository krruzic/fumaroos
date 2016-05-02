#ifndef FUMAROOS_FLAPPERS_HPP
#define FUMAROOS_FLAPPERS_HPP

#include "../../States/State.hpp"
#include "FlappersWall.hpp"
#include "Birdaroo.hpp"

namespace Fumaroos {

    class Flappers : public State {
    public:
        Flappers(StateStack &stack, Context &context);

        virtual void renderTopScreen(cpp3ds::Window &window);

        virtual void renderBottomScreen(cpp3ds::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const cpp3ds::Event &event);

        void restart();

        void moveBird(float timedelta);

        void moveWalls(float timedelta);

        void handleCollisions();

        void checkBirdBounds();

        void loadWallTextures(Minigame::FlappersWall &wall);

        std::string intToString(int a);

    private:
        SpriteManager m_animSpriteSheet;
        Minigame::Birdaroo m_birdaroo;
        std::deque<Minigame::FlappersWall> m_walls;
        cpp3ds::Text m_pointsText;
        int wallSpeed;
        int wallDistance;
        int jumpVelocity;
        int gravity;
        float birdarooVelocity;
        bool paused;
        float move_delta;
        int m_points;
    };

}
#endif //FUMAROOS_FLAPPERS_HPP
