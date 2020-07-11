#ifndef AUDIO_H
#define AUDIO_H

#include "Media.h"

class Audio : public Media {
private:
	std::string formatDescriptor;
	std::string qualitySpec;
	std::string type;

public:
	Audio();
	/**
	* PRE: None.
	* POST: Initializes strings to empty, type to Audio.  Calls Media().
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	Audio(std::string uniqueID, std::string name, int runningTime, std::string formatDescriptor, std::string qualitySpec);
	/**
	* PRE: Input file opened for read.
	* POST: Initializes member variables to parameterized values, type to Audio.
	*		Calls Media().
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	bool ReadData(std::istream& in);
	/**
	* PRE: Input file opened for read.
	* POST: Calls Media::ReadData(). Reads and assigns formatDescriptor, qualitySpec variables.
	* RETURNS: Boolean on successful read.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	bool WriteData(std::ostream& out);
	/**
	* PRE: Ouput file opened.
	* POST: Calls Media::WriteData(). Writes formatDescriptor and qualitySpec variables to output file.
	* RETURNS: Boolean on successful write.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	std::string getType() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: type member variable.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
};
#endif // !AUDIO_H