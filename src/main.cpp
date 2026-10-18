#include "ruther/renderer.hpp"

const std::string PROJECT = "Ruther";
const std::string VERSION = "v0.0.0";

const std::string WINDOW_NAME = PROJECT + " - " + VERSION;
constexpr Ruther::Vec2 WINDOW_SIZE = {800.0f, 600.0f};
constexpr int WINDOW_FPS = 60;

int main() {
    Ruther::Renderer::createWindow(WINDOW_SIZE, WINDOW_NAME, WINDOW_FPS);

    while (!Ruther::Renderer::windowShouldClose()) {
        Ruther::Renderer::beginFrame();



        Ruther::Renderer::endFrame();
    }

    Ruther::Renderer::destroyWindow();
    return 0;
}
