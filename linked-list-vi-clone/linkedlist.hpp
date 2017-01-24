//
//  linkedlist.hpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
#include <iostream>

class linkedlist {
    
    struct Node {
        std::string data;
        struct Node* next;
    }*start=NULL;
    
    struct Node* head;
    
    void add(std::string data);
    void remove(int index);
    void insert(int index, std::string data);
    Node* get(int index);
};

#endif /* linkedlist_hpp */
