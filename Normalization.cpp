#include "Normalization.h"

/**
 * @brief
 * 
 * @param buffer 
 * @param bufferSize 
 */
void Normalization::processBuffer(unsigned char* buffer, int bufferSize){
    int greatestSignal = 0;
    for(int i = 0; i < bufferSize; i++){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    float amplitudeScale = 128.0/buffer[greatestSignal];
    for(int i = 0; i < bufferSize; i++){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 */
void Normalization::processBuffer(signed short* buffer, int bufferSize){
    int greatestSignal = 0;
    for(int i = 0; i < bufferSize; i++){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    float amplitudeScale = 32768.0/buffer[greatestSignal];
    for(int i = 0; i < bufferSize; i++){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }
}
