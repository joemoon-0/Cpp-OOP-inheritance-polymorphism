#ifndef VIDEO_H
#define VIDEO_H

#include "Media.h"

class Video : public Media {
protected:
	std::string resolution;
	std::string formatDescriptor;
	std::string qualitySpec;
	std::string type;

public:
	Video();
	/**
	* PRE: None.
	* POST: Initializes strings to empty, type to Video.  Calls Media().
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	Video(std::string uniqueID, std::string name, int runningTime, 
		std::string resolution, std::string formatDescriptor, std::string qualitySpec);
	/**
	* PRE: Input file opened for read.
	* POST: Initializes member variables to parameterized values, type to Video.
	*		Calls Media().
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	bool ReadData(std::istream& in);
	/**
	* PRE: Input file opened for read.
	* POST: Calls Media::ReadData(). Reads and assigns resolution, formatDescriptor, qualitySpec variables.
	* RETURNS: Boolean on successful read.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	bool WriteData(std::ostream& out);
	/**
	* PRE: Ouput file opened.
	* POST: Calls Media::WriteData(). Writes resolution, formatDescriptor, and qualitySpec variables to output file.	
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

#endif // !VIDEO_H