#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include "Processor.h"

class Echo: public Processor{
	int delay;

public:
	Echo();
	Echo(int newDelay);
	void processBuffer(unsigned char* location, int bufferSize) override;

};

#endif
