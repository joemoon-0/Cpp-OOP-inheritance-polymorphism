/***
* Joe Moon
* jmn5y@umsystem.edu
* CS 201R Summer 2020
* Program 5 - Media Info Separation (Inheritance/Polymorphism)
***/

#include <iostream>
#include <fstream>
#include <string>
#include "Audio.h"
#include "Video.h"

int main() {
	// STREAM VARIABLES
	std::ifstream in;
	std::ofstream outAudio;						// audio.txt output stream
	std::ofstream outVideo;						// video.txt output stream
	std::string file1 = "Program5Data.txt";		// Input file
	std::string file2 = "audio.txt";			// Output file - Audio
	std::string file3 = "video.txt";			// Output file - Video

	Media* mediaFiles[200] = { nullptr };
	int readIndex = 0;							// Index for readomg data into array
	int writeIndex = 0;							// Index for writing data to output files
	char fileType = ' ';						// Distinguishes between audio and video files
	int i = 0;									// Loop variable for deallocating memory
	
	// STEP 1: Open and check Input file
	in.open(file1);
	if (!in.is_open()) {
		std::cout << "Failed to open file: " << file1 << std::endl;
		return -1;
	}
	else {
		// STEP 2: Open and check output files
		outAudio.open(file2);			// audio.txt
		outVideo.open(file3);			// video.txt
		if (!outAudio.is_open() || !outVideo.is_open()) {
			std::cout << "Failed to open either " << file2 << " or " << file3 << std::endl;
			return -1;
		}
		else {
			while (in >> fileType) {
				in.ignore();
				// STEP 3: Instantiate Media pointer to corresponding file type and read data
				switch (fileType) {
				case 'A':
					mediaFiles[readIndex] = new Audio;
					break;
				case 'V':
					mediaFiles[readIndex] = new Video;
					break;
				}
				mediaFiles[readIndex]->ReadData(in);
				readIndex++;
			}
		}

		// STEP 4: Write Media data to corresponding output file
		while (mediaFiles[writeIndex] != nullptr && writeIndex <= readIndex) {
			if (mediaFiles[writeIndex]->getType() == "Audio") {
				mediaFiles[writeIndex]->WriteData(outAudio);
			}
			else {
				mediaFiles[writeIndex]->WriteData(outVideo);
			}
			writeIndex++;
		}
	}
	in.close();
	outAudio.close();
	outVideo.close();

	// Deallocate pointer array
	while (mediaFiles[i] != nullptr) {
		delete mediaFiles[i];
		mediaFiles[i] = nullptr;
		i++;
	}
	
	return 0;
}