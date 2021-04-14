#ifndef WAVHEADER_H
#define WAVHEADER_H

/* Author: Tanner Richnak
 * Date: 4/14/2021
 *
 * This header description copied from https://docs.fileformat.com/audio/wav/ S
 * Positions	Sample Value	Description
 * 1 - 4		"RIFF"			Marks the file as a riff file.  Characters are each 1 byte long
 * 5 - 8 		File size (int)	Size of the overall file - 8 bytes, in bytes (32-bit integer).  Typically, you'd fill this in after creation
 * 9 - 12		"WAVE"			File type headeer.  For our purp[oses, it always equals "WAVE"
 * 13 - 16		"fmt"			Format chunk marker.  Includes trailing null
 * 17 - 20		16				Length of format data as listed above
 * 21 - 22		1				Type of format (1 is PCM) - 2 byte integer
 * 23 - 24		2				Number of Channels - 2 byte integer
 * 25 - 28		44100			Sample Rate - 32 byte integer.  Common values are 44100 (CD), 48000 (DAT).  Sample Rate = Number of Samples per second, or Hertz
 * 29 - 32 		176400			(Sample Rate * BitsPerSample * Channels)/8
 * 33 - 34		4				(BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo / 16 bit mono4 - 16 bit stereo
 * 35 - 36		16				Bits per sample
 * 37 - 40		"data"			"data" chunk header.  MArks the beginning of the data section
 * 41 - 44		Filesize (data)	Size of the data section
 */
 
typedef struct WavHeader {
	//RIFF Chunk
	uint8_t RIFF[4]; 				//RIFF header
	uint32_t chunkSize;				//RIFF chunk size
	uint8_t WAVE[4];				//WAVE header
	//fmt subchunk
	uint8_t FMT[4];					//FMT header
	uint32_t fmtChunkSize;			//Size of the fmt subchunk
	uint16_t audioFormat;			//Audio format 1=PCM
	uint16_t numChannels;			//Number of channels 1=mono 2=stereo
	uint32_t sampleRate;			//Number of samples per second (Hz)
	uint32_t byteRate;				//Number of bytes per second
	uint16_t blockAlignment;		//Bytes per sample * Number of channels
	uint16_t bitDepth;				//Number of bits per sample
	//data subchunk
	uint8_t dataHeader[4];			//DATA header
	uint32_t dataChumkSize;			//Size of data chunk
} WavHeader;

#endif //WAVHEADER_H
