#ifndef FUMAROOS_CREATEPET_HPP
#define FUMAROOS_CREATEPET_HPP

#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../Keyboard/Keyboard.hpp"
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
        cpp3ds::RectangleShape m_rectangle;
        util3ds::Keyboard m_keyboard;
        cpp3ds::Texture m_buttonTexture;
        cpp3ds::Texture m_buttonActiveTexture;
        gui3ds::Button m_sexButton;
    };

} // namespace Fumaroos

#endif // FUMAROOS_CREATEPET_HPP
