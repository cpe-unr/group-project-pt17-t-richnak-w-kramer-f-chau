#include "Modify.h"

/**
 * @brief This function modifies data of specified list object to user's input and updates the corresponding data length
 * 
 * @param metadataObj object that will be modified
 * @param newMetadataString User Input
 */
void Modify::modifyMetadata(List* metadataObj, string newMetadataString){
	metadataObj->infoSize = newMetadataString.length();
	metadataObj->info = &newMetadataString[0];
}

//Either this function returns List or adds List to the specified vector
/**
 * @brief This function creates new metadata 
 * 
 * @param list 
 * @param newInfoID 
 * @param newInfo 
 */
void addMetadataSection(std::vector<List> list, char newInfoID[4], std::string newInfo){
	List *newList = new List; //Either this or add constructor to List.h to avoid using pointer
	list.push_back(newList);
	newList->infoID = newInfoID;
	newList->infoSize = newInfo.length();
	newList->info = &newInfo[0];
	
}
	
	
