#pragma once

#include <string>
#include "state.h"

bool openFile(const std::string& filepath); //return true if successfully opened

void writeHeader();

void writeLine(const State& state, double time);

void closeFile();