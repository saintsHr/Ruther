#include "ruther/renderer/renderer.hpp"
#include <algorithm>
#include <raylib.h>

constexpr double RENDER_SCALE = 1.0 / 1e16;

namespace Ruther::Renderer {

void createWindow(Vec2 size, const std::string name, int fps) {
    InitWindow(size.x, size.y, name.c_str());
    SetTargetFPS(fps);
}

void destroyWindow(void) {
    CloseWindow();
}

bool windowShouldClose(void) {
    return WindowShouldClose();
}

void beginFrame(void) {
    BeginDrawing();
    ClearBackground(::BLACK);
}

void endFrame(void) {
    EndDrawing();
}

void drawCircle(Vec2 position, double radius, Ruther::Color color) {
    radius /= RENDER_SCALE;

    DrawCircleV(
        (Vector2){
            static_cast<float>(position.x),
            static_cast<float>(position.y)
        }, radius, ::Color{
            std::clamp<unsigned char>(255.0f * color.r, 0, 255),
            std::clamp<unsigned char>(255.0f * color.g, 0, 255),
            std::clamp<unsigned char>(255.0f * color.b, 0, 255),
            255
        }
    );
}

}
