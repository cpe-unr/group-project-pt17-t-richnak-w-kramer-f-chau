#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include "Processor.h"

class Echo: public Processor{
	int delay;

public:
	Echo();
	Echo(int newDelay);
	void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBuffer(signed short* buffer, int bufferSize) override;
    void processStereoBuffer(unsigned char* buffer, int bufferSize) override;
    void processStereoBuffer(signed short* buffer, int bufferSize) override;
};

#endif
