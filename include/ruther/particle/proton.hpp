#pragma once

#include "ruther/particle/particle.hpp"

namespace Ruther {

class Proton : public Particle {
public:
    Proton() {
        type = ParticleType::PROTON;
        mass = 1.6726219e-27;
        charge = 1.602176634e-19;
        radius = 0.84e-15;
        color = {1.0, 0.25, 0.25};
    }
protected:

private:

};

}
