#include "Normalization.h"


<<<<<<< HEAD
=======
/*void Normalization::processBuffer(T* buffer, int bufferSize, MAX){
    int greatestSignal = 0;
    for(int i = 0; i < bufferSize; i++){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    float amplitudeScale = MAX/buffer[greatestSignal];
    for(int i = 0; i < bufferSize; i++){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }
}*/

>>>>>>> b0465c33b1e4f426470eb695c1e3c59d887f7be2
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
