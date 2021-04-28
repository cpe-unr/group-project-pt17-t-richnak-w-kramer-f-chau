#ifndef WAVMANAGER_H
#define WAVMANAGER_H

#include "Wav.h"
#include "Wav.cpp"
#include "WavAbs.h"
//#include "_8Bit.h"
//#include "_16Bit.h"
#include <vector>

class WavManager {
public:
	std::vector<WavAbs*> wavs;
public:
	WavManager();
	void populateVector(std::vector<std::string> filenames);

};

#endif
