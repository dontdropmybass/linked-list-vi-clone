//
//  main.cpp
//  linked-list-vi-clone
//

#include "fileloader.hpp"
#include "linkedlist.hpp"
#include "regexmatches.h"

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
    filename = argv[1];
    fileloader::loadFileToLinkedList(filename, &ll);
    
    if (argc > 2) {
        savefilename = argv[2];
    }
    else {
        savefilename = filename;
    }
    savefilename = filename;
    
    try {
        std::string data = ll.get(0)->data;
    }
    catch (...) {
        return 0;
    }
    
    int currentLine = 0;

	while (true) {
        try {
		std::cout << std::endl << "Command: ";
		std::string command;
        std::cin.clear();
		getline(std::cin, command);
            std::cout << command << std::endl;
        
        // This thing tokenized the command so you can get the numbers from it
        char * temp;
        std::string array[3];
        char * cmd = new char[command.size() + 1];
        std::copy(command.begin(), command.end(), cmd);
        cmd[command.size()] = '\0';
        temp = std::strtok(cmd, " ");
        int i = 0;
        while (temp != NULL)
        {
            array[i] = temp;
            temp = std::strtok(NULL, " ");
            i++;
        }

		if (regex_match(command, H)) {
			help();
		}
        
        else if (array[0]=="I") {
            if (array[1]!="") {
                int line = stoi(array[1]);
                try {
                    ll.get(line);
                    std::cout << "New line to insert on line " << line << ": " << std::endl;
                    std::cin.clear();
                    std::string newLine;
                    getline(std::cin, newLine);
                    ll.insert(line, newLine);
                }
                catch (...) {
                    std::cout << "Command failed." << std::endl;
                }
            }
            else {
                int line = currentLine;
                try {
                    ll.get(line);
                    std::cout << "New line to insert on line " << line << ": " << std::endl;
                    std::cin.clear();
                    std::string newLine;
                    getline(std::cin, newLine);
                    ll.insert(line, newLine);
                }
                catch (...) {
                    std::cout << "Command failed." << std::endl;
                }
            }
        }
        
        else if (regex_match(command, Dnumnum)) {
            int line1 = stoi(array[1]);
            int line2 = stoi(array[2]);
            if (line1 > line2) {
                try {
                    ll.get(line1);
                    for (int i = line2; i <= line1; i++) {
                        ll.remove(line2);
                    }
                    std::cout << "Removed lines between " << line2 << " and " << line1 << std::endl;
                }
                catch (...) {
                    std::cout << "Command failed." << std::endl;
                }
            }
            else {
                try {
                    ll.get(line2);
                    for (int i = line1; i <= line2; i++) {
                        ll.remove(line1);
                    }
                    std::cout << "Removed lines between " << line1 << " and " << line2 << std::endl;
                }
                catch (...) {
                    std::cout << "Command failed." << std::endl;
                }
            }
        }

		else if (regex_match(command, Dnum)) {
            int line = stoi(array[1]);
            try {
                ll.remove(line);
                std::cout << "Deleted line " << line << std::endl;
            }
            catch (...) {
                std::cout << "Command failed." << std::endl;
            }
		}
        
        else if (regex_match(command, D)) {
            int line = currentLine;
            try {
                ll.remove(line);
                std::cout << "Deleted line " << line << std::endl;
            }
            catch (...) {
                std::cout << "Command failed." << std::endl;
            }
        }
        
		else if (regex_match(command, Gnum)) {
            currentLine = stoi(array[1]);
            try {
                std::cout << "Line " << currentLine << " | " << ll.get(currentLine)->data << std::endl;
            }
            catch (...) {
                std::cout << "Command failed." << std::endl;
            }
		}
        
		else if (regex_match(command, Snum)) {
            try {
                int line = stoi(array[1]);
                ll.get(line);
                std::cout << "Enter text to replace line " << line << ": " << std::endl;
                std::string newLine;
                std::cin.clear();
                getline(std::cin, newLine);
                ll.replace(line, newLine);
            }
            catch (...) {
                std::cout << "Command failed." << std::endl;
            }
		}
        
        else if (regex_match(command, S)) {
            try {
                int line = currentLine;
                ll.get(line);
                std::cout << "Enter text to replace line " << line << ": " << std::endl;
                std::string newLine;
                std::cin.clear();
                getline(std::cin, newLine);
                ll.replace(line, newLine);
            }
            catch (...) {
                std::cout << "Command failed." << std::endl;
            }
        }
        
		else if (regex_match(command, E)) {
			std::cout << "Save and quit." << std::endl;
			fileloader::saveLinkedListToFile(&ll, savefilename);
            return 0;
        }
        
		else if (regex_match(command, Q)) {
			std::cout << "Quit without saving." << std::endl;
            return 0;
		}


        else if (regex_match(command, V)) {
            for (int i = 0; true; i++) {
                try {
                    std::string line = ll.get(i)->data;
                    std::cout << i << " | " << line << std::endl;
                }
                catch (...) {
                    break;
                }
            }
		}

        else if (regex_match(command, Lnumnum)) {
            try {
                int line1 = stoi(array[1]);
                int line2 = stoi(array[2]);
                int first, second;
                if (line1 > line2) {
                    first = line2;
                    second = line1;
                }
                else {
                    first = line1;
                    second = line2;
                }
                ll.get(second);
                for (int i = first; i < second; i++) {
                    std::string line = ll.get(i)->data;
                    std::cout << i << " | " << line;
                }
            }
            catch (...) {
                std::cout << "Command failed." << std::endl;
            }
        }

		else {
			std::cout << "Invalid command." << std::endl;
		}
            
        }
        catch (...) {
            std::cout << "Invalid command." << std::endl;
        }
	}
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
        "\t\tDisplays current line of the buffer.",
        "\t\tIf a linenum is specified, goto line specified and load into buffer.",
        
        "\n\tL:",
        "\t\tDisplays lines of the buffer between two given line numbers.",
        
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
