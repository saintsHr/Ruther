#include "ruther/renderer.hpp"

const std::string PROJECT = "Ruther";
const std::string VERSION = "v0.0.0";

const std::string WINDOW_NAME = PROJECT + " - " + VERSION;
constexpr Ruther::Vec2 WINDOW_SIZE = {800.0f, 600.0f};
constexpr int WINDOW_FPS = 60;

int main() {
    Ruther::createWindow(WINDOW_SIZE, WINDOW_NAME, WINDOW_FPS);

    while (!Ruther::windowShouldClose()) {
        Ruther::beginFrame();
        Ruther::endFrame();
    }

    Ruther::destroyWindow();
    return 0;
}
