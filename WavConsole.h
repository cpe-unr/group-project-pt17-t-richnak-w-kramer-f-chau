#ifndef WAVCONSOLE_H
#define WAVCONSOLE_H
#include <iostream>
#include <vector>
#include <string>
#include <experimental/filesystem>
#include "Command.h"
#include "WavManager.h"
// #include "WriteToCSV.h" uncomment and add .o back to the makefile when fixed 
class WavConsole{  
public: 
WavManager wm; 
// WriteToCSV wcsv; uncomment when writetocsv fixed  
std::vector<Command> commands;
void addCommand(std::string name, std::string helpText);
void processWav();
void editMetadata();
void writeCSV();
void printCommands();
std::vector<std::string> pullFilenames(std::string directory);
void runConsole();
};
#endif
