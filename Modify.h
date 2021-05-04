#ifndef MODIFY_H
#define MODIFY_H

#include <iostream>
#include <string>
#include "List.h"
#include <vector>



class Modify{
public:

	List* modifyMetadata(List* metadataObj, std::string newMetadataString);

	void addMetadataSection(std::vector<List> list, char newInfoID[4], std::string newInfo);
};


#endif
