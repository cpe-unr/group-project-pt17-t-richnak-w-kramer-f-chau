#ifndef MODIFY_H
#define MODIFY_H

#include <iostream>
#include <string>
#include "List.h"


using namespace std; 

class Modify{
public:

	/**
	 * @brief modifies data of specified list obj to user's input and updates the corresponding data length
	 * 
	 * @param metadataObj 
	 * @param newMetadataString 
	 */

	void modifyMetadata(List* metadataObj, string newMetadataString);

	List createMetadata(char newInfoID[4]);
}


#endif
