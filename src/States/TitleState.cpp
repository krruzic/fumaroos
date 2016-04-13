#include "TitleState.hpp"
#include <cpp3ds/System/I18n.hpp>
#include <cpp3ds/Window/Window.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


namespace Fumaroos {

    TitleState::TitleState(StateStack &stack, Context &context)
            : State(stack, context), m_text(), m_showText(true), m_textEffectTime(0) {
        m_titleTexture.loadFromFile("imgs/title2.png");
        m_titleBackground.setTexture(m_titleTexture);
        m_textTitle.setCharacterSize(10);
        m_textTitle.setFillColor(cpp3ds::Color::White);
        m_textTitle.setString(_("v0.1"));
        m_textTitle.setPosition(std::floor(398.f - m_textTitle.getLocalBounds().width), 225.f);

        m_text.setCharacterSize(12);
        m_text.setFillColor(cpp3ds::Color::White);
        m_text.setString(_("Press any key to start. SELECT to exit."));
        m_text.setPosition(std::floor(200.f - m_text.getLocalBounds().width / 2), 170.f);
    }

    void TitleState::renderTopScreen(cpp3ds::Window &window) {
        window.draw(m_titleBackground);
        window.draw(m_textTitle);
        if (m_showText)
            window.draw(m_text);
    }

    void TitleState::renderBottomScreen(cpp3ds::Window &window) {
        // Nothing
    }

    bool TitleState::update(float delta) {
        m_textEffectTime += delta;

        if (m_textEffectTime >= 0.5f) {
            m_showText = !m_showText;
            m_textEffectTime = 0;
        }

        return true;
    }

    bool TitleState::processEvent(const cpp3ds::Event &event) {
        // If any key is pressed, trigger the next screen
        if (event.type == cpp3ds::Event::KeyPressed) {
            if (event.key.code == cpp3ds::Keyboard::Select) {
                requestStackClear();
                return true;
            }
            requestStackPop();
            if (!checkSave()) {
                requestStackPush(States::NamePet);
            }
        }

        return true;
    }

    bool TitleState::checkSave() {

        FILE *file = fopen("save.bin", "rb");
        if (file == NULL) {
            return false;
        } else {
            return false;
        }
    }

} // namespace Fumaroos
