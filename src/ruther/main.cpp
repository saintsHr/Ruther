#include "ruther/particle/particle.hpp"
#include "ruther/renderer/renderer.hpp"
#include "ruther/input/input.hpp"
#include "ruther/simulation/simulation.hpp"
#include "ruther/utils/vector.hpp"

const std::string PROJECT = "Ruther";
const std::string VERSION = "v0.0.0";

const std::string WINDOW_NAME = PROJECT + " - " + VERSION;
constexpr Ruther::Vec2 WINDOW_SIZE = {800.0f, 600.0f};
constexpr int WINDOW_FPS = 60;

static void handleInput(Ruther::Simulation *simulation);

int main() {
    Ruther::Renderer::createWindow(WINDOW_SIZE, WINDOW_NAME, WINDOW_FPS);

    Ruther::Simulation sim;

    while (!Ruther::Renderer::windowShouldClose()) {
        handleInput(&sim);
        sim.update(WINDOW_FPS);

        Ruther::Renderer::beginFrame();
        sim.render();
        Ruther::Renderer::endFrame();
    }

    Ruther::Renderer::destroyWindow();
    return 0;
}

static void handleInput(Ruther::Simulation *simulation) {
    if (Ruther::Input::isKeyPressed(Ruther::Input::Key::KEY_ONE)) {

    }
    if (Ruther::Input::isKeyPressed(Ruther::Input::Key::KEY_TWO)) {

    }
    if (Ruther::Input::isKeyPressed(Ruther::Input::Key::KEY_THREE)) {

    }
}
