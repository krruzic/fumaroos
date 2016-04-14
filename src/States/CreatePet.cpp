#include "CreatePet.hpp"

namespace Fumaroos {
    CreatePet::CreatePet(StateStack &stack, Context &context)
            : State(stack, context) {

        m_text.setString(_("Create your Pet"));
        m_text.setCharacterSize(20);
        m_text.setPosition(std::round(160.f - m_text.getLocalBounds().width / 2.f), 2.f);
//
        m_backButtonTexture.loadFromFile("imgs/femaleT.png");
        m_backButtonActiveTexture.loadFromFile("imgs/maleT.png");
        m_backButton.setTexture(m_backButtonTexture);
        m_backButton.setPosition(6.f, 2.f);

        m_bg_texture.loadFromFile("imgs/bg.png");
        m_bg.setTexture(m_bg_texture);
        m_bg.setTextureRect(cpp3ds::IntRect(10, 10, 32, 32));
//        m_backButton.onClick([this]{
//            requestStackPop();
//            requestStackPush(States::Title);
//        });
//
        m_sexButtonTexture.loadFromFile("imgs/femaleT.png");
        m_sexButtonActiveTexture.loadFromFile("imgs/maleT.png");
        m_sexToggle.setTexture(m_sexButtonTexture);
        m_sexToggle.setPosition(6.f, 58.f);

    }

    void CreatePet::renderTopScreen(cpp3ds::Window &window) {
    }

    void CreatePet::renderBottomScreen(cpp3ds::Window &window) {
        window.draw(m_bg);
        window.draw(m_text);
        window.draw(m_backButton);
//        window.draw(m_sexToggle);
//        window.draw(m_keyboard);
    }

    bool CreatePet::update(float delta) {
//        m_sexToggle.update(delta);
        return true;
    }

    bool CreatePet::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::KeyPressed) {
            if (event.key.code == cpp3ds::Keyboard::Select) {
                requestStackClear();
                return true;
            }
        }
        if (m_sexToggle.getActive()) {
            m_sexToggle.setTexture(m_sexButtonActiveTexture);
        } else {
            m_sexToggle.setTexture(m_sexButtonTexture);
        }
        m_sexToggle.processEvent(event);
//        m_backButton.processEvent(event);
        return false;
    }

    std::string CreatePet::convert(float number) {
        std::ostringstream buff;
        buff << number;
        return buff.str();
    }


} // namespace Fumaroos
