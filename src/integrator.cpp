#include"integrator.h"
#include "dynamics.h"
#include "state.h"

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

State rk4(const State& state, double mu, double dt){

    State k1 = computeStateDerivative(state, mu);
    State k2 = computeStateDerivative(state + k1*(dt/2), mu);
    State k3 = computeStateDerivative(state + k2*(dt/2), mu);
    State k4 = computeStateDerivative(state + k3*dt, mu);

    return state + (dt/6) * (k1 + 2*k2 + 2*k3 + k4);
}
