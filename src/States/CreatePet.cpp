#include "CreatePet.hpp"

namespace Fumaroos {
    CreatePet::CreatePet(StateStack &stack, Context &context)
            : State(stack, context) {
        context.texmgr.loadTexture(States::CreatePet, "back", "imgs/back.png");
        context.texmgr.loadTexture(States::CreatePet, "backT", "imgs/backT.png");
        context.texmgr.loadTexture(States::CreatePet, "femaleT", "imgs/femaleT.png");
        context.texmgr.loadTexture(States::CreatePet, "maleT", "imgs/maleT.png");
        context.texmgr.loadTexture(States::None, "bg", "imgs/bg.png");
        context.texmgr.loadTexture(States::CreatePet, "mold", "sprites/mold.png");

        m_bg.setTexture(context.texmgr.getRef(States::None, "bg"));

        m_text.setString(_("Create your Pet"));
        m_text.setCharacterSize(20);
        m_text.setPosition(std::round(160.f - m_text.getLocalBounds().width / 2.f), 2.f);

        m_backButton.setTexture(context.texmgr.getRef(States::CreatePet, "back"));
        m_backButton.setActiveTexture(context.texmgr.getRef(States::CreatePet, "backT"));
        m_backButton.setPosition(6.f, 2.f);
        m_backButton.onClick([this] {
            requestStackPop();
            requestStackPush(States::Title);
        });

        m_sexToggle.setTexture(context.texmgr.getRef(States::CreatePet, "femaleT"));
        m_sexToggle.setActiveTexture(context.texmgr.getRef(States::CreatePet, "maleT"));
        m_sexToggle.setPosition(320.f - context.texmgr.getRef(States::CreatePet, "femaleT").getSize().x - 6.f, 2.f);

        m_moldAnim.setSpriteSheet(context.texmgr.getRef(States::CreatePet, "mold"));
        m_moldAnim.addFrame(cpp3ds::IntRect(0, 0, 32, 32));
//        m_moldAnim.addFrame(cpp3ds::IntRect( 32, 32, 32, 32));
//        m_moldAnim.addFrame(cpp3ds::IntRect(64, 0, 64, 64));
        m_moldSprite = AnimatedSprite(0.2f, true, false);
//
        m_moldSprite.setPosition(50.f, 50.f);
////        m_moldSprite.setColor(cpp3ds::Color::Magenta);
//
        m_moldSprite.play(m_moldAnim);
    }

    void CreatePet::renderTopScreen(cpp3ds::Window &window) {
    }

    void CreatePet::renderBottomScreen(cpp3ds::Window &window) {
        window.draw(m_bg);
        window.draw(m_text);
        window.draw(m_backButton);
        window.draw(m_sexToggle);
        window.draw(m_moldSprite);
//        window.draw(m_keyboard);
    }

    bool CreatePet::update(float delta) {
//        m_sexToggle.update(delta);
//        if (delta >= 0.2f)
        m_moldSprite.update(delta);
        return true;
    }

    bool CreatePet::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::KeyPressed) {
            if (event.key.code == cpp3ds::Keyboard::Select) {
                requestStackClear();
                return true;
            }
        }
        m_sexToggle.processEvent(event);
        m_backButton.processEvent(event);
        return false;
    }

    std::string CreatePet::convert(float number) {
        std::ostringstream buff;
        buff << number;
        return buff.str();
    }


} // namespace Fumaroos
