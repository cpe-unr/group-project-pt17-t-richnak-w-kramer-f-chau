WavProcessor: main.cpp WavManager.o Wav.o libprocessors.so
	g++ -std=c++11 main.cpp WavManager.o Wav.o -L. -lprocessors -o WavProcessor

WavManager.o: WavManager.cpp WavManager.h
	g++ -c -std=c++11 WavManager.cpp

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

libprocessors.so: NoiseGate.o Normalization.o Echo.o
	g++ NoiseGate.o Normalization.o Echo.o -shared -o libprocessors.so

NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c NoiseGate.cpp -fpic

Normalization.o: Normalization.cpp Normalization.h
	g++ -c Normalization.cpp -fpic

Echo.o: Echo.cpp Echo.h
	g++ -c Echo.cpp -fpic

clean:
	rm *.o WavProcessor something.wav
