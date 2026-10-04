#include "B2D/AnimatedSprite.hpp"


namespace B2D
{

AnimatedSprite::AnimatedSprite(B2D::AnimationLibrary& animation_library)
: animation_library(animation_library)
{
}

void AnimatedSprite::play(Collections::StringView anim)
{
    playing = true;
    animation = &animation_library.get_animation(anim);
    current_sequence_index = 0;
}

void AnimatedSprite::update(f32 dt)
{
    time += dt;

    if(!playing)
    {
        return;
    }

    Collections::String& frame_name = animation->sequence.get(current_sequence_index);
    B2D::AnimationLibrary::Frame& frame = animation->frames.get(frame_name.view());

    if(time >= frame.duration)
    {
        time = 0;
        current_sequence_index += 1;
    }

    if(current_sequence_index >= animation->sequence.count && animation->loop)
    {
        current_sequence_index = 0;
    }
    else if(current_sequence_index >= animation->sequence.count)
    {
        time = 0;
        playing = false;
        animation = nullptr;
        current_sequence_index = 0;
    }
}

void AnimatedSprite::render_internal(const Rect2D& rect, const Transform2D& transform, Basic::SpriteBatch& sprite_batch)
{
    if(!playing)
    {
        return;
    }

    Basic::Texture2D* spritesheet = animation_library.data.spritesheet;

    Collections::String& frame_name = animation->sequence.get(current_sequence_index);
    B2D::AnimationLibrary::Frame& frame = animation->frames.get(frame_name.view());

    sprite_batch.draw_texture_transformed_pivot_centered(
        rect,
        transform,
        frame.uv, mod_color,
        spritesheet->texture_view, Vector2(spritesheet->size), Basic::SpriteFilter::Nearest);
}

}
