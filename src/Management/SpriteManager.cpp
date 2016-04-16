////////////////////////////////////////////////////////////
//
// Copyright (C) 2014 Maximilian Wagenbach (aka. Foaly) (foaly.f@web.de)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

// altered from here: https://github.com/SFML/SFML/wiki/Source:-AnimatedSprite
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

void SpriteManager::setSpriteSheet(const cpp3ds::Texture &texture) {
    m_texture = texture;
}

const cpp3ds::Texture &SpriteManager::getSpriteSheet() const {
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