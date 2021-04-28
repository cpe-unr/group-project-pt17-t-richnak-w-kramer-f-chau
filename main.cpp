/** @file */
#include <iostream>
#include <vector>
#include <fstream>
#include "Wav.h"
#include "WavManager.h"
#include "Processor.h"
#include "Echo.h"
#include "Normalization.h"

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
const std::string _8bitM = "yes-8bit-mono.wav";
const std::string _8bitS = "yes-8-bit-stereo.wav";
const std::string _16bitM = "yes-16-bit-mono.wav";
const std::string _16bitS = "yes-26-bit-stereo.wav";
 
void fn(){

}

int main() {
	WavManager n;
	std::vector<std::string> filenames;
	filenames.push_back(_16bitM);
	n.populateVector(filenames);
	
	for (WavAbs *wav: n.wavs) {
		if(auto * a = dynamic_cast<Wav<short>*>(wav)) {
			std::cout << a->wavHeader.chunkSize << std::endl;
			std::cout << a->wavHeader.dataChunkSize << std::endl;
			std::cout << a->wavHeader.chunkSize - a->wavHeader.dataChunkSize << std::endl;
	
			std::cout << a->list.size() << std::endl;

			std::cout << a->listHeader.LIST << std::endl;
			std::cout << a->listHeader.listChunkSize << std::endl;
			std::cout << a->listHeader.typeID << std::endl;
			for(List r : a->list) {
				std::cout << r.infoID <<std::endl;
				std::cout << r.infoSize <<std::endl;
				std::cout << r.info <<std::endl;
			}
			a->writeFile("something.wav");
		}
	}
	
	/*for (Wav *wav: n.wavs) {		
  		if(auto * a = dynamic_cast<_8Bit*>(wav)) {
			a->writeFile("something.wav");
		} else if(auto * a = dynamic_cast<_16Bit*>(wav)){
			a->writeFile("something.wav");
   		}
<<<<<<< HEAD
	}
		
=======
	}*/
	
>>>>>>> d8f4f749c8d4d8fdc57aaa0e30a05aaec89ef4e5
    return 0;
}
