#include "B2D/Animation/Animation.hpp"


namespace B2D
{

Animation::Animation(Mem::Allocator& allocator)
: frames(allocator, 4, {})
{}

void Animation::add_frame(Basic::Texture2D* texture, Rect2D uv, f32 duration)
{
    (void)frames.add(
        Frame
        {
            .texture = texture,
            .uv = uv,
            .duration = duration,
        }
    );
}

}