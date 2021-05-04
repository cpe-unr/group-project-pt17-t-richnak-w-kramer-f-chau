#include "Normalization.h"

/**
 * @brief This function finds the greatest signal and then multiples all the signals at the highest scale based on the max signal divided by the greatest signal in the buffer
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 bit audio file 
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
 * @brief For each of the right and left signals in the buffer of the stereo audio file, this function finds the greatest signal and then multiples all the signals at the highest scale based on the max signal divided by the greatest signal in the buffer
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 bit stereo audio file 
 * @param bufferSize 
 */
void Normalization::processStereoBuffer(unsigned char* buffer, int bufferSize){
    //Left
    int greatestSignal = 0;
    for(int i = 0; i < bufferSize; i+=2){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    float amplitudeScale = 128.0/buffer[greatestSignal];
    for(int i = 0; i < bufferSize; i+=2){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }

    //Right
    greatestSignal = 0;
    for(int i = 1; i < bufferSize; i+=2){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    amplitudeScale = 128.0/buffer[greatestSignal];
    for(int i = 1; i < bufferSize; i+=2){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }
}

/**
 * @brief This function finds the greatest signal and then multiples all the signals at the highest scale based on the max signal divided by the greatest signal in the buffer
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 bit mono audio file
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

/**
 * @brief For each of the right and left signals in the buffer of the stereo audio file, this function finds the greatest signal and then multiples all the signals at the highest scale based on the max signal divided by the greatest signal in the buffer
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 bit stereo audio file
 * @param bufferSize 
 */
void Normalization::processStereoBuffer(signed short* buffer, int bufferSize){
    //Left
    int greatestSignal = 0;
    for(int i = 0; i < bufferSize; i+=2){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    float amplitudeScale = 32768.0/buffer[greatestSignal];
    for(int i = 0; i < bufferSize; i+=2){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }

    //Right
    greatestSignal = 0;
    for(int i = 1; i < bufferSize; i+=2){
        if (buffer[greatestSignal] < buffer[i]){
                greatestSignal = i;
        }
    }
    amplitudeScale = 32768.0/buffer[greatestSignal];
    for(int i = 1; i < bufferSize; i+=2){
        buffer[i] = buffer[i] * round(amplitudeScale);
    }

}
