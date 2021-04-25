#include "_8Bit.h"
#include <fstream>
#include <iostream>

void _8Bit::readFile(const std::string &filename) {
	std::ifstream file(filename,std::ios::binary | std::ios::in);
	if(file.is_open()){
        file.read((char*)&wavHeader, sizeof(WavHeader));
		buffer = new unsigned char[wavHeader.dataChunkSize];	
		file.read((char*)buffer, wavHeader.dataChunkSize);
		if (checkForList()) {	
			file.read((char*)&listHeader, sizeof(ListHeader));
			for(int i = 0; !file.eof(); i++) {
				list.push_back(List());
				file.read((char*)&list[i].infoID, sizeof(list[i].infoID));
				file.read((char*)&list[i].infoSize, sizeof(list[i].infoSize));
				list[i].info = new char[list[i].infoSize];
				file.read((char*)list[i].info, list[i].infoSize);
			}
		}
		file.close();
	}
}

void _8Bit::writeFile(const std::string &outFileName) {
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wavHeader,sizeof(wavHeader));
    outFile.write((char*)buffer, wavHeader.dataChunkSize);
    if(hasListChunk) {
    	outFile.write((char*)&listHeader, sizeof(listHeader));
   		for(List r : list) {
    		outFile.write((char*)&r.infoID, 4);
    		outFile.write((char*)&r.infoSize,4);
    		outFile.write((char*)&r.info, r.infoSize);
    	}
    }
    outFile.close();
}

bool _8Bit::checkForList() {
	if (wavHeader.chunkSize - wavHeader.dataChunkSize > 158) {
		hasListChunk = 1;
		return 1;
	} else {
		return 0;
	}
}

int _8Bit::getBufferSize () const {
	return wavHeader.dataChunkSize;
}

_8Bit::~_8Bit() {
	    if(buffer != NULL) {
        	delete[] buffer;
        }
}	
