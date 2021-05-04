# CS 202 Semester Project Template

PT17 is Will Kramer, Tanner Richnak, Fiorina Chau

**Responsibilities**

Will: UI (WavConsole)
Tanner: WAV and associated classes
Fiorina: Processing, CSV writing, metadata editing

**Challenges**

Navigating the new makefile and git concepts introduced in this project proved difficult at times, especially manipulating the libraries and coordinating commits/pushes/pulls. 

Research on the WAV file format for file I/O and processing was also a challenge, but one that was eventually solidly overcome - the whole team seems to now have a solid grasp of the WAV file structure. 

**Design**

The WAV is split into three chunks: the WavHeader, which contains the leading information; the buffer, which contains the actual audio, and the list vector, which contains List elements that comprise the metadata for the WAV file. 
 
Processor is the base class for classes that directly modify the buffer, of which we've included three: Normalization, NoiseGate, and Echo. For NoiseGate and Echo, a numerical parameter can be specified to give the noise threshold and echo delay, respectively. 

Modify is the class assigned to manipulate the list vector; its function modifyMetadata is used to edit an individual value.

WriteToCSV is the class that handles well, well, writing the files and their metadata to a CSV file.  

UI is handled through the WavConsole class and specifically through the function runConsole(), which hosts the above classes, each of which is encapsulated to take on a specific requirement. 

The full diagram is as follows.

image::7ca52389.pdf[]





  
