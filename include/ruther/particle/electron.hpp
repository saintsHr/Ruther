#pragma once

#include "ruther/particle/particle.hpp"

namespace Ruther {

class Electron : public Particle {
public:
    Electron() {
        type = ParticleType::ELECTRON;
        mass = 9.1093837e-31;
        charge = -1.602176634e-19;
        radius = 0.4e-15;
        color = {0.35, 0.65, 1.0};
    }
protected:

private:

};

}
