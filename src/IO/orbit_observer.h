#pragma once
#include "../state.h"

class OrbitObserver{
    public:
        virtual ~OrbitObserver() = default;
        virtual void onInit(const State& currentState, double time) = 0;
        virtual void onStep(const State& currentState, double time) = 0;
        virtual void onFinish() = 0;
};