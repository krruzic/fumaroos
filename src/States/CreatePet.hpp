#ifndef FUMAROOS_CREATEPET_HPP
#define FUMAROOS_CREATEPET_HPP

#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../GUI/NineSliceButton.hpp"
#include "../AnimatedSprite.hpp"
#include <cpp3ds/Graphics/Sprite.hpp>
#include <cpp3ds/Graphics/Text.hpp>
#include <sstream>

namespace Fumaroos {

    class CreatePet : public State {
    public:
        CreatePet(StateStack &stack, Context &context);

        virtual void renderTopScreen(cpp3ds::Window &window);

        virtual void renderBottomScreen(cpp3ds::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const cpp3ds::Event &event);

        std::string convert(float number);

    private:
        cpp3ds::Text m_text;


        gui3ds::Button m_sexToggle;
        gui3ds::Button m_backButton;

        cpp3ds::Sprite m_bg;

        Animation m_moldAnim;
//        m_moldAnim = new Animation;
        AnimatedSprite m_moldSprite;

    };

} // namespace Fumaroos

#endif // FUMAROOS_CREATEPET_HPP
