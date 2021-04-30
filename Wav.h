//
// Created by Tanner Richnak on 4/24/21.
//

#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H


#include "WavHeader.h"
#include "ListHeader.h"
#include "List.h"
#include "WavAbs.h"
#include <string>
#include <vector>

template <typename T>
class Wav : public WavAbs {
public:
	WavHeader wavHeader;
	ListHeader listHeader;
	bool hasListChunk = 0;
	std::vector<List> list;
	T* buffer = NULL;
public:
    void readFile(const std::string &filename) override;
    void writeFile(const std::string &outFileName);   
    
    bool checkForList();
    int getBufferSize() const;
    T *getBuffer() const;
    WavHeader getWavHeader() const;
    ListHeader getListHeader() const;
    
    
    virtual ~Wav<T>(){
		if(buffer != NULL) {
	   		delete[] buffer;
		}
	}
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
