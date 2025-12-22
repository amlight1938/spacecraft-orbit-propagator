#include "dynamics.h"
#include <cmath>

double accelerationFactor(const State& state, const double mu){
    double rSquared = 
        state.rx * state.rx +
        state.ry * state.ry +
        state.rz * state.rz;
                    
    double rNorm = std::sqrt(rSquared);
    if (rNorm == 0.0){
        return 0.0; // dont divide by 0
    }
    return -mu/(std::pow(rNorm,3));
}

State computeStateDerivative(const State& state, const double mu){
    State stateDot;
    stateDot.rx = state.vx;
    stateDot.ry = state.vy;
    stateDot.rz = state.vz;

    double a = accelerationFactor(state, mu);
    stateDot.vx = a * state.rx;
    stateDot.vy = a * state.ry;
    stateDot.vz = a * state.rz;

    return stateDot;
}

