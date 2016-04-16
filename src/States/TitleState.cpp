#include "TitleState.hpp"


namespace Fumaroos {

    TitleState::TitleState(StateStack &stack, Context &context)
            : State(stack, context) {
        TextureManager *texmgr = &context.texmgr; // save some typing

        texmgr->loadTexture(States::Title, "title", "imgs/title2.png");
        texmgr->loadTexture(States::Title, "start", "imgs/start.png");
        texmgr->loadTexture(States::Title, "startP", "imgs/startP.png");

        m_titleBackground.setTexture(texmgr->getRef(States::Title, "title"));

        m_textTitle.setCharacterSize(10);
        m_textTitle.setFillColor(cpp3ds::Color::White);
        m_textTitle.setString(_("v0.1"));
        m_textTitle.setPosition(std::floor(398.f - m_textTitle.getLocalBounds().width), 225.f);

        m_startButton.setTexture(texmgr->getRef(States::Title, "start"));
        m_startButton.setActiveTexture(texmgr->getRef(States::Title, "startP"));
        m_startButton.setPosition(31.f, 88.f);
//        m_startButton.setTextureRect(cpp3ds::IntRect(10, 10, 16, 16));

        m_startButton.onClick([this] {
            requestStackPop();
            requestStackPush(States::CreatePet);
        });
    }

    void TitleState::renderTopScreen(cpp3ds::Window &window) {
        window.draw(m_titleBackground);
        window.draw(m_textTitle);
    }

    void TitleState::renderBottomScreen(cpp3ds::Window &window) {
        window.draw(m_startButton);
    }

    bool TitleState::update(float delta) {
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
