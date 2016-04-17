#include "CreatePet.hpp"
#include <cpp3ds/Graphics.hpp>

namespace Fumaroos {
    CreatePet::CreatePet(StateStack &stack, Context &context)
            : State(stack, context) {

        TextureManager *texmgr = &context.texmgr; // save some typing
        texmgr->loadTexture(States::CreatePet, "back", "imgs/back.png");
        texmgr->loadTexture(States::CreatePet, "backT", "imgs/backT.png");
        texmgr->loadTexture(States::CreatePet, "femaleT", "imgs/femaleT.png");
        texmgr->loadTexture(States::CreatePet, "maleT", "imgs/maleT.png");
        texmgr->loadTexture(States::CreatePet, "spritesheet", "sprites/ss.png");

        m_animSpriteSheet.setSpriteSheet(texmgr->getRef(States::CreatePet, "spritesheet"));
        m_backButton.setTexture(texmgr->getRef(States::CreatePet, "back"));
        m_backButton.setActiveTexture(texmgr->getRef(States::CreatePet, "backT"));
        m_backButton.setPosition(6.f, 2.f);
        m_sexToggle.setTexture(texmgr->getRef(States::CreatePet, "maleT"));
        m_sexToggle.setActiveTexture(texmgr->getRef(States::CreatePet, "femaleT"));
        m_sexToggle.setPosition(320.f - texmgr->getRef(States::CreatePet, "femaleT").getSize().x - 6.f, 2.f);

        m_backButton.onClick([this] {
            requestStackPop();
            requestStackPush(States::Title);
        });
        m_sexToggle.onClick([this] {
            if (m_sexToggle.getActive()) {
                m_moldSprite.setColor(cpp3ds::Color::Magenta);
            } else {
                m_moldSprite.setColor(cpp3ds::Color::White);
            }
        });

        m_text.setString(_("Create your Pet"));
        m_text.setOutlineColor(cpp3ds::Color::Black);
        m_text.setOutlineThickness(1.f);
        m_text.setCharacterSize(24);
        m_text.setPosition(std::round(160.f - m_text.getLocalBounds().width / 2.f) - 10.f, 2.f);

        m_animSpriteSheet.addFrames("shadow", cpp3ds::IntRect(0, 64, 128, 64), 2, 64);

        for (int i = 0; i < 8; i++) {
            AnimatedSprite m_temp = AnimatedSprite(0.4f, false, true, "shadow");
            m_temp.setSpriteManager(m_animSpriteSheet);
            m_shadowSprites.push_back(m_temp);
            m_shadowSprites[i].setPosition(29.f + (i * 64), 76.f);
            if (i >= 4)
                m_shadowSprites[i].setPosition(29.f + ((i - 4) * 64), 140.f);
            m_shadowSprites[i].stop();
        }
        m_shadowSprites[m_hilighted].play();

        loadPets();
    }

    void CreatePet::loadPets() {
        m_animSpriteSheet.addFrames("mold", cpp3ds::IntRect(0, 0, 320, 64), 5, 64);
        m_moldSprite = AnimatedSprite(0.4f, false, true, "mold");
        m_moldSprite.setPosition(29.f, 64.f);
        m_moldSprite.play(m_animSpriteSheet);
    }

    void CreatePet::renderTopScreen(cpp3ds::Window &window) {
    }

    void CreatePet::renderBottomScreen(cpp3ds::Window &window) {
        window.draw(m_text);
        window.draw(m_backButton);
        window.draw(m_sexToggle);
        for (int i = 0; i < m_shadowSprites.size(); ++i)
            window.draw(m_shadowSprites[i]);
        window.draw(m_moldSprite);
    }

    bool CreatePet::update(float delta) {
        m_moldSprite.update(delta);
        for (int i = 0; i < m_shadowSprites.size(); ++i)
            m_shadowSprites[i].update(delta);

        return true;
    }

    bool CreatePet::processEvent(const cpp3ds::Event &event) {
        if (event.type == cpp3ds::Event::KeyPressed) {
            if (event.key.code == cpp3ds::Keyboard::DPadRight) {
                if (m_hilighted < 7) {
                    m_shadowSprites[m_hilighted].stop();
                    m_shadowSprites[m_hilighted + 1].play();
                    m_hilighted++;
                }
            }
            if (event.key.code == cpp3ds::Keyboard::DPadLeft) {
                if (m_hilighted > 0) {
                    m_shadowSprites[m_hilighted].stop();
                    m_shadowSprites[m_hilighted - 1].play();
                    m_hilighted--;
                }
            }
            if (event.key.code == cpp3ds::Keyboard::DPadDown) {
                if (m_hilighted < 4) {
                    m_shadowSprites[m_hilighted].stop();
                    m_shadowSprites[m_hilighted + 4].play();
                    m_hilighted += 4;
                }
            }
            if (event.key.code == cpp3ds::Keyboard::DPadUp) {
                if (m_hilighted > 3) {
                    m_shadowSprites[m_hilighted].stop();
                    m_shadowSprites[m_hilighted - 4].play();
                    m_hilighted -= 4;
                }
            }
        }
        for (int i = 0; i < m_shadowSprites.size(); ++i) {
            bool touched = m_shadowSprites[i].processEvent(event);
            if (touched) {
                m_shadowSprites[m_hilighted].stop();
                m_shadowSprites[i].play();
                m_hilighted = i;
                break;
            }
        }
        m_backButton.processEvent(event);
        m_sexToggle.processEvent(event);

        return false;
    }
} // namespace Fumaroos
