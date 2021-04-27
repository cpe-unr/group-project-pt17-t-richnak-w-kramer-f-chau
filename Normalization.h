#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include <cmath>
#include "Processor.h"

class Normalization: public Processor{

	void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBuffer(signed short* buffer, int bufferSize) override;
}

//find max and min loop through for loop


#endif
