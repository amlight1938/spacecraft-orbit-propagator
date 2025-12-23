#include "csv_orbit_logger.h"
#include <iomanip>

CsvOrbitLogger::CsvOrbitLogger(const std::string& relativeFilepath){
    filepath = relativeFilepath;
}

void CsvOrbitLogger::onInit(const State& currentState, double time){
    //open file
    outputFile.open(filepath);
    outputFile << std::setprecision(10);

    //write header 
    outputFile << "time" << ","
        << "rx" << ","
        << "ry" << ","
        << "rz" << ","
        << "vx" << ","
        << "vy" << ","
        << "vz";
    outputFile << "\n";

    onStep(currentState, time);
}

void CsvOrbitLogger::onStep(const State& currentState, double time){
    outputFile << time << ","
        << currentState.rx << ","
        << currentState.ry << ","
        << currentState.rz << ","
        << currentState.vx << ","
        << currentState.vy << ","
        << currentState.vz;

    outputFile << "\n";
}

void CsvOrbitLogger::onFinish(){
    if(outputFile.is_open()){
        outputFile.close();
    }
}
