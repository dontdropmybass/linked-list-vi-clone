//
//  main.cpp
//  linked-list-vi-clone
//

#include "fileloader.hpp"
#include "linkedlist.hpp"

std::regex inum("i[0-9]+");
std::regex i("i");
std::regex H("H");
std::regex dnumnum("d[0-9]+-[0-9]+");
std::regex dnum("d[0-9]+");
std::regex d("d");
std::regex v("v");
std::regex g("g[0-9]+");
std::regex l("l[0-9]+-[0-9]+");
std::regex s("s");
std::regex snum("s[0-9]+");
std::regex e("e");
std::regex q("q");
std::regex replace1("[0-9]+-");
std::regex replace2("-[0-9]+");
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
    
	char *c;
	std::string line;
    
    int currentLine = 0;

	while (true) {
		std::cout << std::endl << "Command: ";
		std::string command;
		getline(std::cin, command);
		//get user input limited at 512 chars
		std::cin.getline(c,512);

		if (regex_match(c,H)) {
			help();
		}

		if (regex_match(c, inum)) {
			memmove(c, c + 1, strlen(c));
			int line = atoi(c);
			char *text = new char[256];
			std::cout << "Input on line " << c << ":" << std::endl;
			std::cin.clear();
			std::cin.getline(text, 256);
			ll.insert(line, text);
		}//end if


		 //Delete specific line
		else if (regex_match(c, dnum)) {
			std::cout << "Delete line " << c << std::endl;
			memmove(c, c + 1, strlen(c));
			ll.remove(atoi(c));
		}//end else if

		 //Select line as buffer
		else if (regex_match(c, g)) {
			memmove(c, c + 1, strlen(c));
			std::cout << "Display line " << c << std::endl;
			int line = atoi(c);
			std::cout << "Line " << line << " = " << ll.get(line)->data << std::endl << std::endl;
		}//end else if

		 //Substitute line number
		else if (regex_match(c, snum)) {
			//use memmmove to delete first char
			memmove(c, c + 1, strlen(c));
			std::cout << "Substitute line " << c << ":" << std::endl;
			int num = atoi(c);
			char *text = new char[512];
			std::cin.clear();
			std::cin.getline(text, 512);
			ll.replace(num, text);
		}//end else if


		 //Save and quit
		else if (regex_match(c, e)) {
			std::cout << "Save and quit" << std::endl;
			fileloader::saveLinkedListToFile;
			break;
		}//end else if

		 //Quit
		else if (regex_match(c, q)) {
			std::cout << "Quit without saving" << std::endl;
			//Quit using terminate
			break;
		}//end else if


		else if (regex_match(c, v)) {
			//figure out how to show all lines
		}



		else {
			std::cout << "Nothing triggered" << std::endl;
		}//end else


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
