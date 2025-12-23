#include "propagator.h"

State propagateOrbit(
    const State& startState, 
    State (*integrator)(const State& state, double mu, double dt), 
    double mu,
    double dt,
    size_t numSteps,
    OrbitObserver* observer //might be null
){
    if(observer != nullptr){
        observer->onInit(startState,0);
    }
    
    State currentState = startState;

    double time = 0.0;
    for(size_t i = 0; i < numSteps; i++){
        currentState = integrator(currentState, mu, dt);
        time += dt;
        if(observer != nullptr){
            observer->onStep(currentState, time);
        }
    }
    
    if(observer != nullptr){
        observer->onFinish();
    }
    return currentState;
}