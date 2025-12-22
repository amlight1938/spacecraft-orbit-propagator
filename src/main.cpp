#include <iostream>
#include "integrator.h"
#include "io.h"
#include <string>

// ------------------
// physical constants
// ------------------

const double mu = 3.986004418e14; // m^3/s^2
const double earthRadius = 6378000; // meters

// ------------------
// simulation constants
// ------------------
const double dt = 5; //seconds
const int numSteps = 1000;
const std::string filepath = "./output/orbit.csv"; //from project root

// ------------------
// initial conditions
// ------------------
//meters
const double rx0 = 6778000;
const double ry0 = 0;
const double rz0 = 0;
//m/s
const double vx0 = 0;
const double vy0 = 7670;
const double vz0 = 0;


int main(){

    State currentState;
    currentState.rx = rx0;
    currentState.ry = ry0;
    currentState.rz = rz0;
    currentState.vx = vx0;
    currentState.vy = vy0;
    currentState.vz = vz0;

    //open file and write header. exit if not succesful
    if(!openFile(filepath)){
        std::cerr << "Error opening file";
        return 1;
    }

    writeHeader();
    writeLine(currentState, 0);

    for(size_t i = 1; i < numSteps; i++){
        State newState = eulerStep(currentState, mu, dt);
        writeLine(newState,i * dt);
        currentState = newState;
    }
    
    closeFile();

    return 0;
}