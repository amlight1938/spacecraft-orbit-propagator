#include"integrator.h"
#include "dynamics.h"

State eulerStep(const State& state, double mu, double dt){

    State stateDot = computeStateDerivative(state, mu);

    State newState;
    //velocity step
    newState.vx = state.vx + stateDot.vx * dt;
    newState.vy = state.vy + stateDot.vy * dt;
    newState.vz = state.vz + stateDot.vz * dt;

    //position step
    newState.rx = state.rx + state.vx * dt;
    newState.ry = state.ry + state.vy * dt;
    newState.rz = state.rz + state.vz * dt;

    return newState;
}

