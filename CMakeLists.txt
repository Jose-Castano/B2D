

bread_package(
    NAME
        "B2D"
    ASSETS
        "assets"
    INCLUDES
        "."
    SOURCES
        "B2D/Animation/AnimationLibrary.cpp"

        "B2D/AnimatedSprite.cpp"
        "B2D/Sprite.cpp"
)

target_link_libraries(B2D PUBLIC Basic)