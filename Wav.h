//
// Created by Keith Lancaster on 3/13/21.
//

#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H

/*
 * This class is designed to work with PCM 8-bit mono wavefiles.
 * It makes many assumptions about the format of the wave as a result.
 * It will NOT work with stereo files or any other bit-depth than 8 bits.
 */
#include "WavHeader.h"
#include "ListHeader.h"
#include "List.h"
#include <string>
#include <vector>

class Wav {
public:
	WavHeader wavHeader;
	ListHeader listHeader;
	bool hasListChunk = 0;
	std::vector<List> list;

    virtual void readFile(const std::string &filename) = 0;
    virtual void writeFile(const std::string &outFileName) = 0;   
    
    virtual bool checkForList() = 0;
    virtual int getBufferSize() const = 0;
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
