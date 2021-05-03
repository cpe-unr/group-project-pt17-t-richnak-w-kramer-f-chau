#include "Normalization.h"

/**
 * @brief This function finds the greatest signal and then multiples all the signals at the highest scale based on the max signal divided by the greatest signal in the buffer
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 byte audio file 
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
 * @brief This function finds the greatest signal and then multiples all the signals at the highest scale based on the max signal divided by the greatest signal in the buffer
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 byte audio file
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
