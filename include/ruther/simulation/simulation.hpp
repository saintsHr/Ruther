#pragma once

#include "ruther/particle/particle.hpp"

#include <memory>
#include <vector>

namespace Ruther {

class Simulation {
public:
    void update(double dt);
    void render();

    Ruther::Particle *addParticle(std::unique_ptr<Ruther::Particle> particle);
    bool removeParticle(const Ruther::Particle *particle);
protected:

private:
    std::vector<std::unique_ptr<Ruther::Particle>> particles_;
};

}
