#include "Fumaroos.hpp"
#include "States/TitleState.hpp"
#include "States/CreatePet.hpp"
#include "Minigame/Flappers/Flappers.hpp"
#include "Minigame/Dance/Dance.hpp"

using namespace cpp3ds;

namespace Fumaroos {

    Fumaroos::Fumaroos()
            : m_color(cpp3ds::Color::Black),
              m_stateStack(State::Context(m_name, m_data, m_color, m_texmgr)) {
        m_stateStack.registerState<TitleState>(States::Title);
        m_stateStack.registerState<CreatePet>(States::CreatePet);
        m_stateStack.registerState<Flappers>(States::Flappers);
        m_stateStack.registerState<Dance>(States::Dance);
        m_stateStack.pushState(States::Title);
    }

    Fumaroos::~Fumaroos() {
        // Destructor called when game exits
    }

    void Fumaroos::update(float delta) {
        // Need to update before checking if empty
        m_stateStack.update(delta);
        if (m_stateStack.isEmpty())
            exit();

    }

    void Fumaroos::processEvent(Event &event) {
        m_stateStack.processEvent(event);
    }

    void Fumaroos::renderTopScreen(Window &window) {
        window.clear(Color::Black);
        m_stateStack.renderTopScreen(window);
        window.setView(window.getDefaultView());
    }

    void Fumaroos::renderBottomScreen(Window &window) {
        window.clear(Color(6, 110, 164));
        m_stateStack.renderBottomScreen(window);
    }


} // namespace Fumaroos