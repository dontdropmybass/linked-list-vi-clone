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
    return 0;
}
