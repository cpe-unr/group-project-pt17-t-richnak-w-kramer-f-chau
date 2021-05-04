#ifndef PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H
#define PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H


#include <cstdint>
#include <cmath>

class Processor {
public:

    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
    virtual void processBuffer(signed short* buffer, int bufferSize) = 0;
    virtual void processStereoBuffer(unsigned char* buffer, int bufferSize) = 0;
    virtual void processStereoBuffer(signed short* buffer, int bufferSize) = 0;
};

#endif
