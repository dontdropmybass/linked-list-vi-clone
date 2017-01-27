//
//  main.cpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "fileloader.hpp"
#include "linkedlist.hpp"

void help();

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
        std::string command;
        getline(std::cin,command);
        c = command[0];
        
        if (c == 'H') {
            help();
        }

		else if (c == 'Q') {
			return 0;
		}
		
		else if (c == 'D') {
            int lineNum;
            std::cout << std::endl << "Enter line number: ";
            std::cin >> lineNum;
			if (std::cin.fail()) {
				std::cout << std::endl << "Not a valid integer";
			}
			else { //turn into else if to say if it isn't greater than the number of nodes
				ll.remove(lineNum);
			}
			
		}
		
		else if (c == 'I') {
			std::cout << std::endl << "Enter New Line Content:";
			std::string NewLine;
			getline(std::cin, NewLine);
			std::cout << std::endl << "line # to insert before";
			int lineNum;
			std::cin >> lineNum;
			if (std::cin.fail()) { //turn into else if to say if it isn't greater than the number of nodes
				std::cout << std::endl << "Not a valid integer";
			}
			else {
				ll.insert(lineNum, NewLine);
			}
		}

		else if (c == 'V')
		{
			for (int i = 0; true; i++) {
				try {
					std::string data = ll.get(i)->data;
					std::cout << std::endl << i << " | " << data;
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
			std::cin >> lineNum;
			if (std::cin.fail()){
				std::cout << std::endl << "Invalid integer";
			}
			else {
				std::string data = ll.get(lineNum)->data;
				std::cout << data << std::endl;
			}
		}

		else if (c == 'L')
		{
			std::cout << std::endl << "Enter Num 1: ";
			int line1;
			std::cin >> line1;
			if (std::cin.fail()) {
				std::cout << std::endl << "Invalid integer";
			}
			std::cout << std::endl << "Enter Num 2: ";
			int line2;
			std::cin >> line2;

			if (std::cin.fail()) {
				std::cout << std::endl << "Invalid integer";
			}
			//make another if statement making sure both ints are valid indexes
			//also make sure first int is smaller than second
			while (line1 <= line2) {
				try {
					std::string data = ll.get(line1)->data;
					std::cout << std::endl << line1 << " | " << data;
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
			std::cout << std::endl << "Line #: ";
			int lineNum;
			std::cin >> lineNum;
			if (std::cin.fail()) {
				std::cout << std::endl << "Invalid integer";
			}
			else {
				ll.replace(lineNum, NewLine);
			}

		}

		else if (c == 'E')
		{
			fileloader::saveLinkedListToFile(&ll,filename);
			return 0;
		}
        
        else {
            std::cout << std::endl << "Invalid command." << std::endl;
        }

    }
    return 0;
}

void help() {
    std::string a[] = {
        "COMMANDS:",
        
        "\n\tH:\n\t\tDisplays help",
        
        "\n\tI [linenum]:",
        "\t\tInsert a new line, to be filled by the user.",
        "\t\tIf a linenumber is entered after, insert at that line, otherwise insert at the current line.",
        
        "\n\tD [startline] [endline]:",
        "\t\tIf two numbers are entered, delete lines between startline and endline.",
        "\t\tIf one line is entered, delete that line.",
        "\t\tOtherwise, delete current line.",
        
        "\n\tV:",
        "\t\tDisplay all lines.",
        
        "\n\tG [linenum]:",
        "\t\tIf a linenum is specified, goto line specified and load into buffer.",
        "\t\tOtherwise goto the first line and load into buffer.",
        
        "\n\tL:",
        "\t\tDisplays current line of the buffer.",
        
        "\n\tS [linenum]:",
        "\t\tReplaces the specified line, or current line, with user-specified data,",
        "\t\tthen displays all lines.",
        
        "\n\tE:",
        "\t\tSaves data and exits program.",
        
        "\n\tQ:",
        "\t\tExits without saving."
    };
    for (std::string s : a) {
        std::cout << s << std::endl;
    }
}
