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
#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <cpp3ds/Graphics/Rect.hpp>
#include <cpp3ds/Graphics/Texture.hpp>

class Animation
{
public:
    Animation();

    void addFrame(cpp3ds::IntRect rect);
    void setSpriteSheet(const cpp3ds::Texture& texture);
    const cpp3ds::Texture* getSpriteSheet() const;
    std::size_t getSize() const;
    const cpp3ds::IntRect& getFrame(std::size_t n) const;

private:
    std::vector<cpp3ds::IntRect> m_frames;
    const cpp3ds::Texture* m_texture;
};

#endif // ANIMATION_HPP