//
//  linkedlist.cpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "linkedlist.hpp"

void linkedlist::add(std::string data) {
    Node* node;
    
    if (head == NULL) {
        head = new struct Node;
        node = head;
    }
    else {
        node->next = new struct Node;
        node = node->next;
    }
    node->data = data;
}

linkedlist::Node* linkedlist::get(int index) {
    if (head==NULL) throw std::exception();
    if (index==0) return head;
    Node* node = head;
    for (int i = 0; i < index; i++) {
        if (node->next==NULL) {
            throw std::exception();
        }
        node = node->next;
    }
    return node;
}

void linkedlist::insert(int index, std::string data) {
    if (head==NULL) throw std::exception();
    Node* node = head;
    for (int i = 0; i < index; i++) {
        if (node->next==NULL) {
            throw std::exception();
        }
        node = node->next;
    }
    Node* newNode;
    newNode->data = data;
    
    if (node->next!=NULL) {
        newNode->next = node->next;
    }
    
    node->next = newNode;
}
