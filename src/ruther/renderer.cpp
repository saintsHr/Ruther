#include "ruther/renderer.hpp"
#include <raylib.h>

namespace Ruther {

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
    ClearBackground(BLACK);
}

void endFrame(void) {
    EndDrawing();
}

}
