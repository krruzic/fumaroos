// altered from here: https://github.com/SFML/SFML/wiki/Source:-AnimatedSprite
#include <cpp3ds/Graphics/Sprite.hpp>
#include "SpriteManager.hpp"

SpriteManager::SpriteManager() {

}

void SpriteManager::addFrames(const std::string name, cpp3ds::IntRect rect, int frames, int animHeight) {
    int v_frames = static_cast<int>(rect.height) / animHeight;
    int frame_height = static_cast<int>(rect.height) / v_frames;

    cpp3ds::IntRect temp_rect;
    m_frames[name].insert(m_frames[name].begin(), rect); // save the full rect in the first element

    for (int y = 0; y < v_frames; y++) {
        for (int x = 0; x < frames; x++) {
            temp_rect = cpp3ds::IntRect(rect.left + (x * frame_height), rect.top + (y * frame_height), frame_height,
                                        frame_height);
            m_frames[name].push_back(temp_rect);
        }
    }

}

// return the sprite that is inside the rect passed
cpp3ds::Sprite SpriteManager::getSprite(std::string name) {
    cpp3ds::Sprite temp;
    temp.setTextureRect(this->getFrame(name, 0));
    return temp;
}

void SpriteManager::setSpriteSheet(const cpp3ds::Texture &texture) {
    m_texture = &texture;
}

const cpp3ds::Texture *SpriteManager::getSpriteSheet() const {
    return m_texture;
}

std::size_t SpriteManager::getSize(std::string name) const {
    return m_frames.at(name).size() - 1; // don't include the first intRect
}

cpp3ds::IntRect SpriteManager::getAnimSize(std::string name) const {
    return m_frames.at(name)[0];
}

const cpp3ds::IntRect &SpriteManager::getFrame(std::string name, std::size_t n) const {
    return m_frames.at(name)[n+1]; // 0 is the entire animation
}