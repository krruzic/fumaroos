#include "CreatePet.hpp"
#include <cpp3ds/System/I18n.hpp>
#include <cpp3ds/Window/Window.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fumaroos {
    CreatePet::CreatePet(StateStack &stack, Context &context)
            : State(stack, context) {
        m_rectangle.setSize(cpp3ds::Vector2f(400, 240));
        m_rectangle.setFillColor(cpp3ds::Color(0, 0, 0, 150));

        m_keyboard.loadFromFile("kb/keyboard.xml");
        m_text.setString(_("Name your pet"));
        m_text.setCharacterSize(20);
        m_text.setPosition(std::round(160.f - m_text.getLocalBounds().width / 2.f), 2.f);
    }

    void CreatePet::renderTopScreen(cpp3ds::Window &window) {
        window.draw(m_rectangle);
    }

    void CreatePet::renderBottomScreen(cpp3ds::Window &window) {
        window.draw(m_keyboard);
        window.draw(m_text);
    }

    bool CreatePet::update(float delta) {
        m_keyboard.update(delta);
        return true;
    }

    bool CreatePet::processEvent(const cpp3ds::Event &event) {
        m_keyboard.processEvents(event);
        return false;
    }


} // namespace Fumaroos
