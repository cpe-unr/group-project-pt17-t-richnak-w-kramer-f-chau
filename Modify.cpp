#include "Modify.h"


void Modify::modifyMetadata(List* metadataObj, string newMetadataString){
	metadataObj->infoSize = newMetadataString.length();
	metadataObj->info = &newMetadataString[0];
}

//Either this function returns List or adds List to the specified vector
List addMetadataSection(std::vector<List> list, char newInfoID[4]){
	List *newList = new List; //Either this or add constructor to List.h to avoid using pointer
	newList->infoID = newInfoID;
}
	
	
