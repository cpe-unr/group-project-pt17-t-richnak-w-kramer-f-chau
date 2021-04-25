#ifndef MODIFY_H
#define MODIFY_H

#include <iostream>
#include <string>

using namespace; 

class Modify{
private:
	string title;
	string artist;
	string album;
	string genre;
	int release;
	int trackNum;
	string comments;

public:

	Modify();
	Modify(unsigned char* wavs,int index);
	Modify(unsigned char* wavs,int index);

	string getTitle();
	void setTitle(string);

	string getArtist();
	void setArtist(string);
	
	string getAlbum();
	void setAlbum(string);
	
	string getGenre();
	void setGenre(string);

	int getRelease();
	void setRelease();
	
	int getTrackNum();
	void setTrackNum(int);

	string getComments();
	void setComments(string);
	
	



}


#endif
