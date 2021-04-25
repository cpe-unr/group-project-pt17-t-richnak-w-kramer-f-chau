#include "Echo.h"

	Echo::Echo(){
		delay = 0;
	}

	Echo::Echo(int newDelay): delay(newDelay){
	}
//check if its 8 or 16
	void Echo::processBuffer(unsigned char* location, int bufferSize){

		for(int i; i < bufferSize; i++){
			location[i] = (location[i] + location[i - delay])*.5;
		}
	}
