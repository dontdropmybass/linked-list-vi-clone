//
//  main.cpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "fileloader.hpp"
#include "linkedlist.hpp"

//  Main function containing command loop.
int main(int argc, const char * argv[]) {
    linkedlist ll;
    std::string filename;
    if (argc <= 1) {
        std::cout << "please enter a filename" << std::endl;
        return 1;
    }
    filename = argv[1];
    fileloader::loadFileToLinkedList(filename, &ll);
    for (int i = 0; true; i++) {
        try {
            std::string data = ll.get(i)->data;
            std::cout << std::endl << i+1 << " | " << data;
        }
        catch (...) {
            break;
        }
    }
	char c;
	std::string line;

	while (true) {
        std::cout << std::endl << "Command: ";
        std::cin >> c;

		if (c == 'Q') {
			return 0;
		}
		
		else if (c == 'D') {
			std::cout << std::endl << "line: ";
			std::string lineNum;
			std::cin >> lineNum;
			ll.remove(std::stoi(lineNum));
		}
		
		else if (c == 'I') {
			std::cout << std::endl << "Enter New Line Content";
			std::string NewLine;
			std::cin >> NewLine;
			std::cout << std::endl << "line # to insert before";
			std::string lineNum;
			std::cin >> lineNum;
			ll.insert(std::stoi(lineNum), NewLine);

		}

		else if (c == 'V')
		{

		}

		else if (c == 'G')
		{

		}

		else if (c == 'L')
		{

		}

		else if (c == 'S')
		{
			std::cout << std::endl << "Enter New Line Content";
			std::string NewLine;
			std::cin >> NewLine;
			std::cout << std::endl << "line #";
			std::string lineNum;
			std::cin >> lineNum;
			ll.replace(std::stoi(lineNum), NewLine);

		}

		else if (c == 'E')
		{
			fileloader::saveLinkedListToFile(&ll,filename);
			return 0;
		}

    }
    return 0;
}
