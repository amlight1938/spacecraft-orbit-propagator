#include "state.h"

State operator*(const State& state, double scalar){
    State newState;
    newState.rx = state.rx * scalar;
    newState.ry = state.ry * scalar;
    newState.rz = state.rz * scalar;
    newState.vx = state.vx * scalar;
    newState.vy = state.vy * scalar;
    newState.vz = state.vz * scalar;
    return newState;
}

State operator*(double scalar, const State& state){
    return state*scalar;
}

State operator+(const State& state1, const State& state2){
    State newState;
    newState.rx = state1.rx + state2.rx;
    newState.ry = state1.ry + state2.ry;
    newState.rz = state1.rz + state2.rz;
    newState.vx = state1.vx + state2.vx;
    newState.vy = state1.vy + state2.vy;
    newState.vz = state1.vz + state2.vz;
    return newState;
}