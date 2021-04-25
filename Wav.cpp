/*
 * This class is designed to work with PCM 8-bit mono wavefiles.
 * It makes many assumptions about the format of the wave as a result.
 * It will NOT work with stereo files or any other bit-depth than 8 bits.
 */

/*include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"



void Wav::readTechnical(const std::string &filename) {
	std::ifstream file(filename,std::ios::binary | std::ios::in);
	if(file.is_open()){
        file.read((char*)&wavHeader, sizeof(WavHeader));
    }
}

void Wav::writeFile(const std::string &outFileName) {}

int Wav::getBufferSize() const {
    return wavHeader.dataChunkSize;
}
*/
