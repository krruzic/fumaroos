#include "State.hpp"
#include "StateStack.hpp"


namespace Fumaroos {

    State::Context::Context(cpp3ds::String &name, cpp3ds::String &data,
                            cpp3ds::Color &color)
            : name(name), data(data), color(color) {
    }

    State::State(StateStack &stack, Context &context)
            : m_stack(&stack), m_context(context) {
    }

    State::~State() {
    }

    void State::requestStackPush(States::ID stateID) {
        m_stack->pushState(stateID);
    }

    void State::requestStackPop(States::ID stateID) {
        m_stack->popState();
    }

    void State::requestStackClear() {
        m_stack->clearStates();
    }

    State::Context State::getContext() const {
        return m_context;
    }

} // namespace Fumaroos
