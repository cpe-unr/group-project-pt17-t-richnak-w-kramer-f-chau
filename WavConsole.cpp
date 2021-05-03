#include "WavConsole.h"
#include <iostream>
#include <vector>
#include <string>
#include <experimental/filesystem> 
#include "Command.h" 
#include "Processor.h"
#include "NoiseGate.h" 
#include "WavManager.h"
#include "Wav.h"
// #include "WriteToCSV.h" (add back to makefile when fixed) 

using namespace std; 

void WavConsole::printCommands(){ 
	for(Command c : commands){
	cout << c.getName() << ", ";
	}
cout << endl; 
}

vector<string> WavConsole::pullFilenames(string directory){
vector<string> output; 
std::experimental::filesystem::path p; //exceptions: inputted directory doesn't match a real one  
for(const auto &entry : std::experimental::filesystem::directory_iterator(directory)){
p = entry.path();
output.push_back(p);
cout << p.filename() << endl; //this line for testing, remove in final code 

 // to test: wm.populateVector() with full filepaths? return a vector of class Path and then cast it to string, maybe
}
return output;
}

void WavConsole::addCommand(string name, string helpText){
commands.emplace_back(name, helpText);
}


void WavConsole::runConsole(){
string directory;
cout << "Welcome to the PT17 Wav Manager." << endl;
cout << "Select a directory for the manager to manipulate by typing a full filepath. Please ensure all files in the directory are WAV files." << endl; //luxury todo: implement a way to check if the files are all WAVs, less luxury todo: exception handling for if they aren't.  

cin >> directory;
vector<string> filenames = pullFilenames(directory); 
wm.populateVector(filenames); 

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
cout << "Your input does not seem to match any of our commands. Please enter a valid command to receive additional information." << endl; //luxury todo: add something like this to the main while loop, or do a hideous elseif/else
}
}
}
if(input == "process"){
cout << "Processing WAV file. Please enter the filename of the WAV you would like processed." << endl; 
cin >> filename;
for(int i = 0; i < filenames.size(); i++){
if(directory + filename == filenames[i]) //todo: parse through filenames vector (figure out either a way to get relative paths consistently or apply the big bois), construct vector of Processors and then run the chosen file through them, Wav.writeFile() with user output. Exceptions: bad file to process (does not match), bad output filename (matches existing file)  
{

}

}
if(input == "editmetadata"){
cout << "Editing WAV file metadata. Please enter the filename of the WAV you would like to edit the metadata for." << endl;
cin >> filename;
//todo: map filename input to filename vector then to Wav vector; take field input, parse through list of infoIDs, parse through List vector, call Fiorina's class. Exceptions: bad file to edit (doesn't match), bad field name
}

if(input == "writecsv"){
cout << "Writing CSV file. Enter a filename to give the output file." << endl;
cin >> filename;
// wcsv.WriteDataToFile(filename, filenames, wm.wavs); //todo: figure out template stuff. exceptions?: given filename matches existing wav... for some reason
}

}
}
}




