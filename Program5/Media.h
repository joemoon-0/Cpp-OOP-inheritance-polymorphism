#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <fstream>

class Media {
protected:
	std::string uniqueID;
	std::string name;
	int runningTime;

public:
	Media();
	/**
	* PRE: None.
	* POST: Initializes strings to empty, numerical variables to 0.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	Media(std::string uniqueID, std::string name, int runningTime);
	/**
	* PRE: None.
	* POST: Initializes variables to parameterized values.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void setUniqueID(std::string uniqueID);
	/**
	* PRE: uniqueID read in from file.
	* POST: Assigns parameter to uniqueID member variable.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void setName(std::string name);
	/**
	* PRE: name read in from file.
	* POST: Assigns parameter to name member variable.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void setRunningTime(int runningTime);
	/**
	* PRE: runningTime read in from file.
	* POST: Assigns parameter to runngingTime member variable.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	std::string getUniqueID() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: Value of uniqueID member variable.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	std::string getName() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: Value of name member variable.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int getRunningTime() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: Value of runningTime member variable.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	virtual std::string getType() const = 0;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	virtual bool ReadData(std::istream& in);
	/**
	* PRE: Input file opened for read.
	* POST: Reads and assigns uniqueID, name, runningTime variables.
	* RETURNS: Boolean on successful read.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	virtual bool WriteData(std::ostream& out);
	/**
	* PRE: Ouput file opened.
	* POST: Writes uniqueID, name, runningTime variables to output file.
	* RETURNS: Boolean on successful write.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
};

#endif // !MEDIA_H