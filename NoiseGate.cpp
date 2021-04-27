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

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] < NoiseGate::getThreshold()*127){
			buffer[i] = 128;
		}
		
		if(buffer[i] > ((NoiseGate::getThreshold()*127)+128)){
			buffer[i] = 128;
		}	
	}
}

void NoiseGate::processBuffer(signed short* buffer, int bufferSize){
	for(int i = 0; i < bufferSize; i++){
			if(buffer[i] < NoiseGate::getThreshold()*127){
				buffer[i] = 32767;
			}
			
			if(buffer[i] > ((NoiseGate::getThreshold()*127)+128)){
				buffer[i] = 32767;
			}	
		}


	}
}
