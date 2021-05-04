#include "WavConsole.h"
#include <iostream>
#include <vector>
#include <string>
#include <experimental/filesystem> 
#include "Command.h" 
#include "Processor.h"
#include "NoiseGate.h" 
#include "Normalization.h"
#include "Echo.h" 
#include "Modify.h" 
#include "IReadable.h"
#include "WavManager.h"
#include "Wav.h"
#include "WriteToCSV.h"  

using namespace std; 
/**
 * @brief This function prints the name of each valid console command to show the user what options are available.
 * 
 */
void WavConsole::printCommands(){ 
	for(Command c : commands){
	cout << c.getName() << ", ";
	}
cout << endl; 
}

/**
 * @brief This function uses a directory_iterator to get the names of every file in the user-inputted directory.
 * 
 * @param directory User-inputted path to the directory of WAVs to manipulate. 
 * 
 */
vector<std::experimental::filesystem::path> WavConsole::pullFilenames(string directory){

vector<std::experimental::filesystem::path> output; 
	std::experimental::filesystem::path p; //exceptions: inputted directory 	doesn't match a real one  
for(const auto &entry : 	  std::experimental::filesystem::directory_iterator(directory)){

p = entry.path();

		if(p.filename().string().at(0) != '.'){
		output.push_back(p);
		}

}
return output;
}

/**
 * @brief This function pushes a new command to the vector of commands
 * 
 * @param name Name of the chat command. 
 * @param helpText Text to display when additional info is requested on the command. 
 */
void WavConsole::addCommand(string name, string helpText){
commands.emplace_back(name, helpText);
}

/**
 * @brief This function is the main interface with the user. It guides the user through the use of the WAV managment and processing system and calls classes to process, edit, read, and write as required.
 *
 */
