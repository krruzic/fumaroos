#ifndef FUMAROOS_CREATEPET_HPP
#define FUMAROOS_CREATEPET_HPP

#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../GUI/NineSliceButton.hpp"
#include "../AnimatedSprite.hpp"
#include <cpp3ds/Graphics/Sprite.hpp>
#include <cpp3ds/Graphics/Text.hpp>
#include "../Pet.hpp"
#include <sstream>
#include <cmath>

namespace Fumaroos {

    class CreatePet : public State {
    public:
        CreatePet(StateStack &stack, Context &context);

        void loadPets();

        virtual void renderTopScreen(cpp3ds::Window &window);

        virtual void renderBottomScreen(cpp3ds::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const cpp3ds::Event &event);

    private:
        cpp3ds::Text m_text;

        gui3ds::Button m_sexToggle;
        gui3ds::Button m_backButton;

        SpriteManager m_animSpriteSheet;

        AnimatedSprite m_moldSprite;
        int m_hilighted = 0;
        std::vector<AnimatedSprite> m_shadowSprites;

    };

} // namespace Fumaroos

#endif // FUMAROOS_CREATEPET_HPP
