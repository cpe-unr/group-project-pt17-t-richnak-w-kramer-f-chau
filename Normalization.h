#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "Normalization.h"

class Normalization(): public Processor{

	void processBuffer(unsigned char* buffer, int bufferSize) override;
}

//find max and min loop through for loop
//oldest dog function PA2

#endif
