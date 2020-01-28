#pragma once
#include "lists_destruction.h"
#include <fstream>
#include <iostream>


Label* readInput(Label **hd, std::string fileName);

void writeOutput(Label **hd, std::string fileName);
