#ifndef CODE_COMMAND_H
#define CODE_COMMAND_H
#include <string>

class Command{
std::string name;
std::string helpText;
public:
std::string getName();
std::string getHelpText();
void setName(std::string newName);
void setHelpText(std::string newHelpText);
Command(std::string name, std::string helpText);
};
#endif
