#pragma once

#include "state.h"
#include "IO/orbit_observer.h"
#include <cstddef>

State propagateOrbit(
    const State& startState, 
    State (*integrator)(const State& state, double mu, double dt), 
    double mu,
    double dt,
    size_t numSteps,
    OrbitObserver* observer //can be null sometimes
);