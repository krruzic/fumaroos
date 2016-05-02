#include <iterator>
#include <sstream>
#include "Dance.hpp"
namespace Fumaroos {

    Dance::Dance(StateStack &stack, Context &context)
            : State(stack, context) {
        m_infile.open(cpp3ds::FileSystem::getFilePath("dance.dat"));
        TextureManager *texmgr = &context.texmgr; // save some typing
        texmgr->loadTexture(States::Dance, "buttonLine", "sprites/buttonline.png");
        texmgr->loadTexture(States::Dance, "buttonTarget", "sprites/buttontarget.png");

        texmgr->loadTexture(States::Dance, "buttonsprites", "sprites/buttons.png");
        m_animSpriteSheet.setSpriteSheet(texmgr->getRef(States::Dance, "buttonsprites"));

        m_animSpriteSheet.addFrames("A", cpp3ds::IntRect(0, 0, 0, 64), 1, 64);
        m_animSpriteSheet.addFrames("B", cpp3ds::IntRect(0, 0, 64, 64), 1, 64);
        m_animSpriteSheet.addFrames("X", cpp3ds::IntRect(0, 0, 128, 64), 1, 64);
        m_animSpriteSheet.addFrames("Y", cpp3ds::IntRect(0, 0, 256, 64), 1, 64);
        m_animSpriteSheet.addFrames("L", cpp3ds::IntRect(0, 0, 320, 64), 1, 64);
        m_animSpriteSheet.addFrames("R", cpp3ds::IntRect(0, 0, 384, 64), 1, 64);
        m_keymap["A"] = cpp3ds::Keyboard::A;
        m_keymap["B"] = cpp3ds::Keyboard::B;
        m_keymap["X"] = cpp3ds::Keyboard::X;
        m_keymap["Y"] = cpp3ds::Keyboard::Y;
        m_keymap["L"] = cpp3ds::Keyboard::L;
        m_keymap["R"] = cpp3ds::Keyboard::R;


        m_lineSprite.setTexture(texmgr->getRef(States::Dance, "buttonLine"));
        m_targetSprite.setTexture(texmgr->getRef(States::Dance, "buttonTarget"));
        m_lineSprite.setPosition(0, 45);
        m_targetSprite.setPosition(50, 45);

        m_text.setPosition(20, 20);
        m_text.setCharacterSize(20);
        m_text.setString(_("TEST"));

    }

    bool Dance::update(float delta) {
        m_delta += delta;
        m_frame++;
        if (m_delta >= 0.3f - m_speed) {
            move(delta);
            m_delta = 0;
        }
        this->addButtons(m_frame);
    }

    bool Dance::processEvent(const cpp3ds::Event &event) {
        if (event.type == event.KeyPressed) {
            m_points += checkIntersect(m_buttons.front(), event.key.code);
        }
    }

    void Dance::renderTopScreen(cpp3ds::Window &window) {
        window.draw(m_lineSprite);
        window.draw(m_targetSprite);
        for (auto &button: m_buttons) {
            std::cout << "drawing button\n";
            window.draw(button);
        }
        window.draw(m_text);
    }

    void Dance::renderBottomScreen(cpp3ds::Window &window) {
    }

    void Dance::addButtons(int frame) {
        std::string curline;
        std::streampos oldpos = m_infile.tellg();  // store previous line pos
        std::getline(m_infile, curline);
//        std::cout << curline;
        m_text.setString(curline);

        if (m_infile.bad() || curline == "") {
            m_frame = 0;
            frame = 0;
            m_infile.clear();
            m_infile.seekg(0, std::ios::beg);
            return;
//            std::getline(m_infile, curline);
        }
        std::istringstream buf(curline);
        std::istream_iterator<std::string> beg(buf), end;

        std::vector<std::string> tokens(beg, end); // done!
        if (frame == atoi(tokens[0].c_str())) {
            std::cout << "adding button\n";
            Minigame::DanceButton d = Minigame::DanceButton(m_keymap.at(tokens[1]));
            d.setSprite(m_animSpriteSheet.getSprite(tokens[1]));
            m_buttons.push_back(d);
        } else {
            m_infile.seekg(oldpos);   // go back to the previous line
        }
    }

    void Dance::setPosition(float x, float y) {
    }

    void Dance::move(float delta) {
        for (auto &button: m_buttons) {
            button.move(delta, 0);
        }
    }

    int Dance::checkIntersect(Minigame::DanceButton button, cpp3ds::Keyboard::Key keypressed) {
        if (!button.getKey() == keypressed) {
            return -1;
        } else {
            int points = 0;
            cpp3ds::IntRect target_rect = m_targetSprite.getTextureRect();
            cpp3ds::IntRect button_rect = button.getRect();
            int t_right = target_rect.left + target_rect.width;
            int t_centre = target_rect.left + (target_rect.width / 2);

            if (button_rect.left > t_right)
                return -1;

            if (button_rect.left <= t_right)
                points++;
            if (button_rect.left >= t_centre)
                points += 2;
            if (button_rect.left == target_rect.left)
                points += 2;

            m_buttons.erase(m_buttons.begin());
            return points;
        }
    }
}