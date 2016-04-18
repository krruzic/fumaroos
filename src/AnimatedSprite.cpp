// altered from here: https://github.com/SFML/SFML/wiki/Source:-AnimatedSprite
#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(float frameTime, bool paused, bool looped, std::string name) :
        m_spriteSheet(NULL), m_frameTime(frameTime), m_currentFrame(0), m_isPaused(paused), m_isLooped(looped),
        m_name(name) {

}


void AnimatedSprite::setSpriteManager(const SpriteManager &spriteManager) {
    m_spriteSheet = &spriteManager;
    m_sprite.setTexture(*spriteManager.getSpriteSheet());
    // set sprite to a rect cut out of spritesheet
    // this rect contains every animation the sprite has
    m_sprite.setTextureRect(m_spriteSheet->getAnimSize(this->m_name));
    m_currentFrame = 0;
    setFrame(m_currentFrame);
}

void AnimatedSprite::setFrameTime(float time) {
    m_frameTime = time;
}

void AnimatedSprite::play() {
    m_isPaused = false;
}

void AnimatedSprite::play(const SpriteManager &spriteManager) {
    if (getSpriteSheet() != &spriteManager)
        setSpriteManager(spriteManager);
    play();
}

void AnimatedSprite::pause() {
    m_isPaused = true;
}

void AnimatedSprite::stop() {
    m_isPaused = true;
    m_currentFrame = 0;
    setFrame(m_currentFrame);
}

void AnimatedSprite::setLooped(bool looped) {
    m_isLooped = looped;
}

void AnimatedSprite::setColor(const cpp3ds::Color &color) {
    m_sprite.setColor(color);
}

const SpriteManager *AnimatedSprite::getSpriteSheet() const {
    return m_spriteSheet;
}

cpp3ds::FloatRect AnimatedSprite::getLocalBounds() const {
    cpp3ds::IntRect rect = m_spriteSheet->getFrame(this->m_name, m_currentFrame);

    float width = static_cast<float>(std::abs(rect.width));
    float height = static_cast<float>(std::abs(rect.height));

    return cpp3ds::FloatRect(0.f, 0.f, width, height);
}

cpp3ds::FloatRect AnimatedSprite::getGlobalBounds() const {
    return getTransform().transformRect(getLocalBounds());
}

bool AnimatedSprite::isLooped() const {
    return m_isLooped;
}

bool AnimatedSprite::isPlaying() const {
    return !m_isPaused;
}

float AnimatedSprite::getFrameTime() const {
    return m_frameTime;
}

void AnimatedSprite::setFrame(std::size_t newFrame, bool resetTime) {
    cpp3ds::IntRect rect = m_spriteSheet->getFrame(this->m_name, newFrame);
    m_sprite.setTextureRect(rect);

    if (resetTime)
        m_currentTime = 0.f;
}

void AnimatedSprite::update(float deltaTime) {
    // if not paused and we have a valid spriteManager
    if (!m_isPaused && m_spriteSheet) {
        // add delta time
        m_currentTime += deltaTime;
        int output = 10 + (rand() % (int)(54 - 10 + 1));

        // if current time is bigger then the frame time advance one frame
        if (m_currentTime >= m_frameTime) {
            // reset time, but keep the remainder
            m_currentTime = (float) fmod(m_currentTime, m_frameTime);

            // get next Frame index
            if (m_currentFrame + 1 < m_spriteSheet->getSize(this->m_name))
                m_currentFrame++;
            else {
                // animation has ended
                m_currentFrame = 0; // reset to start

                if (!m_isLooped) {
                    m_isPaused = true;
                }

            }

            // set the current frame, not resetting the time
            setFrame(m_currentFrame, false);
        }
    }
}

bool AnimatedSprite::processEvent(const cpp3ds::Event &event) {
    if (event.type == cpp3ds::Event::TouchBegan) {
        if (this->getGlobalBounds().contains(event.touch.x, event.touch.y))
            return true;
    }
    return false;
}

cpp3ds::Vector2f AnimatedSprite::getSize() {
    cpp3ds::IntRect temp = m_spriteSheet->getFrame(this->m_name, 1);
    return cpp3ds::Vector2f(temp.width, temp.height);
}

void AnimatedSprite::draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_sprite, states);
}