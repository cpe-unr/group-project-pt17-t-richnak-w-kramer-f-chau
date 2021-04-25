#include "NoiseGate.h"

	NoiseGate::NoiseGate(){
		threshold = 100;
	}

	NoiseGate::NoiseGate(float newThreshold): threshold(newThreshold){
	}
	float NoiseGate::getThreshold(){
		return threshold;
	}

	void NoiseGate::processBuffer(unsigned char* location, int bufferSize){

//check what byte
if(sample rate/ byte depth = 8)
		for(int i = 0; i < bufferSize; i++){
			if(location[i] < NoiseGate::getThreshold()*127){
				location[i] = 128;
			}
			
			if(location[i] > ((NoiseGate::getThreshold()*127)+128)){
				location[i] = 128;
			}	
		}


if(sample rate/ byte depth = 16)
//16 typecast buffer to shorts

	for(int i = 0; i < bufferSize; i++){
			if(location[i] < NoiseGate::getThreshold()*127){
				location[i] = 128;
			}
			
			if(location[i] > 				((NoiseGate::getThreshold()*127)+128)){
				location[i] = 128;
			}	
		}


	}