void WavConsole::runConsole(){

string METADATA_CODES[22] = {"IARL", "IART", "ICMS", "ICMT", "ICOP", "ICRD", "ICRP", "IDIM", "IDPI", "IENG", "IGNR", "IKEY", "ILGT", "IMED", "INAM", "IPLT", "IPRD", "ISBJ", "ISFT", "ISRC", "ISRF", "ITCH"}; 

string METADATA_DESC[22] = {"Archive location", "Artist", "Commissioner of the work", "General comments", "Copyright information", "Creation date", "Cropping", "Dimensions", "Dots Per Inch", "Engineer", "Genre", "Keywords", "Lightness", "Medium", "Name", "Color Palette", "Intended title", "Subject", "Software used in creation", "Source", "Source form", "Technician"}; 

string directory;

cout << "Welcome to the PT17 Wav Manager." << endl;
cout << "Select a directory for the manager to manipulate by typing a full filepath. Please ensure all files in the directory are WAV files." << endl; 

cin >> directory;
vector<std::experimental::filesystem::path> filenames = pullFilenames(directory); 
vector<string> filenamesstr;
	
	for(int i = 0; i < filenames.size(); i++){
	filenamesstr.push_back(filenames[i].string());
	}

wm.populateVector(filenamesstr); 

cout << "Enter a command from the list (case-sensitive!) below to get started, \"quit\" to exit the manager, or \"help\" to get more info on a command." << endl; 

string input;
string helpQuery;
string filename;
string fieldname; 
bool isQuit = false; 
 
	while(isQuit == false){

	cout << "To continue, enter one or more of the commands from this list, or enter \"quit\" to exit." << endl;

	printCommands();

	cin >> input;

	if(input == "quit"){
		isQuit = true;
		cout << "Exiting PT17 Wav Manager." << endl; 
	}

	if(input == "help"){
		cout << "Select a command to get help on." << endl; 
		bool wasHelped  =  false;
	while(!wasHelped){
		cin >> helpQuery;
		for(Command c : commands){
			if(helpQuery == c.getName()){
				cout << c.getHelpText();
				wasHelped = true; 
				}
			}

		if(!wasHelped){
			cout << "Your input does not seem to match any of our commands. Please enter a valid command to receive additional information." << endl; 
			}
		}
	}
	if(input == "process"){
		cout << "Processing WAV file. Please enter the filename of the WAV you would like processed." << endl; 
		cin >> filename;
		bool matches = false;
		int processorAddI;
		int wavsIndex;
		vector<Processor*> processorAdds; 
		for(int i = 0; i < filenames.size(); i++){
			if(filename == filenames[i].filename()){
				matches = true;
				wavsIndex = i;
			}//endif
		}//end for 
		if(!matches){
		cout << "The inputted filename does not match any files in the 	directory. Please try again." << endl; 
		}//endif

		else{
			cout << "Processing file " << filenames[wavsIndex].filename() << " . Next, input numbers that correspond to the processors you wish to apply to this file: 1 for normalization, 2 for noise-gating, 3 for echo. Input 0 when done." << endl;
			bool processorAdding = true;
			int processorParam; 

			while(processorAdding){
				cin >> processorAddI; 
				switch(processorAddI){
					case 1:{
						Normalization* nm = new Normalization();
						processorAdds.push_back(nm);
						break;
					}
					case 2:{
						cout << "Adding noise-gating. Please enter the percent 	threshold under which noise should be removed." << endl; 
						cin >> processorParam; 
						NoiseGate* ng = new NoiseGate(processorParam);
						processorAdds.push_back(ng);
						break;
					}
					case 3:{
						cout << "Adding echo. Please enter the delay (in terms of samples; 44000 samples roughly corresponds to one second) to echo after." << endl;
						cin >> processorParam;
						Echo* ec = new Echo(processorParam);
						processorAdds.push_back(ec);
						break;
					}
					case 0:{
						processorAdding = false;
						cout << "Ending input." << endl; 
						break;
					}

				}//endswitch 
			}//end while

			IReadable* tomodify = wm.wavs[wavsIndex]; 
			 
      	    if(auto * wFile = dynamic_cast<Wav<short>*>(tomodify)) {
            	for(Processor * p: processorAdds){
					cout << "Processing buffer" << endl;
					if(wFile->wavHeader.numChannels == 1){
					p -> processBuffer(wFile->buffer, wFile->getBufferSize());
						}
					if(wFile->wavHeader.numChannels == 2){
					p -> processStereoBuffer(wFile->buffer, wFile->getBufferSize());
					}				
					} 
				cout << "Processing complete. To output a file with the results, enter the filename to write the output to (please ensure your output file does not match any existing input files). If you don't want to output, type 'done'." << endl;

				string outputFile;
				matches = false; 
				cin >> outputFile;

			if(outputFile != "done"){
				cout << "Preparing to output file." << endl; 
				for(string f : filenamesstr){
					if(outputFile == f){ cout << "Your output file name matches an already existing one and is thus invalid." << endl; matches = true;}
					}//endfor
				if(!matches){
					cout << "Writing output file." << endl; 
					wFile->writeFile(outputFile);
				}//endif(matches)
			}//endif(outputfile)
			
         }//endif (wFile)
        	if(auto * wFile = dynamic_cast<Wav<unsigned char>*>(tomodify))  {
	    		for(Processor* p: processorAdds){
					cout << "Processing buffer" << endl; 
					if(wFile->wavHeader.numChannels == 1){
					p -> processBuffer(wFile->buffer, wFile->getBufferSize());
						}
					if(wFile->wavHeader.numChannels == 2){
					p -> processStereoBuffer(wFile->buffer, wFile->getBufferSize());
					}	
				}          
				cout << "Processing complete. To output a file with the results, enter the filename to write the output to (please ensure your output file does not match any existing input files). If you don't want to output, type 'done'." << endl;
				
				string outputFile;
				matches = false; 
				cin >> outputFile;

			if(outputFile != "done"){
				cout << "Preparing to output file." << endl; 
				for(string f : filenamesstr){
					if(outputFile == f){ cout << "Your output file name matches an already existing one and is thus invalid." << endl; matches = true;}
				}//endfor
				if(!matches){
					cout << "Writing output file." << endl; 
					wFile->writeFile(outputFile);
				}//endif(matches)
			}//endif(outputfile)
		}//endif(wFile)
	}//end else     
}//endif (process) 

	if(input == "editmetadata"){
		bool matches = false; 
		Modify* mod = new Modify();
		cout << "Editing WAV file metadata. Please enter the filename of the WAV you would like to edit the metadata for." << endl;
		cin >> filename;
		int wavsIndex;
		int chosen; 
		for(int i = 0; i < filenames.size(); i++){
			if(filename == filenames[i].filename()){
				matches = true;
				wavsIndex = i;
			}//endif
		}//end for 

		if(!matches){
			cout << "The inputted filename does not match any files in the directory. Please try again." << endl; 
		}//endif
		else{
			cout << "Editing metadata for file " << filename << " ." << endl; 
			cout << "Please enter the number corresponding to the metadata field you would like to edit or create. Available metadata fields are as follows:" << endl; 
			for(int i = 0; i < 22; i++){
				cout << i+1 << ": " << METADATA_DESC[i] << endl; 
			} 
			cin >> chosen; 
			cout << "Please enter the new value you want the chosen field to take. Ensure that no non-alphanumeric characters (including spaces) are in your new value." << endl; 
			cin >> fieldname; 
			char infoidnew[4];
			
			for(int i = 0; i < 4; i++){
				infoidnew[i] = METADATA_CODES[chosen-1].at(i);
			}

			IReadable* tomodify = wm.wavs[wavsIndex]; 
			cout << "Wav index selected" << endl; 

       		if(auto * wFile = dynamic_cast<Wav<short>*>(tomodify)) {

				bool hasMetadata = false;
				int i = 0;
				for(List l : wFile->list){
					
					char linfoid[4] = {l.infoID[0], l.infoID[1], l.infoID[2], l.infoID[3]}; 
					cout << linfoid << endl;
					if(linfoid == METADATA_CODES[chosen-1] && !hasMetadata){
						hasMetadata = true;
						cout << "To modify metadata." << endl;
						wFile->list.erase(wFile->list.begin()+i); 
						List* ltemp = mod->modifyMetadata(&l, fieldname);
						l = *ltemp;
						cout << l.info << endl; 
						wFile->list.push_back(l);
						wFile->writeFile(filename);
						}
						i++; 	
					} //addMetadataSection currently nonfunctional
		// if(!hasMetadata){mod->addMetadataSection(wFile->list, infoidnew, fieldname);}
		
			
		}
				
			if(auto * wFile = dynamic_cast<Wav<unsigned char>*>(tomodify))  {
				bool hasMetadata = false;
				int i = 0;
				for(List l : wFile->list){
					
					char linfoid[4] = {l.infoID[0], l.infoID[1], l.infoID[2], l.infoID[3]}; 
					cout << linfoid << endl;
					if(linfoid == METADATA_CODES[chosen-1] && !hasMetadata){
						hasMetadata = true;
						cout << "Modifying metadata." << endl;
						wFile->list.erase(wFile->list.begin()+i); 
						List* ltemp = mod->modifyMetadata(&l, fieldname);
						l = *ltemp;
						cout << l.info << endl; 
						wFile->list.push_back(l);
						wFile->writeFile(filename);
						}
						i++; 	
					} //addMetadataSection currently nonfunctional
		// if(!hasMetadata){mod->addMetadataSection(wFile->list, infoidnew, fieldname);}
		
			
		}

	}
}

	if(input == "writecsv"){
		cout << "Writing CSV file. Enter a filename to give the output file." << endl;
		cin >> filename;
		wcsv.writeDataToFile(filename, filenamesstr, wm.wavs); 
	}
} //end while

}//end runconsole






