#include "NoiseGate.h"

NoiseGate::NoiseGate(){
	threshold = 100;
}

NoiseGate::NoiseGate(float newThreshold): threshold((newThreshold*128)/100){
}


void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){

	float min = 128 - threshold;
	float max = 128 + threshold;

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 128;
		}	
	}
}

void NoiseGate::processBuffer(signed short* buffer, int bufferSize){

	short min = (short)(0 - threshold);
	short max = (short)(threshold);

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 0;
		}
	}
}
