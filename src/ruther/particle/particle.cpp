#include "ruther/particle/particle.hpp"
#include "ruther/renderer/renderer.hpp"

namespace Ruther {

void Particle::update(double dt) {
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    acceleration = {0.0, 0.0};
}

void Particle::render() const {
    Ruther::Renderer::drawCircle(position, radius, color);
}

void Particle::applyForce(Vec2 force) {
    if (mass <= 0.0) {
        return;
    }

    acceleration.x += force.x / mass;
    acceleration.y += force.y / mass;
}

}
