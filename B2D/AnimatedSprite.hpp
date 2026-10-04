#pragma once
#include <Math/color.h>
#include <Math/transform_2d.h>

#include <Basic/Resource/Texture.hpp>
#include <Basic/2D/SpriteBatch.hpp>

#include "B2D/Animation/AnimationLibrary.hpp"


namespace B2D
{

struct AnimatedSprite
{
    AnimationLibrary& animation_library;
    
    f32 time = 0;
    
    bool playing = false;
    B2D::AnimationLibrary::Animation* animation = nullptr;
    u32 current_sequence_index = 0;

    Color mod_color = Color(255, 255, 255, 255);

    AnimatedSprite(AnimationLibrary& animation_library);

    void play(Collections::StringView anim);

    void update(f32 dt);
    void render_internal(const Rect2D& rect, const Transform2D& transform, Basic::SpriteBatch& sprite_batch);
};

}