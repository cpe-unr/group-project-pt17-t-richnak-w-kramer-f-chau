#include "Echo.h"

Echo::Echo(){
	delay = 0;
}

Echo::Echo(int newDelay): delay(newDelay){
}

int Echo::getDelay(){
	return delay;
}

void Echo::processBuffer(unsigned char* buffer, int bufferSize){

	int delay = Echo::getDelay();
	float ogSignal;
	float delayedSignal;
	float val;
	for(int i=0; i < bufferSize - delay; i++){
		ogSignal = (float)(buffer[i] - 128);
		delayedSignal = (float)(buffer[i+delay] - 128);
		val = ogSignal * .5 + delayedSignal * .5 + 128;
		buffer[i+delay] = (unsigned char)(round(val));
	}
}


void Echo::processBuffer(signed short* buffer, int bufferSize){

	int delay = Echo::getDelay();
	float ogSignal;
	float delayedSignal;
	float val;
	for(int i=0; i < bufferSize - delay; i++){
		ogSignal = (float)(buffer[i]);
		delayedSignal = (float)(buffer[i+delay]);
		val = ogSignal * .5 + delayedSignal * .5;
		buffer[i+delay] = (unsigned char)(round(val));
	}
}
