#ifndef FUMAROOS_STATE_HPP
#define FUMAROOS_STATE_HPP

#include "StateIdentifiers.hpp"
#include "../Management/TextureManager.hpp"
#include "../Pet.hpp"
#include <cpp3ds/System/Time.hpp>
#include <cpp3ds/Window/Event.hpp>
#include <cpp3ds/System/String.hpp>
#include <cpp3ds/Window/Window.hpp>
#include <cpp3ds/System/I18n.hpp>
#include <memory>
#include <cpp3ds/Graphics/Color.hpp>


namespace cpp3ds {
    class Window;

    class TcpSocket;
}

namespace Fumaroos {

    class StateStack;

    class Player;

    class State {
    public:
        typedef std::unique_ptr<State> Ptr;

        struct TransitionData {
            cpp3ds::String message;
            States::ID nextStateID;
        };

        struct Context {
            Context(cpp3ds::String &name, cpp3ds::String &data,
                    cpp3ds::Color &color, TextureManager &texmgr);

            cpp3ds::String &name;
            cpp3ds::String &data;
            cpp3ds::Color &color;

            TextureManager &texmgr;
        };

        State(StateStack &stack, Context &context);

        virtual ~State();

        virtual void renderTopScreen(cpp3ds::Window &window) = 0;

        virtual void renderBottomScreen(cpp3ds::Window &window) = 0;

        virtual bool update(float delta) = 0;

        virtual bool processEvent(const cpp3ds::Event &event) = 0;


    protected:
        void requestStackPush(States::ID stateID);

        void requestStackPop();

        void requestStackClear();

        Context getContext() const;

    private:
        StateStack *m_stack;
        Context m_context;
        Pet *m_pet;
    };

} // namespace Fumaroos

#endif // FUMAROOS_STATE_HPP
