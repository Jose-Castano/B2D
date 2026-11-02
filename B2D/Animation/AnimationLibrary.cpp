#include "B2D/Animation/AnimationLibrary.hpp"


namespace B2D
{

AnimationLibrary::AnimationLibrary(Mem::Allocator& allocator)
: allocator(allocator), animations(allocator, 4)
{}

Animation& AnimationLibrary::add_animation(Collections::StringView name)
{
    return animations.emplace(name, allocator);
}

Animation& AnimationLibrary::get_animation(Collections::StringView name)
{
    return animations.get(name);   
}

}