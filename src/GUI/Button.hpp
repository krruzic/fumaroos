#ifndef GUI3DS_BUTTON_HPP
#define GUI3DS_BUTTON_HPP

#include <cpp3ds/Graphics/Text.hpp>
#include <cpp3ds/Graphics/RectangleShape.hpp>
#include <cpp3ds/Window/Event.hpp>
#include <cpp3ds/Window/Window.hpp>
#include <cpp3ds/Graphics/Transformable.hpp>
#include <cpp3ds/Graphics/Sprite.hpp>
#include <functional>

namespace gui3ds {

    class Button : public cpp3ds::Drawable, public cpp3ds::Transformable {
    public:

        Button();

        bool processEvent(const cpp3ds::Event &event);

        void toggle();


        void setTexture(const cpp3ds::Texture &texture);

        void setActiveTexture(const cpp3ds::Texture &texture);

        bool getActive();

        void onClick(const std::function<void()> &callback);


        void setPosition(float x, float y);

    protected:
        virtual void draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const;

        void ensureUpdate(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const;

    private:
        cpp3ds::Sprite m_texture;
        cpp3ds::Sprite m_activeTexture;

        std::function<void()> m_clickFunction;

        mutable bool m_needsUpdate;
        bool m_touched = false;
        bool m_active;
    };

} // namespace gui3ds

#endif // GUI3DS_BUTTON_HPP
