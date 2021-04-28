#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include "Processor.h"

class Echo: public Processor{
	int delay;

public:
	Echo();
	Echo(int newDelay);
	int getDelay();
	void processBuffer(unsigned char* buffer, int bufferSize) override;
	void processBuffer(signed short* buffer, int bufferSize) override;
};

#endif
