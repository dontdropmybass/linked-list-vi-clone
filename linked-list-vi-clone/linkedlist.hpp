//
//  linkedlist.hpp
//  linked-list-vi-clone
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
#include <iostream>

class linkedlist {
public:
    struct Node {
        std::string data;
        struct Node* next;
        Node(const std::string& data, Node* next = NULL) : data(data), next(next) {}
    }*start=NULL;
    
    struct Node* head = NULL;
    
    void add(std::string data);
    void remove(int index);
    void insert(int index, std::string data);
    void removeHead();
    void insertHead(std::string data);
	void replace(int index, std::string data);
    Node* get(int index);
};

#endif /* linkedlist_hpp */
