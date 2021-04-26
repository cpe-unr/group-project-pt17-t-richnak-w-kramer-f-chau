#ifndef _16BIT_H
#define _16BIT_H

#include "Wav.h"
#include <vector>

class _16Bit : public Wav {
public:
    void readFile(const std::string &filename) override;
    void writeFile(const std::string &outFileName) override;   
 	int getBufferSize() const override;
 	bool checkForList() override;
 	
 	virtual ~_16Bit();
public:
	unsigned short* buffer = NULL;
};

#endif
