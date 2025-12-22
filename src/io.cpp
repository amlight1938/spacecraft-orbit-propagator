#include "io.h"
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

namespace{
    std::ofstream outputFile;
}

//return true if successfully opened
bool openFile(const std::string& filepath){
    outputFile.open(filepath);
    outputFile << std::setprecision(10);
    return outputFile.is_open();
} 

void writeHeader(){
    outputFile << "time" << ","
                << "rx" << ","
                << "ry" << ","
                << "rz" << ","
                << "vx" << ","
                << "vy" << ","
                << "vz";
    outputFile << "\n";
}

void writeLine(const State& state, double time){
    outputFile << time << ","
                << state.rx << ","
                << state.ry << ","
                << state.rz << ","
                << state.vx << ","
                << state.vy << ","
                << state.vz;

    outputFile << "\n";
}

void closeFile(){
    if(outputFile.is_open()){
        outputFile.close();
    }
}