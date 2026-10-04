#pragma once
#include <Math/color.h>
#include <Math/transform_2d.h>

#include <Basic/Resource/Texture.hpp>
#include <Basic/2D/SpriteBatch.hpp>


namespace B2D
{

struct Sprite
{
    Basic::Texture2D* texture = nullptr;
    Rect2D sprite_rect = Rect2D(0, 0, 1, 1);
    Rect2D uv_rect = Rect2D(0, 0, 1, 1);
    Color mod_color = Color(255, 255, 255, 255);

    Sprite();

    void set_texture(Basic::Texture2D* new_texture);

    void draw(const Transform2D& transform, Basic::SpriteBatch& sprite_batch);
};

}