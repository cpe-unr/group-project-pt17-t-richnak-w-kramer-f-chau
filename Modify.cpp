#include "Modify.h"

	Modify();
	Modify(unsigned char* wavs,int index);
	Modify(unsigned char* wavs,int index);

	string getTitle();
	void setTitle(string newTitle){
		wavManager.wavs[i] -> list[n].listChunckAttribute = newTitle;
	}

	string getArtist();
	void setArtist(string newArtist){
		wavManager.wavs[i] -> list[n].listChunckAttribute = newArtist;
	}
	
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
