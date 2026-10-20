#include "ruther/simulation/simulation.hpp"

#include <algorithm>

namespace Ruther {

void Simulation::update(double dt) {
    for (auto& particle : particles_) {
        particle->update(dt);
    }
}

void Simulation::render() {
    for (auto& particle : particles_) {
        particle->render();
    }
}

Ruther::Particle* Simulation::addParticle(std::unique_ptr<Ruther::Particle> particle) {
    if (!particle) {
        return nullptr;
    }

    auto* raw = particle.get();
    particles_.push_back(std::move(particle));

    return raw;
}

bool Simulation::removeParticle(const Ruther::Particle *particle) {
    auto it = std::find_if(
        particles_.begin(), particles_.end(),
        [particle](const auto& ptr) {
            return ptr.get() == particle;
        }
    );

    if (it == particles_.end()) {
        return false;
    }

    particles_.erase(it);

    return true;
}

}
