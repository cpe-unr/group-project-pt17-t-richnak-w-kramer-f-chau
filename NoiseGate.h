#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "Processor.h"

class NoiseGate: public Processor{

	int threshold;

public:
	NoiseGate();
	NoiseGate(float newThreshold);
	void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBuffer(signed short* buffer, int bufferSize) override;
    void processStereoBuffer(unsigned char* buffer, int bufferSize) override;
    void processStereoBuffer(signed short* buffer, int bufferSize) override;
};

#endif
