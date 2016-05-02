#ifndef FUMAROOS_DANCE_HPP
#define FUMAROOS_DANCE_HPP

#include <fstream>
#include "../../States/State.hpp"
#include "../../Management/SpriteManager.hpp"
#include "DanceButton.hpp"

namespace Fumaroos {

    class Dance : public State {
    public:
        Dance(StateStack &stack, Context &context);

        virtual void renderTopScreen(cpp3ds::Window &window);

        virtual void renderBottomScreen(cpp3ds::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const cpp3ds::Event &event);

        void move(float delta);

        void setPosition(float x, float y);

        int checkIntersect(Minigame::DanceButton button, cpp3ds::Keyboard::Key keypressed);

        void addButtons(int frame);


    private:
        SpriteManager m_animSpriteSheet;
        cpp3ds::Sprite m_lineSprite;
        cpp3ds::Sprite m_targetSprite;
        cpp3ds::Text m_text;
        std::vector<Minigame::DanceButton> m_buttons;

        std::map<std::string, cpp3ds::Keyboard::Key> m_keymap;
        std::ifstream m_infile;
        float m_delta;
        float m_speed = 0.1f; // increase this to move the line faster
        int m_frame; // keep track of frame so we can draw new buttons
        int m_points;
    };

}
#endif //FUMAROOS_DANCE_HPP
