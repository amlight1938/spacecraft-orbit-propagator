#pragma once
#include "state.h"

State eulerStep(const State& state, double mu, double dt);

State rk4(const State& state, double mu, double dt);