#ifndef _8BIT_H
#define _8BIT_H

#include "Wav.h"
#include <vector>

class _8Bit : public Wav {
public:
    void readFile(const std::string &filename) override;
    void writeFile(const std::string &outFileName) override;   
 	int getBufferSize() const override;
 	bool checkForList() override;
 	
 	virtual ~_8Bit();
public:
	unsigned char* buffer = NULL;
};

#endif
