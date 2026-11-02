#pragma once
#include <B2D/Animation/Animation.hpp>


namespace B2D
{

struct AnimationLibrary
{
    Mem::Allocator& allocator;
    Collections::StringMap<Animation> animations;

    AnimationLibrary(Mem::Allocator& allocator);

    Animation& add_animation(Collections::StringView name);
    Animation& get_animation(Collections::StringView name);
};

}