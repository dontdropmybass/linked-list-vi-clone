	#include <iostream>
	#include <fstream>
	#include <exception>
	#include "FileHandler.h"

//plz god no halp
class FileIOException { //Must extend exception
private: std::string errorMessage = "File Does Not Exist";
public: std::string getError() {
	return errorMessage;
}
};

//filehandler open code
std::ifstream fileHandler::open(char* fileName) {

		std::ifstream File(fileName);

		try {
			if (!File)
			{
				throw FileIOException();
			}
		}
		//this is right proper frigged up man
		catch (FileIOException &e) {//throw byval catch by ref
			
		}
		return File;
}

//fugg this is going to be hard
void fileHandler::save(char* fileName) {
	std::ofstream saveFile;
	saveFile.open(fileName);
	//saveFile << file contents would go here :s
	//figure out how to pass the whole contents of the file to here

}