#include "State.hpp"
#include "StateStack.hpp"


namespace Fumaroos {


    State::Context::Context(cpp3ds::String &name, cpp3ds::String &data,
                            cpp3ds::Color &color, TextureManager &texmgr)
            : name(name), data(data), color(color), texmgr(texmgr) {
    }

    State::State(StateStack &stack, Context &context)
            : m_stack(&stack), m_context(context) {
    }

    State::~State() {
    }

    void State::requestStackPush(States::ID stateID) {
        m_stack->pushState(stateID);
    }

    void State::requestStackPop() {
        States::ID s = m_stack->getTopID();
        m_context.texmgr.unloadTextures(s);
        m_stack->popState();
    }

    void State::requestStackClear() {
        m_context.texmgr.unloadTextures(m_stack->getTopID());
        m_stack->clearStates();
    }

    State::Context State::getContext() const {
        return m_context;
    }

} // namespace Fumaroos
