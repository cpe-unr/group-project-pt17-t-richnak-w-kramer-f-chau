WavProcessor: main.cpp WavManager.o WavConsole.o Wav.o Modify.o WriteToCSV.o Command.o libprocessors.a
	g++ -std=c++17 main.cpp WavManager.o WavConsole.o Wav.o Modify.o WriteToCSV.o Command.o libprocessors.a -lstdc++fs -o WavProcessor

WavManager.o: WavManager.cpp WavManager.h
	g++ -c -std=c++17 WavManager.cpp
Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++17 Wav.cpp

libprocessors.a: NoiseGate.o Normalization.o Echo.o libprocessors.h
	ar rs libprocessors.a libprocessors.h NoiseGate.o Normalization.o Echo.o 

NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++17 NoiseGate.cpp 

Modify.o: Modify.cpp Modify.h
	g++ -c -std=c++17 Modify.cpp 

Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++17 Normalization.cpp 

Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++17 Echo.cpp 

WavConsole.o: WavConsole.cpp WavConsole.h
	g++ -c -std=c++17 -lstdc++fs WavConsole.cpp

Command.o: Command.cpp Command.h
	g++ -c -std=c++17 Command.cpp 

WriteToCSV.o: WriteToCSV.cpp WriteToCSV.h
	g++ -c -std=c++17 WriteToCSV.cpp

clean:
	rm *.o *.a WavProcessor something.wav
