#include "_16Bit.h"
#include <fstream>
#include <iostream>

void _16Bit::readFile(const std::string &filename) {
	std::ifstream file(filename,std::ios::binary | std::ios::in);
	if(file.is_open()){
        file.read((char*)&wavHeader, sizeof(WavHeader));
		buffer = new short[wavHeader.dataChunkSize];	
		file.read((char*)buffer, wavHeader.dataChunkSize);
		if (checkForList()) {	
			file.read((char*)&listHeader, sizeof(ListHeader));
			for(int i = 0; !file.eof(); i++) {
				list.push_back(List());
				file.read((char*)&list[i].infoID, 4);
				file.read((char*)&list[i].infoSize, 4);
				list[i].info = new char[list[i].infoSize];
				file.read((char*)list[i].info, list[i].infoSize);
			}
		}
		file.close();
	}
}

void _16Bit::writeFile(const std::string &outFileName) {
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wavHeader,sizeof(wavHeader));
    outFile.write((char*)buffer, wavHeader.dataChunkSize);
    outFile.write((char*)&listHeader.LIST, 1);
   		for(List r : list) {
    		outFile.write(r.infoID, 4);
    		outFile.write((char*)&r.infoSize,4);
    		outFile.write(r.info, r.infoSize);
    	}
    outFile.close();
}

bool _16Bit::checkForList() {
	if (wavHeader.chunkSize - wavHeader.dataChunkSize > 158) {
		hasListChunk = 1;
		return 1;
	} else {
		return 0;
	}
}

int _16Bit::getBufferSize () const {
	return wavHeader.dataChunkSize;
}
_16Bit::~_16Bit() {
	if(buffer != NULL) {
	    delete[] buffer;
	}
}
