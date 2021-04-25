#include "WavManager.h"
#include <fstream>

WavManager::WavManager() {}

void WavManager::populateVector(std::vector<std::string> filenames) {
	for (std::string filename : filenames) {
		WavHeader n;
		std::ifstream file(filename,std::ios::binary | std::ios::in);
		if(file.is_open()) {
			file.read((char*)&n, sizeof(WavHeader));
			file.close();
		}
		if (n.bitDepth == 8) {
			Wav* a = new _8Bit;
			a->readFile(filename);
			wavs.push_back(a);
		} else if (n.bitDepth == 16) {
			Wav* a = new _16Bit;
			a->readFile(filename);
			wavs.push_back(a);
		}
	}
}
