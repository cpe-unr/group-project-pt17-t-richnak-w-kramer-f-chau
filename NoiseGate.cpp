#include "NoiseGate.h"

NoiseGate::NoiseGate(){
	threshold = 100;
}

NoiseGate::NoiseGate(float newThreshold): threshold(newThreshold){
}

float NoiseGate::getThreshold(){
	return threshold;
}

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){

	int min = 128 - NoiseGate::getThreshold();
	int max = 128 + NoiseGate::getThreshold();

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 128;
		}	
	}
}

void NoiseGate::processBuffer(signed short* buffer, int bufferSize){

	int min = 0 - NoiseGate::getThreshold();
	int max = NoiseGate::getThreshold();

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > min && buffer[i] < max){
			buffer[i] = 0;
		}
	}
}
