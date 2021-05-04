#ifndef WAVCONSOLE_H
#define WAVCONSOLE_H
#include <iostream>
#include <vector>
#include <string>
#include <experimental/filesystem>
#include "Command.h"
#include "WavManager.h"
#include "WriteToCSV.h"  
class WavConsole{  
public: 
WavManager wm; 
WriteToCSV wcsv;  
std::vector<Command> commands;
void addCommand(std::string name, std::string helpText);
void processWav();
void editMetadata();
void writeCSV();
void printCommands();
std::vector<std::experimental::filesystem::path> pullFilenames(std::string directory);
void runConsole();
};
#endif
