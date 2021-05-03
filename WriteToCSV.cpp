#include "WriteToCSV.h"


/**
 * @brief This function writes the technical information and metadata from the given file into a CSV file.
 * 
 * @param CSVfile_name 
 * @param fileNames 
 * @param wavFiles 
 * @return true 
 * @return false 
 */
bool WriteToCSV::writeDataToFile(std::string CSVfile_name, std::vector<std::string> fileNames, std::vector<Wav*> wavFiles){

    std::ofstream file;
    file.open(CSVfile_name);
    
    for(std::string fileName; fileNames){
        file << fileName << ",";
    }

    //technicalinformation (sample rates, etc.), and the file metadata. If no metadata exists, the phrase “Nometadata present” should be included in the description for that file.

    file << std::endl;

    for(std::wavFile: wavFiles){
        file << wavFile->listHeader.listChunkSize << ","; //size of chunk in bytes
    }
    file << std::endl;


    for(Wav* wavFile; wavFiles){ //file metadata

        for(List r: wavFile->list){ 
            file << r.infoID << ","; 
        }
        file << std::endl;

        for(List r: wavFile->list){
            file << r.infoSize << ",";
        }
        file << std::endl;

        for(List r: wavFile->list){
            file << r.info << ",";
        }
        file << std::endl;

    }


    file.close();


    

    return true;
}
