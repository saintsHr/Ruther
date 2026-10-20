#include "ruther/particle/electron.hpp"
#include "ruther/particle/neutron.hpp"
#include "ruther/particle/proton.hpp"
#include "ruther/renderer/renderer.hpp"
#include "ruther/input/input.hpp"
#include "ruther/simulation/simulation.hpp"
#include "ruther/utils/vector.hpp"

const std::string PROJECT = "Ruther";
const std::string VERSION = "v0.0.0";

const std::string WINDOW_NAME = PROJECT + " - " + VERSION;
constexpr double WINDOW_WIDTH = 800.0;
constexpr double WINDOW_HEIGHT = 600.0;
constexpr int WINDOW_FPS = 60;

constexpr double SIMULATION_DT = 1.0 / WINDOW_FPS;
constexpr double SIMULATION_SPEED = 50.0;

static void handleInput(Ruther::Simulation *sim);

int main() {
    Ruther::Renderer::createWindow(
        {WINDOW_WIDTH, WINDOW_HEIGHT},
        WINDOW_NAME, WINDOW_FPS
    );

    Ruther::Simulation sim;

    while (!Ruther::Renderer::windowShouldClose()) {
        handleInput(&sim);
        sim.update(SIMULATION_DT * SIMULATION_SPEED);

        Ruther::Renderer::beginFrame();
        sim.render();
        Ruther::Renderer::endFrame();
    }

    Ruther::Renderer::destroyWindow();
    return 0;
}

static void handleInput(Ruther::Simulation *sim) {
    if (Ruther::Input::isKeyPressed(Ruther::Input::Key::KEY_ONE)) {
        auto proton = std::make_unique<Ruther::Proton>();

        proton->position = Ruther::Input::getMousePosition();

        sim->addParticle(std::move(proton));
    }
    if (Ruther::Input::isKeyPressed(Ruther::Input::Key::KEY_TWO)) {
        auto neutron = std::make_unique<Ruther::Neutron>();

        neutron->position = Ruther::Input::getMousePosition();

        sim->addParticle(std::move(neutron));
    }
    if (Ruther::Input::isKeyPressed(Ruther::Input::Key::KEY_THREE)) {
        auto electron = std::make_unique<Ruther::Electron>();

        electron->position = Ruther::Input::getMousePosition();

        sim->addParticle(std::move(electron));
    }
}
