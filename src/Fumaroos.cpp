#include "Fumaroos.hpp"
#include "States/TitleState.hpp"
#include "States/NamePet.hpp"

using namespace cpp3ds;

namespace Fumaroos {

    Fumaroos::Fumaroos() : m_bottomStateStack(State::Context(m_bottomName, m_bottomData, m_bottomColor)),
                           m_topStateStack(State::Context(m_topName, m_topData, m_topColor)) {

        m_topStateStack.registerState<TitleState>(States::Title);
        m_bottomStateStack.registerState<NamePet>(States::NamePet);

        m_topStateStack.pushState(States::Title);
        m_bottomStateStack.pushState(States::NamePet);

    }

    Fumaroos::~Fumaroos() {
        // Destructor called when game exits
    }

    void Fumaroos::update(float delta) {
        // Need to update before checking if empty
        m_topStateStack.update(delta);
        m_bottomStateStack.update(delta);

        if (m_topStateStack.isEmpty() && m_bottomStateStack.isEmpty())
            exit();

    }

    void Fumaroos::processEvent(Event &event) {
        m_topStateStack.processEvent(event);
        m_bottomStateStack.processEvent(event);
    }

    void Fumaroos::renderTopScreen(Window &window) {
        window.clear(Color::White);
//        m_stateStack.renderTopScreen(window);
        m_topStateStack.renderTopScreen(window);
        window.setView(window.getDefaultView());
    }

    void Fumaroos::renderBottomScreen(Window &window) {
        window.clear(Color(100, 100, 220));
//        m_stateStack.renderBottomScreen(window);
        m_bottomStateStack.renderBottomScreen(window);
    }

} // namespace DrawAttack