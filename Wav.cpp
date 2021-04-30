#include "Wav.h"
#include <fstream>
#include <iostream>

template <typename T>
void Wav<T>::readFile(const std::string &filename) {
	std::ifstream file(filename,std::ios::binary | std::ios::in);
	if(file.is_open()){
        file.read((char*)&wavHeader, sizeof(WavHeader));
		buffer = new T[wavHeader.dataChunkSize];	
		file.read((char*)buffer, wavHeader.dataChunkSize);	
		file.read((char*)&listHeader, sizeof(ListHeader));
		if(checkForList()) {
			int listBytes = sizeof(listHeader.typeID);
			for(int i = 0; listBytes < listHeader.listChunkSize; i++) {
				list.push_back(List());
				file.read((char*)&list[i].infoID, sizeof(list[i].infoID));
				file.read((char*)&list[i].infoSize, sizeof(list[i].infoSize));
				list[i].info = new char[list[i].infoSize];
				file.read((char*)list[i].info, list[i].infoSize);
				listBytes += sizeof(list[i].infoID) + sizeof(list[i].infoSize) + list[i].infoSize;
			}
		}
		file.close();
	}
}

template <typename T>
void Wav<T>::writeFile(const std::string &outFileName) {
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wavHeader,sizeof(wavHeader));
    outFile.write((char*)buffer, wavHeader.dataChunkSize);
    if(hasListChunk) {
    	outFile.write((char*)&listHeader, sizeof(listHeader));
   		for(List r : list) {
    		outFile.write(r.infoID, sizeof(r.infoID));
    		outFile.write((char*)&r.infoSize,4);
    		outFile.write(r.info, r.infoSize);
    	}
    }
    outFile.close();
}

template <typename T>
bool Wav<T>::checkForList() {
	std::string header;
	for(char n : listHeader.LIST) {
		header += n;
	}
	if (header == "LIST") {
		hasListChunk = 1;
		return 1;
	} else {
		return 0;
	}
}

template <typename T>
int Wav<T>::getBufferSize () const {
	return wavHeader.dataChunkSize;
}

template <typename T>
T *Wav<T>::getBuffer() const {
	return buffer;
}

template <typename T>
WavHeader Wav<T>::getWavHeader() const {
	return wavHeader;
}


