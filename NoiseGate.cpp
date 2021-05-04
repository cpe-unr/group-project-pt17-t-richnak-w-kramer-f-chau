#include "NoiseGate.h"

NoiseGate::NoiseGate(){
	threshold = 100;
}

NoiseGate::NoiseGate(float newThreshold): threshold((newThreshold*128)/100){
}

/**
 * @brief This function sets any signals that fall within the threshold area to 0
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 bit mono audio file   
 * @param bufferSize 
 */
void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){

	float min = 128 - threshold;
	float max = 128 + threshold;

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 128;
		}	
	}
}

/**
 * @brief For each of the left and right signals of the buffer in the stereo file, this function sets any signals that fall within the threshold area to 0. 
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 bit stereo audio file    
 * @param bufferSize 
 */

void NoiseGate::processStereoBuffer(unsigned char* buffer, int bufferSize){

	float min = 128 - threshold;
	float max = 128 + threshold;

	//Left
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 128;
		}	
	}

	//Right
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 128;
		}	
	}
}

/**
 * @brief This function sets any signals that fall within the threshold area to 0
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 bit mono audio file 
 * @param bufferSize 
 */
void NoiseGate::processBuffer(signed short* buffer, int bufferSize){

	short min = (short)(0 - threshold);
	short max = (short)(threshold);

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 0;
		}
	}
}

/**
 * @brief For each of the left and right signals of the buffer in the stereo audio file, this function sets any signals that fall within the threshold area to 0. 
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 bit stereo audio file 
 * @param bufferSize 
 */
void NoiseGate::processStereoBuffer(signed short* buffer, int bufferSize){

	short min = (short)(0 - threshold);
	short max = (short)(threshold);

	//Left
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 0;
		}
	}

	//Right
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 0;
		}
	}
}
