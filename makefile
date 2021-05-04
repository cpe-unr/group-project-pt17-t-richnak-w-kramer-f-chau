WavProcessor: main.cpp WavManager.o WavConsole.o Wav.o Modify.o WriteToCSV.o Command.o libprocessors.so
	g++ -std=c++17 main.cpp WavManager.o WavConsole.o Wav.o Modify.o WriteToCSV.o Command.o -L. -lprocessors -lstdc++fs -o WavProcessor

WavManager.o: WavManager.cpp WavManager.h
	g++ -c -std=c++17 WavManager.cpp
Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++17 Wav.cpp

libprocessors.so: NoiseGate.o Normalization.o Echo.o
	g++ NoiseGate.o Normalization.o Echo.o -shared -o libprocessors.so

NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++17 NoiseGate.cpp -fpic
Modify.o: Modify.cpp Modify.h
	g++ -c -std=c++17 Modify.cpp 
Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++17 Normalization.cpp -fpic
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++17 Echo.cpp -fpic
WavConsole.o: WavConsole.cpp WavConsole.h
	g++ -c -std=c++17 -lstdc++fs WavConsole.cpp
Command.o: Command.cpp Command.h
	g++ -c -std=c++17 Command.cpp 
WriteToCSV.o: WriteToCSV.cpp WriteToCSV.h
	g++ -c -std=c++17 WriteToCSV.cpp
clean:
	rm *.o WavProcessor something.wav
