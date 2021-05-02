/** @file */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Wav.h"
#include "WavManager.h"
#include "WavConsole.h"
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

int main() { //if you're testing anything else, either comment my stuff out or add your stuff before mine - but don't delete this outright   
WavConsole wc;
wc.addCommand("writecsv", "Writes a CSV file containing the names and all of the metadata of each file, with the filename you input. Input 1: Name of the created CSV file. \n"); 
wc.addCommand("editmetadata", "Allows you to manipulate the metadata (artist name, song title, etc.) of files in your directory. Input 1: Filename you want to edit. Input 2: What field of the metadata (e.g. artist or song) you want to modify. Input 3: The new value of that field after modification. \n"); 
wc.addCommand("process", "Processes a WAV file of your choice with any of three audio processors: normalization, noise-gating, or echo. Input 1: Filename of the WAV you wish to modify. Input 2: The list of processors you want to apply, followed by \"done\". Input 3 (optional): The name of the file you want to write the processed audio to. Note that you cannot output the name of any existing file. \n");
wc.addCommand("help", "Provides additional information on a command of your choice. But you already knew that, didn't you. Input 1: Command to seek additional information on. \n"); 
wc.runConsole();

/*	WavManager n;
	std::vector<std::string> filenames;
	filenames.push_back(_8bitM);
	filenames.push_back(_8bitS);
	filenames.push_back(_16bitM);
	filenames.push_back(_16bitS);
	
	n.populateVector(filenames);
	
	for (IReadable *wav: n.wavs) {
		if(auto * a = dynamic_cast<Wav<short>*>(wav)) {
			a->writeFile("something.wav");
			
			//Parse through char[4] variables
			/*std::string x;
			for(char n : a->list[0].infoID) {
				x += n;
			}
			std::cout << x << std::endl;*/
			
			/* std::cout << a->inFile << std::endl;
			
			std::cout << a->wavHeader.bitDepth << std::endl;
			std::cout << a->listHeader.LIST << std::endl;
			std::cout << a->listHeader.listChunkSize << std::endl;
			std::cout << a->listHeader.typeID << std::endl;
			for(List r : a->list) {
				std::cout << r.infoID << std::endl;
				std::cout << r.infoSize << std::endl;
				std::cout << r.info << std::endl;
			}
			std::cout << "======================" << std::endl;
		} else if(auto * a = dynamic_cast<Wav<unsigned char>*>(wav)) {
			a->writeFile("something.wav");	
			
			
			std::cout << a->inFile << std::endl;
			
			std::cout << a->wavHeader.bitDepth << std::endl;
			std::cout << a->listHeader.LIST << std::endl;
			std::cout << a->listHeader.listChunkSize << std::endl;
			std::cout << a->listHeader.typeID << std::endl;
			for(List r : a->list) {
				std::cout << r.infoID << std::endl;
				std::cout << r.infoSize << std::endl;
				std::cout << r.info << std::endl;
			}
			std::cout << "======================" << std::endl;
		}
	}
*/
    return 0;
}
