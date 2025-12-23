#pragma once

struct State{
    //position (meters)
    double rx, ry, rz;
    //velocity (m/s)
    double vx, vy, vz;
};

State operator*(double scalar, const State& state);

State operator*(const State& state, double scalar);

State operator+(const State& state1, const State& state2);

