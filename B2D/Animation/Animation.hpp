#pragma once
#include <Collections/Array.hpp>
#include <Collections/StringMap.hpp>
#include <Math/rect_2d.h>
#include <Basic/Resource/Texture.hpp>


namespace B2D
{

struct Animation
{
    struct Frame
    {
        Basic::Texture2D* texture;
        Rect2D uv;
        f32 duration;
    };

    Collections::Array<Frame> frames;

    Animation(Mem::Allocator& allocator);

    void add_frame(Basic::Texture2D* texture, Rect2D uv, f32 duration);
};

}