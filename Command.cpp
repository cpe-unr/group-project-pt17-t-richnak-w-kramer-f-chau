#include "Command.h"
#include <string>

Command::Command(std::string name, std::string helpText) : name(name), helpText(helpText) {}

std::string Command::getHelpText(){
return helpText;
}
std::string Command::getName(){
return name; 
}
void Command::setName(std::string newName){
name = newName;
}
void Command::setHelpText(std::string newHelpText){
helpText = newHelpText;
}



