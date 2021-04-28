WavProcessor: main.cpp WavManager.o _8Bit.o _16Bit.o libprocessors.so
	g++ -std=c++11 main.cpp WavManager.o _8Bit.o _16Bit.o -L. -lprocessors -o WavProcessor

WavManager.o: WavManager.cpp WavManager.h
	g++ -c -std=c++11 WavManager.cpp
	
_8Bit.o: _8Bit.cpp _8Bit.h
	g++ -c -std=c++11 _8Bit.cpp
	
_16Bit.o: _16Bit.cpp _16Bit.h
	g++ -c -std=c++11 _16Bit.cpp

libprocessors.so: NoiseGate.o Normalization.o Echo.o
	g++ NoiseGate.o Normalization.o Echo.o -shared -o libprocessors.so

NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c NoiseGate.cpp -fpic

Normalization.o: Normalization.cpp Normalization.h
	g++ -c Normalization.cpp -fpic

Echo.o: Echo.cpp Echo.h
	g++ -c Echo.cpp -fpic

clean:
	rm *.o wavprocessor something.wav
