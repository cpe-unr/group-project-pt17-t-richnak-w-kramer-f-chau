WavProcessor: main.cpp WavManager.o _8Bit.o _16Bit.o
	g++ -std=c++11 main.cpp WavManager.o _8Bit.o _16Bit.o -o wavprocessor

WavManager.o: WavManager.cpp WavManager.h
	g++ -c -std=c++11 WavManager.cpp
	
_8Bit.o: _8Bit.cpp _8Bit.h
	g++ -c -std=c++11 _8Bit.cpp
	
_16Bit.o: _16Bit.cpp _16Bit.h
	g++ -c -std=c++11 _16Bit.cpp
	
clean:
	rm *.o wavprocessor something.wav
