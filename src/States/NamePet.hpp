#ifndef FUMAROOS_NAMEPET_HPP
#define FUMAROOS_NAMEPET_HPP

#include "State.hpp"
#include "../GUI/ToggleButton.hpp"
#include "../GUI/Button.hpp"
#include "../Keyboard/Keyboard.hpp"
#include <cpp3ds/Graphics/Sprite.hpp>
#include <cpp3ds/Graphics/Text.hpp>
#include <sstream>

namespace Fumaroos {

    class NamePet : public State {
    public:
        NamePet(StateStack &stack, Context &context);

        virtual void renderTopScreen(cpp3ds::Window &window);

        virtual void renderBottomScreen(cpp3ds::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const cpp3ds::Event &event);

        std::string convert(float number);

    private:
        cpp3ds::Text m_text;
        cpp3ds::RectangleShape m_rectangle;
        util3ds::Keyboard m_keyboard;
        cpp3ds::Texture m_sexButtonTexture;
        cpp3ds::Texture m_sexButtonActiveTexture;
        cpp3ds::Texture m_backButtonTexture;
        cpp3ds::Texture m_backButtonActiveTexture;
        gui3ds::ToggleButton m_sexToggle;
        gui3ds::ToggleButton m_backButton;

    };

} // namespace Fumaroos

#endif // FUMAROOS_NAMEPET_HPP
