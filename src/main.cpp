#include <iostream>
#include "integrator.h"
#include "io.h"
#include <string>
#include "propagator.h"
#include "IO/csv_orbit_logger.h"
#include <cmath>

// ------------------
// physical constants
// ------------------

const double mu = 3.986004418e14; // m^3/s^2
const double earthRadius = 6378000; // meters

// ------------------
// simulation constants
// ------------------
const double dt = 5; //seconds
const size_t numSteps = 10000;
const std::string rk4Filepath = "./output/rk4-orbit.csv"; //from project root
const std::string eulerFilepath = "./output/euler-orbit.csv"; //from project root
const bool logOutput = true;

// ------------------
// initial conditions
// ------------------
// //CIRCULAR
// // meters (ECI frame)
// const double rx0 = 6778000.0;   // Earth radius (6378 km) + 400 km
// const double ry0 = 0.0;
// const double rz0 = 0.0;

// // m/s (circular orbit velocity)
// const double vx0 = 0.0;
// const double vy0 = 7668.6;
// const double vz0 = 0.0;

//ELLIPTICAL
// meters (ECI frame — start at perigee on +X axis)
const double rx0 = 8078000.0;   // Earth radius (6378 km) + 700 km
const double ry0 = 0.0;
const double rz0 = 0.0;

// m/s (perigee velocity, purely tangential)
const double vx0 = 1000.0;
const double vy0 = 6423.0;
const double vz0 = 5000.0;

int main(){
    State initialState{
        rx0, ry0, rz0,
        vx0, vy0, vz0
    };

    OrbitObserver* eulerObserver = nullptr;
    OrbitObserver* rk4Observer = nullptr;
    CsvOrbitLogger eulerLogger = CsvOrbitLogger(eulerFilepath);
    CsvOrbitLogger rk4Logger = CsvOrbitLogger(rk4Filepath);

    if(logOutput){
        eulerObserver = &eulerLogger;
        rk4Observer = &rk4Logger;
    }

    State eulerFinalState = propagateOrbit(initialState, eulerStep, mu, dt, numSteps, eulerObserver);

    State rk4FinalState = propagateOrbit(initialState, rk4, mu, dt, numSteps, rk4Observer);
    
    return 0;
}


