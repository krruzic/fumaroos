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
#ifndef ANIMATEDSPRITE_HPP
#define ANIMATEDSPRITE_HPP

#include <cpp3ds/Graphics/RenderTarget.hpp>
#include <cpp3ds/System/Time.hpp>
#include <cpp3ds/Graphics/Drawable.hpp>
#include <cpp3ds/Graphics/Transformable.hpp>
#include <cpp3ds/Graphics/VertexArray.hpp>
#include <cpp3ds/System/Vector2.hpp>
#include <cpp3ds/Graphics/Sprite.hpp>

#include "Management/SpriteManager.hpp"

class AnimatedSprite : public cpp3ds::Drawable, public cpp3ds::Transformable {
public:
    AnimatedSprite(float frameTime = 0.2f, bool paused = false, bool looped = true, std::string name = "default");

    void update(float deltaTime);


    void setSpriteManager(const SpriteManager &spriteManager);

    void setFrameTime(float time);

    void play();

    void play(const SpriteManager &spriteManager);

    void pause();

    void stop();

    void setLooped(bool looped);

    void setColor(const cpp3ds::Color &color);

    const SpriteManager *getSpriteManager() const;

    cpp3ds::FloatRect getLocalBounds() const;

    cpp3ds::FloatRect getGlobalBounds() const;

    bool isLooped() const;

    bool isPlaying() const;

    float getFrameTime() const;

    void setFrame(std::size_t newFrame, bool resetTime = true);

private:
    const SpriteManager *m_spriteManager;
    float m_frameTime;
    float m_currentTime;
    std::size_t m_currentFrame;
    bool m_isPaused;
    bool m_isLooped;
    cpp3ds::Sprite m_sprite;
    cpp3ds::VertexArray m_vertices;
//    bool m_color;

    std::string m_name;

    virtual void draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const;

};

#endif // ANIMATEDSPRITE_HPP