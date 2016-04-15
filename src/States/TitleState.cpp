#include "TitleState.hpp"


namespace Fumaroos {

    TitleState::TitleState(StateStack &stack, Context &context)
            : State(stack, context), m_text(), m_showText(true), m_textEffectTime(0) {
        context.texmgr.loadTexture(States::Title, "title", "imgs/title2.png");
        context.texmgr.loadTexture(States::Title, "start", "imgs/start.png");
        context.texmgr.loadTexture(States::Title, "startP", "imgs/startP.png");

        m_titleBackground.setTexture(context.texmgr.getRef(States::Title, "title"));
        m_textTitle.setCharacterSize(10);
        m_textTitle.setFillColor(cpp3ds::Color::White);
        m_textTitle.setString(_("v0.1"));
        m_textTitle.setPosition(std::floor(398.f - m_textTitle.getLocalBounds().width), 225.f);

        m_startButton.setTexture(context.texmgr.getRef(States::Title, "start"));
        m_startButton.setActiveTexture(context.texmgr.getRef(States::Title, "startP"));
        m_startButton.setPosition(31.f, 88.f);
//        m_startButton.setTextureRect(cpp3ds::IntRect(10, 10, 16, 16));

        m_startButton.onClick([this] {
            requestStackPop();
            requestStackPush(States::CreatePet);
        });

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
        window.draw(m_startButton);
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
//         If any key is pressed, trigger the next screen
        m_startButton.processEvent(event);
//        if (event.type == cpp3ds::Event::KeyPressed) {
//            if (event.key.code == cpp3ds::Keyboard::Select) {
//                requestStackClear();
//                return true;
//            }
//            requestStackPop();
//            if (!checkSave()) {
//                requestStackPush(States::CreatePet);
//            }
//        }

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
