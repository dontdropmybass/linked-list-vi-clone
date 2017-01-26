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
    
    try {
        std::string data = ll.get(0)->data;
        /*std::cout << std::endl  << data;*/
    }
    catch (...) {
        return 0;
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
			int lineNum;
			std::cin >> lineNum;
			ll.remove(lineNum);
		}
		
		else if (c == 'I') {
			std::cout << std::endl << "Enter New Line Content";
			std::string NewLine;
			getline(std::cin, NewLine);
			std::cout << std::endl << "line # to insert before";
			int lineNum;
			std::cin >> lineNum;
			ll.insert(lineNum, NewLine);

		}

		else if (c == 'V')
		{
			for (int i = 0; true; i++) {
				try {
					std::string data = ll.get(i)->data;
					std::cout << std::endl << i + 1 << " | " << data;
				}
				catch (...) {
					break;
				}
			}
		}

		else if (c == 'G')
		{
			std::cout << std::endl << "Go to Line #";
            int lineNum;
			std::string data = ll.get(lineNum)->data;
			std::cout << data << std::endl;
		}

		else if (c == 'L')
		{
			std::cout << std::endl << "Enter Num 1: ";
			int line1;
			std::cin >> line1;
			std::cout << std::endl << "Enter Num 2: ";
			int line2;
			std::cin >> line2;

			while (line1 <= line2) {
				try {
					std::string data = ll.get(line1)->data;
					std::cout << std::endl << line1 + 1 << " | " << data;
                    line1++;
				}
				catch (...) {
					break;
				}
			}
		}

		else if (c == 'S')
		{
			std::cout << std::endl << "Enter New Line Content";
			std::string NewLine;
            getline(std::cin, NewLine);
			std::cout << std::endl << "line #";
			int lineNum;
			std::cin >> lineNum;
			ll.replace(lineNum, NewLine);

		}

		else if (c == 'E')
		{
			fileloader::saveLinkedListToFile(&ll,filename);
			return 0;
		}

    }
    return 0;
}


