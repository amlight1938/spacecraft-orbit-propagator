#include <iostream>
#include "integrator.h"
#include "io.h"
#include <string>
#include "propagator.h"
#include "IO/csv_orbit_logger.h"

// ------------------
// physical constants
// ------------------

const double mu = 3.986004418e14; // m^3/s^2
const double earthRadius = 6378000; // meters

// ------------------
// simulation constants
// ------------------
const double dt = 5; //seconds
const size_t numSteps = 20000;
const std::string rk4Filepath = "./output/rk4-orbit.csv"; //from project root
const std::string eulerFilepath = "./output/euler-orbit.csv"; //from project root
const bool logOutput = true;

// ------------------
// initial conditions
// ------------------
//meters
const double rx0 = 6778000;
const double ry0 = 0;
const double rz0 = 0;
//m/s
const double vx0 = 3452;
const double vy0 = 5670;
const double vz0 = 4000;


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


