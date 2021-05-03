#ifndef MODIFY_H
#define MODIFY_H

#include <iostream>
#include <string>
#include "List.h"
#include <vector>


using namespace std; 

class Modify{
public:

	void modifyMetadata(List* metadataObj, string newMetadataString);

	void createMetadata(char newInfoID[4]);
}


#endif
