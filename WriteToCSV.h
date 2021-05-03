#ifndef WRITE_CSV_H
#define WRITE_CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Wav.h"

class WriteToCSV{

bool writeDataToFile(std::string CSVfile_name, std::vector<std::string> fileNames, std::vector<IReadable*> wavFiles);


};

#endif
