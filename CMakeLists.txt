

bread_package(
    NAME
        "B2D"
    ASSETS
        "assets"
    INCLUDES
        "."
    SOURCES
        "B2D/Animation/Animation.cpp"
        "B2D/Animation/AnimationLibrary.cpp"
)

target_link_libraries(B2D PUBLIC Basic)