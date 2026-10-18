#pragma once

#include <raylib.h>
#include <string>

#include "ruther/color.hpp"
#include "ruther/vector.hpp"

namespace Ruther::Renderer {

void createWindow(Vec2 size, const std::string name, int fps);
void destroyWindow(void);
bool windowShouldClose(void);

void beginFrame(void);
void endFrame(void);

void drawCircle(Vec2 position, float radius, Ruther::Color);

}
