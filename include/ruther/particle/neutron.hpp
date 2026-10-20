#pragma once

#include "ruther/particle/particle.hpp"

namespace Ruther {

class Neutron : public Particle {
public:
    Neutron() {
        type = ParticleType::NEUTRON;
        mass = 1.6749275e-27;
        charge = 0.0;
        radius = 0.8e-15;
        color = {1.0, 0.95, 0.80};
    }
protected:

private:

};

}
