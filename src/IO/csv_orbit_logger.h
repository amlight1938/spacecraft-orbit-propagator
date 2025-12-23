#pragma once

#include "orbit_observer.h"
#include <string>
#include <fstream>

class CsvOrbitLogger : public OrbitObserver {
    private:
        std::string filepath;
        std::ofstream outputFile;

    public:
        CsvOrbitLogger(const std::string& relativeFilepath);
        void onInit(const State& currentState, double time) override;
        void onStep(const State& currentState, double time) override;
        void onFinish() override;
};