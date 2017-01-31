//
//  main.cpp
//  linked-list-vi-clone
//

#include "fileloader.hpp"
#include "linkedlist.hpp"

void help();

//  Main function containing command loop.
//  Takes a filename via command line.
int main(int argc, const char * argv[]) {
    linkedlist ll;
    std::string filename;
    std::string savefilename;
    if (argc <= 1) {
        std::cout << "please enter a filename" << std::endl;
        return 1;
    }
    filename = argv[0];
    fileloader::loadFileToLinkedList(filename, &ll);
    
    if (argc == 2) {
        savefilename = argv[1];
    }
    else {
        savefilename = filename;
    }
    
    try {
        std::string data = ll.get(0)->data;
    }
    catch (...) {
        return 0;
    }
    
	char c;
	std::string line;
    
    int currentLine = 0;

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
            int lineNum2;
            std::cout << std::endl << "Enter line number: ";
            std::cin >> lineNum;
			if (std::cin.fail()) {
                try {
                    ll.remove(currentLine);
                    std::cout << std::endl << "Deleted line number " << currentLine;
                }
                catch (...) {
                    std::cout << std::endl << "Delete failed.";
                }
			}
			else {
                std::cout << std::endl << "Enter second line number, greater than the first: ";
                std::cin >> lineNum2;
                if (std::cin.fail()) {
                    try {
                        ll.remove(lineNum);
                        std::cout << std::endl << "Deleted line number " << lineNum;
                    }
                    catch (...) {
                        std::cout << std::endl << "Invalid line number.";
                    }
                }
                else if (lineNum2 > lineNum) {
                    try {
                        ll.get(lineNum2);
                        for (; lineNum <= lineNum2; lineNum++) {
                            ll.remove(lineNum);
                            std::cout << std::endl << "Deleted line number " << lineNum;
                        }
                    }
                    catch (...) {
                        std::cout << std::endl << "Invalid line number.";
                    }
                }
                else {
                    std::cout << std::endl << "Second number needs to be bigger than the first.";
                }
			}
			
		}
		
		else if (c == 'I') {
			std::cout << std::endl << "Enter New Line Content: ";
			std::string newLine;
			getline(std::cin, newLine);
			std::cout << std::endl << "Line # to insert before: ";
            std::string lineNum;
			std::cin >> lineNum;
			if (std::cin.fail() || lineNum == "") {
                try {
                    ll.insert(currentLine, newLine);
                    std::cout << std::endl << "Inserted " << newLine << " before line " << currentLine;
                }
                catch (...) {
                    std::cout << std::endl << "Line does not exist.";
                }
			}
			else {
                try {
                    ll.insert(stoi(lineNum), newLine);
                    std::cout << std::endl << "Inserted " << newLine << " before line " << lineNum;
                }
                catch (...) {
                    std::cout << std::endl << "Line does not exist.";
                }
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
                currentLine = lineNum;
				std::string data = ll.get(lineNum)->data;
				std::cout << data << std::endl;
			}
		}

		else if (c == 'L')
		{
            try {
                std::string data = ll.get(currentLine)->data;
                std::cout << std::endl << data;
            }
            catch (...) {
                std::cout << std::endl << "Failure of some sort.";
            }
		}

		else if (c == 'S')
		{
			std::cout << std::endl << "Enter New Line Content: ";
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
			fileloader::saveLinkedListToFile(&ll,savefilename);
			return 0;
		}
        
        else {
            std::cout << std::endl << "Invalid command. Use `H` to shows a list of commands." << std::endl;
        }

    }
    return 0;
}

//  prints the help doc
void help() {
    std::string a[] = {
        "COMMANDS:",
        
        "\n\tH:\n\t\tDisplays help",
        
        "\n\tI:",
        "\t\tInsert a new line, to be filled by the user.",
        "\t\tIf a linenumber is entered after, insert at that line, otherwise insert at the current line.",
        
        "\n\tD:",
        "\t\tIf two numbers are entered, delete lines between startline and endline.",
        "\t\tIf one line is entered, delete that line.",
        "\t\tOtherwise, delete current line.",
        
        "\n\tV:",
        "\t\tDisplay all lines.",
        
        "\n\tG:",
        "\t\tIf a linenum is specified, goto line specified and load into buffer.",
        "\t\tOtherwise goto the first line and load into buffer.",
        
        "\n\tL:",
        "\t\tDisplays current line of the buffer.",
        
        "\n\tS:",
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
