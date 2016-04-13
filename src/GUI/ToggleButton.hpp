#ifndef GUI3DS_TOGGLEBUTTON_HPP
#define GUI3DS_TOGGLEBUTTON_HPP

#include <cpp3ds/Graphics/Text.hpp>
#include <cpp3ds/Graphics/RectangleShape.hpp>
#include "NinePatch.hpp"
#include "../TweenTransformable.hpp"

namespace gui3ds {

    class ToggleButton : public cpp3ds::Drawable, public util3ds::TweenTransformable {
    public:
        static const int COLOR_RGB = 11;
        static const int COLOR_ALPHA = 12;
        static const int TEXTCOLOR_ALPHA = 13;

        ToggleButton();

        bool processEvent(const cpp3ds::Event &event);

        void toggle();

        void setTextOffset(const cpp3ds::Vector2f &offset);

        const cpp3ds::Vector2f &getTextOffset() const;

        void setString(const cpp3ds::String &string);

        const cpp3ds::String &getString() const;

        cpp3ds::Text &getText() const;

        void setTextColor(const cpp3ds::Color &color);

        const cpp3ds::Color &getTextColor() const;

        void setTextActiveColor(const cpp3ds::Color &color);

        const cpp3ds::Color &getTextActiveColor() const;

        void setTexture(const cpp3ds::Texture &texture);

        void setActiveTexture(const cpp3ds::Texture &texture);

        const u_int getTextSize() const;

        void setTextSize(const u_int &size);

        const cpp3ds::FloatRect getRect() const;

        void onClick(const std::function<void()> &callback);

        void setPosition(float x, float y);

    protected:
        virtual void draw(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const;

        void ensureUpdate(cpp3ds::RenderTarget &target, cpp3ds::RenderStates states) const;

    private:
        mutable cpp3ds::FloatRect m_rect;
        mutable cpp3ds::Text m_text;

        cpp3ds::Vector2f m_textOffset;
        cpp3ds::Color m_textColor;
        cpp3ds::Color m_textActiveColor;

        cpp3ds::Sprite m_texture;
        cpp3ds::Sprite m_activeTexture;

        std::function<void()> m_clickFunction;

        mutable bool m_needsUpdate;
        bool m_active;
    };

} // namespace gui3ds

#endif // GUI3DS_TOGGLEBUTTON_HPP
