#include "_16Bit.h"
#include <fstream>
#include <iostream>

void _16Bit::readFile(const std::string &filename) {
	std::ifstream file(filename,std::ios::binary | std::ios::in);
	if(file.is_open()){
        file.read((char*)&wavHeader, sizeof(WavHeader));
		buffer = new short[wavHeader.dataChunkSize];	
		file.read((char*)buffer, wavHeader.dataChunkSize);	
			file.read((char*)&listHeader, sizeof(ListHeader));
			int listBytes = sizeof(listHeader.typeID);
			for(int i = 0; listBytes < listHeader.listChunkSize; i++) {
				list.push_back(List());
				file.read((char*)&list[i].infoID, sizeof(list[i].infoID));
				listBytes += sizeof(list[i].infoID);
				file.read((char*)&list[i].infoSize, sizeof(list[i].infoSize));
				listBytes += sizeof(list[i].infoSize);
				list[i].info = new char[list[i].infoSize];
				file.read((char*)list[i].info, list[i].infoSize);
				listBytes += list[i].infoSize;
			}
		file.close();
	}
}

void _16Bit::writeFile(const std::string &outFileName) {
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wavHeader,sizeof(wavHeader));
    outFile.write((char*)buffer, wavHeader.dataChunkSize);
    outFile.write((char*)&listHeader, sizeof(listHeader));
   		for(List r : list) {
    		outFile.write(r.infoID, sizeof(r.infoID));
    		outFile.write((char*)&r.infoSize,4);
    		outFile.write(r.info, r.infoSize);
    	}
    outFile.close();
}

bool _16Bit::checkForList() {
	if (listHeader.LIST == "LIST") {
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
