#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include "Processor.h"

class Normalization: public Processor{

	void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBuffer(signed short* buffer, int bufferSize) override;
    void processStereoBuffer(unsigned char* buffer, int bufferSize) override;
    void processStereoBuffer(signed short* buffer, int bufferSize) override;
};

#endif
