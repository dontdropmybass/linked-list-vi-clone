#ifndef fileHandler_hpp
#define fileHandler_hpp

#include <fstream>

class fileHandler {
	public:
		std::ifstream open(char* FileName);
		void save(char* FileName);
};

#endif