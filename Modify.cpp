#include "Modify.h"

/**
 * @brief This function modifies data of specified list object to user's input and updates the corresponding data length
 * 
 * @param metadataObj object that will be modified
 * @param newMetadataString User Input
 */
List* Modify::modifyMetadata(List* metadataObj, std::string newMetadataString){
	metadataObj->infoSize = newMetadataString.length();
	metadataObj->info = &newMetadataString[0];
	return metadataObj;
}

//Either this function returns List or adds List to the specified vector
/**
 * @brief This function creates new metadata 
 * 
 * @param list 
 * @param newInfoID 
 * @param newInfo 
 */
/* void Modify::addMetadataSection(std::vector<List> list, char newInfoID[4], std::string newInfo){
	
	list.push_back(List());
	int i = list.size() - 1;
	list[i].infoID = newInfoID;
	list[i].infoSize = newInfo.length();
	list[i].info = &newInfo[0];
	
} */ 
	
	
