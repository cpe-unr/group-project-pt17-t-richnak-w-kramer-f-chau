#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "Processor.h"

class NoiseGate: public Processor{

	float threshold;

public:
	NoiseGate();
	NoiseGate(float newThreshold);
	float getThreshold();
	void processBuffer(unsigned char* location, int bufferSize) override;
	void processBuffer(signed short* buffer, int bufferSize) override;
};

#endif
