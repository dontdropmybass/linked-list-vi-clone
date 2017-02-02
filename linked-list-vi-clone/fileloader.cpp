//
//  fileloader.cpp
//  linked-list-vi-clone
//

#include "fileloader.hpp"

//  takes a filename, and a pointer to a linked list
//  saves every line to a node in the linked list
void fileloader::loadFileToLinkedList(const std::string filename, linkedlist* ll) {
    
    std::ifstream ifs(filename);
    
    // if the file isn't open, the argument is invalid
    if (ifs.fail()) {
        throw std::invalid_argument("failed to load file");
    }
    
    // load every line of the file into the string, including whitespace.
    while (!ifs.eof()) {
        std::string temp;
        getline(ifs,temp);
        ll->add(temp);
        std::cout << temp << std::endl;
        temp.clear();
    }
    
    // close the stream
    ifs.close();
}

//  takes a pointer to a linked list, and a filename
//  saves every node to the given file
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
