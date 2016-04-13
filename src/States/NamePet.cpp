#include "NamePet.hpp"
#include "TitleState.hpp"
#include <cpp3ds/System/I18n.hpp>
#include <cpp3ds/Window/Window.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fumaroos {
    NamePet::NamePet(StateStack &stack, Context &context)
            : State(stack, context) {
        m_rectangle.setSize(cpp3ds::Vector2f(400, 240));
        m_rectangle.setFillColor(cpp3ds::Color::Black);

        m_keyboard.loadFromFile("kb/keyboard.xml");
        std::cout << "testing after kb";
        m_text.setString(_("Name your Pet"));
        m_text.setCharacterSize(20);
        m_text.setPosition(std::round(160.f - m_text.getLocalBounds().width / 2.f), 2.f);

        m_backButtonTexture.loadFromFile("imgs/back.png");
        m_backButtonActiveTexture.loadFromFile("imgs/backT.png");
        m_backButtonActiveTexture.setSmooth(true);
        m_backButtonTexture.setSmooth(true);
        m_backButton.setTexture(m_backButtonTexture);
        m_backButton.setActiveTexture(m_backButtonActiveTexture);
        m_backButton.setPosition(6.f, 2.f);

        m_backButton.onClick([this]{
            requestStackPop();
            requestStackPush(States::Title);
        });

        m_sexButtonTexture.loadFromFile("imgs/femaleT.png");
        m_sexButtonActiveTexture.loadFromFile("imgs/maleT.png");
        m_sexButtonActiveTexture.setSmooth(true);
        m_sexButtonTexture.setSmooth(true);
        m_sexToggle.setTexture(m_sexButtonTexture);
        m_sexToggle.setActiveTexture(m_sexButtonActiveTexture);
        m_sexToggle.setPosition(6.f, 58.f);

    }

    void NamePet::renderTopScreen(cpp3ds::Window &window) {
        window.draw(m_rectangle);
    }

    void NamePet::renderBottomScreen(cpp3ds::Window &window) {
        window.draw(m_text);
        window.draw(m_sexToggle);
        window.draw(m_backButton);
        window.draw(m_keyboard);
    }

    bool NamePet::update(float delta) {
        m_keyboard.update(delta);
//        m_sexToggle.update(delta);
        return true;
    }

    bool NamePet::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::KeyPressed) {
            if (event.key.code == cpp3ds::Keyboard::Select) {
                requestStackClear();
                return true;
            }
        }
        m_sexToggle.processEvent(event);
        m_backButton.processEvent(event);
        m_keyboard.processEvents(event);
        return false;
    }

    std::string NamePet::convert(float number) {
        std::ostringstream buff;
        buff << number;
        return buff.str();
    }


} // namespace Fumaroos
