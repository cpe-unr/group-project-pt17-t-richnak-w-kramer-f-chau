#ifndef LIBPROCESSORS_H
#define LIBPROCESSORS_H

#include "Processor.h"
#include "Normalization.h"
#include "Echo.h"
#include "NoiseGate.h"

class libprocessor{


public:

virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;

virtual void processBuffer(signed short* buffer, int bufferSize) = 0;

virtual void processStereoBuffer(unsigned char* buffer, int bufferSize) = 0;

virtual void processStereoBuffer(signed short* buffer, int bufferSize) = 0;

};

#endif