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

#include "Animation.hpp"

class AnimatedSprite : public cpp3ds::Drawable, public cpp3ds::Transformable
{
public:
    explicit AnimatedSprite(float frameTime = 0.2f, bool paused = false, bool looped = true);

    void update(float deltaTime);
    void setAnimation(const Animation& animation);
    void setFrameTime(float time);
    void play();
    void play(const Animation& animation);
    void pause();
    void stop();
    void setLooped(bool looped);
    void setColor(const cpp3ds::Color& color);
    const Animation* getAnimation() const;
    cpp3ds::FloatRect getLocalBounds() const;
    cpp3ds::FloatRect getGlobalBounds() const;
    bool isLooped() const;
    bool isPlaying() const;
    float getFrameTime() const;
    void setFrame(std::size_t newFrame, bool resetTime = true);

private:
    const Animation* m_animation;
    float m_frameTime;
    float m_currentTime;
    std::size_t m_currentFrame;
    bool m_isPaused;
    bool m_isLooped;
    const cpp3ds::Texture* m_texture;
    cpp3ds::VertexArray m_vertices;
//    cpp3ds::VertexAr m_vertices[6];
    virtual void draw(cpp3ds::RenderTarget& target, cpp3ds::RenderStates states) const;

};

#endif // ANIMATEDSPRITE_HPP