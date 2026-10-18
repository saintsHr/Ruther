#include <memory>
#include <vector>

#include "ruther/particle/particle.hpp"
#include "ruther/renderer/renderer.hpp"
#include "ruther/utils/vector.hpp"

const std::string PROJECT = "Ruther";
const std::string VERSION = "v0.0.0";

const std::string WINDOW_NAME = PROJECT + " - " + VERSION;
constexpr Ruther::Vec2 WINDOW_SIZE = {800.0f, 600.0f};
constexpr int WINDOW_FPS = 60;

std::vector<std::unique_ptr<Ruther::Particle>> particles;

int main() {
    Ruther::Renderer::createWindow(WINDOW_SIZE, WINDOW_NAME, WINDOW_FPS);

    while (!Ruther::Renderer::windowShouldClose()) {
        for (const auto& particle : particles) {
            particle->update(1.0 / WINDOW_FPS);
        }

        Ruther::Renderer::beginFrame();

        for (const auto& particle : particles) {
            particle->render();
        }

        Ruther::Renderer::endFrame();
    }

    Ruther::Renderer::destroyWindow();
    return 0;
}
