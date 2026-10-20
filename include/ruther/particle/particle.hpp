#pragma once

#include <cstdint>

#include "ruther/utils/color.hpp"
#include "ruther/utils/vector.hpp"

constexpr uint64_t INVALID_ID = UINT64_MAX;

namespace Ruther {

enum class ParticleType {
    NONE,

    NEUTRON,
    PROTON,
    ELECTRON
};

class Particle {
public:
    uint64_t id = INVALID_ID;
    ParticleType type = ParticleType::NONE;

    Vec2 position = {0.0, 0.0};
    Vec2 velocity = {0.0, 0.0};
    Vec2 acceleration = {0.0, 0.0};

    double mass = 0.0;
    double charge = 0.0;

    double radius = 0.0;
    Color color = {0.0, 0.0, 0.0};

    bool active = true;

    Particle() = default;
    virtual ~Particle() = default;

    void update(double dt);
    void render() const;
    void applyForce(Vec2 force);

protected:

private:

};

}
