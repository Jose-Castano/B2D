#include "B2D/Sprite.hpp"


namespace B2D
{

Sprite::Sprite()
{}

void Sprite::set_texture(Basic::Texture2D* new_texture)
{
    if(new_texture == nullptr)
    {
        texture = nullptr;
        return;
    }

    texture = new_texture;
    sprite_rect = Rect2D(Vector2(), Vector2(new_texture->get_size()));
    uv_rect = Rect2D(Vector2(), Vector2(new_texture->get_size()));
}

void Sprite::draw(const Transform2D& transform, Basic::SpriteBatch& sprite_batch)
{
    if(texture == nullptr)
    {
        return;
    }

    sprite_batch.draw_texture_transformed_pivot_centered(
        sprite_rect, transform, uv_rect, mod_color,
        texture->texture_view, Vector2(texture->size), Basic::SpriteFilter::Nearest);
}

}
