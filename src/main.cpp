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
const size_t numSteps = 3000;
const std::string rk4Filepath = "./output/rk4-orbit.csv"; //from project root
const std::string eulerFilepath = "./output/euler-orbit.csv"; //from project root
const bool logOutput = true;

// ------------------
// initial conditions
// ------------------

// =====================================================
// CASE 3: HIGH-ALTITUDE INCLINED ORBIT (MEO-LIKE)
// =====================================================
// meters (ECI frame)
// ~16,000 km altitude (GNSS-like)
const double rx0 = 16378000.0;
const double ry0 = 0.0;
const double rz0 = 0.0;

// m/s
// Circular velocity at this radius, inclined out of equatorial plane
const double vx0 = 1000.0;
const double vy0 = 3000.0;
const double vz0 = 3000.0;

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


