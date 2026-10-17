#pragma once

#include <raylib.h>
#include <string>

#include "ruther/vector.hpp"

namespace Ruther {

void createWindow(Vec2 size, const std::string name, int fps);
void destroyWindow(void);
bool windowShouldClose(void);

void beginFrame(void);
void endFrame(void);

}
