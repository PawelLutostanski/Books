/** @file */
#pragma once
#include "lists_destruction.h"
#include <fstream>
#include <iostream>

/**
 * Reads file of given fileName and pushes Books to given Labels 
 * @param hd pointer to Linked List of Labels
 * @param fileName string which corresponds which file it should open
 * @return pointer
 */
Label* readInput(Label **hd, std::string fileName);

/**
 * Writes list to file
 * @param hd pointer to Label LL
 * @param fileName string which corresponds to  name of output file
 */
void writeOutput(Label **hd, std::string fileName);
