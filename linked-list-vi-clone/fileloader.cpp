//
//  fileloader.cpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "fileloader.hpp"

// loads file to a string
void fileloader::loadFileToLinkedList(const std::string filename, linkedlist* ll) {
    
    std::ifstream ifs;
    
    ifs.open(filename, std::fstream::in);
    
    // if the file isn't open, the argument is invalid
    if (ifs.fail()) {
        throw std::invalid_argument("failed to load file");
    }
    
    // load every line of the file into the string, including whitespace.
    while (!ifs.eof()) {
        std::string temp;
        getline(ifs,temp);
        ll->add(temp);
        temp.clear();
    }
    
    // close the stream
    ifs.close();
}

// saves file to string
void fileloader::saveLinkedListToFile(linkedlist* ll, std::string filename) {
    std::ofstream ofs(filename, std::fstream::out | std::fstream::trunc);
    
    // if the file isn't open, the argument is invalid
    if (ofs.fail()) throw std::invalid_argument("failed to save file");
    
    // output the string to file
    linkedlist::Node* node = ll->head;
    while (true) {
        ofs << node->data << std::endl;
        if (node->next==NULL) {
            break;
        }
        node = node->next;
    }
    
    // close the stream
    ofs.close();
}
