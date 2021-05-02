#include "WriteToCSV.h"



bool WriteToCSV::writeDataToFile(std::string CSVfile_name, std::vector<std::string> fileNames, std::vector<Wav*> wavFiles){

    std::ofstream file;
    file.open(CSVfile_name);
    
    for(std::string fileName; fileNames){
        file << fileName << ",";
    }

    //technicalinformation (sample rates, etc.), and the file metadata. If no metadata exists, the phrase “Nometadata present” should be included in the description for that file.

    file << std::endl;

    for(std::wavFile : wavFiles){
        file << wavFile->listHeader.listChunkSize << ","; //size of chunk in bytes
    }
    file << std::endl


    for(std::wavFile; wavFiles){ //file metadata

        for(List r: wavFile->list){ 
            file << r.infoID << ","; 
        }
        file << std::endl

        for(List r: wavFile->list){
            file << r.infoSize << ",";
        }
        file << std::endl

        for(List r: wavFile->list){
            file << r.info << ",";
        }
        file << std::endl

    }


    file.close();


    

    return true;
}
