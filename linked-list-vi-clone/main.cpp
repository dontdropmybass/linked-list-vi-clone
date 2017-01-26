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
            std::string data = ll.get(1)->data;
            std::cout << std::endl  << data;
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
			std::string NewLine;
			std::string data = ll.get(std::stoi(NewLine))->data;
			std::cout << data << std::endl;
		}

		else if (c == 'L')
		{
			std::cout << std::endl << "Enter Num 1";
			std::string line1;
			std::cin >> line1;
			std::cout << std::endl << "Enter Num 2";
			std::string line2;
			std::cin >> line2;
			int intLine2 = std::stoi(line1);
			int intLine1 = std::stoi(line1);

			for (intLine1; intLine2; intLine1++) {
				try {
					std::string data = ll.get(intLine1)->data;
					std::cout << std::endl << intLine1 + 1 << " | " << data;
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


