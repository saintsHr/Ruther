#include "ruther/renderer/renderer.hpp"
#include <algorithm>
#include <raylib.h>

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

void drawCircle(Vec2 position, float radius, Ruther::Color color) {
    DrawCircleV(
        (Vector2){position.x, position.y}, radius,
        ::Color{
            std::clamp<unsigned char>(255.0f * color.r, 0, 255),
            std::clamp<unsigned char>(255.0f * color.g, 0, 255),
            std::clamp<unsigned char>(255.0f * color.b, 0, 255),
            255
        }
    );
}

}
