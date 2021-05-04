#include "Echo.h"

Echo::Echo(){
	delay = 0;
}

Echo::Echo(int newDelay): delay(newDelay){
}

/**
 * @brief This function creates delayed signals, each one with less amplitude than the one before.
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 bit mono audio file 
 * @param bufferSize 
 */
void Echo::processBuffer(unsigned char* buffer, int bufferSize){

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

/**
 * @brief For each of the left and right signals of the buffer of the stereo audio file, this function creates delayed signals, each one with less amplitude than the one before.
 * 
 * @param buffer unsigned char* buffer of the audio signals for 8 bit stereo audio file 
 * @param bufferSize 
 */

void Echo::processStereoBuffer(unsigned char* buffer, int bufferSize){

	float ogSignal;
	float delayedSignal;
	float val;

	//Left
	for(int i=0; i < bufferSize - delay; i+=2){
		ogSignal = (float)(buffer[i] - 128);
		delayedSignal = (float)(buffer[i+delay] - 128);
		val = ogSignal * .5 + delayedSignal * .5 + 128;
		buffer[i+delay] = (unsigned char)(round(val));
	}

	//Right
	for(int i=1; i < bufferSize - delay; i+=2){
		ogSignal = (float)(buffer[i] - 128);
		delayedSignal = (float)(buffer[i+delay] - 128);
		val = ogSignal * .5 + delayedSignal * .5 + 128;
		buffer[i+delay] = (unsigned char)(round(val));
	}
}

/**
 * @brief This function creates delayed signals, each one with less amplitude than the one before.
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 bit mono audio file
 * @param bufferSize 
 */
void Echo::processBuffer(signed short* buffer, int bufferSize){

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

/**
 * @brief For each of the left and right signals of the buffer of the stereo audio file, this function creates delayed signals, each one with less amplitude than the one before.
 * 
 * @param buffer signed short* buffer of the audio signals for a 16 bit stereo audio file 
 * @param bufferSize 
 */
void Echo::processStereoBuffer(signed short* buffer, int bufferSize){

	float ogSignal;
	float delayedSignal;
	float val;

	//Left
	for(int i=0; i < bufferSize - delay; i+=2){
		ogSignal = (float)(buffer[i]);
		delayedSignal = (float)(buffer[i+delay]);
		val = ogSignal * .5 + delayedSignal * .5;
		buffer[i+delay] = (unsigned char)(round(val));
	}

	//Right
	for(int i=1; i < bufferSize - delay; i+=2){
		ogSignal = (float)(buffer[i]);
		delayedSignal = (float)(buffer[i+delay]);
		val = ogSignal * .5 + delayedSignal * .5;
		buffer[i+delay] = (unsigned char)(round(val));
	}
}
