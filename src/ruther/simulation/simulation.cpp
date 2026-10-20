#include "ruther/simulation/simulation.hpp"
#include "ruther/particle/particle.hpp"
#include "ruther/utils/vector.hpp"

#include <algorithm>

constexpr double ELECTROSTATIC_CONSTANT = 8.9875517923e9;

static void applyCoulomb(Ruther::Particle* a, Ruther::Particle* b) {
    if (a->charge == 0.0 || b->charge == 0.0) {
        return;
    }

    Ruther::Vec2 delta = a->position - b->position;

    double distanceSquared = delta.x * delta.x + delta.y * delta.y;
    if (distanceSquared < 1e-18) {
        return;
    }

    Ruther::Vec2 direction = delta.normalized();

    double chargeProduct = a->charge * b->charge;

    double forceMagnitude = ELECTROSTATIC_CONSTANT * chargeProduct / distanceSquared;

    Ruther::Vec2 forceA = (direction * forceMagnitude);
    Ruther::Vec2 forceB = -(direction * forceMagnitude);

    a->applyForce(forceA);
    b->applyForce(forceB);
}

namespace Ruther {

void Simulation::update(double dt) {
    for (std::size_t i = 0; i < particles_.size(); ++i) {
        for (std::size_t j = i + 1; j < particles_.size(); ++j) {
            Ruther::Particle *a = particles_[i].get();
            Ruther::Particle *b = particles_[j].get();

            applyCoulomb(a, b);
        }
    }

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
